#include <gtest/gtest.h>
#include "Stack.h"

TEST(myStack, can_create_empty_stack)
{
	MyStack s;
	EXPECT_TRUE(s.empty());
}

TEST(myStack, can_push_and_get_top_elem)
{
	MyStack s;
	s.push(5);
	s.push(10);
	EXPECT_EQ(10, s.top());
}

TEST(myStack, cannot_use_top_for_empty_stack)
{
	MyStack s;
	EXPECT_ANY_THROW(s.top());
}

TEST(myStack, can_pop_and_empty_stack_test)
{
	MyStack s;
	s.push(5);
	s.push(10);
	s.pop();
	s.pop();
	EXPECT_TRUE(s.empty());
}

TEST(myStack, not_empty_stack_test)
{
	MyStack s;
	s.push(5);
	s.push(10);
	s.pop();
	EXPECT_FALSE(s.empty());
}

TEST(myStack, cannot_use_pop_for_empty_stack)
{
	MyStack s;
	EXPECT_ANY_THROW(s.pop());
}

TEST(myStack, correct_search_min_element_in_sorted_stack)
{
	MyStack s;
	int min_elem = 0;
	for (int i = 5; i < 10; ++i)
		s.push(i);
	min_elem = s.min();
	EXPECT_EQ(5, min_elem);
}

TEST(myStack, correct_search_min_element_in_unsorted_stack)
{
	MyStack s;
	int min_elem = 0;
	s.push(5);
	s.push(7);
	s.push(2);
	s.push(10);
	s.push(4);
	s.push(3);
	min_elem = s.min();
	EXPECT_EQ(2, min_elem);
}

int main(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}