#pragma once
#include <KamataEngine.h>

using namespace KamataEngine;

class Effect {

public:
	void Initialize(Model* model, Vector3 pos);
	void Update();
	void Draw(Camera& camera);
	bool IsFinished();

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;
	// 色変更オブジェクト
	ObjectColor objectColor_;
	// 色の数値
	Vector4 color_;
	// 終了フラグ
	bool isFinished_ = false;
	// 経過時間カウント
	float counter_ = 0.0f;
	// 存在時間(消滅までの時間)<秒>
	const float kDuration = 1.0f;

};
