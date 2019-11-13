
/*Author: Suresh Balaiyan
Course: SENG 6120.
Student number:3302159.
Program Description: This program implements Doubly linked list using the given node
structure by creating nodes by using  Node class
*/


#ifndef Linked_H
#define Linked_H

#include "Node.h"

using namespace std;
template <typename value_type>
class LinkedList
{
public:
	//pre condition: An instance of Linked list must be instantiated.
//post condition: none.

	LinkedList()
	{
		head = NULL;
		tail = NULL;

	}
	//pre condition: Linked list will be deleted with all the node members.
	//post condition: none.
	~LinkedList()
	{
		Node<value_type>* current;
		while (head)
		{
			current = head->getNext();
			delete head;

			head = current;
		}


	}

	//pre condition: An instance of Linked list will be added to the head.
	//post condition: none.
	void addToHead(const value_type& value) //adds new student to the head of the list.
	{
		Node<value_type>* newNode = new Node<value_type>(value); // very important to add <value_type>
		if (head == NULL)
		{														// list is empty

			head = newNode;
			tail = newNode;
		}
		else
		{

			Node <value_type>* headCopy = head; //creates new Node type pointer and assigns as head
			head = newNode;
			head->setNext(headCopy);
			headCopy->setPrev(head);
		}

	}



	//pre condition: The head node will be removed from the linked list.
//post condition: none.
	value_type removeFromHead()//removes the head of the node from  the list
	{


		Node <value_type>* ptr = this->head;

		if (ptr->getNext() == NULL) //one node only exists.
		{
			value_type dat = ptr->getData();
			head = NULL;
			delete head;
			return dat;
		}
		else
		{
			value_type dat = ptr->getData();
			Node <value_type>* ptrCopy = this->head;

			this->head = ptr->getNext();
			ptrCopy = NULL;
			delete ptrCopy;
			return dat;
		}





	}

	//pre condition:retuens data that belongs to head of the link list
	//pre-condition: return data

	 // this function is used in getData_LS() in LStack ,which is then used in TowerHanoi.cpp. 
								//This function return data of the head node.
	string getData_LL()const
	{

		return this->head->getData();
	}
	//pre condition:*Out put of this function is used as a final output of the program.
					//This function is called in getDataPrint_LS() in LStack which is called by getDataPrint_h() in TowerHanoi.cpp
	//postcondition: none

	string getdata_Print_L()const
	{

		Node<string>* current = this->head;
		string str = "";
		while (current)
		{
			str = str + current->getData() + "\n";
			current = current->getNext();

		}
		return str;
	}
	//pre condition: checks the Linked list is empty
	//post condition:none
	bool isEmpty_LL() const//
	{


		if (head)
			return false;
		else
			return true;
	}

private:
	Node<value_type>* head; // points to the head of the linked list
	Node<value_type>* tail; //point to the end of the Linked lIst
	Node<value_type>* current;
};
#endif



