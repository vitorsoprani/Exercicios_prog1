gcc P3_2017_Q5.c -o teste

echo "Teste 1:"
./teste <input/test_1 >output/out_1
diff output/out_1 output/test_1 --color -u
