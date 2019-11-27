#pragma once
#ifndef STACK_H
#define STACK_H
#include "LinkedList.hpp"
template <class T>
class ListStack
{
private:
	LinkedList<T> stackList;

public:
	ListStack() {};
	void push(T elem)
	{
		stackList.addFirst(elem);
	}
	T pop()
	{
		return stackList.removeFirst();
	}
	T peek()
	{
		return stackList.getFirst();
	}
	int size()
	{
		return stackList.getSize();
	}
	bool isEmpty()
	{
		return stackList.getSize() < 1;
	}
	//print first n elements of the stack
	void printRange(int n)
	{
		stackList.printRange(n);
	}
};
#endif