#include "GraphDrawer.h"

using namespace KamataEngine;

void GraphDrawer::Initialize() {

	textureHandle_ = TextureManager::Load("./Resources/white1x1.png");

	for (int i = 0; i < maxHP; ++i) {

		auto gauge = KamataEngine::Sprite::Create(textureHandle_, startPos);
		gauge->SetSize(size);

		if (i == Red) {
			gauge->SetColor(Vector4(1.0f, 0.0f, 0.0f, 1.0f)); // 赤で表示
		} else if (i == Green) {
			gauge->SetColor({0.24f, 0.70f, 0.44f, 1.0f}); // 緑で表示
		}
		GaugeSprite_.push_back(gauge);
	}
}

void GraphDrawer::Update() {

	for (int i = 0; i < GaugeSprite_.size(); ++i) {

		if (i == Green) {
			GaugeSprite_[i]->SetSize(Vector2(GaugeSprite_[i]->GetSize().x - 1, GaugeSprite_[i]->GetSize().y));
			if (GaugeSprite_[i]->GetSize().x < 0) {
				GaugeSprite_[i]->SetSize(size);
			}
		}
	}
}

void GraphDrawer::Draw() {

	// グラフ描画
	for (int i = 0; i < maxHP; i++) {
		GaugeSprite_[i]->Draw();
	}
}
