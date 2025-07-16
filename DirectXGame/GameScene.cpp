#include "GameScene.h"
#include <cmath> // sin関数に必要

using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() {
	// デストラクタ
	delete sprite_;
}

void GameScene::Initialize() {

	// 背景ステージの初期化
	stage_.Initialize();

	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("Title.png");
	// スプライトインスタンスの生成
	sprite_ = Sprite::Create(textureHandle_, {0, 0});

	player_.Initialize();

	camera_ = new Camera();
	camera_->Initialize();
}

// メンバー変数に追加
int frameCount = 0;

void GameScene::Update() {

	frameCount++;
	stage_.Update();

	// sin波で上下に揺れるY座標を作る（±20ピクセル範囲で動かす）
	float y = 20 * sin(frameCount * 0.05f);
	// スプライトの位置を更新
	sprite_->SetPosition({20.0f, y});

	player_.Update();
	camera_->Update();
}

void GameScene::Draw() {

	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	// スプライト描画前処理
	Sprite::PreDraw(dxCommon->GetCommandList());

	stage_.Draw();

	// 深度バッファクリア
    dxCommon->ClearDepthBuffer(); 

	// 3D描画
	player_.Draw(*camera_); 

	Sprite::PreDraw(dxCommon->GetCommandList());

	if (frameCount % 60 >= 30) {
		sprite_->Draw();
	}

	Sprite::PostDraw();
}