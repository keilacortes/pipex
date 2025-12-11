#!/bin/bash

make

echo "=== Teste REAL: cat e wc ==="
echo -e "linha1\nlinha2\nlinha3\nlinha4" > infile
./pipex infile "cat" "wc -l" outfile
echo "Pipex: $(cat outfile)"
echo -n "Esperado: "
< infile cat | wc -l
echo

echo "=== Teste: grep ==="
echo -e "apple\nbanana\norange\napple juice" > fruits.txt
./pipex fruits.txt "grep apple" "wc -l" outfile2
echo "Pipex: $(cat outfile2)"
echo -n "Esperado: "
< fruits.txt grep apple | wc -l
echo

echo "=== Teste: ls (ignora input) ==="
# Cria um arquivo vazio como input
touch empty.txt
./pipex empty.txt "ls -l" "wc -l" outfile3
echo "Pipex: $(cat outfile3)"
echo -n "Esperado (ls normal): "
ls -l | wc -l
echo -n "Esperado (com redirecionamento): "
< empty.txt ls -l | wc -l
echo

echo "=== Teste: comandos com argumentos ==="
echo -e "1\n2\n3\n4\n5" > numbers.txt
./pipex numbers.txt "head -n 3" "wc -l" outfile4
echo "Pipex: $(cat outfile4)"
echo -n "Esperado: "
< numbers.txt head -n 3 | wc -l

# Limpar
rm -f infile fruits.txt empty.txt numbers.txt outfile* expected*
make fclean