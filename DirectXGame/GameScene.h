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

	// テクスチャハンドル
	uint32_t textureHandle_ = 0;
	uint32_t textureHandle2_ = 0;
	// スプライト
	KamataEngine::Sprite* sprite_ = nullptr;
	KamataEngine::Sprite* sprite2_ = nullptr;

	KamataEngine::Camera* camera_ = nullptr;
	Stage stage_;
	Player player_;
	int frameCount = 0;
};