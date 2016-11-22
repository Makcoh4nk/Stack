#include "Stack.h"

MyStack::MyStack()
{
	first = NULL;
	last = NULL;
}

MyStack::~MyStack()
{
	while (first != last)
	{
		CNode* temp = last;
		last = temp->next;

		temp->next = NULL;
		temp = NULL;
		delete temp;
	}
	first = NULL;
	last = NULL;
}

void MyStack::push(int data)
{
	CNode* temp = new CNode;
	temp->data = data;

	if (first != NULL)
	{
		temp->next = last;

		last = temp;
	}
	else
	{
		temp->next = NULL;
		first = last = temp;
	}
}

void MyStack::pop()
{
	if (!empty())
	{
		if (last == first)
		{
			last = NULL;
			first = NULL;
			return;
		}
		CNode* temp = last;

		last = temp->next;
		temp->next = NULL;
	}
	else
		throw 1;
}

int MyStack::top()
{
	if (!empty())
	{
		return last->data;
	}
	else
		throw 1;
}

bool MyStack::empty()
{
	if ((first == NULL) && (last == NULL))
		return true;
	else
		return false;
}

int MyStack::min()
{
	int imin;
	CNode* temp = last;
	if (!empty())
	{
		imin = temp->data;
		temp = temp->next;

		while (temp != NULL)
		{
			if (temp->data < imin)
				imin = temp->data;
			temp = temp->next;
		}
		return imin;
	}
	else
		throw 1;
}


