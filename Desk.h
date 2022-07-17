#include "Hacker.h"
#include<vector>
#include<queue>
#include<string>
using namespace std;

#ifndef DESK_H
#define DESK_H

template<typename T>
class CompDesk {
public:
	bool operator() (T* e1, T* e2) {
		return *e1 < *e2;
	};
};

class Desk {
public:
	Desk(string type);
	static float getAvgTurnaroundTime(); // returns average turnaround time
	static int invalid_attempt_for_queuing;
	static int invalid_attempt_for_overgifting;
	void newDesk(float opDur);
	float getAverageWaiting();
	bool processNew(Hacker* h, bool enter);
	int max_len_of_queue;
	string type;
	bool tablesFull(float time);
	std::vector<pair<float, float>> desks; //first float nextAvailableTime, second float operationDuration
	static float avg_turnaround_time;
	static int total_people_queued; //
	int q; // int that stores the number of current hackers in the queue
	float average_waiting; //later divide this to total people queued,
	pair<float,float>* findNextAvailableDesk(float time);
	priority_queue<Hacker*, vector<Hacker*>, CompDesk<Hacker>> hoodieQueue;
};
#endif