#pragma once
#include "Effect.h"
#include "KamataEngine.h"

class GameScene {

public:
	~GameScene();
	void Initialize();
	void Update();
	void Draw();

private:
	// 菱形3Dモデルデータ
	Model* modelEffect_ = nullptr;
	// カメラ
	Camera camera_;
	// 菱形
	Effect* effect_ = nullptr;
};