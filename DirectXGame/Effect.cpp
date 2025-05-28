#include "Effect.h"

void Effect::Initialize(Model* model) {

	// NULLポインタチェック
	assert(model);
	// 引数として受け取ったデータをメンバ変数に記録する
	model_ = model;
	// ワールド変換の初期化
	worldTransform_.Initialize();
}

void Effect::Update() {

	// 行列を定数バッファに転送
	worldTransform_.TransferMatrix();
}

void Effect::Draw(Camera& camera) {

	// 3Dモデル描画
	model_->Draw(worldTransform_, camera);
}