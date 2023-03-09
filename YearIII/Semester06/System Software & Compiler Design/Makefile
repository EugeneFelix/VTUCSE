eval: eval.yy.c
	clang ./expr_eval/eval.tab.c ./expr_eval/eval.yy.c -o expr -lfl

eval.yy.c: eval.tab.c
	flex -o ./expr_eval/eval.lex ./expr_eval/eval.yy.c

eval.tab.c:
	yacc -d ./expr_eval/eval.y -o ./expr_eval/eval.tab.c
