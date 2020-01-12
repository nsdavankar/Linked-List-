/*****************************************************************************
* AUTHOR		: Nisha Davankar
* STUDENT ID	: 1045735
* Assignment #4	: Search Linked Lists
* CLASS			: CS1B
* SECTION		: M/W: 6:30pm- 10pm
* DUE DATE		: 11/6/17
*****************************************************************************/

#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct MovieList							//Struct of the movielist
{
	string title;
	string leadingactor;
	string supportingActor;
	string genre;
	string alternatGenre;
	int year;
	int rating;
	string synopsis;

	MovieList *next;
};

enum ListOption								//Enumerated type for the list
{
	EXIT,
	ENTIRE,
	TITLE,
	GENRE,
	ACTOR,
	YEAR,
	RATING
};

/*****************************************************************************
* FUNCTION PrintHeader
*-----------------------------------------------------------------------------
* 	This function receives an output variable, student name, class day/time,
* 		assignment name, assignment type, and assignment/lab # then outputs
* 		the appropriate header
* 		==> returns nothing - This will output the class heading.
*-----------------------------------------------------------------------------
******************************************************************************/
void PrintHeader(ostream  &out,				// IN/OUT - output file
				 string   stName,			// IN     - student name to output
				 string   clTime,			// IN     - class day/time to output
				 string   asName,			// IN     - assignment name to output
				 char     asType,			// IN     - assignment type
				 int      asNum);			// IN     – assign. number to output

/******************************************************************************
* CREATELIST
* This function reads in the list of theh movie list from the text file using
* pointer into a linked list.
*****************************************************************************/
MovieList CreateList(ifstream &inFile);		//INPUT- infile variable

/******************************************************************************
* OUTPUTLIST
* This function recieves the list of movie names passed in through main with
* the head pointer and putputs the movie list to an output file.
*****************************************************************************/
void EntireList(MovieList *head,			//INPUT- the MovieList head pointer
				ofstream  &outFile);		//OUTPUT- outfile variable

/******************************************************************************
* WORDWRAP
* This function word wraps the the synopsis member of the Movielist struct and
* outputs the word wrapped list into an output file.
*****************************************************************************/
void WordWrap(string outputString,			//INPUT- string of synoposis from creatlist
			  ofstream &outFile);			//OUTPUT- outfile variable
/******************************************************************************
* LISTOPTION
* This function outputs a menu, for the user to chose an option. It then returns
* the user input integer to main.
*****************************************************************************/
ListOption GetInput();

/******************************************************************************
* SEARCH
* This function will recieve output file variable, the head pointer and
* user selcted option from the menu. Then the function will search the chosen
* member of the MovieList struct from the list. The funtion will output if the
* search item  was found and how many instances it occured in the list. This
* function will also output the information of the movies from the list on the
* output file. If the option is title search, it will call the word wrap function
* to word wray the synopsis member of the MovieList struct.
*****************************************************************************/
void Search(ofstream   &outFile,			//OUTPUT- the output file variable
			MovieList  *head,				//INPUT- the MovieList head pointer
			ListOption choice);				//INPUT- user entered choice

/******************************************************************************
* ShortenString
* This function shortens the length of the string of the actors name if it is 
* larger than the max length.
*******************************************************************************/
void ShortenString(string stringName,	//INPUT- the string of actors name
				   ofstream &outFile);	//OUTPUT- output file variable

#endif /* HEADER_H_*/

