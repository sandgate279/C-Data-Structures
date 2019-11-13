

/*Author: Suresh Balaiyan
Course: SENG 6120.
Student number:3302159.
Program Description: This program implements Doubly linked list using the given node
structure by creating nodes by using  Node class
*/


#ifndef Linked_H
#define Linked_H

#include "BTNode.h"
#include "MechPart.h"

using namespace std;
template <typename value_type>
class LinkedList
{
public:
	//pre condition: An instance of Linked list must be instantiated.
//post condition: none.

	LinkedList(){
		head = NULL;
		tail = NULL;
	}
	//pre condition: Linked list will be deleted with all the node members.
	//post condition: none.
	~LinkedList(){
		BTNode<value_type>* current;
		while (head){
			current = this->head;
			delete head;
			head = current;
		}
	}
	
	//pre condition: An instance of Linked list will be added to the head.
	//post condition: none.
	void add_L(const value_type& value){ //adds new student to the head of the list.

		BTNode<value_type>* newNode = new BTNode<value_type>(value); // very important to add <value_type>
		BTNode <value_type>* headCopy = head; //creates new Node type pointer and assigns as head
		head = newNode;
		head->set_rLink(headCopy);
		headCopy->set_lLink(head);
		tail = headCopy;
		
	}


	void addToHead(const value_type& value)	{		
		if (head == NULL) {														// list is empty
			BTNode<value_type>* newNode = new BTNode<value_type>(value); // very important to add <value_type>
			head = newNode;			
			tail = newNode;
		}
	}
	void getdata_Print_L()const
	{

		
		BTNode<value_type>* current = this->head;
		while(current)	{		
		cout << current->get_data()<<endl ;
		current=current->get_rLink();
		}
	}

	//pre condition: The head node will be removed from the linked list.
//post condition: none.
	int removeNode(value_type& value){ //removes the head of the node from  the list

			for(BTNode <value_type>* ptr = head;ptr!=NULL;ptr=ptr->get_rLink())	{
				BTNode <value_type>* ptr_lLink = ptr->get_lLink();
				BTNode <value_type>*  ptr_rLink = ptr->get_rLink();
				if (ptr->get_data() == value && head->get_data()== ptr->get_data() && head->get_rLink()==NULL){ //head to delete and only node exists
						ptr = NULL;
						head = NULL;
						tail = NULL;
						delete head;
						delete tail;
						delete ptr;
						return 1; //1 means  head is empty.
				}

				else if (ptr->get_data() == value && ptr->get_data() == head->get_data() && head->get_rLink() != NULL){ //head to delete ,has a next node.
							BTNode <value_type>* temp = head;
							head = ptr_rLink;
							ptr_rLink->set_lLink(NULL);
							ptr = NULL;
							delete ptr;
							return 0;
				}
				else if(ptr->get_data() == value && ptr_lLink !=NULL && ptr_rLink!= NULL){
					ptr_lLink->set_rLink(ptr_rLink);  //3 nodes scenerio and middle to delete
					ptr_rLink->set_lLink(ptr_lLink);
					ptr = NULL;
					delete ptr;
					return 0;
				}

				else if (ptr->get_data() == value && tail->get_data() == ptr->get_data()) { //tail to delete
					ptr_lLink->set_rLink(NULL);
					tail = NULL;
					delete tail;
					tail = ptr_lLink;
					return 0;
				}
			}

		}
	

	int calculate_LParts(int &count)const{
		for(BTNode<value_type>* current = this->head;current!=NULL;current=current->get_rLink()){
		count++;
		//return count;			
		}
		return count;
	}
	int calculate_LQty(int &count)const {
		
		for (BTNode<value_type>* current = this->head; current != NULL; current = current->get_rLink()) {
			count=count+current->get_data().get_quantity();
		}
		return count;
	}
	
private:
	BTNode<value_type>* head; // points to the head of the linked list
	BTNode<value_type>* tail; //point to the end of the Linked lIst
	BTNode<value_type>* current;
};
#endif



