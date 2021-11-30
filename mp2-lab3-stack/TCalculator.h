#pragma once

#include <string> 
#include "TStack.h"

using namespace std;

class TCalculator{
	string expr;
	string postfix;
	TStack<char> stack_char;
	TStack<double> stack_int;

	int Priority(char op);//Определяем приорите операции
	bool isOperator(char);
	bool isFunction(string);
	string addBrackets(string input);

public:
	TCalculator(string _expr);
	void calcPostfix();
	string convert(string input);
	double calc();
private:
	
};

