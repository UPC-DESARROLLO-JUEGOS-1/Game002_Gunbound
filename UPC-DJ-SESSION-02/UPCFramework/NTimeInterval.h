#pragma once

#include <SDL\SDL.h>
#include <functional>

class NTimeInterval
{
public:
	NTimeInterval();
	~NTimeInterval();

	std::function<void()> OnEndLoop;
	std::function<void()> OnEndInterval;

	void Initialize(float time);
	void Initialize(float time, int loops);

	void Update(float dt);

private:
	bool mIsFinished;
	int mLoopLimit;
	int mCurrentLoop;
	float mTimeLimit;
	float mCurrentTime;
};

