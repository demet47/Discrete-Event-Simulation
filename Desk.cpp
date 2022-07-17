#include "Desk.h"
#include <typeinfo>
#include <vector>
#include <utility>
#include <string> 
#include <iostream>
using namespace std;

int Desk::invalid_attempt_for_queuing = 0;
int Desk::invalid_attempt_for_overgifting = 0;
float Desk::avg_turnaround_time = 0;
int Desk::total_people_queued = 0; //


Desk::Desk(string type) {
	this->type = type;
	max_len_of_queue = 0;
	average_waiting = 0;
	q = 0;
	vector<pair<float, float>> desks;

}


void Desk::newDesk(float t) {
	desks.push_back(make_pair(0.0f, t));
}

bool Desk::tablesFull(float time) {
	for (int i = 0; i < (int)desks.size(); i++) {
		if (abs(desks[i].first - time) < 0.00001 || desks[i].first < time  )
			return false;
	}
	return true;
}

//returns false if invalid attempt for queuing or leaving queue
// just puts the hacker to queue or pops hacker
//called in arrivaltodesk event through finfind the appropriate desk
bool Desk::processNew(Hacker* h, bool enter) { // just works on the hacker queue 
	if (type == "sticker") {
		if (enter) {
			if (h->numOfCommit < 3 || h->numOfCommitLines < 20 || h->total_souvenir >= 3 ) { 
				++invalid_attempt_for_queuing;
				if (h->total_souvenir >= 3) ++invalid_attempt_for_overgifting;
				return false;
			}
			else {
				++q;
				average_waiting -= h->sq_enter_time;
				total_people_queued++;
				h->all_queue_waitings -= h->sq_enter_time;
				h->total_souvenir++;
				Hacker::totalSouv++;
				avg_turnaround_time -= h->sq_enter_time;
				// total souvenir is considered as a pocket, so just incremented here, not in hoodie again
			}
		}
		else {
			if (abs(h->sq_enter_time - h->sq_leave_time) >= 0.00001 && max_len_of_queue < q)
				max_len_of_queue = q;
			--q;
			average_waiting += h->sq_leave_time;
			h->all_queue_waitings += h->sq_leave_time;
		}
	}
	else {
		if (enter) {
			++q;
			average_waiting -= h->hq_enter_time;
			h->all_queue_waitings -= h->hq_enter_time;
		}
		else {
			if (!enter && abs(h->hq_enter_time - h->hq_leave_time) >= 0.00001 && max_len_of_queue < q)
				max_len_of_queue = q;
			--q;
			
			avg_turnaround_time += h->hq_leave_time;
			average_waiting += h->hq_leave_time;
			h->all_queue_waitings += h->hq_leave_time;
		}
	}

	return  true;
}

//with the call, it updates the next available time for the desk
pair<float, float>* Desk::findNextAvailableDesk(float time) { //first->earliest emptying time, second->duration of operation
	int earliestEmptyingIndex = 0;
	pair<float, float>* min = &desks[0];
	for (int i = 0; i < (int)desks.size(); i++) {
		pair<float, float>* p = &desks[i];
		if (p->first <= time) {
			p->first = time;
			return &*p;
		}
		else if (p->first < min->first) {
			earliestEmptyingIndex = i;
			*min = *p;
		}
	}
	return &*min;
}


float Desk::getAverageWaiting() { //non-static funct
	return average_waiting / total_people_queued;
}

float Desk::getAvgTurnaroundTime() { //static funct
	return avg_turnaround_time / total_people_queued;
}


