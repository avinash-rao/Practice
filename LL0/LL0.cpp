#include <iostream>
#include <conio.h>
using namespace std;

class LinkedList
{
private:
	int data;
	LinkedList *next;
	static LinkedList *start;
public:
	LinkedList() { }
	LinkedList(int item)
	{
		LinkedList *newnode = new LinkedList;
		newnode -> data = item;
		newnode -> next = NULL;
		start = newnode;
	}
	void traverse();
	void add(int);
	void del(int);
};

LinkedList* LinkedList::start = NULL;

void LinkedList::traverse()
{
		LinkedList *current = start;
		if(current == NULL)
		{
			cout << "The linked list is empty" << endl;
			return;
		}
		while(current != NULL)
		{
			cout << current -> data << "  ";
			current = current->next;
		}
		cout << endl;
}

void LinkedList::add(int item)
{
	LinkedList *newnode = new LinkedList;
	newnode -> data = item;
	newnode -> next = NULL;
	if(start == NULL)
	{
		start = newnode;
	}
	else
	{
		LinkedList* currptr = start;
	
		while(currptr->next != NULL)
		{
			currptr = currptr -> next;
		}
		currptr -> next = newnode;
	}
}

void LinkedList::del(int item)
{
	LinkedList* currptr = start;
	LinkedList* prevptr = NULL;
	
	if(start->data == item)
	{
		start = start->next;
		delete currptr;
		return;
	}
	
	//The below statement is not appropriate. When the currptr reaches end and is equal to NULL then it wouldn't be able to point to 'data'. So it is runtime error.
	//while((currptr->data != item) && (currptr != NULL))
	
	while((currptr != NULL) && (currptr->data != item))
	{
		prevptr = currptr;
		currptr = currptr -> next;
	}
	if(currptr == NULL)
	{
		cout << item << " not found in Linked List" << endl;
	}
	else
	{
		prevptr->next = currptr->next;
		delete currptr;
		cout << "Item deleted: " << item << endl;
	}
}

int main()
{
//	LinkedList train = LinkedList(4);
//	train.add(6);
//	train.add(1);
//	train.traverse();
//	train.del(6);
//	train.del(3);
//	train.traverse();
	
	int ch,item;
	
	cout << "Enter the first element of Linked List: ";
	cin >> item;
	LinkedList list = LinkedList(item);
	
	while(1)
	{
		cout << endl << "1. Add" << endl;
		cout << "2. Delete" << endl;
		cout << "3. Display" << endl;
		cout << "4. Exit" << endl << endl;
		
		cout << "Enter your choice: ";
		cin >> ch;
		
		switch(ch)
		{
			case 1: cout << endl << "----------- Add an element --------------" << endl;
					cout << "Enter the item : ";
					cin >> item;
					list.add(item);
					break;
			case 2: cout << endl << "----------- Delete an element --------------" << endl;
					cout << "Enter the item : ";
					cin >> item;
					list.del(item);
					break;
			case 3: cout << endl << "----------- Traversal of Linked list --------------" << endl << endl;
					list.traverse();
					break;
			case 4: exit(0);
					break;
			default: cout << endl << "Please provide an integer between 1 to 4";
		}
	}
	return 0;
}