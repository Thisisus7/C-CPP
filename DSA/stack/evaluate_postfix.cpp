#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool operator_check(char c){
	if (c == '+' || c == '-' || c == '*' || c == '/')
			return true;
	return false;
}

bool number_check(char c){
	if (c >= '0' && c<= '9') return true;

	return false;
}

int perform_operation(char operation, int operand1, int operand2){
	if (operation == '+') return operand1 + operand2;
	else if (operation == '-') return operand1 - operand2;
	else if (operation == '*') return operand1 * operand2;
	else if (operation == '/') return operand1 / operand2;

	else cout << "unexpected Error" << endl;
	return -1;
}
// for eval_prefix, we should scan from right to left
int eval_postfix(string exp){
	stack<int> S;

	for (int i=0; i<exp.length(); i++){
		if (exp[i] == ' ' || exp[i] == ',') continue;
		// if char is operator, pop two elements from stack, perform operation and push result back
		else if (operator_check(exp[i])){
			int operand2 = S.top(); S.pop();
			int operand1 = S.top(); S.pop();

			int result = perform_operation(exp[i], operand1, operand2);
			S.push(result);
		}
		else if (number_check(exp[i])){
			int operand = 0;
			while (i < exp.length() && number_check(exp[i])){
				// for number with more than 1 digit, as we are scanning from left to right
				// 10 times current operand and add the new operand
				operand = operand * 10 + (exp[i] - '0');
				i++;
			}	
			i--;  // back 1 position
			S.push(operand);
		}
	}
	return S.top();
}

int main(){
	string expression;
	cout << "Enter Postfix Expression" << endl;
	getline(cin, expression);  // e.g. 1 2 * or 1,2 *
	int result = eval_postfix(expression);
	cout << "Output = " << result << endl;
}
