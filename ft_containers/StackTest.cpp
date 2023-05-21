#include <iostream>
#include <stack>
#include "Stack.hpp"
#include "test.hpp"

template <typename T>
static void print_origin_my_fun(std::string const &str, T ori_value, T my_value)
{
	std::cout << GREEN << "ori " << str << " = " << ori_value << RESET;
	std::cout << RED << " my " << str << " = " << my_value << RESET << std::endl;
}

static void print_origin_my_fun(std::string const &str, bool ori_value, int my_value)
{
	std::cout << GREEN <<"ori " << str << " = " << ori_value << RESET;
	std::cout << RED << " my " << str << " = " << my_value << RESET << std::endl;
}

void stack_test(void)
{
	std::stack<int> ost;
	ft::Stack<int> mst;

	twoline("empty");

	std::cout << std::boolalpha;

	print_origin_my_fun("empty", ost.empty(), mst.empty());
	print_origin_my_fun("size", ost.size(), mst.size());

	twoline("push");

	oneline("push 100 to 500");

	for (int i = 1; i <= 5; i++)
	{
		ost.push(i * 100);
		mst.push(i * 100);
	}

	print_origin_my_fun("size", ost.size(), mst.size());

	oneline("top");

	print_origin_my_fun("top", ost.top(), mst.top());

	oneline("pop");

	ost.pop();
	mst.pop();

	print_origin_my_fun("size", ost.size(), mst.size());
	print_origin_my_fun("top", ost.top(), mst.top());

	oneline("pop 3times");

	for (int i = 0; i < 3; i++)
	{
		ost.pop();
		mst.pop();
	}

	print_origin_my_fun("size", ost.size(), mst.size());
	print_origin_my_fun("top", ost.top(), mst.top());

	oneline("pop last");

	ost.pop();
	mst.pop();

	print_origin_my_fun("size", ost.size(), mst.size());
	//print_origin_my_fun("top", ost.top(), mst.top());

}
