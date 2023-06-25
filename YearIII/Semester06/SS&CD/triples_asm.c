#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream inputFile("./inputs/asmin.c");
	ofstream outputFile("./inputs/asmout.a");

	string op, arg1, arg2, result;
	while (inputFile >> result >> arg1 >> op >> arg2) {
		switch (op[0]) {
			case '+':
				outputFile << "\nMOV R0," << arg1;
				outputFile << "\nADD R0," << arg2;
				outputFile << "\nMOV " << result << ",R0";
				break;
			case '*':
				outputFile << "\nMOV R0," << arg1;
				outputFile << "\nMUL R0," << arg2;
				outputFile << "\nMOV " << result << ",R0";
				break;
			case '-':
				outputFile << "\nMOV R0," << arg1;
				outputFile << "\nSUB R0," << arg2;
				outputFile << "\nMOV " << result << ",R0";
				break;
			case '/':
				outputFile << "\nMOV R0," << arg1;
				outputFile << "\nDIV R0," << arg2;
				outputFile << "\nMOV " << result << ",R0";
				break;
			case '=':
				outputFile << "\nMOV R0," << arg1;
				outputFile << "\nMOV " << result << ",R0";
				break;
			default:
				break;
		}
	}

	inputFile.close();
	outputFile.close();
	return 0;
}