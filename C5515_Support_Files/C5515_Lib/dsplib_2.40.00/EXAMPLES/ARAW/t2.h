#define NX 64
#define NLAGS 64 // max NLAGS = N 
#define FNAME "t2"
#define MAXERROR 10 // max absolute error allowed 

DATA x[NX] ={
-494,
-1311,
-1522,
-1106,
-875,
749,
-3116,
-3784,
-340,
3029,
3557,
-1930,
-2783,
3054,
-2148,
1194,
3824,
1351,
3034,
-4015,
-2974,
2611,
-573,
3197,
1924,
1534,
-1261,
-2736,
-2822,
-2531,
-636,
2916,
-80,
2588,
-322,
-350,
-404,
-720,
3289,
-4051,
-1660,
-3694,
1582,
1229,
3956,
431,
-819,
-2468,
1025,
1911,
-1017,
-4016,
-657,
2078,
2407,
3440,
2823,
-1084,
989,
1894,
-2508,
3316,
566,
1079,
};

DATA rtest[NLAGS] ={ // lag0, lag1,...  
10394, 
1450, 
-670, 
-2423, 
-2357, 
500, 
399, 
815, 
1164, 
-1014, 
-133, 
188, 
631, 
838, 
-1121, 
-180, 
-1646, 
-378, 
-855, 
-554, 
459, 
1402, 
441, 
569, 
-831, 
76, 
-895, 
-399, 
789, 
-508, 
-573, 
13, 
596, 
724, 
-56, 
-71, 
-716, 
-348, 
813, 
961, 
1566, 
-576, 
-1697, 
256, 
306, 
1377, 
909, 
-857, 
-80, 
-276, 
-243, 
-146, 
-384, 
-86, 
-302, 
-648, 
-145, 
-205, 
-76, 
-130, 
-158, 
-123, 
-52, 
-16, 
};

