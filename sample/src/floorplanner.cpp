#include <iostream>
#include "floorplanner.h"
#include <string>
using namespace std;

//parser
size_t myStrGetTok
(const string& str, string& tok, size_t pos = 0)
{
   size_t begin = str.find_first_not_of(' ', pos);
   if (begin == string::npos) { tok = ""; return begin; }
   size_t end = str.find_first_of(' ', begin);
   tok = str.substr(begin, end - begin);
   return end;
}

void getTokens
(const string& line, vector<string>& tokens)
{
   string token;
   size_t n = myStrGetTok(line, token);
   while (token.size()) {
      tokens.push_back(token);
      n = myStrGetTok(line, token, n);
   }
}

void Floorplanner::parseInput
(fstream& input_blk, fstream& input_net)
{
	string line;
	vector<string> tokens;
	tokens.reserve(4);

	//parse blk
	//Outline
	getline(input_blk, line);
	getTokens(line, tokens);
	_outline_w = stoi(tokens[1]);
	_outline_h = stoi(tokens[2]);
	tokens.clear();

	//NumBlocks
	getline(input_blk, line);
	getTokens(line, tokens);
	_numBlocks = stoi(tokens[1]);
	tokens.clear();

	//NumTerminals
	getline(input_blk, line);
	getTokens(line, tokens);
	_numTerminals = stoi(tokens[1]);
	tokens.clear();

	//for debug
	printInfo();
/*
	while (getline(input_blk, str)){
		vector<string> tokens;
		tokens.reserve(4);
		
		getTokens		
	}
*/	
}

void Floorplanner::floorplan()
{

}

void Floorplanner::writeResult(fstream& outFile)
{

}

void Floorplanner::printInfo()
{
	cout << "outline w = " << _outline_w << endl;
	cout << "outline h = " << _outline_h << endl;
	cout << "num blocks = " <<  _numBlocks << endl;
	cout << "num terminals =" << _numTerminals << endl;
}

void Floorplanner::clear()
{

}
