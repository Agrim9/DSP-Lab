/* Test for dlms: sine */
#define NX 40
#define NH 21
#define STEP 1638
#define FNAME "t2"
#define MAXERROR 20

DATA x[NX] ={
0,
11585,
16384,
11585,
0,
-11586,
-16384,
-11586,
-1,
11585,
16384,
11585,
0,
-11586,
-16384,
-11586,
-1,
11585,
16384,
11585,
0,
-11586,
-16384,
-11586,
-1,
11585,
16384,
11585,
0,
-11586,
-16384,
-11586,
-1,
11585,
16384,
11585,
0,
-11586,
-16384,
-11586,
};

DATA des[NX] ={
32767,
23170,
0,
-23171,
-32768,
-23171,
-1,
23170,
32767,
23170,
0,
-23171,
-32768,
-23171,
-1,
23170,
32767,
23170,
0,
-23171,
-32768,
-23171,
-1,
23170,
32767,
23170,
-1,
-23171,
-32768,
-23171,
-1,
23170,
32767,
23170,
-1,
-23171,
-32768,
-23171,
-1,
23170,
};

DATA htest[NH] ={ /* C54x: hn-1 ... h0 (backward order) */
-155,
-1991,
-2909,
-2116,
205,
2827,
4100,
2963,
-253,
-3815,
-5501,
-3957,
288,
4915,
7057,
5061,
-307,
-6074,
-8695,
-6223,
304,
};

DATA rtest[NX] ={
0,
0,
0,
145,
0,
-145,
207,
873,
1637,
1449,
-376,
-2946,
-4748,
-3788,
463,
5808,
8947,
6878,
-448,
-9094,
-13706,
-10329,
343,
12418,
18468,
13665,
-93,
-15001,
-22046,
-16135,
-50,
16968,
24730,
17962,
124,
-18465,
-26743,
-19315,
-156,
19603,
};

#pragma DATA_SECTION (dbuffer,".dbuffer")
DATA dbuffer[NH+2];

#pragma DATA_SECTION (h,".coeffs")
DATA h[NH];

DATA r[NX];

DATA error;

