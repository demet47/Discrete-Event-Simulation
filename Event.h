#include "Desk.h"
#include <queue>
using namespace std;

template<typename T>
class Compare {
public:
	bool operator() (T* e1, T* e2) {
		return *e1 < *e2;

	};
};

#ifndef	EVENT_H
#define EVENT_H
class Event {
public:
	int ID;
	virtual void execute() = 0;// returns if the execution is successful
	float time;  
	static Desk* sticker;
	static Desk* hoodie;
	bool operator<(Event& other);
	static priority_queue <Event*, vector<Event*>, Compare<Event>> queue;
	string barkod;
};
#endif

#ifndef ARRIVAL_H
#define ARRIVAL_H
class Arrival : public Event {
public:
	Arrival(float t);
	void execute();
private:
	static int count;
	//barkodu constructor a yaz

};
#endif

#ifndef CODEDOMMIT_H
#define CODEDOMMIT_H
class CodeCommit : public Event {
public:
	CodeCommit(int ID, int numOfLineChange, float t);
	void execute();
	int numOfLineChange;
};
#endif

#ifndef QUEUEENTRANCEATTEMPT_H
#define QUEUEENTRANCEATTEMPT_H
class QueueEntranceAttempt : public Event {
public:
	QueueEntranceAttempt(int ID, float t);
	void execute();
};
#endif

#ifndef	LEAVINGDESK_H
class LeavingDesk : public Event {
public:
	LeavingDesk(bool deskCode, int ID, float t);
	void execute();
	bool deskCode; // true for sticker, false for hoodie
};
#endif

#ifndef ARRIVINGATDESK_H
#define ARRIVINGATDESK_H
class ArrivingAtDesk : public Event {
public:
	ArrivingAtDesk(int ID, float arrive, float leave, bool type);
	void execute();
	bool typeOfDesk; //true for sticker, false for hooodie
	float leaveTime;
};
#endif
