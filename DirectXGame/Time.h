#pragma once

class Time {
public:

	static void Update();
	static float GetDeltaTime();

private:

	static float deltaTime_;
	static long long previousTime_;
};
