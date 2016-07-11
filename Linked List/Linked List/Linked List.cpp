// Sierra S2 Written Assignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
/****************************************************************
Class: Node
Purpose: Effectively extremely dynamic array that deallocates all
         resources upon deletion. Size can be returned, any 
		 variable can be easily changed at any time without need
		 of loops. The size is extremely dynamic, a new node can
		 be added to the end at any time. Very easy to use class
		 
		 This node stores int values but can be 
		 modified to store anything.
Additional Info: Accessing a node is the same as an array, it starts
		from 0 and goes up from there. When the size is returned 
		it's as a total, it does not start at 0, so if there are
		four total nodes, it will return four, if you want to 
		access the fourth node, you input 3 into valid functions
Functions:
		Node(): Initializes new empty Node object
		Node(int nextValue): Initializes new node and sets stored
			value
		virtual ~Node(): Destroys all used resources for effective 
			memory allocation
		void AddNode(int NextValue): Adds a new node to the end of 
			pointer list and sets its value
		void AddNode(): Adds a new empty Node at the end of the list
		void DisplayAll(): Displays all current Node entries with a 
			space between them
		int GetSize(): Returns size of list
		bool IsEntry(int nodeNumber): Returns true if there's a node 
			at specified location, otherwise returns false
		void AccessNodeInput(int nodeNumber, int value): Inputs 
			value into specified node
		int AccessNodeReturn(int nodeNumber): Returns value stored
			in specified node
****************************************************************/

class Node
{
private:
	Node* nextPtr;
	int intValue;
	int size;

public:
	Node()
	{
		nextPtr = nullptr;
		size = 1;
	}
//used to immediately initialize int value for current Node
	Node (int nextValue)
	{
		nextPtr = nullptr;
		intValue = nextValue;
		size = 1;
	}
//Destroys memory from heap to avoid wasting resources
	virtual ~Node()
	{
		if (nextPtr != nullptr)
		{
			nextPtr -> ~Node();
		}
		delete nextPtr;
		nextPtr = nullptr;
	}
//Puts an additional node at the end of the current list and assigns int value
	void AddNode (int nextValue)
	{
		size++;
		if (nextPtr == nullptr)
		{
			nextPtr = new Node(nextValue);
		}
		else
		{
			nextPtr->AddNode(nextValue);
		}
	}
//Puts an additional node at the end of list
	void AddNode ()
	{
		size++;
		if (nextPtr == nullptr)
		{
			nextPtr = new Node();
		}
		else
		{
			nextPtr->AddNode();
		}
	}

//Displays all integer values in list nodes
	void DisplayAll ()
	{
		cout << intValue << " ";

		if (nextPtr != nullptr)
		{
			nextPtr -> DisplayAll();
		}
	}

//Gets size stored in list object
	int GetSize ()
	{
		return size;
	}

//Returns true if there's an entry of the specified value
	bool IsEntry(int nodeNumber)
	{
		if (nodeNumber > 0 && nextPtr != nullptr)
		{
			nodeNumber -= 1;
			return nextPtr -> IsEntry(nodeNumber);
		}
		else if (nodeNumber == 0)
		{
			return true;
		}
		else if (nodeNumber > 0 && nextPtr == nullptr)
		{
			return false;
		}
	}

//Accesses specified node number and inputs an int value in that node
	void AccessNodeInput (int nodeNumber, int value)
	{
		if (nodeNumber > 0 && nextPtr != nullptr)
		{
			nodeNumber -= 1;
			nextPtr -> AccessNodeInput(nodeNumber, value);
		}
		else
		{
			intValue = value;
		}
	}

//returns the value in the specified node number
	int AccessNodeReturn (int nodeNumber)
	{
		if (nodeNumber > 0 && nextPtr != nullptr)
		{
			nodeNumber -= 1;
			nextPtr -> AccessNodeReturn(nodeNumber);
		}
		else
		{
			return intValue;
		}
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	Node testNode(25);

	testNode.AddNode(500);
	testNode.AddNode();
	testNode.AddNode(250);
	testNode.AccessNodeInput(2, 512);
	testNode.DisplayAll();

	cout << endl;
	cout << testNode.IsEntry(3) << " " << testNode.IsEntry(15) << endl;
	testNode.AccessNodeInput(1, 5504);
	cout << testNode.AccessNodeReturn(1) << endl;
	cout << "List size is: " << testNode.GetSize() << endl;
	testNode.~Node();

	cout << testNode.IsEntry(1) << endl;

	system("Pause");

	return 0;
}



