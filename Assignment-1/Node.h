/*Author: Suresh Balaiyan
Course: SENG 6120.
Student number:3302159.
Program Description: This program implements Doubly linked list using the given student structure by creating nodes of students using classes such as
Student,Node and LinkedList*/

#ifndef Node_H
#define Node_H

#include "Student.h"

class Node
{

public:
	typedef Student valuetype;
	Node(); //default constructor.
	Node(const valuetype& i, Node* n = NULL, Node* p = NULL);//constructor with initial inputs.
	~ Node(); //destructor
	void setNext( Node*);  //Function to set Next.
	void setPrev(Node*); //Function to set prev.
	Node* getNext()const; //Function to get the next node.
	Node* getPrev()const; //Function to get the previous node
	void setData( valuetype&); //Function to set the data.
	valuetype getData()const; //gets the Student data.
	

private:
	Node* next; //Pointer to reference next node.
	Node* prev; //Pointer to reference revious node.
	valuetype data; //Student type data.

};
#endif
