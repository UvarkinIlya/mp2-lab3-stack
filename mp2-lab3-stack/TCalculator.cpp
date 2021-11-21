#include "TCalculator.h"
#include <string>


using namespace std;

double TCalculator::calcPostfix(){
	for(int i = 0; i < postfix.size(); i++){
		if(postfix[i] <= '9' && postfix[i] >= '1'){
			stack_int.push(stod(&postfix[i]));
		}

		if(postfix[i] == '+' || postfix[i] == '-'){
			double a = stack_int.pop();
			double b = stack_int.pop();
			switch(postfix[i]){
			case '+':
				stack_int.push(a + b);
				break;
			case '-':
				stack_int.push(b - a);
				break;
			default:
				throw 0;
				break;
			}
		}
	}

	return stack_int.pop();
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

		if(isOpertor(input[i])){
			while(Priority(stack_char.top()) <= Priority(input[i])){
				output += stack_char.pop() + ' ';
			}

			stack_char.push(input[i]);
		}
	}

	return output;
}

string addBrackets(string input){
	return '(' + input + ')';
}

bool isOperator(char){
	return	true;
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
				default:
					throw 0;
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
				default:
					throw 0;
					break;
				}
			}

			stack_char.push(input[i]);
		}
	}

	return stack_int.pop();
}