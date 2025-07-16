#include "Stage.h"
#include <cmath>

using namespace KamataEngine;

void Stage::Initialize() {
	// 背景画像の読み込み
	textureHandle_ = TextureManager::Load("background.png");

	// スプライト2枚生成（同じ画像）
	sprite1_ = Sprite::Create(textureHandle_, {0, 0});
	sprite2_ = Sprite::Create(textureHandle_, {1280, 0});
}

void Stage::Update() {
	// 左に移動（スクロール）
	x_ -= 2.0f; // スクロール速度

	if (x_ <= -1280.0f) {
		x_ += 1280.0f;
	}

	// スプライトの位置更新（2枚）
	sprite1_->SetPosition({x_, 0});
	sprite2_->SetPosition({x_ + 1280, 0});
}

void Stage::Draw() {
	sprite1_->Draw();
	sprite2_->Draw();
}
