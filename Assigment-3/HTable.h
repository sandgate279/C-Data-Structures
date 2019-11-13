#include "LinkedList.h"
#include<iostream>
#include<stdio.h>
#include <list> 
#include "MechPart.h"
using namespace std;
/*Author: Suresh Balaiyan
Course: SENG 6120.
Student number:3302159.
Program Description: This program implements a hash table using the given node
structure by creating nodes by using  BTNode class
*/
#ifndef HTable_H
#define HTable_H
template<typename value_type>
class HTable
{
public:
	   
	HTable() { //default constructor initializes 300 data*
		int i = 0;
		while (i < 300)	{
			data[i] = NULL;
			i++;
		}
	}
	~HTable() { //destructor to delete the table.
		int i = 0;
		while (i < 300) {
			data[i] = NULL;
			delete data[i];
			i++;
		}
	}

	// hash function to map values to key 
	int hashfun(const value_type& value)const{
		int position = 0;
		string temp = value.get_code();
		for (int i = 0; i < (int)temp.length(); i++){
			position += (i + 1) * (i + 1) * temp.at(i);			
		}		
		return position % bucket;
	}


	void remove(value_type& val){ //removes the given node
		int index_val = hashfun(val);
		if (data[index_val] != NULL) {
			int j=data[index_val]->removeNode(val);
			if (j > 0)data[index_val] = NULL; //make data[index]=NULL
		}
	}

	void add(const value_type& val){ //adds a new node
		int index = 0;
		index = hashfun(val);		
		LinkedList<value_type>* p = data[index];
		if(p==NULL)	{
			data[index] = new	LinkedList<value_type>();
			data[index]->addToHead(val);			
		}
		else {
			data[index]->add_L(val);
		}
	}
	
	
		void  get_Data()const{ //prints the data from LinkedList
			int i = 0;
			while (i < 300)	{
			if(data[i]!=NULL)
			data[i]->getdata_Print_L();
				i++;
			}
		}
		int calculateParts()const{ // calculate number of codes

			int i = 0,count = 0;
					while (i < 300) {
						if (data[i] != NULL){
							count = data[i]->calculate_LParts(count);
						}
						i++;
					}
					return count;
					
				}
		int calculateInventory()const { // calculate qty of the table

			int i = 0, count = 0;
			while (i < bucket) {
				if (data[i] != NULL) {
					count = data[i]->calculate_LQty(count);
				}
				i++;
			}
			return count;

		}
	private:
	int bucket=300;
	LinkedList<value_type> *data[300];
};

template<typename value_type>
ostream& operator <<(ostream& out, HTable<value_type>& list) //operator overload << to display the output
{
	list.get_Data();

	return out;
}

#endif

