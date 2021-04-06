#include <fstream>
#include <vector>
#include "module.h"

using namespace std;

class Floorplanner
{
public:
	Floorplanner(fstream& input_blk, fstream& input_net, double& alpha):
		_alpha(alpha), _outline_w(0), _outline_h(0), _numBlocks(0), 
		_numTerminals(0) {
		parseInput(input_blk, input_net);
	}
	~Floorplanner(){
		clear();
	}

	void parseInput(fstream& input_blk, fstream& input_net);
	void floorplan();

	void printInfo();
	void writeResult(fstream& outFile);

private:
	int _outline_w;
	int _outline_h;
	int _numBlocks;
	int _numTerminals;
	vector<Block*> _blockArray;
	vector<Terminal*> _terminalArray;
	vector<Net*> _netArray;

	double _alpha;
	void clear();
};
