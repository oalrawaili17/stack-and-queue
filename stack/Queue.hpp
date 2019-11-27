#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.hpp"
//Exceptions class
class QueueUnderflow
{
public:
	QueueUnderflow() {};
};
template <class T>
class ListQueue
{
private:
	LinkedList<T> queueList;

public:
	ListQueue() {};
	void enqueue(T elem)
	{
		queueList.addLast(elem);
	}
	T dequeue()
	{
		if (isEmpty())
		{
			throw QueueUnderflow();
		}
		return queueList.removeFirst();
	}
	T first()
	{
		if (isEmpty())
		{
			throw QueueUnderflow();
		}
		return queueList.getFirst();
	}
	int size()
	{
		return queueList.getSize();
	}
	bool isEmpty()
	{
		return queueList.getSize() < 1;
	}
	//print first n elements of the queue
	void printRange(int n)
	{
		queueList.printRange(n);
	}
};
#endif