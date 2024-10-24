#include <iostream>
#include <fstream>
#include <sstream>
//1) ToDo: include the window.h header
#include "window.h"
//2) ToDo: include the filehandling header
#include "filehandling.h"

int main(int argc, char* argv[])
{
	//3) ToDo: Create a C++ string namd fileContents
	std::string fileContents;
	
	//4) ToDo: Create a const C++ string named fileName and assign it a literal string to match the fileName
	//const std::string fileName = "windowParameters.txt";

	//5) ToDo: Call the readFromFile function using the fileName and fileContents strings
	readFromFile(fileParameters::FILE_NAME, fileContents);

	//6) ToDo: Create a stringstream object named sStream using the fileContents string
	std::stringstream sStream(fileContents);

	//7) ToDo: Create a string variable to store a line of text name it line
	std::string line;
	
	//8) ToDo: Create a string array named tokens with 6 elements (Why 6? check the windowParameters.txt file)
	//The first field is the name of the object the remaining fields are the attributes of the object
	std::string tokens[6];

	//9) ToDo: Get a line from the sStream using getline(stringstream, string) 
	// this line is the window with the parameters check the windowParameters.txt file
	std::getline(sStream, line);

	//10) ToDo: Use your splitString(const std::string& str, char delimiter, std::string result[], const int arraySize);
	//function to split the delimited string into the string array
	splitString(line, fileParameters::DELIMITER, tokens, 6);

	//We now have the parameters from the file to create a window
	Window window = Window(tokens[1], stoi(tokens[2]), stoi(tokens[3]), stoi(tokens[4]), stoi(tokens[5]));

	//The remainder of the file represents things to put in the window (rectangles for now)
	//There could be many so we loop through grabbing line by line
	while (std::getline(sStream, line))
	{
		//11) ToDo: Use your splitString(const std::string& str, char delimiter, std::string result[], const int arraySize);
		//function to split the delimited string into the string array, this time we only have 5 elements
		//(Why 5? check the windowParameters.txt file)
		splitString(line, fileParameters::DELIMITER, tokens, 5);
		
		//Variable required to create a rectangle, you don't need to know anything about the rectangle for now
		//other than is needs these variables, they will be assigned from the tokens array
		float recXPos, recYPos, recWidth, recHeight;

		//12) ToDo: Use an if statment to test an element in the array for the string "rectangle"
		//if it is we need to use the tokens array to assign values to the rectangles variables
		if (tokens[0] == configParameters::RECT_IDENTIFIER)
		{
			recXPos = std::stof(tokens[1]);	//13) ToDo: use an element in the array that represents the xPos of the rectangle (Note: we are trying to store a string in a float);
			recYPos = std::stof(tokens[2]); //14) ToDo: use an element in the array that represents the yPos (Note: we are trying to store a string in a float);
			recWidth = std::stof(tokens[3]); //15) ToDo: use an element in the array that represents the width (Note: we are trying to store a string in a float);
			recHeight = std::stof(tokens[4]); //16) ToDo: use an element in the array that represents the height (Note: we are trying to store a string in a float);
			
			//This next line creates a user defined data type (struct) Rectangle (we will discuss these in week 7). 
			// We are using the data read in from the file.
			Rectangle rec = { recXPos, recYPos, recWidth, recHeight };

			//17) ToDo: The window object has an AddRectangle() method use that to add the rectangle to the window. 
			window.addRectangle(rec);
		}
	}

	//Now we can run the window
	window.Run();
	return 0;
}
