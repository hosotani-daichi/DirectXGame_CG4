#pragma once
#include "KamataEngine.h"
#include <array>
#include <vector>
#include <DirectXMath.h>

class GraphDrawer {
public:

	void Initialize(uint32_t textureId);
	void SetGraphData(const std::vector<float>& data, const std::array<float, 4>& color);
	void SetPosition(float x, float y);
	void Draw();

private:

	static const int kMaxPoints = 128;
	std::vector<KamataEngine::Sprite*> graphSprites_;
	std::vector<float> yValues_;
	DirectX::XMFLOAT4 graphColor_;
	float baseX_ = 100.0f;  // 開始X位置
	float baseY_ = 50.0f;  // 開始Y位置
	float spacingX_ = 5.0f; // 点の間隔
	float hpRatio_ = 1.0f;  // HP割合
};
