gcc L5_12.c -o teste

./teste <input/test_1 >output/out_1

echo "TESTE 1:"
diff output/test_1 output/out_1 --color -u

rm teste
