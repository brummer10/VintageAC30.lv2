// generated from file 'voxac30_topboost.dsp' by dsp2cc:
// Code generated with Faust 2.40.0 (https://faust.grame.fr)

#include <cmath>
#include <algorithm>

using std::signbit;

#include "math.h"
#include "voxac30_stage1_neg_table.h"
#include "voxac30_stage1_table.h"

namespace voxac30_topboost {

class Dsp {
private:
	uint32_t fSampleRate;
	double fConst0;
	double fConst1;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT	*fVslider0_;
	double fRec1[2];
	double fConst2;
	double fConst4;
	double fConst6;
	double fConst7;
	double fConst9;
	double fConst10;
	double fConst11;
	double fConst12;
	double fConst13;
	double fConst15;
	double fConst17;
	double fConst18;
	double fConst19;
	double fConst20;
	double fConst21;
	double fRec2[5];
	double fConst23;
	double fConst24;
	double fConst25;
	double fConst26;
	double fConst27;
	double fConst28;
	double fConst29;
	double fConst30;
	double fConst31;
	double fConst32;
	double fConst34;
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT	*fVslider1_;
	double fRec3[2];
	double fConst36;
	double fConst38;
	double fConst39;
	double fConst40;
	double fConst41;
	double fConst42;
	double fConst43;
	double fConst44;
	double fConst46;
	double fConst48;
	double fConst50;
	double fConst51;
	double fConst52;
	double fConst53;
	double fRec0[5];
	double fConst55;
	double fConst57;
	double fConst58;
	double fConst60;
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT	*fVslider2_;
	double fRec4[2];
	double fConst62;
	double fConst64;
	double fConst66;
	double fConst68;
	double fConst69;
	double fConst71;
	double fConst73;
	double fConst75;
	double fConst77;
	double fConst78;
	double fConst79;
	double fConst80;
	double fConst81;
	double fConst82;
	double fConst83;
	double fConst84;
	double fConst85;
	double fConst86;
	double fConst87;
	double fConst88;
	double fConst89;
	double fConst90;
	double fConst91;
	double fConst92;


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
	for (int l0 = 0; l0 < 2; l0 = l0 + 1) fRec1[l0] = 0.0;
	for (int l1 = 0; l1 < 5; l1 = l1 + 1) fRec2[l1] = 0.0;
	for (int l2 = 0; l2 < 2; l2 = l2 + 1) fRec3[l2] = 0.0;
	for (int l3 = 0; l3 < 5; l3 = l3 + 1) fRec0[l3] = 0.0;
	for (int l4 = 0; l4 < 2; l4 = l4 + 1) fRec4[l4] = 0.0;
}

inline void Dsp::init(uint32_t sample_rate)
{
	fSampleRate = sample_rate;
	fConst0 = std::min<double>(192000.0, std::max<double>(1.0, double(fSampleRate)));
	fConst1 = 0.10000000000000001 * fConst0;
	fConst2 = mydsp_faustpower2_f(fConst0);
	double fConst3 = 3.8802654000133502e-15 * fConst2;
	fConst4 = 1.3087594271538099e-07 - fConst3;
	double fConst5 = 9.1300147529378906e-19 * fConst0;
	fConst6 = fConst2 * (-2.3907284555305201e-14 - fConst5) + -5.1388902192685597e-10;
	fConst7 = fConst2 * (fConst5 + 2.5505046267084001e-14);
	double fConst8 = 1.3695022129406799e-18 * fConst2;
	fConst9 = fConst8 + 2.5044632694837101e-11;
	fConst10 = 5.1388902192685599e-13 - fConst8;
	fConst11 = fConst3 + -1.3087594271538099e-07;
	fConst12 = fConst2 * (2.3907284555305201e-14 - fConst5) + 5.1388902192685597e-10;
	fConst13 = fConst2 * (fConst5 + -2.5505046267084001e-14);
	double fConst14 = 1.9401327000066798e-15 * fConst0;
	fConst15 = fConst0 * (8.0536280805539305e-11 - fConst14) + -6.5437971357690599e-08;
	double fConst16 = 2.2825036882344698e-19 * fConst0;
	fConst17 = fConst0 * (fConst0 * (fConst16 + -1.19536422776526e-14) + -1.2522316347418601e-11) + 2.5694451096342799e-10;
	fConst18 = fConst0 * (fConst0 * (1.2752523133542001e-14 - fConst16) + -2.56944510963428e-13);
	fConst19 = fConst0 * (fConst14 + 8.0536280805539305e-11) + 6.5437971357690599e-08;
	fConst20 = fConst0 * (fConst0 * (fConst16 + 1.19536422776526e-14) + -1.2522316347418601e-11) + -2.5694451096342799e-10;
	fConst21 = fConst0 * (fConst0 * (-1.2752523133542001e-14 - fConst16) + -2.56944510963428e-13);
	double fConst22 = 9.4631325577256199e-13 * fConst0;
	fConst23 = fConst0 * (-4.7441837889397796e-09 - fConst22) + -6.3087550384836394e-08;
	fConst24 = fConst0 * (fConst22 + 1.2617510076967299e-11);
	fConst25 = 1.8926265115451199e-12 * fConst2;
	fConst26 = fConst0 * (fConst25 + -1.26175100769673e-07);
	fConst27 = 0.0 - 1.8926265115451199e-12 * mydsp_faustpower3_f(fConst0);
	fConst28 = 9.4883675778795493e-09 * fConst2;
	fConst29 = 0.0 - 2.5235020153934498e-11 * fConst2;
	fConst30 = 1.26175100769673e-07 - fConst25;
	fConst31 = fConst0 * (fConst22 + -4.7441837889397796e-09) + 6.3087550384836394e-08;
	fConst32 = fConst0 * (1.2617510076967299e-11 - fConst22);
	double fConst33 = 5.5283860578378502e-17 * fConst2;
	fConst34 = fConst0 * (7.6258830017880104e-11 - fConst33);
	double fConst35 = 2.4324898654486498e-18 * fConst0;
	fConst36 = fConst2 * (-1.3062626037579199e-14 - fConst35) + 1.47654625402069e-12;
	double fConst37 = 2.4106918781546098e-18 * fConst0;
	fConst38 = fConst2 * (fConst37 + 1.2998651482078101e-14) + -7.6233087050691705e-11;
	fConst39 = 3.6487347981729799e-18 * fConst2 + -2.3865408641023399e-12;
	fConst40 = 2.9406548982098701e-12 - 3.6160378172319097e-18 * fConst2;
	fConst41 = 5.8850739175238204e-13 * fConst2;
	fConst42 = fConst0 * (fConst33 + -7.6258830017880104e-11);
	fConst43 = fConst2 * (1.3062626037579199e-14 - fConst35) + -1.47654625402069e-12;
	fConst44 = fConst2 * (fConst37 + -1.2998651482078101e-14) + 7.6233087050691705e-11;
	double fConst45 = 2.7641930289189199e-17 * fConst0;
	fConst46 = fConst0 * (fConst0 * (2.9425369587619102e-13 - fConst45) + -3.812941500894e-11);
	double fConst47 = 6.0812246636216303e-19 * fConst0;
	fConst48 = fConst0 * (fConst0 * (fConst47 + -6.5313130187895902e-15) + 1.1932704320511699e-12) + -7.3827312701034397e-13;
	double fConst49 = 6.0267296953865197e-19 * fConst0;
	fConst50 = fConst0 * (fConst0 * (6.4993257410390298e-15 - fConst49) + -1.4703274491049401e-12) + 3.8116543525345801e-11;
	fConst51 = fConst0 * (fConst0 * (fConst45 + 2.9425369587619102e-13) + 3.812941500894e-11);
	fConst52 = fConst0 * (fConst0 * (fConst47 + 6.5313130187895902e-15) + 1.1932704320511699e-12) + 7.3827312701034397e-13;
	fConst53 = fConst0 * (fConst0 * (-6.4993257410390298e-15 - fConst49) + -1.4703274491049401e-12) + -3.8116543525345801e-11;
	double fConst54 = 1.5289897356948601e-16 * fConst0;
	fConst55 = fConst0 * (-1.4826096634268e-12 - fConst54) + -2.24286820047292e-11;
	double fConst56 = 3.3637774185287002e-18 * fConst0;
	fConst57 = fConst0 * (fConst0 * (-4.0922606841550202e-14 - fConst56) + -7.3973537899982003e-11) + -1.1114283427185101e-09;
	fConst58 = fConst0 * (fConst0 * (fConst56 + 4.0992106374990897e-14) + 7.4713947661946494e-11) + 1.1226307175477699e-09;
	double fConst59 = 3.0579794713897297e-17 * fConst0;
	fConst60 = fConst2 * (fConst59 + 4.6333022293784298e-16);
	double fConst61 = 3.0885592661036198e-17 * fConst0;
	fConst62 = fConst0 * (fConst0 * (9.2202714364629007e-16 - fConst61) + 1.79013949771437e-13) + 2.39323462261283e-12;
	double fConst63 = 1.40389057550165e-15 * fConst0;
	fConst64 = fConst0 * (-1.8080408926915201e-13 - fConst63) + -2.4171669688389501e-12;
	double fConst65 = 3.0579794713897301e-16 * fConst2;
	fConst66 = fConst65 + -4.4857364009458401e-11;
	double fConst67 = 1.3455109674114801e-17 * fConst0;
	fConst68 = fConst2 * (fConst67 + 8.1845213683100504e-14) + -2.2228566854370301e-09;
	fConst69 = fConst2 * (-8.1984212749981795e-14 - fConst67) + 2.2452614350955299e-09;
	double fConst70 = 1.2231917885558899e-16 * fConst0;
	fConst71 = fConst2 * (-9.2666044587568597e-16 - fConst70);
	double fConst72 = 1.2354237064414501e-16 * fConst0;
	fConst73 = fConst2 * (fConst72 + -1.8440542872925801e-15) + 4.7864692452256503e-12;
	double fConst74 = 2.8077811510032901e-15 * fConst2;
	fConst75 = fConst74 + -4.83433393767791e-12;
	double fConst76 = 2.0182664511172199e-17 * fConst2;
	fConst77 = 1.4794707579996401e-10 - fConst76;
	fConst78 = fConst76 + -1.4942789532389299e-10;
	fConst79 = 1.8347876828338399e-16 * fConst2;
	fConst80 = -3.5802789954287501e-13 - 1.85313555966217e-16 * fConst2;
	fConst81 = 4.4857364009458401e-11 - fConst65;
	fConst82 = fConst2 * (fConst67 + -8.1845213683100504e-14) + 2.2228566854370301e-09;
	fConst83 = fConst2 * (8.1984212749981795e-14 - fConst67) + -2.2452614350955299e-09;
	fConst84 = fConst2 * (9.2666044587568597e-16 - fConst70);
	fConst85 = fConst2 * (fConst72 + 1.8440542872925801e-15) + -4.7864692452256503e-12;
	fConst86 = 4.83433393767791e-12 - fConst74;
	fConst87 = fConst0 * (fConst54 + -1.4826096634268e-12) + 2.24286820047292e-11;
	fConst88 = fConst0 * (fConst0 * (4.0922606841550202e-14 - fConst56) + -7.3973537899982003e-11) + 1.1114283427185101e-09;
	fConst89 = fConst0 * (fConst0 * (fConst56 + -4.0992106374990897e-14) + 7.4713947661946494e-11) + -1.1226307175477699e-09;
	fConst90 = fConst2 * (fConst59 + -4.6333022293784298e-16);
	fConst91 = fConst0 * (fConst0 * (-9.2202714364629007e-16 - fConst61) + 1.79013949771437e-13) + -2.39323462261283e-12;
	fConst92 = fConst0 * (fConst63 + -1.8080408926915201e-13) + 2.4171669688389501e-12;
	clear_state_f();
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fVslider0 (*fVslider0_)
#define fVslider1 (*fVslider1_)
#define fVslider2 (*fVslider2_)
	double fSlow0 = 0.00036676987543879196 * (std::exp(3.0 * double(fVslider0)) + -1.0);
	double fSlow1 = 0.0070000000000000062 * double(fVslider1);
	double fSlow2 = 0.00036676987543879196 * (std::exp(3.0 * double(fVslider2)) + -1.0);
	for (int i0 = 0; i0 < count; i0 = i0 + 1) {
		fRec1[0] = fSlow0 + 0.99299999999999999 * fRec1[1];
		double fTemp0 = fConst0 * (fConst19 + fRec1[0] * (fConst20 + fConst21 * fRec1[0])) + 1.2847225548171399e-06;
		fRec2[0] = double(input0[i0]) - (fRec2[1] * (fConst0 * (fConst4 + fRec1[0] * (fConst6 + fConst7 * fRec1[0])) + 5.1388902192685597e-06) + fRec2[2] * (fConst2 * (fRec1[0] * (fConst9 + fConst10 * fRec1[0]) + -1.61072561611079e-10) + 7.7083353289028505e-06) + fRec2[3] * (fConst0 * (fConst11 + fRec1[0] * (fConst12 + fConst13 * fRec1[0])) + 5.1388902192685597e-06) + fRec2[4] * (fConst0 * (fConst15 + fRec1[0] * (fConst17 + fConst18 * fRec1[0])) + 1.2847225548171399e-06)) / fTemp0;
		double fTemp1 = (fRec1[0] * (fConst0 * fRec2[0] * (fConst23 + fConst24 * fRec1[0]) + fRec2[1] * (fConst26 + fConst27 * fRec1[0]) + fRec2[2] * (fConst28 + fConst29 * fRec1[0]) + fConst0 * fRec2[3] * (fConst30 + fConst25 * fRec1[0]) + fConst0 * fRec2[4] * (fConst31 + fConst32 * fRec1[0]))) / fTemp0;
		double fThen0 = double(voxac30_stage1clip(double(fTemp1)));
		double fElse0 = double(voxac30_stage1_negclip(double(fTemp1)));
		fRec3[0] = fSlow1 + 0.99299999999999999 * fRec3[1];
		double fTemp2 = fConst51 + fRec3[0] * (fConst0 * (fConst52 + fConst53 * fRec3[0]) + -8.6443832551698297e-10) + 8.7308270877215204e-10;
		fRec0[0] = ((int(signbit(double(fTemp1)))) ? fElse0 : fThen0) - (fRec0[1] * (fConst34 + fRec3[0] * (fConst0 * (fConst36 + fConst38 * fRec3[0]) + -3.4577533020679298e-09) + 3.4923308350886098e-09) + fRec0[2] * ((fRec3[0] * (fConst2 * (fConst39 + fConst40 * fRec3[0]) + -5.1866299531018999e-09) + 5.2384962526329098e-09) - fConst41) + fRec0[3] * (fConst42 + fRec3[0] * (fConst0 * (fConst43 + fConst44 * fRec3[0]) + -3.4577533020679298e-09) + 3.4923308350886098e-09) + fRec0[4] * (fConst46 + fRec3[0] * (fConst0 * (fConst48 + fConst50 * fRec3[0]) + -8.6443832551698297e-10) + 8.7308270877215204e-10)) / fTemp2;
		fRec4[0] = fSlow2 + 0.99299999999999999 * fRec4[1];
		output0[i0] = FAUSTFLOAT(fConst1 * (fRec0[0] * (fConst55 + fRec3[0] * (fConst57 + fRec3[0] * (fConst58 + fConst60 * fRec4[0]) + fConst62 * fRec4[0]) + fConst64 * fRec4[0]) + fRec0[1] * (fConst66 + fRec3[0] * (fConst68 + fRec3[0] * (fConst69 + fConst71 * fRec4[0]) + fConst73 * fRec4[0]) + fConst75 * fRec4[0]) + fConst0 * fRec0[2] * (fRec3[0] * (fConst77 + fRec3[0] * (fConst78 + fConst79 * fRec4[0]) + fConst80 * fRec4[0]) + 3.6160817853830401e-13 * fRec4[0] + 2.96521932685359e-12) + fRec0[3] * (fConst81 + fRec3[0] * (fConst82 + fRec3[0] * (fConst83 + fConst84 * fRec4[0]) + fConst85 * fRec4[0]) + fConst86 * fRec4[0]) + fRec0[4] * (fConst87 + fRec3[0] * (fConst88 + fRec3[0] * (fConst89 + fConst90 * fRec4[0]) + fConst91 * fRec4[0]) + fConst92 * fRec4[0])) / fTemp2);
		fRec1[1] = fRec1[0];
		for (int j0 = 4; j0 > 0; j0 = j0 - 1) {
			fRec2[j0] = fRec2[j0 - 1];
		}
		fRec3[1] = fRec3[0];
		for (int j1 = 4; j1 > 0; j1 = j1 - 1) {
			fRec0[j1] = fRec0[j1 - 1];
		}
		fRec4[1] = fRec4[0];
	}
#undef fVslider0
#undef fVslider1
#undef fVslider2
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case bass: 
		fVslider1_ = static_cast<float*>(data); // , 0.5, 0.0, 1.0, 0.01 
		break;
	case gain2: 
		fVslider0_ = static_cast<float*>(data); // , 0.5, 0.0, 1.0, 0.01 
		break;
	case treble: 
		fVslider2_ = static_cast<float*>(data); // , 0.5, 0.0, 1.0, 0.01 
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
} // end namespace voxac30_topboost
