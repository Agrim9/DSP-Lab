#define NX 128
#define NH 64
#define FNAME "t4"
#define MAXERROR 10

DATA x[NX] ={
19321,
29939,
1480,
24912,
-21434,
31440,
-14979,
-16232,
24624,
15552,
-23822,
-31998,
25814,
-19718,
-13191,
10580,
-14129,
-2017,
-28523,
32003,
5425,
-5014,
1016,
-10883,
-4398,
-17961,
5230,
17063,
1954,
9209,
-19067,
-7877,
18568,
11851,
-2550,
4445,
19281,
-28890,
6741,
-29474,
-5546,
-12780,
24534,
-31785,
17560,
30857,
32118,
18930,
-4021,
-111,
-18746,
9403,
-11795,
30152,
14852,
-5771,
16027,
-15208,
-3938,
28401,
12014,
-18838,
22232,
8440,
-24002,
-19194,
7025,
8512,
-8489,
4924,
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
-27631,
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
};

#pragma DATA_SECTION(h,".coeffs")
DATA h[NH] ={ /* b0 b1 b2 ... b(NH-1) */
-88,
783,
919,
-499,
-720,
789,
-556,
308,
989,
349,
784,
-1039,
-769,
675,
-148,
826,
497,
396,
-326,
-708,
-730,
-655,
-165,
754,
-21,
669,
-84,
-91,
-105,
-186,
850,
-1048,
-430,
-956,
409,
317,
1023,
111,
-212,
-639,
265,
494,
-263,
-1039,
-170,
537,
622,
889,
730,
-281,
255,
489,
-649,
857,
146,
279,
-563,
103,
914,
-350,
329,
-229,
269,
421,
};

#pragma DATA_SECTION(db,".dbuffer")
DATA db[NH+2] ;

DATA rtest[NX] ={
-52,
382,
1254,
515,
-186,
-112,
173,
58,
558,
-186,
3885,
-289,
-3869,
1486,
179,
-613,
707,
1790,
1014,
-3139,
-1208,
-732,
942,
-2527,
500,
1082,
-2031,
-243,
1445,
870,
224,
-1415,
-887,
-1675,
19,
2712,
-755,
4141,
-1750,
-1729,
-2884,
-679,
2963,
1169,
570,
-11,
288,
60,
-1039,
4637,
777,
-287,
-1546,
630,
2258,
2765,
2265,
-2618,
-650,
466,
15,
5216,
-210,
3122,
-3383,
-4135,
-3715,
593,
3042,
1130,
3628,
-3536,
2692,
-6114,
-460,
-1810,
-75,
596,
-2496,
-3921,
-2139,
1357,
1899,
695,
-2461,
-927,
-956,
-4960,
-4143,
2941,
-1722,
-1724,
1982,
3228,
608,
-590,
1238,
387,
-908,
-24,
148,
-1729,
595,
2334,
7396,
1216,
-400,
-81,
-2759,
-164,
1736,
3601,
-1529,
895,
1652,
-2928,
4404,
-500,
-2613,
-4179,
-3444,
1784,
-3339,
-2382,
3613,
-1299,
-878,
-3167,
};

DATA r[NX];
