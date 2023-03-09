eval: eval.yy.c
	clang ./expr_eval/eval.tab.c ./lex.yy.c -o expr -lfl

eval.yy.c: eval.tab.c
	flex ./expr_eval/eval.lex

eval.tab.c:
	yacc -d ./expr_eval/eval.y -o ./expr_eval/eval.tab.c
