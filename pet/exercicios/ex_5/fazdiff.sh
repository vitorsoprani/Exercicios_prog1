gcc ex_5.c -o teste -lm

./teste <input/entrada_1 >output/teste_1
./teste <input/entrada_2 >output/teste_2
./teste <input/entrada_3 >output/teste_3
./teste <input/entrada_4 >output/teste_4
./teste <input/entrada_5 >output/teste_5

echo "TESTE 1:"
diff output/saida_1 output/teste_1 --color -u
echo "TESTE 2:"
diff output/saida_2 output/teste_2 --color -u
echo "TESTE 3:"
diff output/saida_3 output/teste_3 --color -u
echo "TESTE 4:"
diff output/saida_4 output/teste_4 --color -u
echo "TESTE 5:"
diff output/saida_5 output/teste_5 --color -u
