//Course: SENG1120
//Coded by: Alex Mendes 

#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class Student 
{
public:
	
	// Constructors
	Student();
	Student(const string, const int);

	// Destructor
    ~Student();

	// Setters
    void set_name(const string);
	void set_score(const int);

	// Getters
	string get_name() const;
	int get_score() const;

//Private member variables
private:
	string name; // student's name
	int score;	// student's score
};
ostream& operator <<(ostream&, const Student&);

bool operator == (const Student& s1, const Student& s2);

#endif