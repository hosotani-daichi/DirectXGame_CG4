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
	//プレイヤーの初期化
	player_.Initialize();

	camera_ = new Camera();
	camera_->Initialize();
}

void GameScene::Update() {

	stage_.Update();
	player_.Update();
}

void GameScene::Draw() {

    Sprite::PreDraw(DirectXCommon::GetInstance()->GetCommandList());
	stage_.Draw();
	Sprite::PostDraw();

	player_.Draw(*camera_);

}