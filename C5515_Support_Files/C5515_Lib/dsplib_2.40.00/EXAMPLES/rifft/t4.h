/* Test for rfft: rand */
#define NX 64
#define FNAME "t4"
#define MAXERROR 10

#pragma DATA_SECTION (x,".input")

DATA x[NX] ={
-7971,	/* 0 */ 
23591,	/* 1 */ 
23174,	/* 2 */ 
6131,	/* 3 */ 
-226,	/* 4 */ 
26196,	/* 5 */ 
21076,	/* 6 */ 
9495,	/* 7 */ 
20836,	/* 8 */ 
10499,	/* 9 */ 
-10356,	/* 10 */ 
-13780,	/* 11 */ 
-10407,	/* 12 */ 
2233,	/* 13 */ 
14882,	/* 14 */ 
-12498,	/* 15 */ 
22181,	/* 16 */ 
4460,	/* 17 */ 
-8492,	/* 18 */ 
13285,	/* 19 */ 
3051,	/* 20 */ 
-3612,	/* 21 */ 
12749,	/* 22 */ 
7949,	/* 23 */ 
19319,	/* 24 */ 
29936,	/* 25 */ 
1480,	/* 26 */ 
24910,	/* 27 */ 
-21432,	/* 28 */ 
31437,	/* 29 */ 
-14977,	/* 30 */ 
-16230,	/* 31 */ 
24622,	/* 32 */ 
15550,	/* 33 */ 
-23819,	/* 34 */ 
-31995,	/* 35 */ 
25811,	/* 36 */ 
-19716,	/* 37 */ 
-13190,	/* 38 */ 
10579,	/* 39 */ 
-14128,	/* 40 */ 
-2017,	/* 41 */ 
-28520,	/* 42 */ 
32000,	/* 43 */ 
5425,	/* 44 */ 
-5014,	/* 45 */ 
1016,	/* 46 */ 
-10882,	/* 47 */ 
-4397,	/* 48 */ 
-17959,	/* 49 */ 
5229,	/* 50 */ 
17061,	/* 51 */ 
1954,	/* 52 */ 
9208,	/* 53 */ 
-19065,	/* 54 */ 
-7876,	/* 55 */ 
18566,	/* 56 */ 
11850,	/* 57 */ 
-2550,	/* 58 */ 
4444,	/* 59 */ 
19279,	/* 60 */ 
-28887,	/* 61 */ 
6740,	/* 62 */ 
-29471,	/* 63 */ 
};

#pragma DATA_SECTION (rtest,".test")

/* format: y(0)Re,y(1)Re,y(2)Re,y(3)Re, ... y(N-1)Re */

DATA rtest[NX] ={
1307,	-272,	 /* 0 */ 
541,	-937,	 /* 1 */ 
1132,	624,	 /* 2 */ 
-1815,	-1354,	 /* 3 */ 
-149,	350,	 /* 4 */ 
-3241,	781,	 /* 5 */ 
-839,	-1133,	 /* 6 */ 
-807,	1621,	 /* 7 */ 
-464,	2107,	 /* 8 */ 
232,	-256,	 /* 9 */ 
1863,	-697,	 /* 10 */ 
-983,	-257,	 /* 11 */ 
-696,	-387,	 /* 12 */ 
-246,	670,	 /* 13 */ 
-8,	-851,	 /* 14 */ 
204,	-964,	 /* 15 */ 
2388,	-1996,	 /* 16 */ 
-2576,	-96,	 /* 17 */ 
982,	-3532,	 /* 18 */ 
-1912,	2179,	 /* 19 */ 
-61,	-717,	 /* 20 */ 
-1864,	905,	 /* 21 */ 
-164,	-1768,	 /* 22 */ 
1083,	1130,	 /* 23 */ 
2692,	-1244,	 /* 24 */ 
-491,	-1805,	 /* 25 */ 
-981,	1128,	 /* 26 */ 
2194,	-3084,	 /* 27 */ 
1255,	1781,	 /* 28 */ 
2738,	-451,	 /* 29 */ 
-157,	-1234,	 /* 30 */ 
2733,	1853,	 /* 31 */ 
};

DATA error;

