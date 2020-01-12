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
* WORDWRAP
* This function word wraps the the synopsis member of the Movielist struct and
* outputs the word wrapped list into an output file.
*
* PRE-CONDITIONS:
*	The following need a defined value passed in
*		*head- the head pointer passes in through main
*		oFile- The outfile variable
*
* POST-CONDITIONS:
*	RETURNS: nothing
*		Outputs the synopsis string to the output file.
*****************************************************************************/
void WordWrap(string outputString,			//INPUT- string of synoposis from creatlist
			  ofstream &outFile)			//OUTPUT- outfile variable
{
	//DECLARATIONS
	int strlen;								//OUTPUT- the length of the string
	string outputWord;						//OUTPUT- the line that will be in the output
	string outputline;						//OUTPUT- the line that will be in the output
	int maxLength;							//INPUT- the max length the string can be
	int index;								//INPUT- counter until the length of the string

	//INITIALIZATIONS
	maxLength = 75;

	outputWord.clear();
	outputline.clear();

	//PROCESSING- the string length of the synopsis
	strlen = outputString.size();

	//PROCESSING-	for loop outputs the string by word wrapping 
	for (int index = 0; index < strlen; index++)
	{
		if (outputString[index] != ' ')
		{
			outputWord += outputString[index];
		}
		else
		{
			if (outputline.size() + outputWord.size() > maxLength)
			{
				outFile << outputline << endl;
				outputline.clear();
			}
			outputline += outputWord + ' ';
			outputWord.clear();
		}
	}

	if (outputWord.size() + outputline.size() > maxLength)
	{
		outFile << outputline << endl;
		if (outputWord.size() + outputline.size() != 0)
		{
			outFile << outputWord << endl;
		}
	}
	else
	{
		outFile << outputline + outputWord << endl;
	}

}