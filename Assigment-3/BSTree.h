
/*Author: Suresh Balaiyan
Course: SENG 6120.
Student number:3302159.
Program Description: This program implements binary search tree using the given node
structure by creating nodes by using  BTNode class
*/
#include "MechPart.h"
#include<iostream>
#include<stdio.h>
#include"BTNode.h"

#ifndef BSTree_H
#define BSTree_H


template<typename value_type>
class BSTree
{
public:
	BSTree() { //default constructor
		root = NULL;
	}
	~BSTree() {

		delete_tree(root);
	}

	void delete_tree(BTNode< value_type>* p) { //destructor to delete the tree

		if (p != NULL) {

			delete_tree(p->get_lLink());
			delete_tree(p->get_rLink());
			p = NULL;
			delete p;
		}
	}

	void add(const value_type& value) {		// If root is null make new node and add to root
		if (root == NULL) {
			root = new BTNode< value_type>(value);
		}
		else {
			root->add(value);
		}
	}

	void inorder(BTNode<value_type> * p) {
		if (p != NULL) {
			inorder(p->get_lLink());
			std::cout << p->get_data() << endl;
			inorder(p->get_rLink());

		}

	}
	void inorder() { //called from << overloaded operator
		inorder(root);
	}

	void remove(const value_type& deleteItem) { //if tree empty

		if (root == NULL) {
			cout << "can't remove from empty tree";
			return;
		}

		if (root->get_data() == deleteItem) {
			if (root->get_lLink() == NULL && root->get_rLink() == NULL) {//root has no children
				delete  root; //delete root
				cout << "Tree has no nodes";
				return;
			}

			else if (root->get_lLink() == NULL && root->get_rLink() != NULL) { //root has right child
				BTNode<value_type> * temp = root->get_rLink();
				root->set_rLink(NULL);
				root = NULL;
				delete root;
				root = temp;
			}
			else if (root->get_lLink() != NULL && root->get_rLink() == NULL) {//root has left child
				BTNode<value_type> * temp = root->get_lLink();
				root->set_lLink(NULL);
				root = NULL;
				delete root;
				root = temp;
			}
			else if (root->get_lLink() != NULL && root->get_rLink() != NULL) {//root has left child
				root->remove(root, deleteItem);
			}

		}

		else {
			root->remove(root, deleteItem); // other than root and its child to be deleted.
		}
	}


	int calculate_Code(BTNode<value_type> *p, int &count) { //calculate number of codes
		if (p != NULL) {
			count++;
			calculate_Code(p->get_lLink(), count);
			calculate_Code(p->get_rLink(), count);

		}
		return count;
	}

	int calculateParts() { //calculate code
		int count = 0;
		count = calculate_Code(root, count);
		cout << endl;
		return count;
	}

	int calculate_Quantity(BTNode<value_type> *p, int &quantity) { //calculate total quantity
		if (p != NULL) {
			quantity = quantity + p->get_data().get_quantity();

			calculate_Quantity(p->get_lLink(), quantity);

			calculate_Quantity(p->get_rLink(), quantity);
		}
		return quantity;
	}

	int calculateInventory() { //calculate total quantity
		int quantity = 0;
		quantity = calculate_Quantity(root, quantity);
		return quantity;
	}
private:
	BTNode<value_type> *root;
};
template<typename value_type>
ostream& operator <<(ostream& out, BSTree<value_type>& list) {//operator overload << to display the output

	list.inorder();
	return out;
}
#endif

