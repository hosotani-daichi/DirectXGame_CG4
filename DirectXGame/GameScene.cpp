#include "GameScene.h"
#include <cmath>

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

	whiteTex_ = TextureManager::Load("white1x1.png");

	redGraph_.Initialize(whiteTex_);
	greenGraph_.Initialize(whiteTex_);

	// 仮データ作成
	std::vector<float> redData(50), greenData(50);
	for (int i = 0; i < 50; ++i) {
		redData[i] = 50.0f * std::sin(i * 0.1f);
		greenData[i] = 50.0f * std::cos(i * 0.1f);
	}

	redGraph_.SetGraphData(redData, {1.0f, 0.0f, 0.0f, 1.0f});     // 赤
	greenGraph_.SetGraphData(greenData, {0.0f, 1.0f, 0.0f, 1.0f}); // 緑
}

void GameScene::Update() {

	stage_.Update();
	player_.Update();
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

	//  グラフ描画
	redGraph_.Draw();   // 赤いグラフ
	greenGraph_.Draw(); // 緑のグラフ

	// スプライト描画後処理
	Sprite::PostDraw();
}