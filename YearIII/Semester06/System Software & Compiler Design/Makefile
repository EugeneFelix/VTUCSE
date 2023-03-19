eval: eval.yy.c
	clang ./expr_eval/eval.tab.c ./expr_eval/eval.yy.c -o ./build/expr -lfl

eval.yy.c: eval.tab.c
	flex --outfile=./expr_eval/eval.yy.c ./expr_eval/eval.lex

eval.tab.c:
	yacc -d ./expr_eval/eval.y -o ./expr_eval/eval.tab.c
