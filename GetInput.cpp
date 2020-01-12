/*****************************************************************************
* AUTHOR		: Nisha Davankar
* STUDENT ID	: 1045735
* Assignment #4	: Search Linked Lists
* CLASS			: CS1B
* SECTION		: M/W: 6:30pm- 10pm
* DUE DATE		: 11/6/17
*****************************************************************************/

#include "header.h"

/******************************************************************************
* LISTOPTION
* This function outputs a menu, for the user to chose an option. It then returns 
* the user input integer to main. 
*
* PRE-CONDITIONS:
*	The following need a defined value passed in
*		none
*
* POST-CONDITIONS:
*	RETURNS: option
*******************************************************************************/
ListOption GetInput()
{
	//DECLARATION
	int		   userInput;					//INPUT- user entered choice	
	ListOption option;						//OUTPUT- user entered choice

	//INITIALIZATION
	userInput = 0;

	//MENU OPTIONS 
	cout << "\n\n\DVD MENU OPTIONS\n" << endl
		 << "1 - Output Entire List" << endl
		 << "2 - Title Search" << endl
		 << "3 - Genre Search" << endl
		 << "4 - Actor Search" << endl
		 << "5 - Year Search" << endl
		 << "6 - Rating Search(0 - 6)" << endl
		 << "0 - EXIT" << endl
		 << "Enter an option(0 to exit) : ";

	//PROCRESSING- checks if the userinput is an integer
	if (!(cin >> userInput))
	{
		cout << "\n**** Please enter a NUMBER between 0 to 6 ****\n";
		cin.clear();
	}

	else if (userInput < 0 || userInput > 6)
	{
		cout << left;
		cout << "\n**** " << "The number " << userInput << setw(31) << " is an invalid entry "
			 << "****" << endl;
		cout << "**** " << setw(43) << "Please input a number between 0 to 6 "
			 << "****" << endl;
		cout << right;
	}

	else
	{
		option = ListOption(userInput);

		return option;
	}

	cin.ignore(1000, '\n');
}

