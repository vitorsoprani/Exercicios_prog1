gcc P3_2016_Q4.c -o teste

echo "Teste 1:"
./teste <input/test_1 >output/out_1
diff output/test_1 output/out_1 --color -u
