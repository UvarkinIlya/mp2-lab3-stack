#pragma once

#include <string> 
#include "TStack.h"

using namespace std;

class TCalculator{
	string expr;
	string postfix;
	TStack<string> stack_char;
	TStack<double> stack_int;

	int Priority(string op);//Определяем приорите операции
	bool isOperator(string);
	bool isFunction(string, int);
	string getFunction(string input, int start);
	string addBrackets(string input);

public:
	TCalculator(string _expr);
	void calcPostfix();
	string convert(string input);
	double calc(int x = 0);
private:
	
};

