#include<iostream>
#include "Event.h"
#include<queue>

using namespace std;

QueueEntranceAttempt::QueueEntranceAttempt(int ID, float t) {
	this->ID = ID;
	this->time = t;
	barkod = "queue entrance attempt";

}

void QueueEntranceAttempt::execute() { // create a arriving sticker desk event
	Hacker::hackers[ID]->sq_enter_time = time; // here miggght give error
	if (sticker->processNew(Hacker::hackers[ID], true)) {
		pair<float, float>* p = sticker->findNextAvailableDesk(time);
		queue.push((Event*)new ArrivingAtDesk(ID, p->first, p->first + p->second, true));
		p->first += p->second;

	}
	//no need to recheck if entrance to queue is valid
}

