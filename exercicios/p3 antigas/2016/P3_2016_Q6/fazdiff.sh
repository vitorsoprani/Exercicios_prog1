gcc P3_2016_Q6.c -o teste

echo "Teste 1:"
./teste <input/test_1 >output/out_1
diff output/test_1 output/out_1 --color -u

echo "Teste 2:"
./teste <input/test_2 >output/out_2
diff output/test_2 output/out_2 --color -u
