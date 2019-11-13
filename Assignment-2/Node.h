
/*Author: Suresh Balaiyan
Course: SENG 6120.
Student number:3302159.
Program Description: This program  is used as a base class for linked list and stack ,that holds data and next and previous pointer to that data*/


#ifndef Node_H
#define Node_H

#include<iostream>
using namespace std;
template <typename value_type>
class Node
{

public:
	//Node(); //default constructor.
	Node(const value_type i, Node<value_type>* n = NULL, Node<value_type>* p = NULL)//constructor with initial inputs.
	{


		data = i;
		next = n;
		prev = p;
	}
	//pre-condition: sets the data and pointers to empty values and nulls.
//post-condition:none
	~Node()//destructor
	{

		data = ""; //empty value is assigned.
		delete next;	//NULL is set to next pointer,as it is not currently pointing to any.				
		delete prev;	//NULL is set to prev pointer,as it is not currently pointing to any. 
	}




	//pre-condition: Receives next input parameter and assigns to the next pointer.
	//post-condition:none

	void setNext(Node<value_type>* newNext)//function that sets the next pointer with the given input parameter.
	{
		next = newNext;

	}
	//pre-condition: Receives prev input parameter and assigns to the prev pointer.
//post-condition:none

	void setPrev(Node<value_type>* newPrev) //function that sets the prev pointer with the given input parameter.
	{
		prev = newPrev;

	}
	//pre-condition: Returns next as output parameter.
//post-condition:retuen next

	Node<value_type>* getNext() const//function that returns the next pointer.
	{

		return next;

	}
	//pre-condition: Receives data and sets the data to the data private memeber
//post-condition:none

	void setData(const value_type& newData)//function that sets the data with the given input parameter.
	{
		data = newData;
	}

	//pre-condition: Returns data as output parameter.
//post-condition:none
	value_type getData() const//function that returs student data
	{
		//		cout << data;
		return data;

	}

	//pre-condition: Returns Prev as output parameter.
//post-condition:none
	Node<value_type> * getPrev()const //function that gets the prev pointer.
	{
		return prev;
	}


private:
	Node<value_type>* next; //Pointer to reference next node.
	Node<value_type>* prev; //Pointer to reference revious node.
	value_type data; //Node type data.

};



#endif
