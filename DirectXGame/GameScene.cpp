#include "GameScene.h"
#include <random>

using namespace KamataEngine;

std::random_device seed_Generator;
std::mt19937 RandomEngine(seed_Generator());
std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
std::uniform_real_distribution<float> RandomFloat(-1.0f, 1.0f);

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
	// 乱数の初期化
	srand((unsigned)time(NULL));
}

void GameScene::Update() {

		if (rand() % 20 == 0) {
		Vector3 pos = Vector3(RandomFloat(RandomEngine) * 30.0f, RandomFloat(RandomEngine) * 20.0f, 0);
		Vector4 color = Vector4(distribution(RandomEngine), distribution(RandomEngine), distribution(RandomEngine), 1.0f);
		EffectBorn(pos, color);
	}

	// 菱形の更新
	for (Effect* effect : effectes_) {
		effect->Update();
	}

	// 終了フラグが立ったエフェクトを削除
	effectes_.remove_if([](Effect* effect) {
		if (effect->IsFinished()) {
			delete effect;
			return true;
		}
		return false;
	});
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

void GameScene::EffectBorn(Vector3 pos, Vector4 color) {
	for (int i = 0; i < 10; i++) {
		// 生成
		Effect* effect = new Effect();
		//  初期化
		effect->Initialize(modelEffect_, pos, color);
		// リストに追加
		effectes_.push_back(effect);
	}
}
