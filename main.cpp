// main.cpp  Andrew Levy  Matthew Puentes

#include "main.h"

int main(int argc, char* argv[]) {
	using namespace std;
	if (argc <= 1) {
		cout << "Please give at least one argument" << endl;
		exit(0);
	}

	for (int i = 1; i < argc; i++) {
		ifstream input;
		input.open(argv[i]);
		if (!input) {
			perror("unable to open file");
		}

		string readLine;
		while (true) {
			getline(input, readLine);
			if (readLine != "") {
				stringstream line;
				line << readLine;

				Rational first;
				Rational second;
				string oper;

				bool booleanReturn = false;
				cout << readLine << "\t: ";
				try {
					line >> first;
					bool booleanReturnValue = false;
					while (!line.eof()) {
						line >> second >> oper;
						if (booleanReturn) {
							throw operation_on_boolean_exception();
						}
						if (oper == "+") {
							first = (first + second);
						} else if (oper == "-") {
							first = (first - second);
						} else if (oper == "*") {
							first = (first * second);
						} else if (oper == "/") {
							if (second == 0) {
								throw devide_by_zero_exception();
							}
							first = (first / second);
						} else if (oper == "==") {
							booleanReturnValue = (first == second);
							booleanReturn = true;
						} else if (oper == "!=") {
							booleanReturnValue = (first != second);
							booleanReturn = true;
						} else if (oper == "<") {
							booleanReturnValue = (first < second);
							booleanReturn = true;
						} else if (oper == ">") {
							booleanReturnValue = (first > second);
							booleanReturn = true;
						} else if (oper == "<=") {
							booleanReturnValue = (first <= second);
							booleanReturn = true;
						} else if (oper == ">=") {
							booleanReturnValue = (first >= second);
							booleanReturn = true;
						}
						line >> std::ws;
					}
					if (booleanReturn) {
						if (booleanReturnValue)
							cout << "True" << endl;
						else
							cout << "False" << endl;
					} else
						cout << first << " (double:" << first.toDouble() << ")"
								<< endl;
				} catch (const invalid_input_exception& e) {
					cout << "Error: " << e.what() << endl;
				} catch (const devide_by_zero_exception& e) {
					cout << "Error: " << e.what() << endl;
				} catch (const operation_on_boolean_exception& e) {
					cout << "Error: " << e.what() << endl;
				}
			} else {
				break;
			}
		}

		input.close();
	}
	cout << "program finished" << endl;
	return 0;
}
