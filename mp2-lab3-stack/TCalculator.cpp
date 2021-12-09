#include "TCalculator.h"
#include <string>

//using namespace std;

TCalculator::TCalculator(std::string _expr = ""){
	expr = _expr;
}

void TCalculator::calcPostfix(){
	for(unsigned int i = 0; i < expr.size(); i++){
		if(expr[i] <= '9' && expr[i] >= '0'){
			stack_int.push(std::stod(&expr[i]));
		}

		if(isOperator(std::string(1, expr[i]))){
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

std::string TCalculator::convert(std::string input){
	std::string output = "";

	input = addBrackets(input);

	stack_char.cleaning();

	for(unsigned int i = 0; i < input.size(); i++){
		if(input[i] <= '9' && postfix[i] >= '1'){
			output += input[i] + ' ';
		}

		if(input[i] == '('){
			stack_char.push("(");
		}

		if(input[i] == ')'){
			while(stack_char.top() != "("){
				output += stack_char.pop() + ' ';
			}

			stack_char.pop();
		}

		if(isOperator(std::string(1, input[i]))){
			while(Priority(stack_char.top()) <= Priority(std::string(1, input[i]))){
				output += stack_char.pop() + ' ';
			}

			stack_char.push(std::string(1, input[i]));
		}
	}

	return output;
}

std::string TCalculator::addBrackets(std::string input){
	return '(' + input + ')';
}

int TCalculator::Priority(std::string op){
	if(op == "cos" || op == "sin" || op == "tg" || op == "ctg"){
		return 4;
	} else if(op == "*" || op == "/"){
		return 3;
	} else if(op == "+" || op == "-"){
		return 2;
	} else if(op == "("){
		return 1;
	} else{
		throw "operation is not supported!!!";
	}

	/*switch(op){
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
	}*/
}

bool TCalculator::isOperator(std::string op){
	return op == "+" || op == "-" || op == "/" || op == "*";
}

bool TCalculator::isFunction(std::string input, int start){
	std::string func = "";
	int i = start;

	while (input[i] != '(' && (input[i] >= 'a' && input[i] <= 'z')){
		func += input[i++];
	}

	return func == "cos" || func == "sin" || func == "tg" || func =="ctg";
}

std::string TCalculator::getFunction(std::string input, int start){
	std::string func = "";
	int i = start;

	while(input[i] != '('){
		func += input[i++];
	}

	return func;
}

double TCalculator::calc(int x){
	std::string input = addBrackets(expr);
	//clear stack

	for(unsigned int i = 0; i < input.size(); i++){
		if(input[i] >= 'x'){
			stack_int.push(x);
			continue;
		}

		if(input[i] >= '0' && input[i] <= '9'){
			size_t ind;
			double num = std::stod(&input[i], &ind);
			stack_int.push(num);
			i += ind - 1;
			continue;
		}

		if(input[i] == '('){
			stack_char.push("(");
			continue;
		}

		if(input[i] == ')'){
			while(stack_char.top() != "("){
				double a = stack_int.pop();
				if(stack_char.top() == "sin"){
					stack_int.push(sin(a));
					stack_char.pop();
					continue;
				} else if(stack_char.top() == "cos"){
					stack_int.push(cos(a));
					stack_char.pop();
					continue;
				} else if(stack_char.top() == "tg"){
					stack_int.push(tan(a));
					stack_char.pop();
					continue;
				} else if(stack_char.top() == "ctg"){
					stack_int.push(1/tan(a));
					stack_char.pop();
					continue;
				}
				double b = stack_int.pop();
				if(stack_char.top() == "+"){
					stack_int.push(a + b);
				} else if(stack_char.top() == "-"){
					stack_int.push(b - a);
				} else if (stack_char.top() == "*"){
					stack_int.push(b * a);
				} else if(stack_char.top() == "/"){
					if(a == 0.0){
						throw "cannot be divided by zero!";
					}
					stack_int.push(b / a);
				} else{
					throw "operation is not supported!!!";
				}
				stack_char.pop();

				/*switch(stack_char.pop()){
				case "+":
					stack_int.push(a + b);
					break;
				case "-":
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
				}*/
			}
			stack_char.pop();
			continue;
		}

		if(isOperator(std::string(1, input[i]))){
			std::string opr(1, input[i]);

			while(Priority(stack_char.top()) >= Priority(opr)){
				double a = stack_int.pop();
				if(stack_char.top() == "sin"){
					stack_int.push(sin(a));
					stack_char.pop();
					continue;
				} else if(stack_char.top() == "cos"){
					stack_int.push(cos(a));
					stack_char.pop();
					continue;
				} else if(stack_char.top() == "tan"){
					stack_int.push(tan(a));
					stack_char.pop();
					continue;
				} else if(stack_char.top() == "ctg"){
					stack_int.push(1 / tan(a));
					stack_char.pop();
					continue;
				}
				double b = stack_int.pop();
				if(stack_char.top() == "+"){
					stack_int.push(a + b);
				} else if(stack_char.top() == "-"){
					stack_int.push(b - a);
				} else if(stack_char.top() == "*"){
					stack_int.push(b * a);
				} else if(stack_char.top() == "/"){
					if(a == 0.0){
						throw "cannot be divided by zero!";
					}
					stack_int.push(b / a);
				} else{
					throw "operation is not supported!!!";
				}
				stack_char.pop();
			}

			stack_char.push(opr);
			continue;
		}

		if(isFunction(input, i)){
			std::string func = getFunction(input, i);
			stack_char.push(func);
			i += func.size();
			stack_char.push("(");
			continue;
		}
	}

	double ans = stack_int.pop();
	if(!stack_int.empty()){
		throw "error!!!";
	}

	return ans;
}