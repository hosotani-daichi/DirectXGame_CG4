#include "GameScene.h"
#include <cmath> // sin関数に必要

using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() {

}

void GameScene::Initialize() {

	// 背景ステージの初期化
	stage_.Initialize();

	player_.Initialize();

	camera_ = new Camera();
	camera_->Initialize();
}


void GameScene::Update() {

	stage_.Update();
	player_.Update();
}

void GameScene::Draw() {

	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	// スプライト描画前処理
	Sprite::PreDraw(dxCommon->GetCommandList());

	stage_.Draw();

	Sprite::PostDraw();

	dxCommon->PreDraw();  

	// 深度バッファクリア
	dxCommon->ClearDepthBuffer();

	// 3D描画
	player_.Draw(*camera_);

	dxCommon->PostDraw();  

	Sprite::PostDraw();
}