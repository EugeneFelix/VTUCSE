#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> productions = {
	"A->aBa",
	"B->bB",
	"B->@"
};
string inputString;
vector<char> stack;
size_t inputIndex = 0;

void pushProduction(char nonTerminal) {
	int productionIndex = (nonTerminal == 'A') ? 0 : 1;
	stack.pop_back();
	for (int i = productions[productionIndex].size() - 1; i >= 3; --i)
		stack.push_back(productions[productionIndex][i]);
}

void validateInputString() {
	for (char c : inputString) {
		if (c != 'a' && c != 'b' && c != '$') {
			cout << "Invalid string" << endl;
			exit(0);
		}
	}
	if (inputString.back() != '$') {
		cout << "\n\nInput string entered without end marker $\n";
		exit(0);
	}
}

void checkAcceptance() {
	if (stack.back() == '$' && inputString[inputIndex] == '$')
		cout << "\n$\t$\nString Accepted\n";
	else
		cout << "\nString rejected\n";
}

int main() {
	inputString = "abba$";
	validateInputString();
	stack = {'$', 'A'};
	cout << "\n\nstack\tInput\taction\n\n----------------------\n";
	while (inputIndex != inputString.size() && stack.back() != '$') {
		cout << endl;
		for (auto it = stack.rbegin(); it != stack.rend(); ++it)
			cout << *it;
		cout << "\t";
		cout << inputString.substr(inputIndex);
		cout << "\t";

		if (stack.back() == 'A') {
			cout << "A->aBa";
			pushProduction('A');
		} else if (stack.back() == 'B') {
			if (inputString[inputIndex] == 'b') {
				cout << "B->bB";
				pushProduction('B');
			} else {
				cout << "B->@\tMatched @";
				stack.pop_back();
			}
		} else {
			if (stack.back() == inputString[inputIndex]) {
				cout << "POP " << inputString[inputIndex] << "\tMatched " << inputString[inputIndex];
				stack.pop_back();
				++inputIndex;
			} else
				break;
		}
	}

	checkAcceptance();
	return 0;
}