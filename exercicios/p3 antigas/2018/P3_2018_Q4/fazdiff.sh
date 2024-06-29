gcc P3_2018_Q4.c -o teste

echo "Teste 1:"
./teste <input/test_1 >output/out_1
diff output/out_1 output/test_1 --color -u

echo "Teste 2:"
./teste <input/test_2 >output/out_2
diff output/out_2 output/test_2 --color -u

echo "Teste 3:"
./teste <input/test_3 >output/out_3
diff output/out_3 output/test_3 --color -u
