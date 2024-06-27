gcc L6_2c.c -o teste

echo "Teste 1:"
./teste < input/test_1 >output/out_1
diff output/out_1 output/test_1 --color -u

rm teste
