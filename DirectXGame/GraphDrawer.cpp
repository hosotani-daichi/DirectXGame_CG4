#define NOMINMAX
#include <Windows.h>
#include "GraphDrawer.h"

using namespace KamataEngine;

void GraphDrawer::Initialize(uint32_t greenTextureId, uint32_t redTextureId) {

	greenBar_ = Sprite::Create(greenTextureId, {200.0f, 20.0f}, {0.0f, 0.0f}); //緑
	redBar_ = Sprite::Create(redTextureId, {200.0f, 20.0f}, {0.0f, 0.0f}); //赤

    // 棒の高さは固定例
    float barHeight = 20.0f;
    greenBar_->SetSize({ 200.0f, barHeight }); // 最初は最大幅
    redBar_->SetSize({ 0.0f, barHeight });     // 初期は0幅

    // 初期位置（例として左上）
    float startX = 100.0f;
    float startY = 50.0f;
    greenBar_->SetPosition({ startX, startY });
    redBar_->SetPosition({ startX + 200.0f, startY }); // 右隣に配置（幅0なので重なり）
}

void GraphDrawer::Update(float hpRatio) {
	hpRatio_ = hpRatio;

	float barFullWidth = 200.0f;
	float barHeight = 20.0f;

	// 緑バーの幅をHP残量に合わせて変更
	greenBar_->SetSize({barFullWidth * hpRatio_, barHeight});

	// 赤バーの幅を残りのHP分に合わせて変更
	redBar_->SetSize({barFullWidth * (1.0f - hpRatio_), barHeight});

	// 赤バーの位置は緑バーの右端に合わせる
	float startX = 100.0f;
	float startY = 50.0f;
	greenBar_->SetPosition({startX, startY});
	redBar_->SetPosition({startX + barFullWidth * hpRatio_, startY});
}


void GraphDrawer::SetGraphData(const std::vector<float>& data, const std::array<float, 4>& color) {
	hpRatio_ = data.empty() ? 0.0f : data[0];
	graphColor_ = DirectX::XMFLOAT4(color[0], color[1], color[2], color[3]);
}

void GraphDrawer::Draw() {
	greenBar_->Draw();
	redBar_->Draw();
}
