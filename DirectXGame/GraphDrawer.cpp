#define NOMINMAX
#include <Windows.h>
#include "GraphDrawer.h"

using namespace KamataEngine;

void GraphDrawer::Initialize(uint32_t textureId) {
	graphSprites_.resize(1);                                                     // スプライト1個だけ
	graphSprites_[0] = Sprite::Create(textureId, {200.0f, 20.0f}, {0.0f, 0.5f}); // 幅200、高さ20、左端基準
	graphSprites_[0]->SetSize({200.0f, 20.0f});
}

void GraphDrawer::SetPosition(float x, float y) {
	baseX_ = x;
	baseY_ = y;
}

void GraphDrawer::SetGraphData(const std::vector<float>& data, const std::array<float, 4>& color) {
	hpRatio_ = data.empty() ? 0.0f : data[0];
	graphColor_ = DirectX::XMFLOAT4(color[0], color[1], color[2], color[3]);
}

void GraphDrawer::Draw() {
	graphSprites_[0]->SetSize({200.0f * hpRatio_, 50.0f});
	graphSprites_[0]->SetColor(Vector4(graphColor_.x, graphColor_.y, graphColor_.z, graphColor_.w));
	graphSprites_[0]->SetPosition({baseX_, baseY_}); // 表示位置（左端）
	graphSprites_[0]->Draw();
}
