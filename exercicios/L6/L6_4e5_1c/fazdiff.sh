gcc L6_1c.c -o teste

echo "Teste 1:"
./teste < input/test_1 >output/out_1
diff output/out_1 output/test_1 --color -u

echo "Teste 2:"
./teste < input/test_2 >output/out_2
diff output/out_2 output/test_2 --color -u

rm teste
