#include "TCalculator.h"

void main(){
	TCalculator calc("8+2*x+cos(7*x)");
	double res = calc.calc(5);
	double x = 8 + 2 * 5 + cos(7 * 5);

	cout << res << "   " << x;
	
	system("pause");
}