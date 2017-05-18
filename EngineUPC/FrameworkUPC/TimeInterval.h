#pragma once

#include <SDL\SDL.h>
#include <functional>

class TimeInterval
{
public:
	TimeInterval();
	~TimeInterval();

	std::function<void()> onEndLoop;
	std::function<void()> onEndInterval;

	void Initialize(float time);
	void Initialize(float time, int loops, bool start);
	void Update(float dt);
	void Reset();

private:
	bool isFinished;
	int loops;
	int currentLoop;
	float timeLimit;
	float currentTime;
};

