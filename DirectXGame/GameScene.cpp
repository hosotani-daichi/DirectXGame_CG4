#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() {
	Model2::StaticFinalize();

	delete model_;
	delete camera_;
	camera_ = nullptr;
}

void GameScene::Initialize() {
	// DirectXCommonインスタンスの取得
	dxCommon_ = DirectXCommon::GetInstance();
	// Inputインスタンスの取得
	input_ = Input::GetInstance();
	// Audioインスタンスの取得
	audio_ = Audio::GetInstance();

	worldTransform_.Initialize();

	// カメラの初期化
	camera_ = new Camera();
	camera_->Initialize();

	// モデル共通初期化
	Model2::StaticInitialize();

	// モデルの生成（正方形）
	model_ = Model2::CreateSquare();

	//モデルリング
	model_ = Model2::CreateRing(64, 2.0f, 3.0f);

	// テクスチャの読み込み
	model2Handle_ = TextureManager::Load("uvChecker.png");
}

void GameScene::Update() { worldTransform_.UpdateMatrix(); }

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	Sprite::PreDraw(commandList);
	Sprite::PostDraw();
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	Model2::PreDraw(commandList);

	// モデル描画
	model_->Draw(worldTransform_, *camera_, model2Handle_);

	Model2::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	Sprite::PreDraw(commandList);
	Sprite::PostDraw();
#pragma endregion
}