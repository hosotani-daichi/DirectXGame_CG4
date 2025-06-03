#include "GameScene.h"

using namespace KamataEngine;

GameScene::~GameScene() {
	
	Model2::StaticFinalize();
}

void GameScene::Initialize() {

	Model2::StaticInitialize();
}

void GameScene::Update() {

}

void GameScene::Draw() {

	// DirectXCommon　インスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	// 3Dモデル描画処理
	Model2::PreDraw(dxCommon->GetCommandList());

	// 3Dモデル描画処理
	Model2::PostDraw();
}
