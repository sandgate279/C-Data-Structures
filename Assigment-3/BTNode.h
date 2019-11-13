
#include "MechPart.h"
#include<iostream>
#include<stdio.h>
/*Author: Suresh Balaiyan
Course: SENG 6120.
Student number:3302159.
Program Description: This program implements  given node
structure by creating nodes 
*/

//using namespace std;
#ifndef BTNode_H
#define BTNode_H
template<typename value_type>
class BTNode{
public:
	   
	BTNode(const value_type& value)	{
		data = value;
		lLink = NULL;
		rLink = NULL;
	}

	value_type get_data(){
		return data;
	}

	
	//pre condition: An instance of Linked list must be instantiated.
//post condition: none.
	BTNode<value_type>* get_lLink()const	{ //returns left link
		return lLink;
	}

	void set_lLink(BTNode<value_type>* BNT) { //set left link
		lLink = BNT;

	}

	void set_rLink(BTNode<value_type>* BNT) { //set right link
		rLink = BNT;

	}

	BTNode<value_type>* get_rLink()	const { //get right link

		return rLink;
		
	}

	void add(const value_type& value){ //adds new node to the tree
		if (value < data)	{			//travel left and insert the new node 
			if (lLink == NULL){
				lLink = new BTNode<value_type>(value);
			}
			else{
				lLink->add(value);				
			}
		}
		else if((value > data))	{ 	//travel right and insert the new node 
			if (rLink == NULL){
				rLink = new BTNode< value_type>(value);
			}
			else{
				rLink->add(value);
			}
		}
	}

	void remove_two(BTNode<value_type>* parent, BTNode<value_type>* target) {
		
		if (lLink != NULL)	{
			
			lLink->remove_two(this, target);
		}
		else {
														//this;	// successor node
			delete_From_Tree(this, parent, target);
														//parent;	// parent of successor node
				
														//target;	// node to remove
		}

	}

	void remove(BTNode<value_type>* parent,const value_type&  value){	// travels the tree to find the node to delete  
																		// deletes node if it has 1 child or zero child 
																		//calls remove_two if node has 2 child.
		
		if (data == value)	{
			if (rLink != NULL && lLink != NULL)				//node to delete has 2 child
				rLink->remove_two(parent, this);

			else if (parent->lLink == this && rLink==NULL) { //node to delete has 1 left child 
				parent->lLink = lLink; delete this;						// node is left of parent
			}
			else if (parent->lLink == this && lLink == NULL) { //node to delete has 1 right child 
				parent->lLink = rLink;	delete this;						//node is left of parent
			}
			else if (parent->rLink == this && lLink == NULL) { //node to delete has 1 right child 
				parent->rLink = rLink; delete this;					//node is right of parent
			}
			else if (parent->rLink == this && rLink == NULL) { 	//node to delete has 1 left child 
				parent->rLink = lLink;	delete this;						//node is right of parent
			}
			
			else if (rLink == NULL && lLink == NULL) { //0 child exists
				if(parent->lLink==this){ //node to delete is parent of left
						parent->lLink=NULL;
						 
						delete this;
						return;
				}
				else  { //node to delete is parent of right
						parent->rLink = NULL;
						
						delete this;
						return;
				}
			}
		}
				
		else if (value < data){
			if (lLink != NULL) {
				lLink->remove(this, value); //travel left
			}
		}
		else if (value > data){
			if(rLink!=NULL){
			rLink->remove(this,value); //travel right
			}
		}

		
  	}
	void delete_From_Tree(BTNode<value_type>* sucessor, BTNode<value_type>* parent, BTNode<value_type>* current)const {
		//current has 2 child			
		BTNode<value_type>* temp;
		int x = 0;
		current->data = sucessor->data;  //- swap data of current and sucessor
		if (sucessor->rLink != NULL) { //if sucessor right has right node then sucessor right should become parent's left. 
			if (sucessor->get_data() == current->rLink->get_data()) { //if parent right is sucessor then sucessor right is parents right.
				parent->rLink = sucessor->rLink;
				x = 1;
			}
			if(x!=1){
			parent->lLink = sucessor->rLink; // if parent right is not sucessor then sucessor right is parents left. 
			}
		}
		if (sucessor->rLink == NULL && (sucessor->get_data() == current->rLink->get_data())) {
			current->rLink = NULL;
		}
		
		sucessor = NULL;
		delete  sucessor;
		}
		

		
private:
	value_type data;
	BTNode<value_type>* lLink;
	BTNode<value_type>* rLink;
};
#endif
