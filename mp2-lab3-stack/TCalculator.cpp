#include "TCalculator.h"
#include <string>

using namespace std;

TCalculator::TCalculator(string _expr){
	expr = _expr;
}

void TCalculator::calcPostfix(){
	for(int i = 0; i < expr.size(); i++){
		if(expr[i] <= '9' && expr[i] >= '0'){
			stack_int.push(stod(&expr[i]));
		}

		if(isOperator(expr[i])){
			double a = stack_int.pop();
			double b = stack_int.pop();
			switch(expr[i]){
			case '+':
				stack_int.push(a + b);
				break;
			case '-':
				stack_int.push(b - a);
				break;
			default:
				throw "operation is not supported!!!";
				break;
			}
		}
	}
}

string TCalculator::convert(string input){
	string output = "";

	input = addBrackets(input);

	stack_char.cleaning();

	for(int i = 0; i < input.size(); i++){
		if(input[i] <= '9' && postfix[i] >= '1'){
			output += input[i] + ' ';
		}

		if(input[i] == '('){
			stack_char.push('(');
		}

		if(input[i] == ')'){
			while(stack_char.top() != '('){
				output += stack_char.pop() + ' ';
			}

			stack_char.pop();
		}

		if(isOperator(input[i])){
			while(Priority(stack_char.top()) <= Priority(input[i])){
				output += stack_char.pop() + ' ';
			}

			stack_char.push(input[i]);
		}
	}

	return output;
}

string TCalculator::addBrackets(string input){
	return '(' + input + ')';
}

int TCalculator::Priority(char op){
	switch(op){
	case '/':
	case '*':
		return 3;
	case '-':
	case '+':
		return 2;
	case '(':
		return 1;
	default:
		throw "operation is not supported!!!";
		break;
	}
}

bool TCalculator::isOperator(char op){
	return op == '+' || op == '-' || op == '/' || op == '*';
}

bool TCalculator::isFunction(string func){
	return func == "cos";
}

double TCalculator::calc(){
	string input = addBrackets(expr);
	//clear stack

	for(int i = 0; i < input.size(); i++){
		if(input[i] >= '0' && input[i] <= '9'){
			size_t ind;
			double num = stod(&input[i], &ind);
			stack_int.push(num);
			i += ind - 1;
		}

		if(input[i] == '('){
			stack_char.push('(');
		}

		if(input[i] == ')'){
			while(stack_char.top() != '('){
				double a = stack_int.pop();
				double b = stack_int.pop();
				switch(stack_char.pop()){
				case '+':
					stack_int.push(a + b);
					break;
				case '-':
					stack_int.push(b - a);
					break;
				case '*':
					stack_int.push(b * a);
					break;
				case '/':
					stack_int.push(b / a);
					break;
				default:
					throw "operation is not supported!!!";
					break;
				}
			}
			stack_char.pop();
		}

		if(isOperator(input[i])){
			while(Priority(stack_char.top()) >= Priority(input[i])){
				double a = stack_int.pop();
				double b = stack_int.pop();
				switch(stack_char.pop()){
				case '+':
					stack_int.push(a + b);
					break;
				case '-':
					stack_int.push(b - a);
					break;
				case '*':
					stack_int.push(b * a);
					break;
				case '/':
					stack_int.push(b / a);
					break;
				default:
					throw "operation is not supported!!!";
					break;
				}
			}

			stack_char.push(input[i]);
		}
	}

	return stack_int.pop();
}