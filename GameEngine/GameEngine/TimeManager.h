#pragma once
#include "Singleton.h"

class TimeManager : public Singleton<TimeManager>
{
	friend class Singleton<TimeManager>;
public:
	bool newFrame();
	void init();
private:
	TimeManager();
	~TimeManager();
	int past;
	const float        UPDATE_INTERVAL = 1000.0f / 60.0f;
};

