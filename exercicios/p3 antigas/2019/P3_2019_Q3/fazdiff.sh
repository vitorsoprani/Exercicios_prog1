gcc P3_2019_Q3_a.c -o teste

echo "TESTE 1:"
./teste <input/test_1 >output/out_1
diff output/out_1 output/test_1 --color -u

echo "TESTE 2:"
./teste <input/test_2 >output/out_2
diff output/out_2 output/test_2 --color -u

