.PHONY: clean

clean:
	rm -rf ./build/*
	rm -rf ./intr/*
	rm -rf ./*.yy.c
	rm -rf ./*.tab.c
	rm -f ./a.out

<<<<<<< HEAD
rmc: 
	flex ./lexy/rm_cmnt/rm_cmnt.lex
	gcc -c lex.yy.c
	./a.out ./lexy/rm_cmnt/in.c ./lexy/rm_cmnt/out.c
=======
eval: eval.yy.c
	clang ./intr/eval.tab.c ./intr/eval.yy.c -o ./build/expr

eval.yy.c: eval.tab.c
	flex --outfile=./intr/eval.yy.c ./expr_eval/eval.lex

eval.tab.c:
	yacc -d ./expr_eval/eval.y -o ./intr/eval.tab.c

srp:
ll:
asm:
robin:
lruf:
bank:
>>>>>>> 9c3ad91f1b0df939a6cd213df87aaf093825e659
