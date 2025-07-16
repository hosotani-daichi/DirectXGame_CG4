#pragma once
#include "KamataEngine.h"
#include "Stage.h"
#include "Player.h"

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
};