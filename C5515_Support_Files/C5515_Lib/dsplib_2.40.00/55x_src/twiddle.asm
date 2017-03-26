;***********************************************************
; Version 2.40.00                                           
;***********************************************************

	.def twiddle

	.sect ".data:twiddle" 

twiddle:
        .word    32767		; cos(0)
        .word    0000		; sin(0)
        .word    0000		; cos(PI/2) 		
        .word    32767		; sin(PI/2)
        .word    23170		
        .word    23170		
        .word    -23170		
        .word    23170
        .word    30274
        .word    12540
        .word    -12540
        .word    30274
        .word    12540
        .word    30274
        .word    -30274
        .word    12540
        .word    32138
        .word    6393
        .word    -6393
        .word    32138
        .word    18205
        .word    27246
        .word    -27246
        .word    18205
        .word    27246
        .word    18205
        .word    -18205
        .word    27246
        .word    6393
        .word    32138
        .word    -32138
        .word    6393
        .word    32610
        .word    3212
        .word    -3212
        .word    32610
        .word    20788
        .word    25330
        .word    -25330
        .word    20788
        .word    28899
        .word    15447
        .word    -15447
        .word    28899
        .word    9512
        .word    31357
        .word    -31357
        .word    9512
        .word    31357
        .word    9512
        .word    -9512
        .word    31357
        .word    15447
        .word    28899
        .word    -28899
        .word    15447
        .word    25330
        .word    20788
        .word    -20788
        .word    25330
        .word    3212
        .word    32610
        .word    -32610
        .word    3212
        .word    32729
        .word    1608
        .word    -1608
        .word    32729
        .word    22006
        .word    24279
        .word    -24279
        .word    22006
        .word    29622
        .word    14010
        .word    -14010
        .word    29622
        .word    11039
        .word    30853
        .word    -30853
        .word    11039
        .word    31786
        .word    7962
        .word    -7962
        .word    31786
        .word    16846
        .word    28106
        .word    -28106
        .word    16846
        .word    26320
        .word    19520
        .word    -19520
        .word    26320
        .word    4808
        .word    32413
        .word    -32413
        .word    4808
        .word    32413
        .word    4808
        .word    -4808
        .word    32413
        .word    19520
        .word    26320
        .word    -26320
        .word    19520
        .word    28106
        .word    16846
        .word    -16846
        .word    28106
        .word    7962
        .word    31786
        .word    -31786
        .word    7962
        .word    30853
        .word    11039
        .word    -11039
        .word    30853
        .word    14010
        .word    29622
        .word    -29622
        .word    14010
        .word    24279
        .word    22006
        .word    -22006
        .word    24279
        .word    1608
        .word    32729
        .word    -32729
        .word    1608
        .word    32758
        .word    804
        .word    -804
        .word    32758
        .word    22595
        .word    23732
        .word    -23732
        .word    22595
        .word    29957
        .word    13279
        .word    -13279
        .word    29957
        .word    11793
        .word    30572
        .word    -30572
        .word    11793
        .word    31972
        .word    7180
        .word    -7180
        .word    31972
        .word    17531
        .word    27684
        .word    -27684
        .word    17531
        .word    26791
        .word    18868
        .word    -18868
        .word    26791
        .word    5602
        .word    32286
        .word    -32286
        .word    5602
        .word    32522
        .word    4011
        .word    -4011
        .word    32522
        .word    20160
        .word    25833
        .word    -25833
        .word    20160
        .word    28511
        .word    16151
        .word    -16151
        .word    28511
        .word    8740
        .word    31581
        .word    -31581
        .word    8740
        .word    31114
        .word    10279
        .word    -10279
        .word    31114
        .word    14733
        .word    29269
        .word    -29269
        .word    14733
        .word    24812
        .word    21403
        .word    -21403
        .word    24812
        .word    2411
        .word    32679
        .word    -32679
        .word    2411
        .word    32679
        .word    2411
        .word    -2411
        .word    32679
        .word    21403
        .word    24812
        .word    -24812
        .word    21403
        .word    29269
        .word    14733
        .word    -14733
        .word    29269
        .word    10279
        .word    31114
        .word    -31114
        .word    10279
        .word    31581
        .word    8740
        .word    -8740
        .word    31581
        .word    16151
        .word    28511
        .word    -28511
        .word    16151
        .word    25833
        .word    20160
        .word    -20160
        .word    25833
        .word    4011
        .word    32522
        .word    -32522
        .word    4011
        .word    32286
        .word    5602
        .word    -5602
        .word    32286
        .word    18868
        .word    26791
        .word    -26791
        .word    18868
        .word    27684
        .word    17531
        .word    -17531
        .word    27684
        .word    7180
        .word    31972
        .word    -31972
        .word    7180
        .word    30572
        .word    11793
        .word    -11793
        .word    30572
        .word    13279
        .word    29957
        .word    -29957
        .word    13279
        .word    23732
        .word    22595
        .word    -22595
        .word    23732
        .word    804
        .word    32758
        .word    -32758
        .word    804
        .word    32766
        .word    402
        .word    -402
        .word    32766
        .word    22884
        .word    23453
        .word    -23453
        .word    22884
        .word    30118
        .word    12910
        .word    -12910
        .word    30118
        .word    12167
        .word    30425
        .word    -30425
        .word    12167
        .word    32058
        .word    6787
        .word    -6787
        .word    32058
        .word    17869
        .word    27467
        .word    -27467
        .word    17869
        .word    27020
        .word    18538
        .word    -18538
        .word    27020
        .word    5998
        .word    32214
        .word    -32214
        .word    5998
        .word    32568
        .word    3612
        .word    -3612
        .word    32568
        .word    20475
        .word    25583
        .word    -25583
        .word    20475
        .word    28707
        .word    15800
        .word    -15800
        .word    28707
        .word    9127
        .word    31471
        .word    -31471
        .word    9127
        .word    31238
        .word    9896
        .word    -9896
        .word    31238
        .word    15091
        .word    29086
        .word    -29086
        .word    15091
        .word    25073
        .word    21097
        .word    -21097
        .word    25073
        .word    2811
        .word    32647
        .word    -32647
        .word    2811
        .word    32706
        .word    2009
        .word    -2009
        .word    32706
        .word    21706
        .word    24548
        .word    -24548
        .word    21706
        .word    29448
        .word    14373
        .word    -14373
        .word    29448
        .word    10660
        .word    30986
        .word    -30986
        .word    10660
        .word    31686
        .word    8351
        .word    -8351
        .word    31686
        .word    16500
        .word    28311
        .word    -28311
        .word    16500
        .word    26078
        .word    19841
        .word    -19841
        .word    26078
        .word    4410
        .word    32470
        .word    -32470
        .word    4410
        .word    32352
        .word    5205
        .word    -5205
        .word    32352
        .word    19195
        .word    26557
        .word    -26557
        .word    19195
        .word    27897
        .word    17190
        .word    -17190
        .word    27897
        .word    7571
        .word    31881
        .word    -31881
        .word    7571
        .word    30715
        .word    11417
        .word    -11417
        .word    30715
        .word    13646
        .word    29792
        .word    -29792
        .word    13646
        .word    24008
        .word    22302
        .word    -22302
        .word    24008
        .word    1206
        .word    32746
        .word    -32746
        .word    1206
        .word    32746
        .word    1206
        .word    -1206
        .word    32746
        .word    22302
        .word    24008
        .word    -24008
        .word    22302
        .word    29792
        .word    13646
        .word    -13646
        .word    29792
        .word    11417
        .word    30715
        .word    -30715
        .word    11417
        .word    31881
        .word    7571
        .word    -7571
        .word    31881
        .word    17190
        .word    27897
        .word    -27897
        .word    17190
        .word    26557
        .word    19195
        .word    -19195
        .word    26557
        .word    5205
        .word    32352
        .word    -32352
        .word    5205
        .word    32470
        .word    4410
        .word    -4410
        .word    32470
        .word    19841
        .word    26078
        .word    -26078
        .word    19841
        .word    28311
        .word    16500
        .word    -16500
        .word    28311
        .word    8351
        .word    31686
        .word    -31686
        .word    8351
        .word    30986
        .word    10660
        .word    -10660
        .word    30986
        .word    14373
        .word    29448
        .word    -29448
        .word    14373
        .word    24548
        .word    21706
        .word    -21706
        .word    24548
        .word    2009
        .word    32706
        .word    -32706
        .word    2009
        .word    32647
        .word    2811
        .word    -2811
        .word    32647
        .word    21097
        .word    25073
        .word    -25073
        .word    21097
        .word    29086
        .word    15091
        .word    -15091
        .word    29086
        .word    9896
        .word    31238
        .word    -31238
        .word    9896
        .word    31471
        .word    9127
        .word    -9127
        .word    31471
        .word    15800
        .word    28707
        .word    -28707
        .word    15800
        .word    25583
        .word    20475
        .word    -20475
        .word    25583
        .word    3612
        .word    32568
        .word    -32568
        .word    3612
        .word    32214
        .word    5998
        .word    -5998
        .word    32214
        .word    18538
        .word    27020
        .word    -27020
        .word    18538
        .word    27467
        .word    17869
        .word    -17869
        .word    27467
        .word    6787
        .word    32058
        .word    -32058
        .word    6787
        .word    30425
        .word    12167
        .word    -12167
        .word    30425
        .word    12910
        .word    30118
        .word    -30118
        .word    12910
        .word    23453
        .word    22884
        .word    -22884
        .word    23453
        .word    402
        .word    32766
        .word    -32766
        .word    402
        .word    32767
        .word    201
        .word    -201
        .word    32767
        .word    23028
        .word    23312
        .word    -23312
        .word    23028
        .word    30196
        .word    12725
        .word    -12725
        .word    30196
        .word    12354
        .word    30350
        .word    -30350
        .word    12354
        .word    32099
        .word    6590
        .word    -6590
        .word    32099
        .word    18037
        .word    27357
        .word    -27357
        .word    18037
        .word    27133
        .word    18372
        .word    -18372
        .word    27133
        .word    6195
        .word    32177
        .word    -32177
        .word    6195
        .word    32590
        .word    3412
        .word    -3412
        .word    32590
        .word    20632
        .word    25457
        .word    -25457
        .word    20632
        .word    28803
        .word    15624
        .word    -15624
        .word    28803
        .word    9319
        .word    31415
        .word    -31415
        .word    9319
        .word    31298
        .word    9704
        .word    -9704
        .word    31298
        .word    15269
        .word    28993
        .word    -28993
        .word    15269
        .word    25202
        .word    20943
        .word    -20943
        .word    25202
        .word    3012
        .word    32629
        .word    -32629
        .word    3012
        .word    32718
        .word    1809
        .word    -1809
        .word    32718
        .word    21856
        .word    24414
        .word    -24414
        .word    21856
        .word    29535
        .word    14192
        .word    -14192
        .word    29535
        .word    10850
        .word    30920
        .word    -30920
        .word    10850
        .word    31737
        .word    8157
        .word    -8157
        .word    31737
        .word    16673
        .word    28209
        .word    -28209
        .word    16673
        .word    26199
        .word    19681
        .word    -19681
        .word    26199
        .word    4609
        .word    32442
        .word    -32442
        .word    4609
        .word    32383
        .word    5007
        .word    -5007
        .word    32383
        .word    19358
        .word    26439
        .word    -26439
        .word    19358
        .word    28002
        .word    17018
        .word    -17018
        .word    28002
        .word    7767
        .word    31834
        .word    -31834
        .word    7767
        .word    30784
        .word    11228
        .word    -11228
        .word    30784
        .word    13828
        .word    29707
        .word    -29707
        .word    13828
        .word    24144
        .word    22154
        .word    -22154
        .word    24144
        .word    1407
        .word    32738
        .word    -32738
        .word    1407
        .word    32753
        .word    1005
        .word    -1005
        .word    32753
        .word    22449
        .word    23870
        .word    -23870
        .word    22449
        .word    29875
        .word    13463
        .word    -13463
        .word    29875
        .word    11605
        .word    30644
        .word    -30644
        .word    11605
        .word    31927
        .word    7376
        .word    -7376
        .word    31927
        .word    17361
        .word    27791
        .word    -27791
        .word    17361
        .word    26674
        .word    19032
        .word    -19032
        .word    26674
        .word    5404
        .word    32319
        .word    -32319
        .word    5404
        .word    32496
        .word    4211
        .word    -4211
        .word    32496
        .word    20001
        .word    25956
        .word    -25956
        .word    20001
        .word    28411
        .word    16326
        .word    -16326
        .word    28411
        .word    8546
        .word    31634
        .word    -31634
        .word    8546
        .word    31050
        .word    10469
        .word    -10469
        .word    31050
        .word    14553
        .word    29359
        .word    -29359
        .word    14553
        .word    24680
        .word    21555
        .word    -21555
        .word    24680
        .word    2210
        .word    32693
        .word    -32693
        .word    2210
        .word    32664
        .word    2611
        .word    -2611
        .word    32664
        .word    21251
        .word    24943
        .word    -24943
        .word    21251
        .word    29178
        .word    14912
        .word    -14912
        .word    29178
        .word    10088
        .word    31177
        .word    -31177
        .word    10088
        .word    31527
        .word    8933
        .word    -8933
        .word    31527
        .word    15976
        .word    28610
        .word    -28610
        .word    15976
        .word    25708
        .word    20318
        .word    -20318
        .word    25708
        .word    3812
        .word    32546
        .word    -32546
        .word    3812
        .word    32251
        .word    5800
        .word    -5800
        .word    32251
        .word    18703
        .word    26906
        .word    -26906
        .word    18703
        .word    27576
        .word    17700
        .word    -17700
        .word    27576
        .word    6983
        .word    32015
        .word    -32015
        .word    6983
        .word    30499
        .word    11980
        .word    -11980
        .word    30499
        .word    13095
        .word    30038
        .word    -30038
        .word    13095
        .word    23593
        .word    22740
        .word    -22740
        .word    23593
        .word    603
        .word    32762
        .word    -32762
        .word    603
        .word    32762
        .word    603
        .word    -603
        .word    32762
        .word    22740
        .word    23593
        .word    -23593
        .word    22740
        .word    30038
        .word    13095
        .word    -13095
        .word    30038
        .word    11980
        .word    30499
        .word    -30499
        .word    11980
        .word    32015
        .word    6983
        .word    -6983
        .word    32015
        .word    17700
        .word    27576
        .word    -27576
        .word    17700
        .word    26906
        .word    18703
        .word    -18703
        .word    26906
        .word    5800
        .word    32251
        .word    -32251
        .word    5800
        .word    32546
        .word    3812
        .word    -3812
        .word    32546
        .word    20318
        .word    25708
        .word    -25708
        .word    20318
        .word    28610
        .word    15976
        .word    -15976
        .word    28610
        .word    8933
        .word    31527
        .word    -31527
        .word    8933
        .word    31177
        .word    10088
        .word    -10088
        .word    31177
        .word    14912
        .word    29178
        .word    -29178
        .word    14912
        .word    24943
        .word    21251
        .word    -21251
        .word    24943
        .word    2611
        .word    32664
        .word    -32664
        .word    2611
        .word    32693
        .word    2210
        .word    -2210
        .word    32693
        .word    21555
        .word    24680
        .word    -24680
        .word    21555
        .word    29359
        .word    14553
        .word    -14553
        .word    29359
        .word    10469
        .word    31050
        .word    -31050
        .word    10469
        .word    31634
        .word    8546
        .word    -8546
        .word    31634
        .word    16326
        .word    28411
        .word    -28411
        .word    16326
        .word    25956
        .word    20001
        .word    -20001
        .word    25956
        .word    4211
        .word    32496
        .word    -32496
        .word    4211
        .word    32319
        .word    5404
        .word    -5404
        .word    32319
        .word    19032
        .word    26674
        .word    -26674
        .word    19032
        .word    27791
        .word    17361
        .word    -17361
        .word    27791
        .word    7376
        .word    31927
        .word    -31927
        .word    7376
        .word    30644
        .word    11605
        .word    -11605
        .word    30644
        .word    13463
        .word    29875
        .word    -29875
        .word    13463
        .word    23870
        .word    22449
        .word    -22449
        .word    23870
        .word    1005
        .word    32753
        .word    -32753
        .word    1005
        .word    32738
        .word    1407
        .word    -1407
        .word    32738
        .word    22154
        .word    24144
        .word    -24144
        .word    22154
        .word    29707
        .word    13828
        .word    -13828
        .word    29707
        .word    11228
        .word    30784
        .word    -30784
        .word    11228
        .word    31834
        .word    7767
        .word    -7767
        .word    31834
        .word    17018
        .word    28002
        .word    -28002
        .word    17018
        .word    26439
        .word    19358
        .word    -19358
        .word    26439
        .word    5007
        .word    32383
        .word    -32383
        .word    5007
        .word    32442
        .word    4609
        .word    -4609
        .word    32442
        .word    19681
        .word    26199
        .word    -26199
        .word    19681
        .word    28209
        .word    16673
        .word    -16673
        .word    28209
        .word    8157
        .word    31737
        .word    -31737
        .word    8157
        .word    30920
        .word    10850
        .word    -10850
        .word    30920
        .word    14192
        .word    29535
        .word    -29535
        .word    14192
        .word    24414
        .word    21856
        .word    -21856
        .word    24414
        .word    1809
        .word    32718
        .word    -32718
        .word    1809
        .word    32629
        .word    3012
        .word    -3012
        .word    32629
        .word    20943
        .word    25202
        .word    -25202
        .word    20943
        .word    28993
        .word    15269
        .word    -15269
        .word    28993
        .word    9704
        .word    31298
        .word    -31298
        .word    9704
        .word    31415
        .word    9319
        .word    -9319
        .word    31415
        .word    15624
        .word    28803
        .word    -28803
        .word    15624
        .word    25457
        .word    20632
        .word    -20632
        .word    25457
        .word    3412
        .word    32590
        .word    -32590
        .word    3412
        .word    32177
        .word    6195
        .word    -6195
        .word    32177
        .word    18372
        .word    27133
        .word    -27133
        .word    18372
        .word    27357
        .word    18037
        .word    -18037
        .word    27357
        .word    6590
        .word    32099
        .word    -32099
        .word    6590
        .word    30350
        .word    12354
        .word    -12354
        .word    30350
        .word    12725
        .word    30196
        .word    -30196
        .word    12725
        .word    23312
        .word    23028
        .word    -23028
        .word    23312
        .word    201
        .word    32767
        .word    -32767
        .word    201
