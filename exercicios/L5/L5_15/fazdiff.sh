gcc L5_15.c -o teste

./teste <input/test_1 >output/out_1
./teste <input/test_2 >output/out_2

echo "TESTE 1:"
diff output/test_1 output/out_1
echo "TESTE 2:"
diff output/test_2 output/out_2

rm teste
