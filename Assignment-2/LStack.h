

/*Author: Suresh Balaiyan
Course: SENG 6120.
Student number:3302159.
Program Description: This program implements Stack using the given linked list data type structure
by creating linked list  object,which in turn creates node with  data to store and next and prev pointer of the node.
*/

#include<list>
#include<stdlib.h>
#include<string.h>
#include "LinkedList.h"

#ifndef LStack_H
#define LStack_H
template <typename value_type>
class LStack
{

public:
	LStack() //default consructor
	{
		data = new LinkedList<value_type>(); // very important to add <value_type>

	}
	~LStack() //destructor to delete linked list data object.
	{
		delete data;

	}
	void push(const value_type& obj)const //pushes linked list object  to the top of the stack only.
	{


		data->addToHead(obj);


	}

	value_type pop()const //removes the top most inked list from the stack
	{

		return data->removeFromHead();
	}


	bool isEmpty()const //checks whether the stack is empty
	{
		return data->isEmpty_LL();
	}
	//This function calls getData_LL of Linked list,//
					   //	which returns the data of the head and that is returned by this function to move () in TowerHanoi.cpp for string comparison.
	string getData_LS()const
	{
		return data->getData_LL();

	}
	string getData_Print_LS()const //This function returns  the data of the nodes to getDataPrint_h() of TowerHanoi.cpp
	{

		string str = data->getdata_Print_L(); //calls getdata_Print_L() of liknked list.
		return str;

	}
private:
	LinkedList<value_type>* data;

};
#endif