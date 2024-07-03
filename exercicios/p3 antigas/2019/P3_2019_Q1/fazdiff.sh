gcc P3_2019_Q1_a.c -o teste

echo "TESTE 1:"
./teste <input/test_1 >output/out_1
diff output/out_1 output/test_1 --color -u

echo "TESTE 2:"
./teste <input/test_2 >output/out_2
diff output/out_2 output/test_2 --color -u

echo "TESTE 3:"
./teste <input/test_3 >output/out_3
diff output/out_3 output/test_3 --color -u
