/*****************************************************************************
* AUTHOR		: Nisha Davankar
* STUDENT ID		: 1045735
* Assignment #4		: Search Linked Lists
* CLASS			: CS1B
* SECTION		: M/W: 6:30pm- 10pm
* DUE DATE		: 11/6/17
*****************************************************************************/

#include "Header.h"

/******************************************************************************
* CREATELIST
* This function reads in the list of the Movie List from the text file using
* pointer and forms a linked list using the MovieList struct.

* PRE-CONDITIONS:
*
* POST-CONDITIONS:
*	RETURNS: *head
*****************************************************************************/
MovieList CreateList(ifstream &inFile)		//INPUT- the input file variable
{
	//DECLARATIONS
	MovieList *head;						//INPUT- the local head pointer 
	MovieList *perPtr;						//INPUT- second local pointer


	//INITIALIZING 
	head = NULL;
	perPtr = NULL;

	perPtr = new MovieList;


	//PROCESSING- the while loop reads the values in from the text file
	while (inFile && perPtr != NULL)
	{
		getline(inFile, perPtr->title);
		getline(inFile, perPtr->leadingactor);
		getline(inFile, perPtr->supportingActor);
		getline(inFile, perPtr->genre);
		getline(inFile, perPtr->alternatGenre);
		inFile >> perPtr->year;
		inFile >> perPtr->rating;
		inFile.ignore(1000, '\n');
		getline(inFile, perPtr->synopsis);
		inFile.ignore(1000, '\n');

		perPtr->next = head;
		head = perPtr;
		perPtr = new MovieList;
	}

	delete perPtr;
	perPtr = NULL;
	inFile.close();

	return *head;
}
