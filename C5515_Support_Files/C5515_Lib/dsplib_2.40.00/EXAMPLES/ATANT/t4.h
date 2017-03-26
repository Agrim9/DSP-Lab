/* Test for maxval: rand */
#define NX 300
#define FNAME "t4"
#define MAXERROR 40

DATA x[NX] ={
-3184,
-29892,
-30987,
-12276,
-31926,
-7605,
12000,
-26684,
-30453,
7365,
7113,
-31736,
-31697,
-20312,
5696,
-28995,
-8680,
8614,
14262,
12626,
-27258,
-2992,
-3813,
-9618,
-22702,
11511,
13055,
14910,
-1417,
3594,
-24836,
-3228,
14148,
25745,
-14870,
-16072,
23960,
-17541,
19980,
26764,
-17571,
-17085,
-29508,
-27632,
9228,
-20259,
22535,
-21372,
-21575,
32394,
-3946,
-10483,
-12176,
-8843,
-6997,
5998,
-24921,
-30270,
-2714,
24239,
28458,
-15438,
-22263,
24435,
-17179,
9557,
30597,
10808,
24273,
-32118,
-23789,
20889,
-4577,
25580,
15394,
12276,
-10086,
-21887,
-22570,
-20243,
-5083,
23329,
-639,
20705,
-2571,
-2795,
-3232,
-5753,
26319,
-32403,
-13278,
-29547,
12660,
9837,
31653,
3451,
-6549,
-19741,
8205,
15293,
-8134,
-32121,
-5253,
16624,
19259,
27522,
22591,
-8667,
7916,
15156,
-20062,
26529,
4535,
8636,
-17406,
3196,
28284,
-10801,
10192,
-7085,
8343,
13046,
-6739,
-5661,
10172,
22123,
-8415,
-4899,
6203,
4308,
14191,
741,
18114,
-699,
-20585,
13148,
31634,
20095,
13341,
-986,
-25257,
10803,
-8823,
-23591,
4376,
21168,
11399,
32731,
30253,
-28911,
-9155,
3179,
-15613,
6379,
-29539,
4656,
13163,
30296,
16417,
15728,
-4465,
8799,
19859,
-27271,
29193,
27259,
6683,
-16151,
24474,
878,
15246,
-5097,
30236,
-28046,
3500,
-13633,
23459,
-10764,
11809,
-29266,
-9395,
-112,
-4297,
4093,
7642,
-25341,
26099,
16682,
19079,
20640,
11141,
-19604,
-14871,
8272,
2415,
-28869,
-26938,
-14988,
-5960,
-1702,
26803,
6307,
-11210,
-1430,
6368,
-22188,
21592,
29892,
6261,
-30884,
20454,
7216,
13205,
-26726,
-4923,
-8155,
-21879,
21833,
22193,
-3172,
29923,
-23125,
24243,
17657,
-3660,
7904,
29601,
9175,
-16560,
-9654,
-20457,
-614,
-5946,
-2391,
7270,
-28104,
-12172,
7103,
-21298,
7931,
-16649,
5725,
396,
-2309,
2714,
28988,
-10371,
-6436,
-12604,
-5796,
-14029,
-6939,
197,
14547,
-12701,
-25418,
-3717,
-2179,
-31807,
10751,
14684,
-14311,
-15610,
13662,
18602,
31860,
-1748,
26399,
-3208,
19956,
21552,
-21872,
-6953,
1360,
14294,
4534,
-2569,
-3585,
-27018,
-3704,
-8763,
-12942,
23058,
17005,
29475,
3797,
-31836,
6303,
20722,
31266,
-18226,
13348,
1445,
28370,
13982,
-17824,
-3301,
-21483,
30724,
-9456,
};

DATA rtest[NX] ={
-3174,
-24233,
-24821,
-11746,
-25309,
-7473,
11503,
-22394,
-24537,
7245,
7004,
-25212,
-25192,
-18183,
5639,
-23737,
-8485,
8424,
13452,
12052,
-22737,
-2984,
-3796,
-9355,
-19854,
11069,
12423,
13992,
-1416,
3579,
-21252,
-3218,
13355,
21821,
-13960,
-14942,
20688,
-16106,
17942,
22442,
-16129,
-15749,
-24022,
-22956,
8995,
-18145,
19741,
-18938,
-19080,
25547,
-3927,
-10146,
-11658,
-8637,
-6894,
5932,
-21306,
-24438,
-2708,
20869,
23433,
-14427,
-19555,
20996,
-15823,
9299,
24614,
10440,
20891,
-25408,
-20577,
18597,
-4548,
21719,
14392,
11746,
-9784,
-19297,
-19765,
-18134,
-5043,
20273,
-639,
18465,
-2566,
-2789,
-3222,
-5695,
22174,
-25552,
-12615,
-24044,
12081,
9556,
25168,
3439,
-6464,
-17767,
8039,
14308,
-7973,
-25410,
-5208,
15384,
17411,
22892,
19778,
-8473,
7767,
14196,
-18002,
22301,
4506,
8444,
-16000,
3186,
23333,
-10434,
9881,
-6977,
8170,
12416,
-6646,
-5606,
9862,
19459,
-8237,
-4863,
6131,
4283,
13392,
741,
16547,
-699,
-18380,
12504,
25159,
18026,
12669,
-986,
-21518,
10436,
-8619,
-20447,
4350,
18794,
10970,
25717,
24429,
-23690,
-8928,
3169,
-14570,
6300,
-24040,
4625,
12516,
24452,
15219,
14663,
-4438,
8596,
17853,
-22744,
23847,
22737,
6593,
-15006,
21021,
878,
14270,
-5057,
24419,
-23197,
3486,
-12919,
20359,
-10401,
11334,
-23888,
-9149,
-112,
-4273,
4072,
7508,
-21570,
22039,
15430,
17277,
18419,
10739,
-17667,
-13961,
8103,
2410,
-23666,
-22547,
-14057,
-5895,
-1700,
22465,
6231,
-10801,
-1429,
6289,
-19504,
19091,
24233,
6187,
-24767,
18286,
7103,
12552,
-22420,
-4886,
-7992,
-19291,
19259,
19507,
-3162,
24250,
-20138,
20872,
16195,
-3645,
7756,
24073,
8946,
-15333,
-9388,
-18288,
-614,
-5882,
-2387,
7154,
-23231,
-11654,
6994,
-18886,
7781,
-15404,
5667,
396,
-2305,
2708,
23732,
-10044,
-6355,
-12032,
-5737,
-13256,
-6838,
197,
13691,
-12117,
-21619,
-3701,
-2176,
-25249,
10388,
13804,
-13493,
-14568,
12944,
16919,
25276,
-1746,
22222,
-3198,
17925,
19064,
-19286,
-6852,
1359,
13479,
4505,
-2564,
-3571,
-22594,
-3689,
-8562,
-12326,
20093,
15686,
24004,
3780,
-25263,
6227,
18478,
24967,
-16633,
12676,
1444,
23382,
13215,
-16324,
-3290,
-19016,
24681,
-9206,
};

DATA r[NX];
