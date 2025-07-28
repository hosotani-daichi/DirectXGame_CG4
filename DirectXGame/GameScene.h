#pragma once
#include "GraphDrawer.h"
#include "KamataEngine.h"
#include "Number.h"
#include "Player.h"
#include "Stage.h"

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
	GraphDrawer* graph_ = nullptr;
	Number* number_ = nullptr;
};