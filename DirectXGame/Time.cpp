#include "Time.h"
#include <chrono>

float Time::deltaTime_ = 0.0f;
long long Time::previousTime_ = 0;

void Time::Update() {
	using namespace std::chrono;
	auto now = duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();

	if (previousTime_ == 0) {
		previousTime_ = now;
		return;
	}

	deltaTime_ = (now - previousTime_) / 1000.0f;
	previousTime_ = now;
}

float Time::GetDeltaTime() { return deltaTime_; }
