#include <iostream>
#include <string>
#include <stack>

class CFGParser {
private:
	std::string startSymbol;
	std::string endMarker;
	std::stack<char> stack;

public:
	CFGParser(const std::string& start, const std::string& end) : startSymbol(start), endMarker(end) {}

	bool parse(const std::string& input) {
		stack.push('$');
		stack.push(startSymbol[0]);
		size_t inputIndex = 0;
		while (!stack.empty()) {
			char top = stack.top();
			stack.pop();
			if (top == endMarker[0] && input[inputIndex] == endMarker[0]) {
				return true;
			} else if (top == input[inputIndex])
				inputIndex++;
			} else if (isNonTerminal(top)) {
				if (!expandNonTerminal(top)) {
					return false;
				}
			} else {
				return false;
			}
		}

		return false;
	}

private:
	bool isNonTerminal(char symbol) {
		return symbol >= 'A' && symbol <= 'Z';
	}

	bool expandNonTerminal(char symbol) {
		switch (symbol) {
			case 'A':
				stack.push('a');
				stack.push('B');
				stack.push('a');
				break;
			case 'B':
				stack.push('b');
				stack.push('B');
				break;
			default:
				return false;
		}

		return true;
	}
};

int main() {
	std::string input = "abba";
	CFGParser parser("A", "$");

	if (parser.parse(input)) {
		std::cout << "Valid string accepted!" << std::endl;
	} else {
		std::cout << "Invalid string rejected!" << std::endl;
	}

	return 0;
}
