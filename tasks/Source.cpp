#include <iostream>
#include <string>
#include <fstream>
#include <istream>
//i'll do all of this in english and there's nothing you can do to stop me

//task 4:
//i feel like i'm doing this wrong
int sum(int* a, int n)
{
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		s += a[i];
	}
	return s;
}

bool IsFileEmpty(std::string& filename)
{
	std::ifstream currentFile(filename);
	if (!currentFile.is_open())
	{
		std::cout << "couldn't open the file\n";
		return false;
	}
	return currentFile.peek() == EOF;
}

int main()
{
	/*
	//task 1:
	int x = 3;
	int y = 4;
	std::cout << x * y + (y - x);
	
	//task 2:
	int arr[5];
	for (int i = 0; i < 5; i++)
	{
		arr[i] = i;
	}

	//task 3:
	//am i doing this right?
	std::string s = "hello";
	s[1] = 'a';
	std::cout << s;

	//task 5:
	// i know how to but i will comment it so it doesn't throw (pun not intentional) off other code;
	//throw - 1;
	*/
	//tasks 1 through 5 are commented above so taht they wouldn't mess with other code 

	std::ofstream file;
	std::string data, line;
	std::ifstream openfile;
	int choise;

	while (true)
	{
		std::cout << "what do you want?\n1 - view all notes\n2 - add a note\n3 - rewrite all notes\n0 - exit\n";
		std::cin >> choise;
		if (choise == 0)
		{
			break;
		}
		else if (choise == 1)//i've got no idea what's going on but when i add something to the notes and then try to view them it doesn't display anything, i don't know why and i don't know how to fix this
		{
			openfile.open("notes.txt"); 
			while (std::getline(openfile, line))
			{
				std::cout << line;
			}
			std::cout << "\n";
			file.close();
		}
		else if (choise == 2)
		{
			std::cin.ignore();
			file.open("notes.txt", std::ios::app);
			if (!file.is_open())
			{
				std::cerr << "this file doesn't exist\n";
				continue;
			}
			std::cout << "input whatever note you wanna add:\n";
			std::getline(std::cin, data, '\n');
			file << data + '\n';
			file.close();
			continue;
		}
		else if (choise == 3)
		{
			std::cin.ignore();
			file.open("notes.txt", std::ios::ate);
			if (!file.is_open())
			{
				std::cerr << "this file doesn't exist\n";
				continue;
			}
			std::cout << "input whatever you were going to write:\n";
			std::getline(std::cin, data, '\n');
			file << data + '\n';
			file.close();
			continue;
		}
		else
		{
			continue;
		}
		continue;
	}

	return 0;
}