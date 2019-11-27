#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
template <class T>
class LinkedList
{
private:
	class Node
	{
	private:
		T element;
		Node* next = nullptr;
		Node* prev = nullptr;

	public:
		Node(Node* p, Node* n)
		{
			next = n;
			prev = p;
		}
		Node(Node* p, Node* n, T e)
		{
			element = e;
			next = n;
			prev = p;
		}
		Node(const Node& node)
		{
			element = node.element;
			next = node.next;
			prev = node.prev;
		}
		Node& operator=(const Node& node)
		{
			if (this != node)
			{
				element = node.element;
				next = node.next;
				prev = node.prev;
			}
			return *this;
		}
		T getElement()
		{
			return element;
		}
		void setElement(T* e)
		{
			element = e;
		}
		Node* getNext()
		{
			return next;
		}
		void setNext(Node* n)
		{
			next = n;
		}
		Node* getPrev()
		{
			return prev;
		}
		void setPrev(Node* p)
		{
			prev = p;
		}
	};
	Node* header = nullptr;
	Node* trailer = nullptr;
	Node* newNode = nullptr;
	int size;
	void addBetween(Node* prev, Node* next, T elem)
	{
		newNode = new Node(prev, next, elem);
		prev->setNext(newNode);
		next->setPrev(newNode);
		size++;
	}
	T remove(Node* node)
	{
		Node* next = node->getNext();
		Node* prev = node->getPrev();
		next->setPrev(prev);
		prev->setNext(next);
		T elem = node->getElement();
		size--;
		delete node;
		return elem;
	}
	Node* getNodeAt(int index) const
	{
		Node* currNode = header->getNext();
		for (int i = 0; i < index; i++)
		{
			currNode = currNode->getNext();
		}
		return currNode;
	}

public:
	LinkedList()
	{
		header = new Node(nullptr, nullptr);
		trailer = new Node(header, nullptr);
		header->setNext(trailer);
		size = 0;
	}
	//Copy constructors
	LinkedList(const LinkedList& lst)
	{
		header = new Node(nullptr, nullptr);
		trailer = new Node(header, nullptr);
		header->setNext(trailer);
		size = 0;
		for (int i = 0; i < lst.size; i++)
		{
			addBetween(trailer->getPrev(), trailer, lst.elementAt(i));
		}
	}
	LinkedList& operator=(const LinkedList& lst)
	{
		if (this != &lst)
		{
			header = new Node(nullptr, nullptr);
			trailer = new Node(header, nullptr);
			header->setNext(trailer);
			size = 0;
			for (int i = 0; i < lst.size; i++)
			{
				addBetween(trailer->getPrev(), trailer, lst.elementAt(i));
			}
		}
		return *this;
	}
	~LinkedList()
	{
		for (int i = 0; i < size; i++)
		{
			remove(getNodeAt(i));
		}
		delete header;
		delete trailer;
	}

	void addFirst(T elem)
	{
		addBetween(header, header->getNext(), elem);
	}
	void addLast(T elem)
	{
		addBetween(trailer->getPrev(), trailer, elem);
	}
	T removeFirst()
	{
		return remove(header->getNext());
	}
	T removeLast()
	{
		return remove(trailer->getPrev());
	}

	T elementAt(int index) const
	{
		return getNodeAt(index)->getElement();
	}
	T getFirst()
	{
		return header->getNext()->getElement();
	}
	T getLast()
	{
		return trailer->getPrev()->getElement();
	}
	int getSize()
	{
		return size;
	}
	void printRange(int n)
	{
		std::cout << "[";
		for (int i = 0; i < n - 1; i++)
		{
			std::cout << elementAt(i) << ",";
		}
		std::cout << elementAt(n - 1) << "]";
	}
};
#endif