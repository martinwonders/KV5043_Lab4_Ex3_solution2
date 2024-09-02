#include <iostream>
#include <fstream>
#include <sstream>
#include "window.h"
//1) ToDo: Include your filehandling.h file here

int main(int argc, char* argv[])
{
	//2) ToDo: Create a string variable to store the contents of the file
		
	//3) ToDo: Use your readFromFile(const std::string& fileName, std::string& fileContents);
	//function to read the entire file into the fileContents string
	

	//4) ToDo: Create a stringstream using the fileContents
	

	//5) ToDo Create a string variable to store a line of text
	
	//6) ToDo Create a string array with 5 elements (Why 5? check the windowParameters.txt file)
	

	while (std::getline(sStream, line))
	{
		//7) ToDo: Use your splitString(const std::string& str, char delimiter, std::string result[], const int arraySize);
		//function to split the delimited string into the string array
		
		std::string windowName =	//8) ToDo: use the element in the array that represents the windowName;
		int xPos =					//9) ToDo: use the element in the array that represents the xPos (Note: we are trying to store a string in an int);
		int yPos = 					//10) ToDo: use the element in the array that represents the yPos (Note: we are trying to store a string in an int);
		int width = 				//11) ToDo: use the element in the array that represents the width (Note: we are trying to store a string in an int);
		int height = 				//12) ToDo: use the element in the array that represents the height (Note: we are trying to store a string in an int);
		
		//We now have the parameters from the file to create a window
		Window window = Window(windowName, xPos, yPos, width, height);
		window.Run();
	}

	return 0;
}