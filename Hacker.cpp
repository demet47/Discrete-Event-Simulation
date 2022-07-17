#include "Hacker.h"
#include <iostream>
#include <vector>

using namespace std;

vector<Hacker*> Hacker::hackers;
float Hacker::average_code_commit = 0;
float Hacker::average_code_line = 0;
int Hacker::totalSouv = 0;
int Hacker::numOfHackers = 0;



Hacker::Hacker(float t) {
	all_queue_waitings = 0;
	sq_enter_time = 0;
	sq_leave_time = 0;
	hq_enter_time = 0;
	hq_leave_time = 0;
	total_souvenir = 0;
	this->numOfCommit = 0;
	this->timeOfArrival = t;
	this->numOfCommitLines = 0;
	this->numOfCommit = 0;
}

void Hacker::commit(int commitLine) {
	//cout << commitLine << endl;
	//cout << numOfCommit << endl;
	
	this->numOfCommit++;
	this->numOfCommitLines += commitLine;
	
	//cout << this->numOfCommit << endl;
	//cout << this->numOfCommitLines << endl << endl;
	
	++average_code_commit;
	average_code_line += commitLine;
}


//getters

float Hacker::getAverageCodeCommit() {
	if (numOfHackers == 0) return 0;
	return average_code_commit / numOfHackers;
}

float Hacker::getAverageCodeLine() {
	if (numOfHackers == 0) return 0;
	return average_code_line / average_code_commit;
}

float Hacker::getQueuingDuration() {
	return all_queue_waitings;
}

int Hacker::getAvgSouvenir() {
	return ((float)totalSouv) / numOfHackers;
}

int Hacker::lessGibberishID() {
	float* min = nullptr;
	int minsID = -1;
	for (int i = 1; i <= numOfHackers; i++) {
		if (hackers[i]->total_souvenir == 6) {
			float a = hackers[i]->all_queue_waitings;
			if (min == nullptr) {
				min = new float(a);
				minsID = i;
			}
			else if (abs(*min - a) > 0.0001) {
				*min = a;
				minsID = i;
			}
		}
	}

	delete min;
	return minsID;
}

int Hacker::mostGibberishID() {
	float max = hackers[1]->all_queue_waitings;
	int maxID = 1;
	for (int i = 2; i <= numOfHackers; i++) {
		float a = hackers[i]->all_queue_waitings;
		if (abs(max - a) > 0.0001 && a > max) {
			max = a;
			maxID = i;
		}
	}
	return maxID;
}


bool Hacker::operator< (Hacker& h) {
	if (this->numOfCommit != h.numOfCommit) return this->numOfCommit < h.numOfCommit;
	else if (abs(this->hq_enter_time - h.hq_enter_time) >= 0.00001) return this->hq_enter_time > h.hq_enter_time;
	else return this->ID > h.ID;
}