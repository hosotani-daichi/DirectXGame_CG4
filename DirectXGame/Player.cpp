#include "Player.h"

using namespace KamataEngine;

void Player::Initialize() {

	model_ = Model::CreateFromOBJ("player"); 
	worldTransform_.Initialize();
	worldTransform_.translation_ = {0.0f, 0.0f, 0.0f};
}

void Player::Update() {

	worldTransform_.UpdateMatrix(); 
}

void Player::Draw(const Camera& camera) {

	model_->Draw(worldTransform_, camera);
}
