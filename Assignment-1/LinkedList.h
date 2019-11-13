/*Author: Suresh Balaiyan
Course: SENG 6120.
Student number:3302159.
Program Description: This program implements Doubly linked list using the given student structure by creating nodes of students using classes such as
Student,Node and LinkedList*/


#ifndef Linked_H
#define Linked_H


#include "Node.h"
#include "Student.h"
using namespace std;

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void addToTail(Student&); //Receives a student object and adds them to the tail of the linked list.
	void addToHead(Student &); //Receives a student object and adds to the head of the linked list.
	void remove(const string name) ; //Receives the name of the student and the student is removed from the list.
	int count(const string name) ; //Receives name of the student and returns count in the given list.
	void order(); //Receives a student object and returns the student list in alphabetical order.
	void operator +=(const LinkedList);
	void operator -=(LinkedList&);
	bool  operator <( const string&)const;
	

	Node* head;
	Node* tail;
	Node* current;


};
ostream& operator <<(ostream&, const LinkedList&);
#endif


