#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> productions = {
	"A->aBa",
	"B->bB",
	"B->@"
};
string inp;
vector<char> stack;
size_t input_idx = 0;

void pushProduction(char nonTerminal) {
	int productionIndex = (nonTerminal == 'A') ? 0 : 1;
	stack.pop_back(); // Remove NT
	for (int i = productions[productionIndex].size() - 1; i >= 3; --i)
		stack.push_back(productions[productionIndex][i]);
}

void validateinp() {
	for (char c : inp) {
		if (c != 'a' && c != 'b' && c != '$') {
			cout << "Invalid string" << endl;
			exit(0);
		}
	}
	if (inp.back() != '$') {
		cout << "\n\nInput string entered without end marker $\n";
		exit(0);
	}
}

void checkAcceptance() {
	if (stack.back() == '$' && inp[input_idx] == '$')
		cout << "\n$\t$\nString Accepted\n";
	else
		cout << "\nString rejected\n";
}

int main(int argc, char **argv) {
	if (argc < 2) {
		cout << "Incorrect usage, please enter string to parse as\n\t" << argv[0] << " " << "\"string\"";
		return -1;
	}
	inp = argv[1];
	validateinp();
	stack = {'$', 'A'};
	cout << "\n\nstack\tInput\taction\n\n----------------------\n";
	while (input_idx != inp.size() && stack.back() != '$') {
		cout << endl;
		for (vector<char>::reverse_iterator it = stack.rbegin(); it != stack.rend(); ++it)
			cout << *it;
		cout << "\t";
		cout << inp.substr(input_idx);
		cout << "\t";

		char stackTop = stack.back();
		char inputChar = inp[input_idx];
		switch (stackTop) {
			case 'A':
				cout << "A->aBa";
				pushProduction('A');
				break;
			case 'B':
				switch (inputChar) {
					case 'b':
						cout << "B->bB";
						pushProduction('B');
						break;
					default:
						cout << "B->@\tMatched @";
						stack.pop_back();
						break;
				}
				break;
			default:
				if (stackTop == inputChar) {
					cout << "POP " << inputChar << "\tMatched " << inputChar;
					stack.pop_back();
					++input_idx;
				} else {
					break;
				}
				break;
		}
	}

	checkAcceptance();
	return 0;
}