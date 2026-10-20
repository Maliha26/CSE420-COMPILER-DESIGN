#!/bin/bash

yacc -d -y --debug --verbose 21301096.y
echo 'Generated the parser C file and header file'

g++ -w -c -o y.o y.tab.c
echo 'Generated the parser object file'

flex 21301096.l
echo 'Generated the scanner C file'

g++ -fpermissive -w -c -o l.o lex.yy.c
echo 'Generated the scanner object file'

g++ y.o l.o
echo 'All ready, running'

./a.exe input.c

echo 'Log file:'
cat 21301096_log.txt