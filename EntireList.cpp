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
* ENTIRELIST
* This function outputs the entire list from the text file on an output file 
* through the MovieList struct with the head pointer that is passed in. It also 
* calls the word wrap function to word wrap the synopsis member of the MovieList 
* struct. 
*
* PRE-CONDITIONS:
*	The following need a defined value passed in
*		*head- the head pointer passes in through main
*		outFile- output file variable
*
* POST-CONDITIONS:
*	RETURNS: nothing
*		Outputs the members of the struct to the output file.
*****************************************************************************/
void EntireList(MovieList *head,			//INPUT- the head pointer passed in from main
				ofstream &outFile)	//OUTPUT- outfile variable
{
	//DECLARATIONS
	MovieList *perPtr;				//INPUT- local pointer
	int		  index;			//OUTPUT- Movie number

	//INITIALIZATIONS
	perPtr = NULL;
	perPtr = head;
	index = 0;

	cout << "\nListing all movies!\n";

	outFile << left;
	outFile << setw(8) << "MOVIE #" << setw(49) << "TITLE"
		<< setw(5) << "YEAR" << setw(7) << "RATING"
		<< setw(18) << "Genre" << setw(18) << "ALT GENRE"
		<< setw(20) << "LEAD ACTOR" << setw(19) << "SUPPORTING ACTOR"
		<< endl;
	outFile << "------- " << "------------------------------------------------ "
		<< "---- " << "------ " << "----------------- " << "----------------- "
		<< "------------------- " << "------------------ " << endl;

	while (perPtr != NULL)
	{
		outFile << setw(8) << index << setw(49) << perPtr->title << setw(5)
			<< perPtr->year << setw(7) << perPtr->rating << setw(18)
			<< perPtr->genre << setw(18) << perPtr->alternatGenre << setw(20);
		ShortenString(perPtr->leadingactor, outFile);
		outFile << setw(19) << perPtr->supportingActor << endl;

		perPtr = perPtr->next;
		index++;
	}
	outFile << right;
}
