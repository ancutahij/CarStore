#include"Domain.h"
#pragma once

class Node
{
public:
	Car value;
	Node * next;

	Node(const Car& value, Node* next)
		: value(value), next(next) {}
	// delegating constructor
	Node() : Node(Car(),nullptr ) {}
	Node(const Node* copy)
	{
		value = copy->value;
		next = copy->next;
	}
	//~Node()
	//{
	//delete this;
	//}
};

class List
{
private:
	Node * head,  *tail;
public:
	List()
	{
		head = nullptr;
		tail = nullptr;
	}

	// Destructor
	~List()
	{
		//std::cout << " se ajunge aici";
		Node *temp ;
		for (temp = head; head != nullptr; temp = head)
		{
			head = head->next;
			delete temp;
		}
		

	}
	void push_back(const Car&);
	//Node* begin();
	//Node* end();
	int size() const ;
	Car& operator[](const int& position) const ;
	void erase(const int& pos);

};
