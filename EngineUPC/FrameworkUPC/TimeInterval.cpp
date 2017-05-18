#include "TimeInterval.h"

TimeInterval::TimeInterval() :
	loops(0),
	currentLoop(0),
	timeLimit(0),
	currentTime(0),
	onEndLoop(nullptr),
	onEndInterval(nullptr),
	isFinished(false)
{
}

TimeInterval::~TimeInterval()
{
	onEndLoop = nullptr;
	onEndInterval = nullptr;
}

void TimeInterval::Initialize(float time)
{
	timeLimit = time;
	loops = -1;
	currentLoop = loops;
}

void TimeInterval::Initialize(float time, int loops, bool start)
{
	//-1 loops for infinite looping
	timeLimit = time;
	this->loops = loops;
	currentLoop = loops;
	isFinished = !start;
}

void TimeInterval::Update(float dt)
{
	if (!isFinished)
	{
		currentTime += dt;
		if (currentTime >= timeLimit)
		{
			currentTime -= timeLimit;
			
			if (onEndLoop != nullptr) onEndLoop();

			if (currentLoop >= 0)
			{
				currentLoop--;
				if (currentLoop == 0)
				{
					isFinished = true;
					if (onEndInterval != nullptr) onEndInterval();
				}
			}
		}
	}
}

void TimeInterval::Reset()
{
	isFinished = false;
	currentTime = 0;
	currentLoop = loops;
}
