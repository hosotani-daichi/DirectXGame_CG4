#pragma once
#include "KamataEngine.h"
#include <array>
#include <vector>
#include <DirectXMath.h>

class GraphDrawer {
public:
	void Initialize(uint32_t textureId);

	// グラフデータを設定（yの値だけ受け取る）
	void SetGraphData(const std::vector<float>& data, const std::array<float, 4>& color);

	// 描画（赤グラフの上に緑グラフを描く）
	void Draw();

private:
	static const int kMaxPoints = 128;
	std::vector<KamataEngine::Sprite*> graphSprites_;
	std::vector<float> yValues_;
	DirectX::XMFLOAT4 graphColor_;
	float baseX_ = 100.0f;  // 開始X位置
	float baseY_ = 500.0f;  // 開始Y位置
	float spacingX_ = 5.0f; // 点の間隔
};
