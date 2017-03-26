#define NX 152
#define NLAGS 152 // max NLAGS = N 
#define FNAME "t8"
#define MAXERROR 10 // max absolute error allowed 

DATA x[NX] ={
1159,
367,
-209,
-291,
-2192,
-301,
-711,
-1050,
1870,
1379,
2390,
307,
-2583,
511,
1680,
2536,
-1479,
1082,
117,
2301,
1134,
-1446,
-268,
-1743,
2492,
-767,
-2398,
1357,
2098,
-1137,
-1323,
2300,
-1962,
2343,
1072,
1848,
-1546,
-239,
-2227,
1866,
329,
-961,
-665,
1955,
-680,
-2267,
-1596,
-2395,
354,
-2010,
117,
-2036,
1434,
-665,
1719,
-2410,
520,
2387,
-1123,
2066,
-2118,
-2311,
-1413,
2302,
-2323,
-1254,
2655,
-1531,
-9,
-1114,
918,
2434,
1416,
883,
-1962,
-2151,
-2579,
-1126,
1683,
2580,
-2566,
1697,
643,
320,
-1361,
1711,
-1259,
1348,
848,
-1520,
542,
557,
847,
-1684,
725,
-1753,
210,
655,
988,
942,
2003,
-2590,
-1008,
1483,
-1025,
2268,
950,
-2263,
-2283,
-2595,
-1451,
86,
-223,
1080,
438,
48,
-2263,
-1631,
-640,
-1189,
1439,
-990,
734,
2586,
15,
2379,
1743,
2219,
-2057,
1659,
2170,
-1827,
-2009,
1396,
1179,
806,
1350,
867,
2038,
-1212,
-429,
-1526,
-2469,
-2227,
1863,
-850,
-180,
2199,
-1443,
1924,
832,
2079,
};

DATA rtest[NLAGS] ={ // lag0, lag1,... 
79,
-2,
0,
-3,
-2,
-9,
0,
2,
-8,
14,
-8,
1,
-7,
4,
2,
11,
-6,
-7,
-8,
-1,
4,
-5,
-1,
-5,
13,
2,
5,
-5,
-2,
0,
-7,
-1,
-1,
9,
-3,
11,
-14,
-6,
-1,
7,
0,
-8,
6,
-7,
10,
-11,
5,
-4,
11,
-4,
-9,
2,
1,
-3,
3,
2,
-2,
13,
-6,
2,
-5,
-2,
-6,
11,
5,
-5,
4,
-3,
5,
-5,
6,
3,
8,
-1,
-9,
-6,
-8,
-1,
1,
3,
-3,
7,
-5,
-1,
-1,
-3,
1,
-1,
-2,
-8,
5,
-3,
3,
-4,
1,
5,
4,
-1,
-1,
-1,
-7,
-2,
-2,
4,
-3,
7,
1,
-1,
-4,
-3,
4,
0,
3,
0,
1,
-1,
8,
0,
-1,
2,
4,
-3,
-2,
-1,
-2,
2,
-2,
3,
-2,
0,
2,
-2,
-1,
-2,
0,
0,
4,
2,
1,
1,
-1,
2,
0,
-1,
0,
-1,
0,
-1,
0,
0,
0,
0,
};

