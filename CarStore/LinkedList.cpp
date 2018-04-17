#include"LinkedList.h"

/*
	Add a new element to the end of the list

*/
void List::push_back(const Car& car)
{
	
	Node *temp = new Node;
	temp->value = car;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else
	{
		tail->next = temp;
		tail = temp;
		temp = NULL;
	}
	
	delete temp;
}


/*
	Return the firt node

Node* List::begin()
{
	return head;
}

Node* List::end()
{
	return tail;
}


/*
	Return the size of the list
*/
int List::size() const 
{
	int count = 0;
	Node* temp ;
	temp = head;
	while (temp != nullptr)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

/*
	Overloading the [] operator for accenssing an element from the list in this way: array[position]
	Return the element from a position
*/
Car& List::operator[](const int& position) const 
{
	Node *temp ;
	temp = head;
	for (int i = 0; i < position; i++)
	{
		temp = temp->next;
	}
	return temp->value;
}

/*
	Delete an element from a position
	Checks out if the position is 0 for deleting the head of linked list
	Elements from a position different from 0 are deleted using 2 auxiliar nodes: prev and current
*/
void List::erase(const int& pos)
{
	if (!pos)
	{
		Node *temp;
		temp = head;
		head = head->next;
		delete temp;
	}
	else
	{
		Node *curent;
		Node *prev;
		curent = head;
		prev = tail;
		for (int i = 0; i < pos; i++)
		{
			prev = curent;
			curent = curent->next;
		}
		Node *aux = prev->next;
		prev->next = curent->next;
		delete aux;
	}
}
