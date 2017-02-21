typedef enum {
	ATH_RATE_1M, 		//0
	ATH_RATE_2M,
	ATH_RATE_5_5M,
	ATH_RATE_11M,		//3

	ATH_RATE_6M,		//4
	ATH_RATE_9M,
	ATH_RATE_12M,
	ATH_RATE_18M,
	ATH_RATE_24M,
	ATH_RATE_36M,
	ATH_RATE_48M,
	ATH_RATE_54M,		//11

	ATH_RATE_6_5M,
	ATH_RATE_13M,
	ATH_RATE_19_5M,
	ATH_RATE_26M,
	ATH_RATE_39M,
	ATH_RATE_52M,
	ATH_RATE_58_5M,
	ATH_RATE_65M,		//19

    ATH_RATE_HT20_MCS8_13M,
    ATH_RATE_HT20_MCS9_26M,
    ATH_RATE_HT20_MCS10_39M,
    ATH_RATE_HT20_MCS11_52M,
    ATH_RATE_HT20_MCS12_78M,
    ATH_RATE_HT20_MCS13_104M,
    ATH_RATE_HT20_MCS14_107M,
    ATH_RATE_HT20_MCS15_130M,	//27

    ATH_RATE_HT20_MCS16_19_5M,
    ATH_RATE_HT20_MCS17_39M,
    ATH_RATE_HT20_MCS18_58_5M,
    ATH_RATE_HT20_MCS19_78M,
    ATH_RATE_HT20_MCS20_117M,
    ATH_RATE_HT20_MCS21_156M,
    ATH_RATE_HT20_MCS22_175_5M,
    ATH_RATE_HT20_MCS23_195M,	//35

    ATH_RATE_HT40_13_5M,
    ATH_RATE_HT40_27M,
    ATH_RATE_HT40_40_5M,
    ATH_RATE_HT40_54M,
    ATH_RATE_HT40_81M,
    ATH_RATE_HT40_108M,
    ATH_RATE_HT40_121_5M,
    ATH_RATE_HT40_135M,		//43

    ATH_RATE_HT40_MCS8_27M,
    ATH_RATE_HT40_MCS9_54M,
    ATH_RATE_HT40_MCS10_81M,
    ATH_RATE_HT40_MCS11_108M,
    ATH_RATE_HT40_MCS12_162M,
    ATH_RATE_HT40_MCS13_216M,
    ATH_RATE_HT40_MCS14_243M,
    ATH_RATE_HT40_MCS15_270M,	//51

    ATH_RATE_HT40_MCS16_40_5M,
    ATH_RATE_HT40_MCS17_81M,
    ATH_RATE_HT40_MCS18_121_5M,
    ATH_RATE_HT40_MCS19_162M,
    ATH_RATE_HT40_MCS20_243M,
    ATH_RATE_HT40_MCS21_324M,
    ATH_RATE_HT40_MCS22_364_5M,
    ATH_RATE_HT40_MCS23_405M,	//59

    ATH_RATE_VHT20_NSS1_MCS0,   //60
    ATH_RATE_VHT20_NSS1_MCS1,
    ATH_RATE_VHT20_NSS1_MCS2,
    ATH_RATE_VHT20_NSS1_MCS3,
    ATH_RATE_VHT20_NSS1_MCS4,
    ATH_RATE_VHT20_NSS1_MCS5,
    ATH_RATE_VHT20_NSS1_MCS6,
    ATH_RATE_VHT20_NSS1_MCS7,
    ATH_RATE_VHT20_NSS1_MCS8,
    ATH_RATE_VHT20_NSS1_MCS9,	//69

    ATH_RATE_VHT20_NSS2_MCS0,	//70
    ATH_RATE_VHT20_NSS2_MCS1,
    ATH_RATE_VHT20_NSS2_MCS2,
    ATH_RATE_VHT20_NSS2_MCS3,
    ATH_RATE_VHT20_NSS2_MCS4,
    ATH_RATE_VHT20_NSS2_MCS5,
    ATH_RATE_VHT20_NSS2_MCS6,
    ATH_RATE_VHT20_NSS2_MCS7,
    ATH_RATE_VHT20_NSS2_MCS8,
    ATH_RATE_VHT20_NSS2_MCS9,	//79

    ATH_RATE_VHT20_NSS3_MCS0,	//80
    ATH_RATE_VHT20_NSS3_MCS1,
    ATH_RATE_VHT20_NSS3_MCS2,
    ATH_RATE_VHT20_NSS3_MCS3,
    ATH_RATE_VHT20_NSS3_MCS4,
    ATH_RATE_VHT20_NSS3_MCS5,
    ATH_RATE_VHT20_NSS3_MCS6,
    ATH_RATE_VHT20_NSS3_MCS7,
    ATH_RATE_VHT20_NSS3_MCS8,
    ATH_RATE_VHT20_NSS3_MCS9,	//89

    ATH_RATE_VHT40_NSS1_MCS0,	//90
    ATH_RATE_VHT40_NSS1_MCS1,
    ATH_RATE_VHT40_NSS1_MCS2,
    ATH_RATE_VHT40_NSS1_MCS3,
    ATH_RATE_VHT40_NSS1_MCS4,
    ATH_RATE_VHT40_NSS1_MCS5,
    ATH_RATE_VHT40_NSS1_MCS6,
    ATH_RATE_VHT40_NSS1_MCS7,
    ATH_RATE_VHT40_NSS1_MCS8,
    ATH_RATE_VHT40_NSS1_MCS9,	//99

    ATH_RATE_VHT40_NSS2_MCS0,	//100
    ATH_RATE_VHT40_NSS2_MCS1,
    ATH_RATE_VHT40_NSS2_MCS2,
    ATH_RATE_VHT40_NSS2_MCS3,
    ATH_RATE_VHT40_NSS2_MCS4,
    ATH_RATE_VHT40_NSS2_MCS5,
    ATH_RATE_VHT40_NSS2_MCS6,
    ATH_RATE_VHT40_NSS2_MCS7,
    ATH_RATE_VHT40_NSS2_MCS8,
    ATH_RATE_VHT40_NSS2_MCS9,	//109

    ATH_RATE_VHT40_NSS3_MCS0,	//110
    ATH_RATE_VHT40_NSS3_MCS1,
    ATH_RATE_VHT40_NSS3_MCS2,
    ATH_RATE_VHT40_NSS3_MCS3,
    ATH_RATE_VHT40_NSS3_MCS4,
    ATH_RATE_VHT40_NSS3_MCS5,
    ATH_RATE_VHT40_NSS3_MCS6,
    ATH_RATE_VHT40_NSS3_MCS7,
    ATH_RATE_VHT40_NSS3_MCS8,
    ATH_RATE_VHT40_NSS3_MCS9,	//119

    ATH_RATE_VHT80_NSS1_MCS0,	//120
    ATH_RATE_VHT80_NSS1_MCS1,
    ATH_RATE_VHT80_NSS1_MCS2,
    ATH_RATE_VHT80_NSS1_MCS3,
    ATH_RATE_VHT80_NSS1_MCS4,
    ATH_RATE_VHT80_NSS1_MCS5,
    ATH_RATE_VHT80_NSS1_MCS6,
    ATH_RATE_VHT80_NSS1_MCS7,
    ATH_RATE_VHT80_NSS1_MCS8,
    ATH_RATE_VHT80_NSS1_MCS9,	//129

    ATH_RATE_VHT80_NSS2_MCS0,	//130
    ATH_RATE_VHT80_NSS2_MCS1,
    ATH_RATE_VHT80_NSS2_MCS2,
    ATH_RATE_VHT80_NSS2_MCS3,
    ATH_RATE_VHT80_NSS2_MCS4,
    ATH_RATE_VHT80_NSS2_MCS5,
    ATH_RATE_VHT80_NSS2_MCS6,
    ATH_RATE_VHT80_NSS2_MCS7,
    ATH_RATE_VHT80_NSS2_MCS8,
    ATH_RATE_VHT80_NSS2_MCS9,	//139

    ATH_RATE_VHT80_NSS3_MCS0,	//140
    ATH_RATE_VHT80_NSS3_MCS1,
    ATH_RATE_VHT80_NSS3_MCS2,
    ATH_RATE_VHT80_NSS3_MCS3,
    ATH_RATE_VHT80_NSS3_MCS4,
    ATH_RATE_VHT80_NSS3_MCS5,
    ATH_RATE_VHT80_NSS3_MCS6,
    ATH_RATE_VHT80_NSS3_MCS7,
    ATH_RATE_VHT80_NSS3_MCS8,
    ATH_RATE_VHT80_NSS3_MCS9,	//149

    ATH_RATE_CCK_2M_S,
    ATH_RATE_CCK_5_5M_S,
    ATH_RATE_CCK_11M_S,		//152

    ATH_RATE_VHT20_NSS4_MCS0,	//153
    ATH_RATE_VHT20_NSS4_MCS1,
    ATH_RATE_VHT20_NSS4_MCS2,
    ATH_RATE_VHT20_NSS4_MCS3,
    ATH_RATE_VHT20_NSS4_MCS4,
    ATH_RATE_VHT20_NSS4_MCS5,
    ATH_RATE_VHT20_NSS4_MCS6,
    ATH_RATE_VHT20_NSS4_MCS7,
    ATH_RATE_VHT20_NSS4_MCS8,
    ATH_RATE_VHT20_NSS4_MCS9,	//162

    ATH_RATE_VHT40_NSS4_MCS0,   //163
    ATH_RATE_VHT40_NSS4_MCS1,
    ATH_RATE_VHT40_NSS4_MCS2,
    ATH_RATE_VHT40_NSS4_MCS3,
    ATH_RATE_VHT40_NSS4_MCS4,
    ATH_RATE_VHT40_NSS4_MCS5,
    ATH_RATE_VHT40_NSS4_MCS6,
    ATH_RATE_VHT40_NSS4_MCS7,
    ATH_RATE_VHT40_NSS4_MCS8,
    ATH_RATE_VHT40_NSS4_MCS9,  //172

    ATH_RATE_VHT80_NSS4_MCS0,  //173
    ATH_RATE_VHT80_NSS4_MCS1,
    ATH_RATE_VHT80_NSS4_MCS2,
    ATH_RATE_VHT80_NSS4_MCS3,
    ATH_RATE_VHT80_NSS4_MCS4,
    ATH_RATE_VHT80_NSS4_MCS5,
    ATH_RATE_VHT80_NSS4_MCS6,
    ATH_RATE_VHT80_NSS4_MCS7,
    ATH_RATE_VHT80_NSS4_MCS8,
    ATH_RATE_VHT80_NSS4_MCS9,  //182

	ATH_RATE_VHT160_NSS1_MCS0, //183
	ATH_RATE_VHT160_NSS1_MCS1,
	ATH_RATE_VHT160_NSS1_MCS2,
	ATH_RATE_VHT160_NSS1_MCS3,
	ATH_RATE_VHT160_NSS1_MCS4,
	ATH_RATE_VHT160_NSS1_MCS5,
	ATH_RATE_VHT160_NSS1_MCS6,
	ATH_RATE_VHT160_NSS1_MCS7,
	ATH_RATE_VHT160_NSS1_MCS8,
	ATH_RATE_VHT160_NSS1_MCS9,

	ATH_RATE_VHT160_NSS2_MCS0,
	ATH_RATE_VHT160_NSS2_MCS1,
	ATH_RATE_VHT160_NSS2_MCS2,
	ATH_RATE_VHT160_NSS2_MCS3,
	ATH_RATE_VHT160_NSS2_MCS4,
	ATH_RATE_VHT160_NSS2_MCS5,
	ATH_RATE_VHT160_NSS2_MCS6,
	ATH_RATE_VHT160_NSS2_MCS7,
	ATH_RATE_VHT160_NSS2_MCS8,
	ATH_RATE_VHT160_NSS2_MCS9,  //202

    ATH_RATE_HT20_MCS24,		//203
    ATH_RATE_HT20_MCS25,
    ATH_RATE_HT20_MCS26,
    ATH_RATE_HT20_MCS27,
    ATH_RATE_HT20_MCS28,
    ATH_RATE_HT20_MCS29,
    ATH_RATE_HT20_MCS30,
    ATH_RATE_HT20_MCS31,		//210

    ATH_RATE_HT40_MCS24,		//211
    ATH_RATE_HT40_MCS25,
    ATH_RATE_HT40_MCS26,
    ATH_RATE_HT40_MCS27,
    ATH_RATE_HT40_MCS28,
    ATH_RATE_HT40_MCS29,
    ATH_RATE_HT40_MCS30,
    ATH_RATE_HT40_MCS31,		//218
 
    MASK_RATE_MAX,
} _AthDataRate;

typedef enum {
    ATH_NOHT,
    ATH_HT20,
    ATH_HT40Minus,
    ATH_HT40Plus,
} _AthHtMode;

