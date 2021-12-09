#include "../mp2-lab3-stack/TCalculator.h"

#include "gtest.h"

TEST(TCalculator, can_create_calculator){
	ASSERT_NO_THROW(TCalculator(""));
}

TEST(TCalculator, can_add_two_positive){
	TCalculator expression("2+2");
	double res = expression.calc();
	double expected = 2.0 + 2.0;

	EXPECT_EQ(res, expected);
}

TEST(TCalculator, can_subtraction_two_positive){
	TCalculator expression("2-2");
	double res = expression.calc();;
	double expected = 2.0 - 2.0;

	EXPECT_EQ(res,expected);
}

TEST(TCalculator,can_multiply_two_positive){
	TCalculator expression("2*3");
	double res = expression.calc();;
	double expected = 2.0 * 3.0;

	EXPECT_EQ(res,expected);
}

TEST(TCalculator,can_divide_two_positive){
	TCalculator expression("3 / 2");
	double res = expression.calc();;
	double expected = 3.0 / 2.0;

	EXPECT_EQ(res,expected);
}

TEST(TCalculator,can_not_divide_to_null){
	TCalculator expression("3 / 0");

	EXPECT_ANY_THROW(expression.calc());
}

TEST(TCalculator, can_calculate_sin){
	TCalculator expression("sin(3)");
	double res = expression.calc();;
	double expected = sin(3);

	EXPECT_EQ(res,expected);
}

TEST(TCalculator,can_calculate_cos){
	TCalculator expression("cos(3)");
	double res = expression.calc();;
	double expected = cos(3);

	EXPECT_EQ(res,expected);
}

TEST(TCalculator,can_calculate_tg){
	TCalculator expression("tg(3)");
	double res = expression.calc();;
	double expected = tan(3);

	EXPECT_EQ(res,expected);
}

TEST(TCalculator,can_calculate_ctg){
	TCalculator expression("ctg(3)");
	double res = expression.calc();;
	double expected = 1 / tan(3);

	EXPECT_EQ(res,expected);
}

TEST(TCalculator,can_calculate_with_brackets){
	TCalculator expression("(2+2)/3+4-(7*8+2)");
	double res = expression.calc();;
	double expected = (2.0 + 2.0) / 3.0 + 4.0 - (7.0 * 8.0 + 2.0);

	EXPECT_EQ(res,expected);
}

TEST(TCalculator, can_not_calculate_with_wrong_brackets){
	TCalculator expression("(2+3))");

	ASSERT_ANY_THROW(expression.calc());
}

TEST(TCalculator,can_calculate_difficult_1){
	TCalculator expression("cos(5)/7+sin(15+8*3)");
	double res = expression.calc();;
	double expected = cos(5.0) / 7.0 + sin(15.0 + 8.0 * 3.0);

	EXPECT_EQ(res,expected);
}

TEST(TCalculator,can_calculate_difficult_2){
	TCalculator expression("cos(sin(7+2*3))");
	double res = expression.calc();;
	double expected = cos(sin(7.0 + 2.0 * 3.0));

	EXPECT_EQ(res,expected);
}

TEST(TCalculator,can_calculate_simple_with_x_1){
	TCalculator expression("x+2");
	double res = expression.calc(5);;
	double expected = 5.0 + 2.0;

	EXPECT_EQ(res,expected);
}

TEST(TCalculator,can_calculate_simple_with_x_2){
	TCalculator expression("5*x");
	double res = expression.calc(10);;
	double expected = 5.0 * 10.0;

	EXPECT_EQ(res,expected);
}

TEST(TCalculator, can_calculate_difficult_with_x_1){
	TCalculator expression("cos(sin(x + 2 * 3 * x))");
	double res = expression.calc(10);;
	double expected = cos(sin(10.0 + 2.0 * 3.0 * 10.0));

	EXPECT_EQ(res,expected);
}

TEST(TCalculator,can_calculate_difficult_with_x_2){
	TCalculator expression("cos(80*x+x)*sin(cos(x*x))");
	double res = expression.calc(5);;
	double expected = cos(80.0 * 5.0 + 5.0) * sin(cos(5.0 * 5.0));

	EXPECT_EQ(res,expected);
}