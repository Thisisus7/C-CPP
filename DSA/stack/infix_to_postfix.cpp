#include<iostream>
#include<stack>
#include<string>
using namespace std;

int has_higher_precedence(char op1, char op2);
bool number_check(char c);
bool operator_check(char c);
int is_right_associative(char op);
int operator_weight(char op);
string infix_to_postfix(string expression);

int main(){
	string expression; 
	cout << "Enter Infix Expression \n";
	getline(cin,expression);
	string postfix = infix_to_postfix(expression);
	cout << "Output = " << postfix << endl;	
}

string infix_to_postfix(string expression){
	stack<char> S;
	string postfix = "";  // initialize postfix as empty string
	for (int i=0; i<expression.length(); i++){
		if (expression[i] == ' ' || expression[i] == ',') continue;

		else if (operator_check(expression[i])){
			while(!S.empty() && S.top() != '(' && has_higher_precedence(S.top(),expression[i])){
				postfix += S.top();
				S.pop();
			}
			S.push(expression[i]);
		}
		else if (number_check(expression[i])){
			postfix += expression[i];
		}
		// if (: push it into stack
		else if (expression[i] == '(') {
			S.push(expression[i]);
		}
		// if ): pop top of the stack until top is '('
		else if(expression[i] == ')') {
			while(!S.empty() && S.top() !=  '(') {
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
	}
	while(!S.empty()) {
		postfix += S.top();
		S.pop();
	}
	return postfix;
}

int has_higher_precedence(char op1, char op2)
{
	int op1Weight = operator_weight(op1);
	int op2Weight = operator_weight(op2);

	// If operators have equal precedence, return true if they are left associative. 
	// return false, if right associative. 
	// if operator is left-associative, left one should be given priority. 
	if(op1Weight == op2Weight)
	{
		if(is_right_associative(op1)) return false;
		else return true;
	}
	return op1Weight > op2Weight ?  true: false;
}

// operator with higher weight will have higher precedence
int operator_weight(char op)
{
	int weight = -1; 
	switch(op){
	case '+':
	case '-':
		weight = 1;
	case '*':
	case '/':
		weight = 2;
	case '$':
		weight = 3;
	}
	return weight;
}

// whether an operator is right associative or not
int is_right_associative(char op){
	if(op == '$') return true;
	return false;
}

bool operator_check(char c){
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '$')
			return true;
	return false;
}

bool number_check(char c){
	if (c >= '0' && c<= '9') return true;
	else if (c >= 'a' && c<= 'z') return true;
	else if (c >= 'A' && c<= 'Z') return true;

	return false;
}
