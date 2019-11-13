/*Author: Suresh Balaiyan
Course: SENG 6120.
Student number:3302159
Program Description: This program implements Doubly linked list using the given student structure by creating nodes of students using classes such as
Student,Node and LinkedList*/

#include"Node.h"
#include"Student.h"
//pre-condition: initializes the data,next and prev pointers with the given corresponding inputs.
//post condition: none
Node::Node(const Student& initial_data,Node* initial_link,Node* initial_link1) //Constructor of Node creates an instance and a pointer to Student.
{

	data = initial_data;
	next = initial_link;
	prev = initial_link1;


}
//pre-condition: sets the data and pointers to empty values and nulls.
//post-condition:none
Node::~Node() //destructor
{
	Node::data.set_name(""); //empty value is assigned.
	Node::next = NULL;	//NULL is set to next pointer,as it is not currently pointing to any.				
	Node::prev = NULL;	//NULL is set to prev pointer,as it is not currently pointing to any. 
						
}
//pre-condition: Receives next input parameter and assigns to the next pointer.
//post-condition:none
void Node:: setNext(Node* newNext) //function that sets the next pointer with the given input parameter.
{
  	next = newNext;

}

//pre-condition: Receives prev input parameter and assigns to the prev pointer.
//post-condition:none
void Node::setPrev( Node* newPrev) //function that sets the prev pointer with the given input parameter.
{
	prev = newPrev;

}
//pre-condition: Receives prev input parameter and assigns to the prev pointer.
//post-condition:none
void Node::setData(valuetype& newData)//function that sets the data with the given input parameter.
{
	data = newData;
}
//pre-condition: Returns next as output parameter.
//post-condition:none
Node* Node::getNext() const//function that returns the next pointer.
{
	return next;
}
//pre-condition: Returns data as output parameter.
//post-condition:none
Student Node::getData() const//function that returs student data
{
	return data;
	
}
//pre-condition: Returns Prev as output parameter.
//post-condition:none
Node* Node::getPrev()const //function that gets the prev pointer.
{
	return prev;
}





