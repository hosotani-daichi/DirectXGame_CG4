#pragma once
#include <KamataEngine.h>

class Number {

public:

	~Number();
	void Initialize();
	void Update();
	void Draw();
	void SetNumber(int value);

private:

	std::vector<KamataEngine::Sprite*> NumberSprite_;
	const KamataEngine::Vector2 size = {32.0f, 64.0f}; // 数字のサイズ
	const KamataEngine::Vector2 startPos = {1200, 30}; // 表示位置
	uint32_t textureHandle_;
	int number_ = 0;
	int frameCounter_ = 0;
};