#pragma once

#include "Audio.h"
#include "DebugCamera.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "WorldTransform.h"
#include<list>
#include<sstream>

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	// 攻撃
	void Fire();
	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	
	//敵発生データの読み込み
	void LoadEnemyPopData();

	//敵発生コマンドの更新
	void UpdateEnemyPopCommands();

	
	bool IsSceneEndOver() { return isSceneEndO_; }
	bool IsSceneEndClear() { return isSceneEndC_; }
	/*Scene::SceneType ClearScene() { return Scene::SceneType::kGameResult; }
	Scene::SceneType OverScene() { return Scene::SceneType::kGameOver; }*/

	/// <summary>
	/// エネミーが発射した弾を登録する関数
	/// </summary>
	/// <param name="enemyBullet"></param>
//	void AddEnemyBullet(EnemyBullet* enemyBullet);

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;
	// スプライト
	uint32_t texHandle_ = 0u;
	// モデル
	Model* model_ = nullptr;
	//3Dモデル スカイドーム
	Model* modelSkydome_ = nullptr;
	// デバッグカメラ
	DebugCamera* debugCamera_ = nullptr;
	uint32_t textureHandle_ = 0u;
	// デバッグカメラ有効
	bool isDebugCameraActive_ = false;

	// カメラ
	ViewProjection viewProjection_;
	
	//敵発生コマンド
	std::stringstream enemyPopCommands;


	

		// 敵が発生待機中か
	bool isWait_ = false;
	// 敵が発生するまでの時間
	int32_t waitTime_ = 0;

bool isSceneEndO_ = false;
	bool isSceneEndC_ = false;
	/// <summary>
	/// ゲームシーン用
	/// </summary>
};