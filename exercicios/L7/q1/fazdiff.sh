gcc q1.c -o teste

./teste arquivos/exemplo1.txt > output/out_1

echo "TESTE 1:"
diff output/out_1 output/saida_exemplo1.txt --color -u

./teste arquivos/exemplo2.txt > output/out_2

echo "TESTE 2:"
diff output/out_1 output/saida_exemplo1.txt --color -u
