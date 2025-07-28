#include "GraphDrawer.h"

using namespace KamataEngine;

void GraphDrawer::Initialize() {

	textureHandle_ = TextureManager::Load("./Resources/white1x1.png");

	for (int i = 0; i < maxHP; ++i) {

		auto graph = KamataEngine::Sprite::Create(textureHandle_, startPos);
		graph->SetSize(size);

		if (i == Red) {
			graph->SetColor(Vector4(1.0f, 0.0f, 0.0f, 1.0f)); // 赤で表示
		} else if (i == Green) {
			graph->SetColor({0.24f, 0.70f, 0.44f, 1.0f}); // 緑で表示
		}
		GraphSprite_.push_back(graph);
	}
}

void GraphDrawer::Update() {

	for (int i = 0; i < GraphSprite_.size(); ++i) {

		if (i == Green) {
			GraphSprite_[i]->SetSize(Vector2(GraphSprite_[i]->GetSize().x - 1, GraphSprite_[i]->GetSize().y));
			if (GraphSprite_[i]->GetSize().x < 0) {
				GraphSprite_[i]->SetSize(size);
			}
		}
	}
}

void GraphDrawer::Draw() {

	// グラフ描画
	for (int i = 0; i < maxHP; i++) {
		GraphSprite_[i]->Draw();
	}
}
