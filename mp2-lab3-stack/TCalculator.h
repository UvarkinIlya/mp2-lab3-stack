#pragma once

#include <string> 
#include "TStack.h"

//using namespace std;

class TCalculator{
	std::string expr;
	std::string postfix;
	TStack<std::string> stack_char;
	TStack<double> stack_int;

	int Priority(std::string op);//Определяем приорите операции
	bool isOperator(std::string);
	bool isFunction(std::string, int);
	std::string getFunction(std::string input, int start);
	std::string addBrackets(std::string input);

public:
	TCalculator(std::string _expr);
	void calcPostfix();
	std::string convert(std::string input);
	double calc(int x = 0);
};

