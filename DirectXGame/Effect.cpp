#include "Effect.h"
#include <random>
std::random_device seed_Generator;
std::mt19937 RandomEngine(seed_Generator());
std::uniform_real_distribution<float> RandomSize(0.0f, 1.0f);
std::uniform_real_distribution<float> RandomRotation(-1.0f, 1.0f);

void Effect::Initialize(Model* model, Vector3 pos) {

	// NULLポインタチェック
	assert(model);
	// 引数として受け取ったデータをメンバ変数に記録する
	model_ = model;
	// ワールド変換の初期化
	worldTransform_.Initialize();
	worldTransform_.scale_.y = RandomSize(RandomEngine) * 10.0f;
	worldTransform_.rotation_.z = RandomRotation(RandomEngine) * 20.0f;
	worldTransform_.translation_ = pos;
	// 色の初期化
	objectColor_.Initialize();
	color_ = Vector4(1, 1, 1, 1);
}

void Effect::Update() {

	// 終了なら何もしない
	if (isFinished_) {
		return;
	}

	// カウンターを1フレーム粉の秒数進める
	counter_ += 1.0f / 60.0f;

	// 存在時間の上限に達したら
	if (counter_ >= kDuration) {
		counter_ = kDuration;
		// 終了扱いにする
		isFinished_ = true;
	}

	// 色変更オブジェクトに色の数値を設定する
	objectColor_.SetColor(color_);
	// フェード処理
	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);
	// 行列を定数バッファに転送
	worldTransform_.UpdateMatrix();
}

void Effect::Draw(Camera& camera) {

	// 3Dモデル描画
	model_->Draw(worldTransform_, camera, &objectColor_);
}

bool Effect::IsFinished() { return isFinished_; }
