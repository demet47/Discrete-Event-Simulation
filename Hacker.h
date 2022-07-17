#include<vector>
#ifndef HACKER_H
#define HACKER_H

class Hacker {
public:
	Hacker(float t);
	const int ID = ++numOfHackers;
	void commit(int commitLine); //sets commit line and commit nums, changes also the average_code_commit and average_code_line
	static float getAverageCodeCommit();
	static float getAverageCodeLine();
	static std::vector<Hacker*> hackers; //push each hacker here when created
	float getQueuingDuration();
	float all_queue_waitings; // duration of waiting in queue
	float sq_enter_time, hq_enter_time, sq_leave_time, hq_leave_time, timeOfArrival;
	int numOfCommit, numOfCommitLines, total_souvenir;
	static int numOfHackers;
	static int getAvgSouvenir();
	static int totalSouv;
	static int lessGibberishID();
	static int mostGibberishID();
	static float average_code_commit;
	static float average_code_line; 
	bool operator<(Hacker& other);
};

#endif