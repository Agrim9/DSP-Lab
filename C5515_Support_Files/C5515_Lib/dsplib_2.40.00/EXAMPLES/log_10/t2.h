/* Test for logn: nois */
#define NX 55
#define FNAME "t2"
#define MAXERROR 20

DATA x[NX] ={
31131,
7573,
19883,
15923,
29203,
24970,
14956,
606,
26913,
14571,
20164,
25948,
30203,
24187,
5775,
13293,
30650,
30042,
13442,
29280,
1897,
11562,
26643,
323,
4551,
6644,
6511,
19783,
8918,
6514,
500,
24468,
14583,
30531,
15268,
13717,
27726,
17206,
6640,
22022,
27461,
643,
22322,
12434,
27254,
16475,
23246,
14053,
9981,
6214,
6338,
22353,
9920,
17748,
4943,
};

long rtest[] ={
-729,
-20846,
-7110,
-10270,
-1639,
-3868,
-11162,
-56780,
-2801,
-11533,
-6910,
-3321,
-1160,
-4321,
-24703,
-12840,
-951,
-1236,
-12680,
-1602,
-40548,
-14825,
-2945,
-65736,
-28094,
-22710,
-22997,
-7181,
-18520,
-22990,
-59510,
-4157,
-11521,
-1006,
-10868,
-12393,
-2378,
-9167,
-22718,
-5655,
-2515,
-55932,
-5463,
-13791,
-2622,
-9786,
-4886,
-12049,
-16918,
-23661,
-23381,
-5443,
-17005,
-8726,
-26917,
};

long r[NX];

