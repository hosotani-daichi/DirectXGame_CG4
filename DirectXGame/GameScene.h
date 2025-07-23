#pragma once
#include "KamataEngine.h"
#include "Stage.h"
#include "Player.h"
#include "GraphDrawer.h"
#include "Time.h"

class GameScene {
public:

	GameScene();
	~GameScene();
	void Initialize();
	void Update();
	void Draw();

private:

	KamataEngine::Camera* camera_ = nullptr;
	Stage stage_;
	Player player_;
	GraphDrawer redGraph_;
	GraphDrawer greenGraph_;
	uint32_t whiteTex_ = 0;
	float hpRatio_ = 1.0f;
	float hpDecreaseSpeed_ = 0.3f;
};