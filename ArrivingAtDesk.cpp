//here while writing comparison of events, prioritize the arriving according to ID (lower served first)

#include "Hacker.h"
#include "Desk.h"
#include "Event.h"
#include<vector>
#include<queue>

using namespace std;

ArrivingAtDesk::ArrivingAtDesk(int ID, float arrive, float leave, bool type) {
	this->time = arrive;
	this->ID = ID;
	typeOfDesk = type;
	leaveTime = leave;
	barkod = "arrive at desk";
	// above last method orients the desks and leaves behind a reoriented desk
	// the function also returns the time I should create an arriveAthoodieDesk. dont forget to
	// set hoodiedesk statics vs vs inside that new event
}

void ArrivingAtDesk::execute() {

	queue.push((Event*)new LeavingDesk(typeOfDesk, ID, leaveTime));

	if (typeOfDesk){
		Hacker::hackers[ID]->sq_leave_time = time;
		sticker->processNew(Hacker::hackers[ID], false);
	}
	else {
		Hacker::hackers[ID]->hq_leave_time = time;
		hoodie->processNew(Hacker::hackers[ID], false);
	}
}

//hoodieye gelince internal mekanizmas� cok farkli olsun, s�rekli queuedan adam �ekip arrive at desk olu�tursun. leaving the desk te de ayr�lan adam� ayarlar np.
//arrival to desk i�in sticker desk ten ayr�l�nca bu hackerlar bi queue ya atans�n. burda hoodie leave leri s�rekli arkas�ndan yeni desk arrival � olu�tursun event
//ve operation queue ya pushlas�n
