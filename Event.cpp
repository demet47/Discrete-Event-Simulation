#include "Event.h"
#include <queue>
using namespace std;

Desk* Event::sticker = new Desk("sticker");
Desk* Event::hoodie = new Desk("hoodie");


bool Event::operator<(Event& other) {
	if (abs(this->time - other.time) > 0.00001) return this->time > other.time;
	else return this->ID > other.ID;
}

priority_queue <Event*, vector<Event*>, Compare<Event>> Event::queue;
