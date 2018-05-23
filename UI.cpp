#include "UI.h"
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

/*
Prints the menu, the options given to the user
*/
void UI::printMenu()
{
	cout << "----------------------------------------------------" << endl;
	cout << "Options are: \n" << endl;
	cout << "1.Add new medical case" << endl;
	cout << "2.Treat a person" << endl;
	cout << "3.See all current cases" << endl;
	cout << "0.Exit" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << endl;
}


/*

The most important function of the UI. It calls the function for displaying the menu, then reads a command and makes
function calls in order to execute what the user wants.
*/
void UI::run() {
	while (1) {
		printMenu();
		int cmd{ -1 };
		do{
			cout << "Give your command: "<<endl;
			cin >> cmd;
			cout << endl;
			}
		while (cmd < 0 || cmd>4);
			switch (cmd) {
			case 0: {
				return;
			}
			case 1: {
				string name,issue;
				cin.ignore();
				cout << "Give the name of the patient:";
				getline(cin, name);
				cout << "Give medical issue:";
				getline(cin, issue);
				this->controller.addController(name, issue);
				displayAll();
				break;

			}
			case 3: {
				displayAll();
				break;
			}
			case 2: {
				this->controller.treatPerson();
				displayAll();
				
				break;
			}
					
		}

	}
}


void UI::displayAll() {
	/*
	Displays all the cases in the queue.
	For each priority the people who have it are shown.

	*/
	unordered_map<int, Node*> map = this->controller.getQueue().getMap();

	if (this->controller.nrOfCases() > 0) {	//checks to have cases to display
		for (auto element : map) {
			cout << "People with priority " << element.first << ":\n";
			Node *currentNode = element.second;
			while (currentNode != NULL)
			{
				cout << currentNode->info << endl;
				currentNode = currentNode->next;
			}

		}
	}
	else {
		cout << "No cases in the queue!" << endl;
	}

	
}