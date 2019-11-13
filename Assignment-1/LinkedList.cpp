/*Author: Suresh Balaiyan
Course: SENG 6120.
Student number:3302159
Program Description: This program implements Doubly linked list using the given student structure by creating nodes of students using classes such as
Student,Node and LinkedList*/
#include<iostream>
#include "Student.h"
#include "LinkedList.h"
#include "Node.h"

//pre condition: An instance of Linked list must be instantiated.
//post condition: none.
LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
	
}
//pre condition: An instance of Linked list will be deleted.
//post condition: none.
LinkedList:: ~LinkedList()
{
	
	 head=NULL;
	 tail=NULL;
	 current=NULL;

	
}
//pre condition: An instance of Linked list will be added to the tail node.
//post condition: none.

void LinkedList::addToTail(Student& stud) //adds new student to the end of the tail in the list.
{
	if (head != NULL && tail != NULL) //check list has nodes.
	{
		

			Node* newTail = new Node(stud, NULL, tail); //new node with tail as prev.
			tail->setNext(newTail); //set tail's next as new node.
			newTail->setPrev(tail); //set prev of new node as tail.
			tail = newTail;// now tail is the new node.
		
		
			
		
	
	}
	else
	{
		head = new Node(stud, NULL, NULL); //New head is created with next and prev as NULL.
		tail = head; //if list is empty then head and tail point to the new node.
		
	
	}
}
//pre condition: An instance of Linked list will be added to the head.
//post condition: none.
void LinkedList::addToHead(Student& stud) //adds new student to the head of the list.
{
	
		if (head != NULL && tail != NULL)  //check list has nodes.
		{

			Node* newHead = new Node(stud, NULL, NULL); //make new node with next and prev =NULL.
			head->setPrev(newHead); // set head's prev as new node.
			newHead->setNext(head);// set new head's next as head.
			head = newHead;// now new node is the head.


		}
		else
		{
			head = new Node(stud, NULL, NULL); //New head is created.
			if (tail == NULL) // this is required to deal with adding to an empty list.
			{
				tail = head; //tail and head point to the new node.
			}

		}
	}



//pre condition: The node with the given name will be removed from the linked list.
//post condition: none.
void LinkedList::remove(const string name)//receives student name as input and deletes the student in the list
{
	
	if(this->head != NULL && this->tail != NULL) //check list is empty.
	{	
		int count = 0; //to delete head
		for (Node * ptr = this->head;ptr != NULL;ptr = ptr->getNext(),count++) //navigate the list
		{
			//cout << ptr->getData().get_name();
				if (ptr->getData().get_name() == name) //check ptr name == iinput name.
				{
					
					if (count==0)//removing from head.
					{
						Node* headCopy = this->head; //copy of head.
						Node* nextPtr = head->getNext(); //head's next node is stored.
						nextPtr->setPrev(NULL); // next node to head prev is made NULL.
						head->setNext(NULL); //head's next is set NULL,so we can delete head
						head->setPrev(NULL); //head's prev is set NULL,so we can delete head
						this->head = nextPtr; //head is head's next node.
						delete headCopy; //delete old head.
						return; //
					}
					if (ptr->getData().get_name() == name && ptr!=this->tail) //remove internal node.
					{
						Node* copy = ptr->getNext();
						ptr->getNext()->setPrev(ptr->getPrev()); // ptr's next's prev value is set to ptr's prev.
						ptr->getPrev()->setNext(ptr->getNext()); //ptr's prev set next is ptr's next.
						ptr->setNext(NULL); //head's next is set NULL,so we can delete head
						ptr->setPrev(NULL);//head's prev is set NULL,so we can delete head
						delete ptr;
						ptr=copy;// ptr is ptr's next.
						//return;

					}
					if (ptr->getData().get_name() == name && ptr == tail) //remove tail node.
					{
						this->tail = ptr->getPrev();//tail is ptr's prev
						Node* copy = ptr->getPrev();
						copy->setNext(NULL); //set tail's next as null.
						ptr->setNext(NULL);// set ptr next as bnull.
						ptr->setPrev(NULL);// set ptr prevt as bnull.
						delete ptr;
						ptr = copy;

					}
				}
				
		}

	}
	}
//pre condition: Returns number of nodes with the given name.
//post condition: none.
int LinkedList::count(const string name)//receives name of the student and returns number of occurences in the list.
{
	int count = 0; //variable that counts number of occurence of the given name.
	for (current = head;current != NULL;current = current->getNext()) //for loop navigates the list
	{
		if(current->getData().get_name()==name) // if name matches with the name in the list.
		{

		count++; //increase count.
		}
	}
	return count;
}
//pre condition: Adds 2 lists as one list
//post condition: none.
void LinkedList::operator +=(const LinkedList two) //first list=first list+ second list.
{
	if (head!=NULL  && two.head!=NULL) // check the list is empty.
	{
		
		tail->setNext(two.head); //set 
		two.head->setPrev(tail);
		tail = two.tail;
	}

}
//pre-condition: removes second list contents from first list.
//post conditio:none
void LinkedList::operator -=(LinkedList& two) // first list =first list-second list.
{
	

	this->current = this->head; // current points to head.
	for (; this->current != NULL; this->current = this->current->getNext()) //for loop that runs for list1
	{
		if (current->getData().get_name() == "Tony")tail = current->getPrev(); //if current name is "Tony" then tail is current's prev.
		tail->setNext(NULL);
	}
	two.head->setPrev(NULL); //second list head's prev is set to NULL.

			
				
}
//pre-condition : Receives string inputs and compares. Returns false when nothing to swap.
	
bool operator < (string& b,const string& a) //compares names of students alphabetically.
{
	int x = a.compare(b);
	if (x == -1)
	return false; //returns false if 2nd node is greater than 1 st node.
	else
	return true; //returns true if 2nd node is smaller than 1 st node.
	
		
}

//Pre-condition: sort List's names alphabetically in ascending order.
//post-condition:None.

void LinkedList::order()
{
	
		if (head == NULL && tail == NULL)return;  //check whether list has atleast 2 nodes.

		if (tail == head)	return;//if one node then return.
		Node* curr = NULL; //curr is inner for loop,while current is outer for loop.curr is one node ahead of current.

		for (current = head; (current != NULL); current = current->getNext()) //for loop that runs through the list and stops befor reaching NULL.
		{


			for (curr = current->getNext(); curr != NULL; curr = curr->getNext())//for loop that is one node ahead of current
			{


				string current_name = current->getData().get_name(); //1 st node name.
				string curr_name = curr->getData().get_name(); //2 nd node name.

				if (curr_name < current_name) // if 2nd node name is smaller than 1 st node name ,then begin swap.
				{

					if (current == head) head = curr; // if head is getting swapped then head is curr node.


					Node* p_one = current->getNext(); // pointer next to current
					Node* p_two = current->getPrev(); //pointer prev to current
					Node* p1 = curr->getNext(); //pointer next to curr
					Node* p2 = curr->getPrev(); //pointer prev to curr

					//1. If curr and current are adjacent nodes to swap.
					if (p_one == curr)
					{
						//1
						current->setPrev(curr);  //if curr and current are adjacent nodes. set current prev as curr.

						//2
						current->setNext(p1); //current's next is p1.

						//3
						curr->setPrev(p_two);  //curr prev is current's prev.

						//4
						curr->setNext(current); //curr next is currnet.

						//5.
						if (p_two != NULL)p_two->setNext(curr); //if p_two is not NULL then set p_two's next curr.

						//6.
						if (p1 != NULL)p1->setPrev(current); //if p1 not NULL then set p1's Prev as current.
					}


					if (p_one != curr) //if curr and current are not adjacent nodes.
					{
						//1
						current->setPrev(p2);  //set current prev as curr's prev.
						//2
						current->setNext(p1); // set current's next as curr next.

						//3
						curr->setPrev(p_two); //set curr prev as current's prev.
						//4
						curr->setNext(p_one); //set curr next as current's next.
						//5
						if (p_two != NULL)	p_two->setNext(curr); // set current's prev''s next as curr,if p_two is not head node.
						//6
						p_one->setPrev(curr); //set current's next's prev as curr.
						//7
						p2->setNext(current); //set curr's prev's next as current.
						//8
						if (p1 != NULL)p1->setPrev(current); // if curr's next is not tail node then curr's next's prev is current.
					}

					//swap curr and current.
					Node* temp = current; // pointer to current
					current = curr; //current now points to curr
					curr = temp; //curr now points to current.

					if (curr->getNext() == NULL)tail = curr;  //set tail as curr only if current is getting swapped and current's next is NULL.

				}
			}
		}
	
	
}
	

	
//Pre-condition : Input as -Linked list.
//post-condition: Must  return Ostream .
ostream& operator <<(ostream& out, const LinkedList& list)
{
	

	for (Node * ptr = list.head; ptr != NULL; ptr = ptr->getNext()) 
	{
		out << "(" << ptr->getData().get_name() << "," << ptr->getData().get_score() << ")"; //display the lists name and score.
	}

	return out;
}
