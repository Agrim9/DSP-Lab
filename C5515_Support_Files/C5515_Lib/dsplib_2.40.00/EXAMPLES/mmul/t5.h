/* Test for mmul: rand */
#define row1 3
#define col1 10
#define row2 10
#define col2 6
#define FNAME "t5"
#define MAXERROR 10

DATA x1[row1*col1] ={
938,
2824,
1847,
3409,
3602,
2580,
2998,
1118,
519,
2084,
3326,
4461,
4258,
2045,
3048,
4230,
6342,
4084,
2925,
857,
3237,
6082,
3695,
4998,
1769,
4217,
2727,
5358,
947,
5140,
};

DATA x2[row2*col2] ={
1223,
3884,
3771,
931,
2267,
3040,
1566,
2691,
2554,
2803,
1282,
2967,
2447,
3968,
2520,
3245,
2498,
3186,
2770,
3330,
3026,
3922,
1193,
1705,
3773,
3830,
5161,
3361,
5517,
4592,
3944,
5169,
3433,
2354,
3084,
5147,
1134,
3548,
1492,
3473,
2456,
4842,
5800,
5198,
3423,
3868,
4266,
3100,
4410,
5762,
3482,
521,
3806,
2899,
2671,
3194,
3542,
3090,
4629,
4233,
};

DATA rtest[] ={
1863,
2537,
2156,
2068,
2014,
2473,
3094,
4440,
3289,
3041,
3183,
4017,
3410,
4523,
3653,
3482,
3358,
4038,
};

DATA r[row1*col2];

