#include "TCalculator.h"

void main(){
	TCalculator calc("tg(sin(5)/cos(5))");
	double res = calc.calc();
	double x = tan(sin(5) / cos(5));

	cout << res << "   " << x;
	
	system("pause");
}