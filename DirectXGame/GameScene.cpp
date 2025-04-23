#include "GameScene.h"

using namespace KamataEngine;

GameScene::~GameScene() {

	delete modelEffect_;
	delete effect_;
}

void GameScene::Initialize() {

	// 3Dモデルデータの生成
	modelEffect_ = Model::CreateSphere(4, 4);////////SphereをEffectに変えるためにEffectを制作する
	// カメラの初期化
	camera_.Initialize();
	// 菱形の生成
	effect_ = new Effect();
	// 菱形の初期化
	effect_->Initialize(modelEffect_);
}

void GameScene::Update() {

	// 菱形の更新
	effect_->Update();
}

void GameScene::Draw() {

	// DirectXCommon　インスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	// 3Dモデル描画処理
	Model::PreDraw(dxCommon->GetCommandList());
	// 菱形の描画
	effect_->Draw(camera_);
	// 3Dモデル描画処理
	Model::PostDraw();
}
