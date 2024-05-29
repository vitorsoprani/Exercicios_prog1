gcc PA_L2.c -o teste

./teste <input/test_1 >output/out1
./teste <input/test_2 >output/out2
./teste <input/test_3 >output/out3
./teste <input/test_4 >output/out4
./teste <input/test_5 >output/out5
./teste <input/test_6 >output/out6

diff output/test_1 output/out1
diff output/test_2 output/out2
diff output/test_3 output/out3
diff output/test_4 output/out4
diff output/test_5 output/out5
diff output/test_6 output/out6

rm teste
