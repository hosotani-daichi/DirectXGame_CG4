#pragma once

#include <KamataEngine.h>

using namespace KamataEngine;

// パーティクル
class Particle {
public:
	~Particle();
	void Initialize(Model* model, Vector3 position, Vector3 velocity);
	void Update();
	void Draw(Camera& camera);
	// 終了フラグ
	bool isFinished_ = false;
	bool IsFinished() {
		return isFinished_;
	}

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;
	// 色変更オブジェクト
	ObjectColor objectColor_;
	// 色の数値
	Vector4 color_;
	// パーティクル　
	std::list<Particle*> particles_;
	// 移動量
	Vector3 velocity_;
	// 経過時間カウント
	float counter_ = 0.0f;
	// 存続時間(消滅までの時間)<秒>
	const float kDuration = 1.0f;
};
