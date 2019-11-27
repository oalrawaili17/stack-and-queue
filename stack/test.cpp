#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Stack.hpp"
#include "Queue.hpp"
void testStack(ListStack<int> stack)
{
	std::cout << "Initial stack: ";
	stack.printRange(stack.size());
	std::cout << "\n";
	std::cout << "Stack size: " << stack.size() << "\n";
	std::cout << "First item: " << stack.peek() << "\n";
	std::cout << "Stack empty?";
	stack.isEmpty() ? std::cout << "True\n" : std::cout << "False\n";
	std::cout << "Popped " << stack.pop() << "\nRemaining elements: ";
	stack.printRange(stack.size());
	std::cout << "\nPopping the rest of the stack: ";
	while (!stack.isEmpty())
	{
		std::cout << stack.pop() << " ";
	}
	std::cout << "\nStack size:" << stack.size();
	std::cout << "\nStack empty?";
	stack.isEmpty() ? std::cout << "True\n" : std::cout << "False\n";
}
void testQueue(ListQueue<int> queue)
{
	std::cout << "Initial queue: ";
	queue.printRange(queue.size());
	std::cout << "\n";
	std::cout << "Queue size: " << queue.size() << "\n";
	std::cout << "First item: " << queue.first() << "\n";
	std::cout << "Queue empty?";
	queue.isEmpty() ? std::cout << "True\n" : std::cout << "False\n";
	std::cout << "Dequeued " << queue.dequeue() << "\nRemaining elements: ";
	queue.printRange(queue.size());
	std::cout << "\n";
	try
	{
		std::cout << "Dequeue and print the rest: ";
		while (!queue.isEmpty())
		{
			std::cout << queue.dequeue() << " ";
		}
		std::cout << "\nQueue size:" << queue.size();
		std::cout << "\nQueue empty?";
		queue.isEmpty() ? std::cout << "True\n" : std::cout << "False\n";
		//Intentionally exceeding the limit
		std::cout << "Trying to delete an element from queue: " << queue.dequeue();
	}
	catch (QueueUnderflow)
	{
		std::cout << "Error: Underflow detected\n";
	}
}
int main()
{
	std::srand(time(NULL));
	ListStack<int> stack;
	ListQueue<int> queue;
	for (int i = 0; i < 5; i++)
	{
		//append random numbers to stack and queue
		stack.push(std::rand() % 50);
		queue.enqueue(std::rand() % 50);
	}
	testStack(stack);
	std::cout << "\n\n\n";
	testQueue(queue);
}