
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstring>
#include <unistd.h>

#include <lv2.h>

typedef enum
{
   input0,
   output0,
   Bypass,
   topboost,
   gain1,
   gain2,
   treble,
   bass,
   volume,
} PortIndex;


#define FAUSTFLOAT float

template<class T> inline T mydsp_faustpower2_f(T x) {return (x * x);}
template<class T> inline T mydsp_faustpower3_f(T x) {return ((x * x) * x);}
template<class T> inline T mydsp_faustpower4_f(T x) {return (((x * x) * x) * x);}
template<class T> inline T mydsp_faustpower5_f(T x) {return ((((x * x) * x) * x) * x);}
template<class T> inline T mydsp_faustpower6_f(T x) {return (((((x * x) * x) * x) * x) * x);}

#define always_inline inline __attribute__((__always_inline__))

#include "voxac30normal.cc"
#include "voxac30topboost.cc"
#include "voxac30poweramp.cc"

///////////////////////// MACRO SUPPORT ////////////////////////////////

#define PLUGIN_URI "https://github.com/brummer10/VintageAC30"

////////////////////////////// PLUG-IN CLASS ///////////////////////////

namespace vintageac30 {

class Xvintageac30
{
private:
    float* input0;
    float* output0;
    float* bypass;
    float bypass_;
    float* topboost;
    float topboost_;
    // bypass ramping
    bool needs_ramp_down;
    bool needs_ramp_up;
    float ramp_down;
    float ramp_up;
    float ramp_up_step;
    float ramp_down_step;
    bool bypassed;
    voxac30_normal::Dsp* ac30norm;
    voxac30_topboost::Dsp* ac30topbbost;
    voxac30::Dsp* ac30poweramp;

    // private functions
    inline void run_dsp_(uint32_t n_samples);
    inline void connect_(uint32_t port,void* data);
    inline void init_dsp_(uint32_t rate);
    inline void connect_all__ports(uint32_t port, void* data);
    inline void activate_f();
    inline void clean_up();
    inline void deactivate_f();
public:
    // LV2 Descriptor
    static const LV2_Descriptor descriptor;
    // static wrapper to private functions
    static void deactivate(LV2_Handle instance);
    static void cleanup(LV2_Handle instance);
    static void run(LV2_Handle instance, uint32_t n_samples);
    static void activate(LV2_Handle instance);
    static void connect_port(LV2_Handle instance, uint32_t port, void* data);
    static LV2_Handle instantiate(const LV2_Descriptor* descriptor,
                                double rate, const char* bundle_path,
                                const LV2_Feature* const* features);
    Xvintageac30();
    ~Xvintageac30();
};

// constructor
Xvintageac30::Xvintageac30() :

    input0(NULL),
    output0(NULL),
    bypass(NULL),
    bypass_(2),
    topboost(NULL),
    needs_ramp_down(false),
    needs_ramp_up(false),
    bypassed(false),
    ac30norm(voxac30_normal::plugin()),
    ac30topbbost(voxac30_topboost::plugin()),
    ac30poweramp(voxac30::plugin()) {};

// destructor
Xvintageac30::~Xvintageac30() {
    ac30norm->del_instance(ac30norm);
    ac30topbbost->del_instance(ac30topbbost);
    ac30poweramp->del_instance(ac30poweramp);
};

///////////////////////// PRIVATE CLASS  FUNCTIONS /////////////////////

void Xvintageac30::init_dsp_(uint32_t rate)
{
    // set values for internal ramping
    ramp_down_step = 32 * (256 * rate) / 48000; 
    ramp_up_step = ramp_down_step;
    ramp_down = ramp_down_step;
    ramp_up = 0.0;
    ac30norm->init(rate);
    ac30topbbost->init(rate);
    ac30poweramp->init(rate);
}

// connect the Ports used by the plug-in class
void Xvintageac30::connect_(uint32_t port,void* data)
{
    switch ((PortIndex)port)
    {
        case 0:
            input0 = static_cast<float*>(data);
            break;
        case 1:
            output0 = static_cast<float*>(data);
            break;
        case 2:
            bypass = static_cast<float*>(data);
            break;
        case 3:
            topboost = static_cast<float*>(data);
            break;
        default:
            break;
    }
}

void Xvintageac30::activate_f()
{
    // allocate the internal DSP mem
    ac30norm->clear_state_f();
    ac30topbbost->clear_state_f();
    ac30poweramp->clear_state_f();
}

void Xvintageac30::clean_up()
{
    // delete the internal DSP mem
    ac30norm->clear_state_f();
    ac30topbbost->clear_state_f();
    ac30poweramp->clear_state_f();
}

void Xvintageac30::deactivate_f()
{
    // delete the internal DSP mem
}

void Xvintageac30::run_dsp_(uint32_t n_samples)
{
    if(n_samples<1) return;

    // get controller values
#define  topboost_ (*(topboost))

    // do inplace processing on default
    if(output0 != input0)
        memcpy(output0, input0, n_samples*sizeof(float));

    float buf0[n_samples];
    // check if bypass is pressed
    if (bypass_ != static_cast<uint32_t>(*(bypass))) {
        bypass_ = static_cast<uint32_t>(*(bypass));
        if (!bypass_) {
            needs_ramp_down = true;
            needs_ramp_up = false;
        } else {
            needs_ramp_down = false;
            needs_ramp_up = true;
            bypassed = false;
        }
    }

    if (needs_ramp_down || needs_ramp_up) {
         memcpy(buf0, input0, n_samples*sizeof(float));
    }
    if (!bypassed) {
        if (!topboost_) {
            ac30norm->compute(n_samples, output0, output0);
        } else {
            ac30topbbost->compute(n_samples, output0, output0);
        }
        ac30poweramp->compute(n_samples, output0, output0);
    }
    // check if ramping is needed
    if (needs_ramp_down) {
        float fade = 0;
        for (uint32_t i=0; i<n_samples; i++) {
            if (ramp_down >= 0.0) {
                --ramp_down; 
            }
            fade = std::max(0.0f,ramp_down) /ramp_down_step ;
            output0[i] = output0[i] * fade + buf0[i] * (1.0 - fade);
        }
        if (ramp_down <= 0.0) {
            // when ramped down, clear buffer from dsp
            ac30norm->clear_state_f();
            ac30topbbost->clear_state_f();
            ac30poweramp->clear_state_f();
            needs_ramp_down = false;
            bypassed = true;
            ramp_down = ramp_down_step;
            ramp_up = 0.0;
        } else {
            ramp_up = ramp_down;
        }
    } else if (needs_ramp_up) {
        float fade = 0;
        for (uint32_t i=0; i<n_samples; i++) {
            if (ramp_up < ramp_up_step) {
                ++ramp_up ;
            }
            fade = std::min(ramp_up_step,ramp_up) /ramp_up_step ;
            output0[i] = output0[i] * fade + buf0[i] * (1.0 - fade);
        }
        if (ramp_up >= ramp_up_step) {
            needs_ramp_up = false;
            ramp_up = 0.0;
            ramp_down = ramp_down_step;
        } else {
            ramp_down = ramp_up;
        }
    }
#undef  topboost_
}

void Xvintageac30::connect_all__ports(uint32_t port, void* data)
{
    // connect the Ports used by the plug-in class
    connect_(port,data); 
    ac30norm->connect(port,data);
    ac30topbbost->connect(port,data);
    ac30poweramp->connect(port,data);
}

////////////////////// STATIC CLASS  FUNCTIONS  ////////////////////////

LV2_Handle 
Xvintageac30::instantiate(const LV2_Descriptor* descriptor,
                            double rate, const char* bundle_path,
                            const LV2_Feature* const* features)
{
    // init the plug-in class
    Xvintageac30 *self = new Xvintageac30();
    if (!self) {
        return NULL;
    }
    self->init_dsp_((uint32_t)rate);
    return (LV2_Handle)self;
}

void Xvintageac30::connect_port(LV2_Handle instance, 
                                   uint32_t port, void* data)
{
    // connect all ports
    static_cast<Xvintageac30*>(instance)->connect_all__ports(port, data);
}

void Xvintageac30::activate(LV2_Handle instance)
{
    // allocate needed mem
    static_cast<Xvintageac30*>(instance)->activate_f();
}

void Xvintageac30::run(LV2_Handle instance, uint32_t n_samples)
{
    // run dsp
    static_cast<Xvintageac30*>(instance)->run_dsp_(n_samples);
}

void Xvintageac30::deactivate(LV2_Handle instance)
{
    // free allocated mem
    static_cast<Xvintageac30*>(instance)->deactivate_f();
}

void Xvintageac30::cleanup(LV2_Handle instance)
{
    // well, clean up after us
    Xvintageac30* self = static_cast<Xvintageac30*>(instance);
    self->clean_up();
    delete self;
}

const LV2_Descriptor Xvintageac30::descriptor =
{
    PLUGIN_URI ,
    Xvintageac30::instantiate,
    Xvintageac30::connect_port,
    Xvintageac30::activate,
    Xvintageac30::run,
    Xvintageac30::deactivate,
    Xvintageac30::cleanup,
    NULL
};

} // end namespace vintageac30

////////////////////////// LV2 SYMBOL EXPORT ///////////////////////////

LV2_SYMBOL_EXPORT
const LV2_Descriptor*
lv2_descriptor(uint32_t index)
{
    switch (index)
    {
        case 0:
            return &vintageac30::Xvintageac30::descriptor;
        default:
            return NULL;
    }
}

///////////////////////////// FIN //////////////////////////////////////
