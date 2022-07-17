//do the queueing hof hoodie desk
#include "Event.h"
using namespace std;

LeavingDesk::LeavingDesk(bool typeOfDesk, int ID, float timeOfLeavingDesk) {
	deskCode = typeOfDesk;
	this->ID = ID;
	this->time  = timeOfLeavingDesk;
	string barkod = "leaving desk";

}

void LeavingDesk::execute() {
	pair<float, float>* p = hoodie->findNextAvailableDesk(time);

	Hacker* h = Hacker::hackers[ID];
	if (deskCode) {
		Hacker* h = Hacker::hackers[ID];
		h->hq_enter_time = time;
		
		if (abs(p->first - time) < 0.00001) {
			h->hq_leave_time = time;
			hoodie->processNew(h, true);
			queue.push((Event*)new ArrivingAtDesk(ID, p->first, p->first + p->second, false));
			p->first += p->second;
		}
		else {
			hoodie->hoodieQueue.push(h);
		}
	}
	else {
		if (!hoodie->hoodieQueue.empty()) {
			Hacker* h = hoodie->hoodieQueue.top();
			hoodie->hoodieQueue.pop();
			queue.push((Event*)new ArrivingAtDesk( h->ID, p->first, p->second + p->first, deskCode));
			h->hq_leave_time = p->first;
			hoodie->processNew(h, false);
			p->first += p->second;
		}
	}
	//write also for leaving hoodie desk
}