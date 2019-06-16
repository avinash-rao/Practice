#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};
typedef struct node NODE;

class Stack
{
private:
	static NODE* top;
	NODE node;
public:
	Stack() {}
	Stack(int item)
f	{
		NODE* newnode = new NODE;
		newnode->data = item;
		
		top = newnode;
	}
	
	void push(int);
	void pop();
	void display();
};
NODE* Stack::top = NULL;

void Stack::push(int item)
{
	NODE* newnode = new NODE;
	newnode->data = item;
	newnode->next = top;
	top = newnode;
}

void Stack::pop()
{
	if(top == NULL)
	{
		cout << "Stack Underflow" << endl;
		return;
	}
	
	NODE* currptr = new NODE;
	currptr = top;
	cout << "Popped Element: " << top->data << endl;
	top = top->next;
	delete currptr;
}

void Stack::display()
{
	NODE* currptr = new NODE;
	currptr = top;
	if (currptr == NULL)
	{
		cout << "Stack Underflow";
		return;
	}
	
	while(currptr != NULL)
	{
		cout << currptr->data << "  ";
		currptr = currptr->next;
	}
	cout << endl;
}

int main()
{
	int ch,item;
	
	cout << "Enter the first element of stack: ";
	cin >> item;
	Stack s = Stack(item);
	
	while(1)
	{
		cout << endl << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Display" << endl;
		cout << "4. Exit" << endl << endl;
		
		cout << "Enter your choice: ";
		cin >> ch;
		
		switch(ch)
		{
			case 1: cout << endl << "----------- Push an element --------------" << endl;
					cout << "Enter the item : ";
					cin >> item;
					s.push(item);
					break;
			case 2: cout << endl << "----------- Pop an element --------------" << endl;
					s.pop();
					break;
			case 3: cout << endl << "----------- Traversal of Stack --------------" << endl << endl;
					s.display();
					break;
			case 4: exit(0);
					break;
			default: cout << endl << "Please provide an integer between 1 to 4";
		}
	}
	return 0;
}
