#include "TCalculator.h"

int main(){
	TCalculator calc("2+2");
	double res = calc.calc();
	double expected = 2.0 + 2.0;
	
	system("pause");
	return 0;
}