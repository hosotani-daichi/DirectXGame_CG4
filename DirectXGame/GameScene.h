#pragma once
#include "KamataEngine.h"
#include "Stage.h"

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
	// スプライト
	KamataEngine::Sprite* sprite_ = nullptr;
	Stage stage_;
};