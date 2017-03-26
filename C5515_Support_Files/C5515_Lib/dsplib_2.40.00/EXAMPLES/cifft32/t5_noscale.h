/*Test for cfft: rand*/
#define NX 128
#define FNAME "t128"
#define MAXERROR 256
#pragma DATA_SECTION (x,".input")
LDATA x[2*NX] ={
-42630913, 23544211,
-55821370, -16360822,
-23607364, 62494449,
9424785, 37139760,
-18159972, -41190271,
-44745866, -22477614,
35993378, 44994126,
-23893623, 13021915,
-378681, 13188869,
-27415, -57288608,
-8369693, 7645667,
13306860, 23006021,
-8858818, -21367131,
-55834940, -33641860,
-34526675, -6228396,
8156905, -35367469,
-42164167, -2400467,
-11649535, 9368344,
-31587209, 46079474,
-39411703, 6034464,
-34263829, -18187058,
-13477699, 54834337,
5827253, 27689626,
-3896290, 7743059,
35705914, 22536296,
-8233798, -17048265,
-50920164, 28734391,
326624, 9009481,
2394876, 20970687,
10621179, -35142830,
16771366, 51528547,
42885388, 14576909,
-18381660, -64328405,
8751278, 15768554,
-442136, 42760128,
-19470429, 21425929,
71682616, 46331372,
-8644196, 44286577,
-47295928, -30515381,
59394730, -77363268,
10923511, 60019827,
-37548737, 13112998,
20815497, 681949,
42606809, -13622328,
-30066197, -51502515,
4535735, 7428049,
-4665409, -46119851,
-39037068, -28161749,
39719037, -7000883,
-517734, 25364231,
17992514, 12607556,
-24039356, -45144568,
-21996923, 49723516,
10548264, 1098443,
3584086, 62761982,
62015845, -40566990,
-9231015, -26260768,
74240995, -25746266,
50617725, -3597039,
-65266008, -32784582,
-56389658, -32346074,
-19244612, -79831777,
-6234968, -28124919,
299779, 8635087,
28083378, -6168445,
-24235382, -5624236,
-24209203, -3925496,
-6750514, 5653525,
-686663, -16817693,
9357996, -23658439,
35510481, 17051177,
20859894, -14123783,
-58740902, 7688440,
23399101, -32195378,
27228947, -4900376,
21352193, 24982551,
43959002, -29880089,
10975571, 4666142,
-22581903, -7923688,
-5010599, -2531988,
-82175400, -12031677,
15880830, -69713857,
3924045, -4816595,
-19834154, 46752782,
-21968344, 21870916,
-36260995, -12654502,
-1601582, -22194346,
12728690, 8353643,
-11085077, -12868667,
-16773802, -17732840,
-1207242, 1858525,
-5863984, 42069492,
-32120486, -84557291,
43370711, 19624515,
14794473, -33825029,
42981246, 31684941,
-16701041, -81334505,
-37537901, -7510536,
27100224, 1948502,
1382428, -14247682,
-25374150, -6808796,
-2990678, -50770439,
-67405832, -37794097,
36370254, -27346934,
-32923292, 12301534,
-23101845, -19666479,
44945473, 51586887,
-30509138, 4700021,
-13853207, -62504077,
-16984018, -15240191,
54349717, -21879976,
2714577, 3466773,
-36274236, -7403169,
-37732556, -9363142,
58239634, -24617612,
65010323, -2165388,
54863785, -48452736,
-42142359, 20546731,
-7165130, -44409390,
-6675052, -22198830,
10317960, -4902789,
-19204056, 8324350,
-32804436, -2571362,
-14992436, 58323306,
36308979, 54424346,
79612854, 21019701,
7693640, 3080753,
-8946388, -27098796,
};


#pragma DATA_SECTION (rtest,".test")
LDATA rtest[2*NX] ={
-312896386, -488023111,
-771926930, 391660964,
-294503608, -493218217,
400265809, -80787379,
317373774, 119525610,
20435242, 340283919,
-576659729, 433589879,
629246089, 511101039,
-592990084, -321546806,
380116951, -622550909,
-7503317, -134110720,
127103481, -622784597,
358959943, -34666703,
-139364341, -809547794,
-239344044, -25504143,
-567176528, -427616398,
-495692666, -348372133,
-321744914, 170487914,
262017682, 226589069,
-622083768, 220915323,
-443734803, -925522430,
-82825095, 45306703,
-261406827, 207488624,
-581880223, -197932883,
-289283128, -21667713,
-870350258, 36667834,
-468259141, 300655958,
-238233421, 71446687,
104613346, -45561320,
-60429076, 385085448,
-59352167, -190116550,
240868275, -304652139,
-51148739, -795409246,
134266720, -348530106,
137274819, 726800714,
205721112, -2923470,
615122867, -122122090,
121188638, 304650812,
373578376, 149737465,
-315243921, -259217069,
93414891, -263869358,
37825303, -279239177,
1008325704, -117541348,
-57808068, 213320152,
173725379, -385554258,
-136155399, -67601083,
245986577, 550042036,
253103603, 434621789,
-203520561, 119627852,
97315360, 324762396,
-623523086, 175430292,
331097645, 524170807,
-157644389, -487398793,
87103185, -663031563,
-24501311, 760056871,
-677192910, 288134489,
333103292, -562567718,
-423403341, -95997787,
-131222476, -231598399,
189696861, 364755398,
50640036, -6386342,
61311323, -53515590,
182950227, 584552341,
784337030, -125885191,
-126507602, 156716499,
-318097551, -48805630,
155479224, 54446411,
-193117312, -255420029,
-361130640, 22596841,
-701979334, 644900333,
402156509, 508854087,
130992990, 72803995,
-186206976, -215769796,
-101373054, 492879211,
-184642109, -70452733,
-175621595, 217638193,
487376370, 2434930,
105280219, -42365260,
40518055, -23242365,
-234623377, -152165625,
-414878344, 807456015,
297472335, 227429969,
351135658, -318416058,
98818816, 405714678,
-141737758, -245860133,
211794815, -379197309,
612040750, 779731930,
-630676532, 434791138,
155002936, -613845804,
146405192, -188266742,
-186268101, 456616363,
-293523142, 192408897,
251472647, -101805593,
-83422919, 454093895,
-467163336, 335739504,
10590735, -592217531,
-631309565, -96138110,
143026868, 867993580,
34249200, -549655598,
473777031, 5991602,
-300950866, -301716266,
104780424, -1052408735,
155032351, -208492147,
-65644525, -481508164,
-547597087, 136769749,
-91527328, 360918981,
890629946, 742720646,
-377441206, -160103122,
112246368, 423273961,
-104175090, -815457597,
-179333139, 239157576,
-175376555, -172027518,
428461191, -39222550,
-203339812, 297231790,
-140697497, -138783234,
-388912868, 220118436,
125261271, 290272509,
-47036942, 111475917,
-113038984, 140751702,
-216731264, -93122146,
113648797, 31888791,
-58798157, 278724826,
-473480772, -65414219,
-45496167, 395858634,
-51361064, 207274909,
-239425543, 628985976,
236649876, 410821893,
262501794, 359156804,
};