#include "NTimeInterval.h"



NTimeInterval::NTimeInterval() :
	mLoopLimit(0), mCurrentLoop(0),
	mTimeLimit(0), mCurrentTime(0),
	OnEndLoop(nullptr), OnEndInterval(nullptr),
	mIsFinished(false)
{
}

NTimeInterval::~NTimeInterval()
{
	OnEndLoop = nullptr;
	OnEndInterval = nullptr;
}

void NTimeInterval::Initialize(float time) {
	mTimeLimit = time;
	mLoopLimit = 1;
}

void NTimeInterval::Initialize(float time, int loops) {
	mTimeLimit = time;
	mLoopLimit = loops;
}

void NTimeInterval::Update(float dt) {
	if (!mIsFinished) {
		mCurrentTime += dt;

		if (mCurrentTime >= mTimeLimit) {
			mCurrentTime -= mTimeLimit;
			mCurrentLoop++;

			if (OnEndLoop != nullptr) {
				OnEndLoop();
			}

			if (mCurrentLoop >= mLoopLimit) {
				mIsFinished = true;

				if (OnEndInterval != nullptr) {
					OnEndInterval();
				}
			}
		}
	}
}