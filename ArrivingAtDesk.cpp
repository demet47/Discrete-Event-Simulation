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

//hoodieye gelince internal mekanizmasý cok farkli olsun, sürekli queuedan adam çekip arrive at desk oluþtursun. leaving the desk te de ayrýlan adamý ayarlar np.
//arrival to desk için sticker desk ten ayrýlýnca bu hackerlar bi queue ya atansýn. burda hoodie leave leri sürekli arkasýndan yeni desk arrival ý oluþtursun event
//ve operation queue ya pushlasýn
