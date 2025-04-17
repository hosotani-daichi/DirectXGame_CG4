#pragma once

#include "KamataEngine.h"
#include "Particle.h"

//class Particle {
//	/// <summary>
//	/// パーティクル発生
//	/// </summary>
//	void ParticleBorn(Vector3 position);
//};

class GameScene {
public:

	~GameScene();
	void Initialize();
	void Update();
	void Draw();
	void ParticleBorn(KamataEngine::Vector3 position);
	
private:

	//パーティクル3Dモデルデータ
	KamataEngine::Model* modelParticle_ = nullptr;
	//カメラ
	KamataEngine::Camera camera_;
	// パーティクル　
	std::list<Particle*> particles_;

};
