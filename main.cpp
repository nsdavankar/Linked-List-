/*****************************************************************************
* AUTHOR		: Nisha Davankar
* STUDENT ID	: 1045735
* Assignment #4	: Search Linked Lists
* CLASS			: CS1B
* SECTION		: M/W: 6:30pm- 10pm
* DUE DATE		: 11/6/17
*****************************************************************************/

#include "Header.h"


/*****************************************************************************
* Movie List Intro to Linked Lists
*----------------------------------------------------------------------------
* This program will allow the user to enter input file and outout file name
* It will read in the movie list from the text file using points. It will assign
* the values from the text file to the MovieList struct.
*
* It will output the members of the struct to an output file.
*
* It will word wrap the synopsis struct member and output the synopsis string from
* CreateList fucntion to the output file.
*
*----------------------------------------------------------------------------
* INPUT:
*		*head-	the head pointer
*****************************************************************************/

int main()
{
	//DECLARATIONS 
	ifstream   inFile;						//INPUT- input file variable
	ofstream   outFile;						//OUTPUT- output file variable
	string     inputFile;					//INPUT- user entered input file name
	string     outputFile;					//INPUT- user entered output file name
	MovieList  *head;						//INPUT- the Movie list head pointer
	ListOption choice;						//INPUT- user entered choice from menu

	/*****************************************************************************
	* FUNCTION PrintHeader
	*-----------------------------------------------------------------------------
	* 	This function receives an output variable, student name, class day/time,
	* 		assignment name, assignment type, and assignment/lab # then outputs
	* 		the appropriate header
	* 		==> returns nothing - This will output the class heading.
	*-----------------------------------------------------------------------------
	******************************************************************************/
	PrintHeader(cout, "Nisha Davankar", "M/W: 6:30pm",
		"Searching Linked Lists", 'A', 5);

	//INITIALIZING 
	head = NULL;

	head = new MovieList;
	
	//PROCESSING- Opening the input and output files
	cout << "Which input file would you like to use(type d for default file)? ";
	getline(cin, inputFile);

	if (inputFile == "d")
	{
		inFile.open("Input.txt");
	}
	else 
	{
		inFile.open(inputFile);
	}

	cout << "Which output file would you like to use(type d for default file)? ";
	getline(cin, outputFile);

	if (outputFile == "d")
	{
		outFile.open("Output.txt");
	}
	else
	{
		outFile.open(outputFile);
	}

	/******************************************************************************
	* CREATELIST
	* This function reads in the list of the Movie List from the text file using
	* pointer and forms a linked list using the MovieList struct.
	*****************************************************************************/
	*head = CreateList(inFile);
	
	/***************************************************************************
	* PROCESSING - This is the main loop for the program. This while loop will
	* 			   run until the user decides to exit
	**************************************************************************/
	
	//PROCESSING- do while loop to call the search function depending on menu choice
	do
	{
		/******************************************************************************
		* GETINPUT
		* This function outputs a menu, for the user to chose an option. It then returns
		* the user input integer to main.
		*******************************************************************************/
		choice = GetInput();

		switch (choice)
		{
			/******************************************************************************
			* ENTIRELIST
			* This function outputs the entire list from the text file on an output file
			* through the MovieList struct with the head pointer that is passed in. It also
			* calls the word wrap function to word wrap the synopsis member of the MovieList
			* struct.
			*****************************************************************************/
		case ENTIRE: EntireList(head, outFile);
			break;

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
		case TITLE: Search(outFile, head, choice);
			break;

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
		case GENRE: Search(outFile, head, choice);
			break;

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
		case ACTOR: Search(outFile, head, choice);
			break;

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
		case YEAR: Search(outFile, head, choice);
			break;

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
		case RATING: Search(outFile, head, choice);
			break;
		}
	} while (choice != EXIT);

	//PROCESSING- CLosing the input and output files
	inFile.close();
	outFile.close();

	return 0;
}
