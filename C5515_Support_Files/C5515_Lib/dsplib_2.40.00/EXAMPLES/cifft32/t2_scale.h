/* Test for cfft: rand */
#define NX 16
#define FNAME "t2"
#define MAXERROR 16

#pragma DATA_SECTION (x,".input")

LDATA x[2*NX] ={
1485,	-188,	/* 0 */ 
1422,	1473,	/* 1 */ 
-307,	-117,	/* 2 */ 
1343,	-278,	/* 3 */ 
-1509,	1181,	/* 4 */ 
-503,	85,	/* 5 */ 
1068,	-1015,	/* 6 */ 
-1673,	587,	/* 7 */ 
-1233,	1153,	/* 8 */ 
-1015,	-1640,	/* 9 */ 
-1028,	618,	/* 10 */ 
354,	-412,	/* 11 */ 
-778,	1132,	/* 12 */ 
-1028,	9,	/* 13 */ 
-1654,	714,	/* 14 */ 
842,	-243,	/* 15 */ 
};

#pragma DATA_SECTION (rtest,".test")

LDATA rtest[2*NX] ={
-263,	191,	 /* 0 */ 
377,	285,	 /* 1 */ 
139,	100,	 /* 2 */ 
239,	80,	 /* 3 */ 
-25,	68,	 /* 4 */ 
-168,	-418,	 /* 5 */ 
292,	125,	 /* 6 */ 
-428,	-194,	 /* 7 */ 
-232,	243,	 /* 8 */ 
-4,	-153,	 /* 9 */ 
77,	-363,	 /* 10 */ 
501,	59,	 /* 11 */ 
10,	316,	 /* 12 */ 
460,	-234,	 /* 13 */ 
125,	-201,	 /* 14 */ 
379,	-99,	 /* 15 */ 
};

DATA error;
