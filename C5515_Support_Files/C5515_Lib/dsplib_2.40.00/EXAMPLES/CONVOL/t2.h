#define NX 128
#define NH 64
#define FNAME "t2"
#define MAXERROR 10  // max absolute value 

DATA x[NX] ={
32767,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
};

DATA h[NH] ={
816,
547,
-91,
-1006,
670,
-116,
240,
609,
880,
497,
-676,
-197,
909,
870,
-188,
821,
-923,
-308,
653,
-1024,
-754,
-621,
-629,
216,
-476,
-629,
-1012,
515,
-115,
901,
-71,
-170,
722,
52,
-621,
359,
705,
-1003,
378,
-252,
692,
5,
437,
-149,
-408,
-648,
-640,
380,
-412,
86,
-729,
413,
-254,
751,
738,
195,
-8,
834,
671,
302,
663,
334,
-330,
-439,
};

DATA rtest[NX+NH-1] ={
816,
547,
-91,
-1006,
670,
-116,
240,
609,
880,
497,
-676,
-197,
909,
870,
-188,
821,
-923,
-308,
653,
-1024,
-754,
-621,
-629,
216,
-476,
-629,
-1012,
515,
-115,
901,
-71,
-170,
722,
52,
-621,
359,
705,
-1003,
378,
-252,
692,
5,
437,
-149,
-408,
-648,
-640,
380,
-412,
86,
-729,
413,
-254,
751,
738,
195,
-8,
834,
671,
302,
663,
334,
-330,
-439,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
};

DATA x_np[NX+NH-1] = {
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
32767,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
};

