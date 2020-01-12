/*****************************************************************************
* AUTHOR		: Nisha Davankar
* STUDENT ID	: 1045735
* Assignment #4	: Search Linked Lists
* CLASS			: CS1B
* SECTION		: M/W: 6:30pm- 10pm
* DUE DATE		: 11/6/17
*****************************************************************************/

#include "Header.h"

/******************************************************************************
* ShortenString
* This function shortens the length of the string of the actors name if it is 
* larger than the max length.
*
* PRE-CONDITIONS:
*	The following need a defined value passed in
*		stringname- the string of the actors name
*
* POST-CONDITIONS:
*	RETURNS: nothing
*		Outputs the shortened name to the outfile
*******************************************************************************/
void ShortenString(string stringName,	//INPUT- the string of actors name
				  ofstream &outFile)	//OUTPUT- output file variable
{
	//DECLARATIONS
	int stringActorLength;				//INPUT- the length of the string
	int maxLength;						//INPUT- the max length the string
										//can be
	string newString;					//OUTPUT- the new shortned string 

	stringActorLength = stringName.length();

	//INITIALIZATIONS
	maxLength = 16;


	if (stringActorLength > maxLength)
	{
		newString = stringName.substr(0, maxLength);
		outFile << newString + "...";
	}
	else
	{
		outFile << stringName;
	}

}