#pragma once
#include "KamataEngine.h"
#include <2d/Sprite.h>

class GraphDrawer {
public:

	void Initialize();
	void Update();
	void Draw();

private:

	std::vector<KamataEngine::Sprite*> GaugeSprite_;
	const int maxHP = 2;
	const KamataEngine::Vector2 startPos = {50, 50};
	const KamataEngine::Vector2 size = {150, 30};
	uint32_t textureHandle_;
	int Red = 0; //赤
	int Green = 1; //緑
};
