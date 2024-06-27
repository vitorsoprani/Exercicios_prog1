gcc PA_2022_L5.c -o teste

echo "TESTE 1:"
./teste <input/test_1 >output/out_1
diff output/out_1 output/test_1  --color -u

echo "TESTE 2:"
./teste <input/test_2 >output/out_2
diff output/out_2 output/test_2 --color -u

echo "TESTE 3:"
./teste <input/test_3 >output/out_3
diff output/out_3 output/test_3 --color -u

echo "TESTE 4:"
./teste <input/test_4 >output/out_4
diff output/out_4 output/test_4 --color -u

echo "TESTE 5:"
./teste <input/test_5 >output/out_5
diff output/out_5 output/test_5 --color -u

echo "TESTE 6:"
./teste <input/test_6 >output/out_6
diff output/out_6 output/test_6 --color -u

rm teste