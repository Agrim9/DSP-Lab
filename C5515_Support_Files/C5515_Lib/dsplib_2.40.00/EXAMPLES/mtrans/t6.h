/* Test for mtrans: nois */
#define row 32
#define col 16
#define FNAME "t6"
#define MAXERROR 0

DATA x[row*col] ={
-8543,
4952,
12117,
-1082,
628,
13050,
7462,
6835,
-7032,
-12983,
4221,
5529,
-1417,
-7198,
11289,
-7827,
-1096,
7437,
3739,
-7004,
9847,
6782,
7659,
12107,
15945,
-8931,
1945,
5795,
-12023,
-10682,
-1119,
-3657,
-15224,
-16262,
-5270,
-14244,
9123,
-3446,
-14156,
5127,
-9033,
-395,
-8311,
14840,
6679,
13824,
3251,
13020,
7770,
13405,
6083,
5145,
14024,
4659,
9747,
11867,
31,
12230,
5128,
4061,
-6347,
-7856,
-9562,
8741,
11458,
5303,
-9260,
4268,
7412,
-6411,
-1530,
13977,
-2296,
2591,
-12047,
-1379,
-14275,
-4094,
559,
-8378,
547,
-14756,
-8800,
7586,
-13257,
-13603,
-9478,
14375,
524,
-2579,
439,
4841,
-10689,
4742,
-11205,
-1486,
-11678,
-1565,
-1893,
14905,
-1661,
12628,
7708,
5430,
-14847,
10264,
-7405,
15690,
-10075,
-6013,
8007,
-7459,
9075,
-11006,
-5443,
-4281,
15616,
-13303,
2536,
3202,
15224,
6398,
2862,
-2574,
5582,
-10078,
-358,
-2517,
-1722,
-961,
-7650,
-14108,
15365,
14784,
9484,
-3128,
-14228,
-1923,
-7587,
15589,
-3700,
-8743,
4903,
6520,
-10961,
10598,
8355,
12042,
4760,
3872,
-13671,
-11991,
328,
-960,
9314,
610,
-14080,
-9179,
-15014,
10401,
-7976,
11467,
-2743,
-6728,
-13344,
8538,
-4070,
-6489,
6730,
12497,
-11513,
1405,
5932,
-13780,
-5412,
10664,
7514,
15210,
14759,
1749,
8913,
3955,
-9798,
-1300,
4092,
4755,
8954,
-3960,
11669,
-12324,
-2184,
-3169,
-14374,
10245,
11028,
9245,
-3146,
2596,
4775,
107,
-8929,
-11591,
652,
11440,
-13201,
1231,
-13152,
4967,
-12671,
-7720,
12971,
-14083,
-7218,
-7180,
-12324,
8615,
4282,
-9424,
2841,
1493,
-3543,
6188,
5928,
-11388,
10309,
-9621,
-8018,
4369,
-8963,
-13114,
246,
14557,
-11364,
-12255,
622,
10326,
-4064,
7212,
-15494,
-5245,
-1261,
14161,
692,
-15035,
-11638,
7260,
-12923,
4910,
-6199,
1183,
-11777,
-467,
508,
14377,
-5870,
-15750,
13394,
-3495,
-5349,
-15588,
-13342,
11187,
-15429,
14625,
4892,
11135,
-6031,
-12575,
12918,
-16113,
-14663,
8791,
12985,
-14339,
5117,
7265,
6642,
10526,
-14722,
-1189,
10995,
-8522,
11837,
-11683,
4647,
2676,
-4274,
-1380,
-9601,
-14947,
-3445,
12640,
5937,
1427,
-10396,
-7497,
-15802,
-15651,
-2181,
9328,
-9722,
1846,
-3805,
-14955,
12257,
-16181,
-13084,
14324,
-1388,
-4443,
317,
-14109,
-3132,
-11522,
-14434,
-7571,
-14125,
6205,
-5377,
-13120,
-8608,
10390,
-1248,
13916,
1060,
31,
4836,
-10243,
9814,
-796,
12643,
1860,
9834,
8550,
12801,
14971,
6039,
13603,
1847,
8398,
-6607,
-5557,
314,
-4946,
-11154,
12386,
-7995,
-11936,
-2521,
10625,
-8580,
3565,
15076,
7917,
-6477,
-4016,
-3178,
-8829,
3250,
13575,
-6146,
11900,
-6961,
-2472,
12854,
907,
-13730,
-8298,
-2406,
-9704,
4284,
10949,
-11387,
3438,
-5360,
-15931,
4295,
16256,
-9045,
-14494,
16117,
-5193,
-6504,
14073,
-10676,
-8708,
796,
6115,
9508,
-14831,
7323,
15974,
2982,
8431,
2989,
9725,
-3248,
-14145,
-10484,
-2296,
-3363,
13057,
-6262,
1809,
-9877,
7750,
-12514,
-10681,
-14597,
12639,
2108,
1950,
-5220,
-7731,
7083,
-14778,
5601,
9428,
-1209,
-13559,
-181,
-402,
650,
-3180,
12106,
-4302,
11990,
8891,
-6004,
16191,
9510,
13266,
-489,
-10387,
-12038,
1794,
-6446,
15916,
16224,
-3301,
7470,
7076,
-9186,
16219,
-4447,
-3753,
-5527,
15669,
-3847,
188,
8553,
5878,
-11535,
15677,
-6116,
9359,
-15840,
-7021,
-6512,
-13448,
3792,
9379,
9227,
5170,
2081,
-14384,
-11962,
-2375,
15203,
-11720,
190,
193,
7997,
9485,
2852,
7252,
3193,
12110,
9065,
7436,
-331,
-11950,
-2256,
-11045,
7762,
14055,
10478,
2044,
-6826,
-9652,
13173,
16295,
6069,
-13591,
-12952,
-373,
-11300,
-15654,
11772,
6340,
614,
-15864,
-6595,
6594,
8404,
-2298,
778,
-12841,
15525,
-534,
-5603,
6087,
};

DATA rtest[] ={
-8543,
-1096,
-15224,
7770,
11458,
547,
-11678,
9075,
-1722,
-10961,
-7976,
7514,
-14374,
-12671,
10309,
-1261,
13394,
12985,
-9601,
12257,
-8608,
6039,
15076,
-2406,
-10676,
-3363,
5601,
-489,
-3847,
2081,
-331,
-11300,
4952,
7437,
-16262,
13405,
5303,
-14756,
-1565,
-11006,
-961,
10598,
11467,
15210,
10245,
-7720,
-9621,
14161,
-3495,
-14339,
-14947,
-16181,
10390,
13603,
7917,
-9704,
-8708,
13057,
9428,
-10387,
188,
-14384,
-11950,
-15654,
12117,
3739,
-5270,
6083,
-9260,
-8800,
-1893,
-5443,
-7650,
8355,
-2743,
14759,
11028,
12971,
-8018,
692,
-5349,
5117,
-3445,
-13084,
-1248,
1847,
-6477,
4284,
796,
-6262,
-1209,
-12038,
8553,
-11962,
-2256,
11772,
-1082,
-7004,
-14244,
5145,
4268,
7586,
14905,
-4281,
-14108,
12042,
-6728,
1749,
9245,
-14083,
4369,
-15035,
-15588,
7265,
12640,
14324,
13916,
8398,
-4016,
10949,
6115,
1809,
-13559,
1794,
5878,
-2375,
-11045,
6340,
628,
9847,
9123,
14024,
7412,
-13257,
-1661,
15616,
15365,
4760,
-13344,
8913,
-3146,
-7218,
-8963,
-11638,
-13342,
6642,
5937,
-1388,
1060,
-6607,
-3178,
-11387,
9508,
-9877,
-181,
-6446,
-11535,
15203,
7762,
614,
13050,
6782,
-3446,
4659,
-6411,
-13603,
12628,
-13303,
14784,
3872,
8538,
3955,
2596,
-7180,
-13114,
7260,
11187,
10526,
1427,
-4443,
31,
-5557,
-8829,
3438,
-14831,
7750,
-402,
15916,
15677,
-11720,
14055,
-15864,
7462,
7659,
-14156,
9747,
-1530,
-9478,
7708,
2536,
9484,
-13671,
-4070,
-9798,
4775,
-12324,
246,
-12923,
-15429,
-14722,
-10396,
317,
4836,
314,
3250,
-5360,
7323,
-12514,
650,
16224,
-6116,
190,
10478,
-6595,
6835,
12107,
5127,
11867,
13977,
14375,
5430,
3202,
-3128,
-11991,
-6489,
-1300,
107,
8615,
14557,
4910,
14625,
-1189,
-7497,
-14109,
-10243,
-4946,
13575,
-15931,
15974,
-10681,
-3180,
-3301,
9359,
193,
2044,
6594,
-7032,
15945,
-9033,
31,
-2296,
524,
-14847,
15224,
-14228,
328,
6730,
4092,
-8929,
4282,
-11364,
-6199,
4892,
10995,
-15802,
-3132,
9814,
-11154,
-6146,
4295,
2982,
-14597,
12106,
7470,
-15840,
7997,
-6826,
8404,
-12983,
-8931,
-395,
12230,
2591,
-2579,
10264,
6398,
-1923,
-960,
12497,
4755,
-11591,
-9424,
-12255,
1183,
11135,
-8522,
-15651,
-11522,
-796,
12386,
11900,
16256,
8431,
12639,
-4302,
7076,
-7021,
9485,
-9652,
-2298,
4221,
1945,
-8311,
5128,
-12047,
439,
-7405,
2862,
-7587,
9314,
-11513,
8954,
652,
2841,
622,
-11777,
-6031,
11837,
-2181,
-14434,
12643,
-7995,
-6961,
-9045,
2989,
2108,
11990,
-9186,
-6512,
2852,
13173,
778,
5529,
5795,
14840,
4061,
-1379,
4841,
15690,
-2574,
15589,
610,
1405,
-3960,
11440,
1493,
10326,
-467,
-12575,
-11683,
9328,
-7571,
1860,
-11936,
-2472,
-14494,
9725,
1950,
8891,
16219,
-13448,
7252,
16295,
-12841,
-1417,
-12023,
6679,
-6347,
-14275,
-10689,
-10075,
5582,
-3700,
-14080,
5932,
11669,
-13201,
-3543,
-4064,
508,
12918,
4647,
-9722,
-14125,
9834,
-2521,
12854,
16117,
-3248,
-5220,
-6004,
-4447,
3792,
3193,
6069,
15525,
-7198,
-10682,
13824,
-7856,
-4094,
4742,
-6013,
-10078,
-8743,
-9179,
-13780,
-12324,
1231,
6188,
7212,
14377,
-16113,
2676,
1846,
6205,
8550,
10625,
907,
-5193,
-14145,
-7731,
16191,
-3753,
9379,
12110,
-13591,
-534,
11289,
-1119,
3251,
-9562,
559,
-11205,
8007,
-358,
4903,
-15014,
-5412,
-2184,
-13152,
5928,
-15494,
-5870,
-14663,
-4274,
-3805,
-5377,
12801,
-8580,
-13730,
-6504,
-10484,
7083,
9510,
-5527,
9227,
9065,
-12952,
-5603,
-7827,
-3657,
13020,
8741,
-8378,
-1486,
-7459,
-2517,
6520,
10401,
10664,
-3169,
4967,
-11388,
-5245,
-15750,
8791,
-1380,
-14955,
-13120,
14971,
3565,
-8298,
14073,
-2296,
-14778,
13266,
15669,
5170,
7436,
-373,
6087,
};

DATA r[row*col];

