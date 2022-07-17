#include "Event.h"
#include <iostream>
using namespace std;

CodeCommit::CodeCommit(int ID, int numOfLineChange, float t) {
	this->numOfLineChange = numOfLineChange;
	this->ID = ID;
	this->time = t;
	barkod = "Commit code";
}

void CodeCommit::execute() {
	Hacker::hackers.at(ID)->commit(numOfLineChange);
}

