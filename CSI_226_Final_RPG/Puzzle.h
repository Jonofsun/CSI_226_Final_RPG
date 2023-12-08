#pragma once
#include<string>
#include<vector>
#include<fstream>
#include<iostream>

class Puzzle
{
public:
	Puzzle(std::string fileName);
	virtual ~Puzzle();
	std::string getAsString();

	inline const int& getCurrectAns()const { return this->correctAnswer; }

private:
	std::string question;
	std::vector<std::string> answers;
	int correctAnswer;
};

