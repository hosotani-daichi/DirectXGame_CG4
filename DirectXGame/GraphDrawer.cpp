#define NOMINMAX
#include <Windows.h>
#include "GraphDrawer.h"

using namespace KamataEngine;

void GraphDrawer::Initialize(uint32_t textureId) {
	graphSprites_.resize(kMaxPoints);
	for (int i = 0; i < kMaxPoints; ++i) {
		graphSprites_[i] = Sprite::Create(textureId); // テクスチャID 0（単色矩形）
		graphSprites_[i]->SetSize({4.0f, 4.0f}); // 点サイズ
	}
}

void GraphDrawer::SetGraphData(const std::vector<float>& data, const std::array<float, 4>& color) {
	yValues_ = data;
	graphColor_ = DirectX::XMFLOAT4(color[0], color[1], color[2], color[3]);
}

void GraphDrawer::Draw() {
	int drawCount = std::min((int)yValues_.size(), kMaxPoints);
	for (int i = 0; i < drawCount; ++i) {
		float x = baseX_ + i * spacingX_;
		float y = baseY_ - yValues_[i]; // yは画面下が正方向
		graphSprites_[i]->SetPosition({x, y});
		graphSprites_[i]->SetColor(graphColor_);
		graphSprites_[i]->Draw();
	}
}
