#pragma once
#include "KamataEngine.h"

class Stage {
public:
	void Initialize();
	void Update();
	void Draw();

private:
	int textureHandle_ = 0;
	KamataEngine::Sprite* sprite1_ = nullptr;
	KamataEngine::Sprite* sprite2_ = nullptr;
	float x_ = 0.0f;
};
