#pragma once
#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;

struct CNode
{
	int data;
	CNode* next;
};

class MyStack
{
	CNode* first;
	CNode* last;

public:

	MyStack();
	~MyStack();

	void push(int);
	void pop();
	int top();
	bool empty();
	int min();
};
