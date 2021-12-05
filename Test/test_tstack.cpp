#include "../mp2-lab3-stack/TStack.h"

#include "gtest.h"

TEST(TStack, can_create_stack_with_positive_size){
  ASSERT_NO_THROW(TStack<int> stack(5));
}

TEST(TStack, can_not_create_stack_with_negative_size){
	ASSERT_ANY_THROW(TStack<int> stack(-1));
}

TEST(TStack, can_add_to_stack){
	TStack<int> stack;
	stack.push(4);

	EXPECT_EQ(stack.top(), 4);
}

TEST(TStack, can_not_add_to_full_stack){
	int size = 5;
	TStack<int> stack(size);
	
	for(int i = 0; i < size; i++){
		stack.push(i);
	}

	ASSERT_ANY_THROW(stack.push(5));
}

TEST(TStack, can_pop_to_not_empty_stack){
	int size = 5;
	TStack<int> stack(size);

	stack.push(3);

	EXPECT_EQ(stack.pop(), 3);
}

TEST(TStack, can_not_pop_to_empty_stack){
	int size = 5;
	TStack<int> stack(size);

	ASSERT_ANY_THROW(stack.pop());
}

TEST(TStack, can_get_top_to_stack){
	int size = 5;
	TStack<int> stack(size);

	stack.push(3);

	EXPECT_EQ(stack.top(), 3);
}

TEST(TStack, can_not_get_top_to_empty_stack){
	int size = 5;
	TStack<int> stack(size);

	ASSERT_ANY_THROW(stack.top());
}

TEST(TStack, can_cleaning_stack){
	int size = 5;
	TStack<int> stack(size);

	for(int i = 0; i < size; i++){
		stack.push(i);
	}

	stack.cleaning();

	ASSERT_ANY_THROW(stack.top());
}

