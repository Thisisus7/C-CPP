#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool pair_check(char open, char close){
	if (open == '(' && close == ')') return true;
	else if (open == '[' && close == ']') return true;
	else if (open == '{' && close == '}') return true;
	return false;
}

bool balanced_cheack(string exp){
	stack<char> S;

	for (int i=0; i<exp.length(); i++){
		if (exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
			S.push(exp[i]);
		else if (exp[i]==')' || exp[i]==']' || exp[i]=='}'){
			if (S.empty() || !pair_check(S.top(), exp[i]))
				return false;
			else
				S.pop();
		}
	}
	return S.empty() ? true:false;	
}

int main(){
	string expression;
	cout << "Enter an expression: ";
	cin >> expression;
	if (balanced_cheack(expression))
		cout << "Balanced" << endl;
	else
		cout << "Not Balanced" << endl;
}
