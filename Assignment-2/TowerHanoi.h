
/*Author: Suresh Balaiyan
Course: SENG 6120.
Student number:3302159.
Program Description: This program implements the stack which uses linked list and which uses node structure.
*/
#include<iostream>
#include<string.h>
#include<list>
#include "LStack.h"
class TowerHanoi
{

public:

	TowerHanoi(int i); //default constructor
	~TowerHanoi(); // destructor
	void move(int i, int y); //moves a list from one stack into other stack
	bool compare(string, string)const; // compare inputs of string data.
	bool gameEnded()const; //checks whether game has ended ie all 
	bool checkWin()const; //check whethet
	void getDataPrint_h()const; //Prints the data from all the nodes.

private:
	int discs; //number of discs played in the game
	list<LStack<string >* >myList; //std::list container is used to contain LStack class
	LStack<string> *L1, *L2, *L3; //pointer of LStack



};

ostream& operator <<(ostream& out, TowerHanoi& list); //operator overload to display the contents of the stack


