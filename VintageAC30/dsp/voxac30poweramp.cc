// generated from file 'voxac30.dsp' by dsp2cc:
// Code generated with Faust 2.40.0 (https://faust.grame.fr)

#include <cmath>
#include <algorithm>


using std::signbit;

#include "math.h"
#include "voxac30_poweramp_neg_table.h"
#include "voxac30_poweramp_table.h"

namespace voxac30 {

class Dsp {
private:
	uint32_t fSampleRate;
	double fConst0;
	double fConst2;
	double fConst4;
	double fConst5;
	double fConst8;
	double fConst10;
	double fConst11;
	double fConst13;
	double fConst15;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT	*fVslider0_;
	double fRec4[2];
	double fConst17;
	double fConst19;
	double fConst20;
	double fConst21;
	double fConst22;
	double fConst23;
	double fConst25;
	double fConst27;
	double fConst28;
	double fConst29;
	double fRec3[6];
	double fConst31;
	double fConst33;
	double fConst35;
	double fConst37;
	double fConst39;
	double fConst41;
	double fConst42;
	double fConst43;
	double fConst44;
	double fConst45;
	double fConst46;
	double fConst47;
	double fConst48;
	double fConst50;
	double fConst51;
	double fConst52;
	double fRec2[4];
	double fConst54;
	double fConst55;
	double fConst56;
	double fConst58;
	double fConst59;
	double fRec1[3];
	double fConst60;
	double fConst61;
	double fConst63;
	double fConst64;
	double fConst65;
	double fConst66;
	double fRec0[5];
	double fConst67;
	double fConst68;


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
	for (int l0 = 0; l0 < 2; l0 = l0 + 1) fRec4[l0] = 0.0;
	for (int l1 = 0; l1 < 6; l1 = l1 + 1) fRec3[l1] = 0.0;
	for (int l2 = 0; l2 < 4; l2 = l2 + 1) fRec2[l2] = 0.0;
	for (int l3 = 0; l3 < 3; l3 = l3 + 1) fRec1[l3] = 0.0;
	for (int l4 = 0; l4 < 5; l4 = l4 + 1) fRec0[l4] = 0.0;
}

inline void Dsp::init(uint32_t sample_rate)
{
	fSampleRate = sample_rate;
	fConst0 = std::min<double>(192000.0, std::max<double>(1.0, double(fSampleRate)));
	double fConst1 = 1.0519671096234801e-19 * fConst0;
	fConst2 = 1.0 / (fConst0 * (fConst0 * (fConst0 * (fConst1 + 3.0639082971263998e-15) + 3.92325405868351e-11) + 2.57000147341282e-07) + 5.6939984671421805e-07);
	double fConst3 = 2.6384380446775501e-10 * fConst0;
	fConst4 = 1.0 / (fConst0 * (fConst3 + 8.1271887042870599e-06) + 0.0019988167005133002);
	fConst5 = fConst0 * (fConst3 + 3.9976334010265901e-06);
	double fConst6 = 8.7781564900278504e-15 * fConst0;
	double fConst7 = fConst0 * (fConst0 * (fConst6 + 1.25575735578898e-11) + 5.6800995828865601e-09) + 8.2319748379028003e-07;
	fConst8 = fConst0 / fConst7;
	double fConst9 = 8.7780687093407494e-15 * fConst0;
	fConst10 = fConst0 * (fConst9 + 2.07147343347553e-11) + 2.4695677556932801e-09;
	fConst11 = mydsp_faustpower2_f(fConst0);
	double fConst12 = 1.01104217213446e-23 * fConst0;
	fConst13 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (-4.6979029297587698e-21 - fConst12) + -3.1345725943159602e-19) + 1.9940981116627801e-17) + 7.1492319395335701e-16);
	double fConst14 = 1.8532563858321301e-23 * fConst0;
	fConst15 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (-4.7333087950325398e-21 - fConst14) + -2.2682791095944998e-19) + 1.19228083631203e-17) + 4.11450104770492e-16) + 1.98626688247003e-15;
	double fConst16 = 2.02208434426893e-23 * fConst0;
	fConst17 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst16 + 3.1319352865058502e-21) + -6.2691451886319205e-19) + -3.9881962233255601e-17) + 4.7661546263557104e-16);
	double fConst18 = 3.7065127716642502e-23 * fConst0;
	fConst19 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst18 + 3.1555391966883598e-21) + -4.5365582191890103e-19) + -2.3845616726240699e-17) + 2.7430006984699498e-16) + 3.97253376494006e-15;
	fConst20 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (3.1319352865058502e-21 - fConst16) + 6.2691451886319205e-19) + -3.9881962233255601e-17) + -4.7661546263557104e-16);
	fConst21 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (3.1555391966883598e-21 - fConst18) + 4.5365582191890103e-19) + -2.3845616726240699e-17) + -2.7430006984699498e-16) + 3.97253376494006e-15;
	fConst22 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst12 + -4.6979029297587698e-21) + 3.1345725943159602e-19) + 1.9940981116627801e-17) + -7.1492319395335701e-16);
	fConst23 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst14 + -4.7333087950325398e-21) + 2.2682791095944998e-19) + 1.19228083631203e-17) + -4.11450104770492e-16) + 1.98626688247003e-15;
	double fConst24 = 2.0220843442689299e-24 * fConst0;
	fConst25 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (1.56596764325292e-21 - fConst24) + -3.1345725943159602e-19) + 1.9940981116627801e-17) + -2.3830773131778601e-16);
	double fConst26 = 3.7065127716642502e-24 * fConst0;
	fConst27 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (1.5777695983441799e-21 - fConst26) + -2.2682791095944998e-19) + 1.19228083631203e-17) + -1.37150034923497e-16) + 3.97253376494006e-16;
	fConst28 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst24 + 1.56596764325292e-21) + 3.1345725943159602e-19) + 1.9940981116627801e-17) + 2.3830773131778601e-16);
	fConst29 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst26 + 1.5777695983441799e-21) + 2.2682791095944998e-19) + 1.19228083631203e-17) + 1.37150034923497e-16) + 3.97253376494006e-16;
	double fConst30 = 8.8103456518630198e-35 * fConst0;
	fConst31 = fConst0 * (fConst0 * (fConst30 + 4.7674690313620799e-32) + 1.8134403082585201e-30) + 9.7964055284766407e-31;
	double fConst32 = 1.04057542554619e-23 * fConst0;
	fConst33 = fConst0 * (fConst0 * (fConst32 + 2.6512763938031598e-21) + 1.60774085928415e-19) + 8.73256483061749e-20;
	double fConst34 = 4.40517282593151e-34 * fConst0;
	fConst35 = fConst0 * (fConst0 * (-1.43024070940862e-31 - fConst34) + -1.8134403082585201e-30) + 9.7964055284766407e-31;
	double fConst36 = 5.2028771277309502e-23 * fConst0;
	fConst37 = fConst0 * (fConst0 * (-7.9538291814094701e-21 - fConst36) + -1.60774085928415e-19) + 8.73256483061749e-20;
	double fConst38 = 8.8103456518630303e-34 * fConst0;
	fConst39 = fConst0 * (fConst0 * (fConst38 + 9.5349380627241599e-32) + -3.6268806165170403e-30) + -1.9592811056953299e-30;
	double fConst40 = 1.04057542554619e-22 * fConst0;
	fConst41 = fConst0 * (fConst0 * (fConst40 + 5.3025527876063197e-21) + -3.2154817185683101e-19) + -1.7465129661234999e-19;
	fConst42 = fConst0 * (fConst0 * (9.5349380627241599e-32 - fConst38) + 3.6268806165170403e-30) + -1.9592811056953299e-30;
	fConst43 = fConst0 * (fConst0 * (5.3025527876063197e-21 - fConst40) + 3.2154817185683101e-19) + -1.7465129661234999e-19;
	fConst44 = fConst0 * (fConst0 * (fConst34 + -1.43024070940862e-31) + 1.8134403082585201e-30) + 9.7964055284766407e-31;
	fConst45 = fConst0 * (fConst0 * (fConst36 + -7.9538291814094701e-21) + 1.60774085928415e-19) + 8.73256483061749e-20;
	fConst46 = fConst0 * (fConst0 * (4.7674690313620799e-32 - fConst30) + -1.8134403082585201e-30) + 9.7964055284766407e-31;
	fConst47 = fConst0 * (fConst0 * (2.6512763938031598e-21 - fConst32) + -1.60774085928415e-19) + 8.73256483061749e-20;
	fConst48 = 1.0 / fConst7;
	double fConst49 = 2.6334469470083501e-14 * fConst0;
	fConst50 = fConst0 * (fConst0 * (-1.25575735578898e-11 - fConst49) + 5.6800995828865601e-09) + 2.4695924513708402e-06;
	fConst51 = fConst0 * (fConst0 * (fConst49 + -1.25575735578898e-11) + -5.6800995828865601e-09) + 2.4695924513708402e-06;
	fConst52 = fConst0 * (fConst0 * (1.25575735578898e-11 - fConst6) + -5.6800995828865601e-09) + 8.2319748379028003e-07;
	double fConst53 = 2.6334206128022299e-14 * fConst0;
	fConst54 = fConst0 * (-2.07147343347553e-11 - fConst53) + 2.4695677556932801e-09;
	fConst55 = fConst0 * (fConst53 + -2.07147343347553e-11) + -2.4695677556932801e-09;
	fConst56 = fConst0 * (2.07147343347553e-11 - fConst9) + -2.4695677556932801e-09;
	double fConst57 = 5.2768760893551003e-10 * fConst11;
	fConst58 = 0.00399763340102659 - fConst57;
	fConst59 = fConst0 * (fConst3 + -8.1271887042870599e-06) + 0.0019988167005133002;
	fConst60 = 0.0 - fConst57;
	fConst61 = fConst0 * (fConst3 + -3.9976334010265901e-06);
	double fConst62 = 4.2078684384939e-19 * fConst0;
	fConst63 = fConst0 * (fConst11 * (-6.1278165942527902e-15 - fConst62) + 5.1400029468256295e-07) + 2.2775993868568701e-06;
	fConst64 = fConst11 * (6.3118026577408498e-19 * fConst11 + -7.84650811736702e-11) + 3.41639908028531e-06;
	fConst65 = fConst0 * (fConst11 * (6.1278165942527902e-15 - fConst62) + -5.1400029468256295e-07) + 2.2775993868568701e-06;
	fConst66 = fConst0 * (fConst0 * (fConst0 * (fConst1 + -3.0639082971263998e-15) + 3.92325405868351e-11) + -2.57000147341282e-07) + 5.6939984671421805e-07;
	fConst67 = 0.0 - 5.0311164227352704e-07 * fConst0;
	fConst68 = 0.0 - 2.5155582113676299e-07 * fConst0;
	clear_state_f();
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fVslider0 (*fVslider0_)
	double fSlow0 = 0.00036676987543879196 * (std::exp(3.0 * double(fVslider0)) + -1.0);
	for (int i0 = 0; i0 < count; i0 = i0 + 1) {
		fRec4[0] = fSlow0 + 0.99299999999999999 * fRec4[1];
		double fTemp0 = fConst28 + fConst29 * fRec4[0] + 6.9916594262945002e-16;
		fRec3[0] = double(input0[i0]) - (fRec3[1] * (fConst13 + fConst15 * fRec4[0] + 3.49582971314725e-15) + fRec3[2] * (fConst17 + fConst19 * fRec4[0] + 6.9916594262945e-15) + fRec3[3] * (fConst20 + fConst21 * fRec4[0] + 6.9916594262945e-15) + fRec3[4] * (fConst22 + fConst23 * fRec4[0] + 3.49582971314725e-15) + fRec3[5] * (fConst25 + fConst27 * fRec4[0] + 6.9916594262945002e-16)) / fTemp0;
		double fTemp1 = fConst11 * (fRec3[0] * (fConst31 + fConst33 * fRec4[0]) + fRec3[1] * (fConst35 + fConst37 * fRec4[0]) + fRec3[2] * (fConst39 + fConst41 * fRec4[0]) + fRec3[3] * (fConst42 + fConst43 * fRec4[0]) + fRec3[4] * (fConst44 + fConst45 * fRec4[0]) + fRec3[5] * (fConst46 + fConst47 * fRec4[0])) / fTemp0;
		double fThen0 = double(voxac30_powerampclip(double(fTemp1)));
		double fElse0 = double(voxac30_poweramp_negclip(double(fTemp1)));
		fRec2[0] = ((int(signbit(double(fTemp1)))) ? fElse0 : fThen0) - fConst48 * (fConst50 * fRec2[1] + fConst51 * fRec2[2] + fConst52 * fRec2[3]);
		fRec1[0] = fConst8 * (fConst10 * fRec2[0] + fConst54 * fRec2[1] + fConst55 * fRec2[2] + fConst56 * fRec2[3]) - fConst4 * (fConst58 * fRec1[1] + fConst59 * fRec1[2]);
		fRec0[0] = fConst4 * (fConst5 * fRec1[0] + fConst60 * fRec1[1] + fConst61 * fRec1[2]) - fConst2 * (fConst63 * fRec0[1] + fConst64 * fRec0[2] + fConst65 * fRec0[3] + fConst66 * fRec0[4]);
		output0[i0] = FAUSTFLOAT(fConst2 * (fConst0 * (2.5155582113676299e-07 * fRec0[0] + 5.0311164227352704e-07 * fRec0[1]) + fConst67 * fRec0[3] + fConst68 * fRec0[4]));
		fRec4[1] = fRec4[0];
		for (int j0 = 5; j0 > 0; j0 = j0 - 1) {
			fRec3[j0] = fRec3[j0 - 1];
		}
		for (int j1 = 3; j1 > 0; j1 = j1 - 1) {
			fRec2[j1] = fRec2[j1 - 1];
		}
		fRec1[2] = fRec1[1];
		fRec1[1] = fRec1[0];
		for (int j2 = 4; j2 > 0; j2 = j2 - 1) {
			fRec0[j2] = fRec0[j2 - 1];
		}
	}
#undef fVslider0
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case volume: 
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
} // end namespace voxac30
