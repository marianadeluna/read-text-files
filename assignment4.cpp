//Mariana De Luna
// Program that reads a text file of students and the courses they are taking
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class student
{
public: 
	string name; //Variables for the class
	int classes; //Size for the Dynamic array
	string* classIDs; // **** Pointer to create the Array of the classes
};

int main()
{
	ifstream file("courses.txt");
	student* StudentArray; //Pointer to create the Array of the "Student" Class
	int studentNum;
	if (file.is_open()) //reading from the file
	{
		file >> studentNum;
		StudentArray = new student[studentNum]; //Creating a dynamic array here with the size read from the file
	}
	else
	{
		cout << "File did not open" << endl; //If the file does not open we are closing the program
		exit(1);
	}

	//Getting name, number of classes, and the class IDS here
	for (int i = 0; i < studentNum; i++)
	{
		string input1;
		string input2;
		file >> input1;
		file >> input2;
		input1 += " ";
		input1 += input2;
		StudentArray[i].name = input1;
		file >> StudentArray[i].classes;
		StudentArray[i].classIDs = new string[StudentArray[i].classes]; //dynamic array with size number of classes
		for (int j = 0; j < StudentArray[i].classes; j++)
		{
			file >> StudentArray[i].classIDs[j];
		}
	}

	file.close(); //done reading from the file so we're closing it

	char MenuChoice = ' ';
	while (MenuChoice != 'Q') //Display menu with command prompts
	{
		cout << "Enter the Menu choice or [Q] to quit " << endl;
		cout << "[D] to display all students and courses " << endl;
		cout << "[S] to display courses for a student " << endl;
		cout << "[C] to display students taking a course " << endl;
		cin >> MenuChoice;
		MenuChoice = toupper(MenuChoice);
		
			if(MenuChoice == 'Q')
				exit(1);
			else if(MenuChoice == 'D')
			{
				cout << "Name " << setw(30) << "Courses " << endl;
				for (int i = 0; i < studentNum; i++)
				{
					cout << StudentArray[i].name << setw(20);
					for (int j = 0; j < StudentArray[i].classes; j++)
					{
						cout << StudentArray[i].classIDs[j] << " ";
					}
					cout << endl;
				}
			}
			else if (MenuChoice == 'S')
			{
				cout << "Please enter the student name: ";
				string toSearch;
				string input1;
				string input2;
				cin >> input1;
				cin >> input2;
				input1 += " ";
				input1 += input2;
				toSearch = input1;
				for (int i = 0; i < studentNum; i++) //Searching the Array of Students to match the name
				{
					if (toSearch == StudentArray[i].name)
					{
						cout << StudentArray[i].name << " is taking: ";
						for (int j = 0; j < StudentArray[i].classes; j++)
						{
							cout << StudentArray[i].classIDs[j] << " ";
						}
						cout << endl;
					}
				}
			}
			else if (MenuChoice == 'C')
			{
				string toSearch;
				cout << "Please enter a course: "; //goes through EVERY student and searches their ClassesID array to check
				cin >> toSearch;				  //to see if they are enrolled in the course
				cout << "Students taking " << toSearch << endl;
				for (int i = 0; i < studentNum; i++)
				{
					for (int j = 0; j < StudentArray[i].classes; j++)
					{
						if (StudentArray[i].classIDs[j] == toSearch)
							cout << StudentArray[i].name << endl;
					}
				}
				cout << endl;
			}
			cout << endl;
	}
}