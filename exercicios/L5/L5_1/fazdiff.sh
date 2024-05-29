gcc L5_1.c -o teste -lm

./teste <input/test_1 >output/out_1
./teste <input/test_2 >output/out_2
./teste <input/test_3 >output/out_3
./teste <input/test_4 >output/out_4

echo "TESTE 1:"
diff output/test_1 output/out_1 --color -u
echo "TESTE 2:"
diff output/test_2 output/out_2 --color -u
echo "TESTE 3:"
diff output/test_3 output/out_3 --color -u
echo "TESTE 4:"
diff output/test_4 output/out_4 --color -u

rm teste
