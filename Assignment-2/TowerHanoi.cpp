/*Author: Suresh Balaiyan
Course: SENG 6120.
Student number:3302159.
Program Description: This program implements the stack which uses linked list and which uses node structure.
*/
#include<iostream>
#include <string>
#include "TowerHanoi.h"




TowerHanoi::TowerHanoi(int dis) //constructor that inializes the number of rings to play the game.
{
	L1 = new LStack<string>();
	L2 = new LStack<string>();
	L3 = new LStack<string>();

	myList.push_front(L1); //stack is pushed into the container std::list
	myList.push_front(L2);//stack is pushed into the container std::list
	myList.push_front(L3); //stack is pushed into the container std::list

	string s[6] = { "     x     ","     xxx     ","     xxxxx     ","     xxxxxxx","     xxxxxxxxx ","     xxxxxxxxxxx" }; //values that represents the number of discs.
	while (dis > 0)
	{


		L1->push(s[dis - 1]); //string values are pushed ino L1 according to the number of discs selected.

		dis--;
	}


}
TowerHanoi::~TowerHanoi() //default destructor 
{

	discs = NULL;


}
//precondition: moves rings from one rod to another
//precondition: none

void TowerHanoi::move(int From, int To) //move's only one disc from one stack to other.
{

	if (From == To) //check From and To are same.
	{
		cout << "From and To should be different";
		return;
	}
	/*  Moving discs from L1--------------------------------------------------------------------------------------------> to L2 or L3    */


	if (From == 1 && (!L1->isEmpty()))  //From is L1 and not empty	
	{

		if (To == 3 && L3->isEmpty())
		{							//Move to L3 without comparing strings in both the stacks
			L3->push(L1->pop());
			return;
		}
		else if (To == 3)
		{
			string s1 = L1->getData_LS(); //gets the data from the head of L1
			string s2 = L3->getData_LS(); //gets the data from the head of L3
			bool status = compare(s1, s2); //compares the string from L1 and L3
			if (status) //if L3 string > L1 string then pop from L1 and push into L3
			{
				L3->push(L1->pop());

			}


		}


		if (To == 2 && L2->isEmpty()) //To is L2 and not empty	
		{
			L2->push(L1->pop());                  //Move to L2 without comparing strings in both the stacks
		}
		else if (To == 2)
		{
			string s1 = L1->getData_LS(); //gets the data from the head of L1
			string s2 = L2->getData_LS(); //gets the data from the head of L2
			bool status = compare(s1, s2); //compares the string - L1 and L2
			if (status) //if L2 string > L1 string then pop from L1 and push into L2
			{
				L2->push(L1->pop());

			}


		}


	}
	/*  Moving discs from L2-------------------------------------------------------------------------------------> to L1 or L3    */

	if (From == 2 && (!L2->isEmpty())) //From is 2 and not empty
	{

		if (To == 3 && L3->isEmpty())
		{							//Move to L3 without comparing strings in both the stacks
			L3->push(L2->pop());
			return;
		}
		else if (To == 3)
		{
			string s1 = L2->getData_LS();//gets the data from the head of L2
			string s2 = L3->getData_LS(); //gets the data from the head of L3
			bool status = compare(s1, s2); //compares the string - L2 and L3
			if (status)//if L3 string > L2 string then pop from L3 and push into L2
			{
				L3->push(L2->pop()); //if L2 string > L3 string then pop from L2 and push into L3

			}


		}


		if (To == 1 && L1->isEmpty())
		{								//Move to L1 without comparing strings in both the stacks
			L1->push(L2->pop());
		}
		else if (To == 1)
		{
			string s1 = L2->getData_LS(); //gets the data from the head of L2
			string s2 = L1->getData_LS(); //gets the data from the head of L1
			bool status = compare(s1, s2);  //if L1 string > L2 string then pop from L2 and push into L1
			if (status)
			{
				L1->push(L2->pop());

			}


		}


	}


	/*  Moving discs from L3-----------------------------------------------------------------------------------------------> to L1 or L3    */
	if (From == 3 && (!L3->isEmpty())) //From is 3
	{

		if (To == 1 && L1->isEmpty())
		{							//Move to L1 without comparing strings in both the stacks
			L1->push(L3->pop());
			return;
		}
		else if (To == 1)
		{
			string s1 = L3->getData_LS();  //gets the data from the head of L3
			string s2 = L1->getData_LS();//gets the data from the head of L1
			bool status = compare(s1, s2);  //if L1 string > L3 string then pop from L3 and push into L1
			if (status)
			{
				L1->push(L3->pop());

			}


		}


		if (To == 2 && L2->isEmpty())
		{								//Move to L2
			L2->push(L3->pop());
		}
		else if (To == 2)
		{
			string s1 = L3->getData_LS();
			string s2 = L2->getData_LS();
			bool status = compare(s1, s2);
			if (status)
			{
				L2->push(L3->pop()); //if L3 string > L2 string then pop from L3 and push into L2

			}


		}


	}


}
//precondition: receives the input as 2 strings to compare .
//post condition:returns bool value
bool TowerHanoi::compare(string s1, string s2)const //function that compares the given strings,alphabetically
{
	int i = s2.compare(s1); //compare s1 and s2 strings.
	if (i == -1) // returns-1 if s2 < s1
	{
		cout << "Incompatable" << endl;
		return false;

	}
	else
		return true;

}
//precondition: checks the game is ended
//postcondition:returns bool value
bool TowerHanoi::gameEnded() const//checks L1 and L2 is empty ,then returms True else false.
{

	if (L1->isEmpty() && L2->isEmpty())
	{
		cout << "Game ended";
		return true;
	}
	else
	{
		cout << "Game is still in progress";
		return false;
	}



}
//precondition: checks the game is ended
//postcondition:returns bool value
bool TowerHanoi::checkWin()const //checks the player has won the game.
{

	if (L1->isEmpty() && L2->isEmpty())
	{
		cout << "Game ended";
		return true;
	}
	else
	{
		cout << "Game is still in progress";
		return false;
	}



}

//precondition: prints the final output of the program
//postcondition:none
void TowerHanoi::getDataPrint_h()const
{

	string str;
	string str1;
	string str2;
	string str3;
	string outputString = "---------------------------------------------\n "
		"    1              2                  3  ";
	str = L1->getData_Print_LS();

	str1 = L2->getData_Print_LS();


	str2 = L3->getData_Print_LS();
	cout << "L1";
	cout << str+"\n";
	cout << "L2";
	cout << str1+"\n";
	cout << "L3\n";
	cout << str2;
	cout<<"\n";

}
//precondition:<< overload the operator calles the getDataPrint_h() which in turn calls getDataPrint_LS()
//post condition:return std::out
ostream& operator <<(ostream& out, TowerHanoi& list) //operator overload << to display the output
{



	list.getDataPrint_h();
	return out;
}















