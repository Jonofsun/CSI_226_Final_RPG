#include "Puzzle.h"

Puzzle::Puzzle(std::string fileName)
{
	this->correctAnswer = 0;

	std::ifstream inFile(fileName);
	int numOfAns = 0;
	int correct = 0;

	std::string answer = "";
	if (inFile.is_open())
	{
		std::getline(inFile, this->question);
		inFile >> numOfAns;
		inFile.ignore();
		for (size_t i = 0; i < numOfAns; i++)
		{
			std::getline(inFile, answer);
			this->answers.push_back(answer);
		}
		inFile >> correct;
		this->correctAnswer = correct;
		inFile.ignore();
	}
	else
		throw("Error loading file");

	inFile.close();
}

Puzzle::~Puzzle()
{

}

std::string Puzzle::getAsString() 
{
	std::string answers = "";

	for (size_t i = 0; i < answers.size(); i++)
	{
		answers += std::to_string(i) + ": " + this->answers[i] + "\n";
	}

	/*return this->question + "\n\n" +
		answers + "\n" +
		std::to_string(this->correctAnswer) + "\n";*/

	return this->question + "\n\n" +
		answers + "\n";
}