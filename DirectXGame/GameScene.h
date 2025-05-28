#pragma once
#include "KamataEngine.h"
#include "Effect.h"

class GameScene {

public:
	~GameScene();
	void Initialize();
	void Update();
	void Draw();
	void EffectBorn(KamataEngine::Vector3 pos, KamataEngine::Vector4 color);

private:
	// 菱形3Dモデルデータ
	Model* modelEffect_ = nullptr;
	// カメラ
	Camera camera_;
	// エフェクト
	std::list<Effect*> effectes_;
};
