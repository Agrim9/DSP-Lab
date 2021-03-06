#define NX 128
#define NLAGS 128 // max NLAGS = N 
#define FNAME "t3"
#define MAXERROR 10 // max absolute error allowed 

DATA x[NX] ={
1960,
394,
-751,
1174,
269,
-320,
1127,
702,
1707,
2646,
130,
2202,
-1895,
2778,
-1324,
-1435,
2176,
1374,
-2106,
-2829,
2281,
-1743,
-1166,
935,
-1249,
-179,
-2522,
2828,
479,
-444,
89,
-962,
-389,
-1588,
462,
1508,
172,
814,
-1686,
-697,
1641,
1047,
-226,
392,
1704,
-2554,
595,
-2606,
-491,
-1130,
2168,
-2810,
1552,
2727,
2838,
1673,
-356,
-10,
-1657,
831,
-1043,
2665,
1312,
-511,
1416,
-1345,
-348,
2510,
1061,
-1666,
1965,
745,
-2122,
-1697,
620,
752,
-751,
435,
-282,
-2643,
-2739,
-1086,
-2822,
-673,
1060,
-2359,
-2692,
651,
628,
-2806,
-2802,
-1796,
503,
-2563,
-768,
761,
1260,
1116,
-2410,
-265,
-337,
-851,
-2007,
1017,
1153,
1317,
-126,
317,
-2196,
-286,
1250,
2275,
-1315,
-1421,
2117,
-1551,
1766,
2365,
-1554,
-1511,
-2609,
-2443,
815,
-1791,
1991,
-1889,
-1907,
2863,
};

DATA rtest[NLAGS] ={// lag0, lag1,...  
82,
0,
-2,
9,
5,
-2,
-1,
20,
2,
2,
4,
4,
-3,
12,
5,
-15,
-6,
8,
-4,
-5,
3,
1,
-5,
-6,
-5,
-11,
-2,
10,
-6,
-7,
6,
-11,
-5,
12,
2,
2,
-8,
-1,
-19,
3,
9,
5,
-2,
13,
12,
-17,
5,
8,
-2,
-10,
12,
4,
-6,
9,
7,
5,
-5,
15,
-9,
-10,
12,
24,
-4,
2,
8,
-7,
-20,
10,
8,
-17,
5,
-6,
-4,
-19,
11,
4,
-2,
-7,
-14,
-9,
-10,
-9,
-21,
2,
1,
-34,
-13,
22,
0,
-3,
-2,
-15,
-13,
-14,
23,
-8,
-1,
22,
-18,
-7,
23,
13,
-6,
0,
14,
-8,
0,
20,
3,
-28,
-20,
37,
-67,
-9,
10,
-36,
20,
-20,
5,
-3,
-30,
11,
-22,
-17,
61,
-67,
-40,
171,
};

