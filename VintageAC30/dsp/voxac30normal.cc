// generated from file 'voxac30_normal.dsp' by dsp2cc:
// Code generated with Faust 2.40.0 (https://faust.grame.fr)

#include <cmath>
#include <algorithm>

using std::signbit;

#include "math.h"
#include "voxac30_normal_neg_table.h"
#include "voxac30_normal_table.h"

namespace voxac30_normal {

class Dsp {
private:
	uint32_t fSampleRate;
	double fConst3;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT	*fVslider0_;
	double fRec0[2];
	double fConst5;
	double fConst6;
	double fConst8;
	double fConst9;
	double fConst10;
	double fRec1[4];
	double fConst11;
	double fConst12;
	double fConst13;


public:
	void connect(uint32_t port,void* data);
	void del_instance(Dsp *p);
	void clear_state_f();
	void init(uint32_t sample_rate);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);
	Dsp();
	~Dsp();
};



Dsp::Dsp() {
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int l0 = 0; l0 < 2; l0 = l0 + 1) fRec0[l0] = 0.0;
	for (int l1 = 0; l1 < 4; l1 = l1 + 1) fRec1[l1] = 0.0;
}

inline void Dsp::init(uint32_t sample_rate)
{
	fSampleRate = sample_rate;
	double fConst0 = std::min<double>(192000.0, std::max<double>(1.0, double(fSampleRate)));
	double fConst1 = 4.07845308653038e-15 * fConst0;
	double fConst2 = fConst0 * (fConst0 * (fConst1 + 2.3810590347523298e-10) + 7.4930376097021702e-09) + 4.88422288211756e-08;
	fConst3 = fConst0 / fConst2;
	double fConst4 = 1.69090382579266e-08 * fConst0;
	fConst5 = -2.2545384343902299e-07 - fConst4;
	fConst6 = 1.0 / fConst2;
	double fConst7 = 1.22353592595911e-14 * fConst0;
	fConst8 = fConst0 * (fConst0 * (-2.3810590347523298e-10 - fConst7) + 7.4930376097021702e-09) + 1.46526686463527e-07;
	fConst9 = fConst0 * (fConst0 * (fConst7 + -2.3810590347523298e-10) + -7.4930376097021702e-09) + 1.46526686463527e-07;
	fConst10 = fConst0 * (fConst0 * (2.3810590347523298e-10 - fConst1) + -7.4930376097021702e-09) + 4.88422288211756e-08;
	fConst11 = fConst4 + -2.2545384343902299e-07;
	fConst12 = fConst4 + 2.2545384343902299e-07;
	fConst13 = 2.2545384343902299e-07 - fConst4;
	clear_state_f();
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fVslider0 (*fVslider0_)
	double fSlow0 = 0.00036676987543879196 * (std::exp(3.0 * double(fVslider0)) + -1.0);
	for (int i0 = 0; i0 < count; i0 = i0 + 1) {
		fRec0[0] = fSlow0 + 0.99299999999999999 * fRec0[1];
		fRec1[0] = double(input0[i0]) - fConst6 * (fConst8 * fRec1[1] + fConst9 * fRec1[2] + fConst10 * fRec1[3]);
		double fTemp0 = fConst3 * fRec0[0] * (fConst5 * fRec1[0] + fConst11 * fRec1[1] + fConst12 * fRec1[2] + fConst13 * fRec1[3]);
		double fThen0 = double(voxac30_normalclip(double(fTemp0)));
		double fElse0 = double(voxac30_normal_negclip(double(fTemp0)));
		output0[i0] = FAUSTFLOAT(((int(signbit(double(fTemp0)))) ? fElse0 : fThen0));
		fRec0[1] = fRec0[0];
		for (int j0 = 3; j0 > 0; j0 = j0 - 1) {
			fRec1[j0] = fRec1[j0 - 1];
		}
	}
#undef fVslider0
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case gain1: 
		fVslider0_ = static_cast<float*>(data); // , 0.5, 0.0, 1.0, 0.01 
		break;
	default:
		break;
	}
}

Dsp *plugin() {
	return new Dsp();
}

void Dsp::del_instance(Dsp *p)
{
	delete p;
}
} // end namespace voxac30_normal
