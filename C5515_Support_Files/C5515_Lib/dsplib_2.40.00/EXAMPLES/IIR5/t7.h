/* Test for iircas5: rand */
#define NX 35
#define NBIQ 4
#define FNAME "t7"
#define MAXERROR 20

DATA x[NX] ={
-926,
-380,
-845,
361,
281,
904,
98,
-188,
-565,
234,
436,
-233,
-918,
-151,
474,
550,
786,
645,
-248,
226,
433,
-574,
757,
129,
246,
-498,
91,
808,
-309,
291,
-203,
238,
372,
-193,
-162,
};

#pragma DATA_SECTION (h,".coeffs")
DATA h[5*NBIQ] ={ /* C54x: a1 a2 b2 b0 b1 ... */
6103,
3722,
-15155,
10868,
18980,
13274,
2584,
6482,
-419,
12057,
-5049,
8514,
-5294,
-12351,
8004,
-2940,
444,
-14155,
7889,
-592,
};

DATA rtest[NX] ={
-1,
9,
17,
-29,
-26,
-3,
-11,
29,
16,
14,
-31,
-26,
16,
55,
-18,
-74,
-2,
53,
-9,
-2,
38,
-31,
-15,
56,
-50,
-11,
71,
-29,
-38,
-5,
68,
-20,
-45,
32,
-6,
};

#pragma DATA_SECTION (dbuffer,".dbuffer")
DATA dbuffer[2*NBIQ];
DATA *dp = dbuffer;

DATA r[NX];

