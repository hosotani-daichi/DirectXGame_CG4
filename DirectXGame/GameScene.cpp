#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() {

	delete camera_;
	camera_ = nullptr;

}

void GameScene::Initialize() {

	Model::StaticInitialize();
	// 背景ステージの初期化
	stage_.Initialize();
	// プレイヤーの初期化
	player_.Initialize();

	camera_ = new Camera();
	camera_->Initialize();

	// ゲージ
	graph_ = new GraphDrawer();
	graph_->Initialize();
}

void GameScene::Update() {
	stage_.Update();
	player_.Update();
	graph_->Update();
}

void GameScene::Draw() {

	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(DirectXCommon::GetInstance()->GetCommandList());
	stage_.Draw();
	Sprite::PostDraw();

	// 深度バッファクリア
	dxCommon->ClearDepthBuffer();

	// 3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	// ここに3Dモデルインスタンスの描画処理を記述する

	player_.Draw(*camera_);

	// 3Dモデル描画後処理
	Model::PostDraw();

	// スプライト描画前処理
	Sprite::PreDraw(dxCommon->GetCommandList());

	// ここに2Dスプライトの描画処理を記述する

	// グラフ
	graph_->Draw();

	// スプライト描画後処理
	Sprite::PostDraw();
}