gcc q2.c -o teste

echo "TESTE 1:"
./teste input/entrada.txt output/teste.txt
diff output/saida.txt output/teste.txt --color -u

echo "TESTE 2:"
./teste input/entrada2.txt output/teste2.txt
diff output/saida2.txt output/teste2.txt --color -u

echor "TESTE 3:"
./teste input/entrada3.txt output/teste3.txt
diff output/saida3.txt output/teste3.txt --color -u
