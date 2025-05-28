#include "GameScene.h"

using namespace KamataEngine;

GameScene::~GameScene() {

	// エフェクトの解放
	for (Effect* effect : effectes_) {
		delete effect;
	}
	delete modelEffect_;
}

void GameScene::Initialize() {

	// 3Dモデルデータの生成
	modelEffect_ = Model::CreateFromOBJ("Plane");
	// カメラの初期化
	camera_.Initialize();

	for (int i = 0; i < 10; i++) {
		// 生成
		Effect* effect = new Effect();
		// 位置
		Vector3 pos = Vector3(0.0f, 0.0f, 0.0f);
		// 初期化
		effect->Initialize(modelEffect_);
		// リストに追加
		effectes_.push_back(effect);
	}
}

void GameScene::Update() {

	// 菱形の更新
	for (Effect* effect : effectes_) {
		effect->Update();
	}
}

void GameScene::Draw() {

	// DirectXCommon　インスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	// 3Dモデル描画処理
	Model::PreDraw(dxCommon->GetCommandList());
	// 菱形の描画
	for (Effect* effect : effectes_) {
		effect->Draw(camera_);
	}
	// 3Dモデル描画処理
	Model::PostDraw();
}
