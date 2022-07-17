#include "Event.h"
using namespace std;

int Arrival::count = 0;

Arrival::Arrival(float t) {
	this->time = t;
	this->ID = ++count;
	barkod = "Arrive";
}


void Arrival::execute() {
	Hacker* h = new Hacker(time);
	Hacker::hackers.push_back(h);
}