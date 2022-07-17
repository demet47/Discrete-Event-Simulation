#include <iostream>
#include "Hacker.h"
#include "Event.h"
#include "Desk.h"
#include <ostream>
using namespace std;

float TOTAL_SEC_PASSED;

int main()
{	
	int numOfHackers, numOfCodeCommits, numOfQueueEntranceAttempts, numOfStickerDesks, numOfHoodieDesks;
	Hacker::hackers.push_back(nullptr); //thus the [ID] hacker gives the hacker with that ID

	cin >> numOfHackers;
	while (numOfHackers) {
		float t;
		cin >> t;
		Event::queue.push((Event*)new Arrival(t));
		--numOfHackers;
	}

	cin >> numOfCodeCommits;
	
	while (numOfCodeCommits) {
		int ID, numOfLineChange;
		float t;
		cin >> ID >> numOfLineChange >> t;
		Event::queue.push((Event*)new CodeCommit(ID, numOfLineChange, t));
		--numOfCodeCommits;
	}

	cin >> numOfQueueEntranceAttempts;

	while (numOfQueueEntranceAttempts) {
		int ID;
		float t;
		cin >> ID >> t;
		Event::queue.push((Event*)new QueueEntranceAttempt(ID, t));
		--numOfQueueEntranceAttempts;
	}

	cin >> numOfStickerDesks;
	while (numOfStickerDesks) {
		float t;
		cin >> t;
		Event::sticker->newDesk(t);
		--numOfStickerDesks;
	}


	cin >> numOfHoodieDesks;
	while (numOfHoodieDesks) {
		float t;
		cin >> t;
		Event::hoodie->newDesk(t);
		--numOfHoodieDesks;
	}

	while (!Event::queue.empty()) {
		Event* e = Event::queue.top();
		Event::queue.pop();
		TOTAL_SEC_PASSED = e->time;
		e->execute();
	}

	/*
	cout << Hacker::hackers[1]->numOfCommit << endl;
	cout << Hacker::hackers[1]->numOfCommitLines << endl;
	cout << Hacker::hackers[2]->numOfCommit << endl;
	cout << Hacker::hackers[2]->numOfCommitLines << endl;
	cout << Hacker::hackers[3]->numOfCommit << endl;
	cout << Hacker::hackers[3]->numOfCommitLines << endl;
	*/

	/*
	cout << Hacker::hackers[1]->total_souvenir << endl;
	cout << Hacker::hackers[2]->total_souvenir << endl;
	cout << Hacker::hackers[3]->total_souvenir << endl;
	*/

	cout << Event::sticker->max_len_of_queue << endl;
	cout << Event::hoodie->max_len_of_queue << endl;
	cout << Hacker::getAvgSouvenir() << endl;
	cout << Event::sticker->getAverageWaiting() << endl;
	cout << Event::hoodie->getAverageWaiting() << endl;
	cout << Hacker::getAverageCodeCommit() << endl;
	cout << Hacker::getAverageCodeLine() << endl;
	cout << Desk::getAvgTurnaroundTime() << endl;
	cout << Event::sticker->invalid_attempt_for_queuing << endl;
	cout << Event::sticker->invalid_attempt_for_overgifting << endl;
	
	int id = Hacker::mostGibberishID();
	if (id != -1) cout << id << " " << Hacker::hackers[id]->all_queue_waitings << endl;
	else cout << -1 << endl;
	
	id = Hacker::lessGibberishID();
	if(id != -1) cout << id << " " << Hacker::hackers[id]->all_queue_waitings << endl;
	else cout << -1 << endl;
	
	cout << TOTAL_SEC_PASSED;

}
