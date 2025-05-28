#include "Effect.h"
#include <random>
std::random_device seed_Generator;
std::mt19937 RandomEngine(seed_Generator());
std::uniform_real_distribution<float> RandomSize(0.0f, 1.0f);
std::uniform_real_distribution<float> RandomRotation(-1.0f, 1.0f);

void Effect::Initialize(Model* model) {

	// NULLポインタチェック
	assert(model);
	// 引数として受け取ったデータをメンバ変数に記録する
	model_ = model;
	// ワールド変換の初期化
	worldTransform_.Initialize();
	worldTransform_.scale_.y = RandomSize(RandomEngine) * 10.0f;
	worldTransform_.rotation_.z = RandomRotation(RandomEngine) * 20.0f;
}

void Effect::Update() {

	// 行列を定数バッファに転送
	worldTransform_.UpdateMatrix();
}

void Effect::Draw(Camera& camera) {

	// 3Dモデル描画
	model_->Draw(worldTransform_, camera);
}
