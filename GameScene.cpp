#include "GameScene.h"
#include "AxisIndicator.h"
#include "ImGuiManager.h"
#include "PrimitiveDrawer.h"
#include "TextureManager.h"
#include <cassert>
#include<fstream>


GameScene::GameScene() {

}

GameScene::~GameScene() {
	delete debugCamera_;
	delete modelSkydome_;
	delete model_;
}

void GameScene::Initialize() {
	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
	viewProjection_.Initialize();
	// デバッグカメラの生成
	debugCamera_ = new DebugCamera(1280, 720);
	// 軸方向表示の表示を有効にする
	AxisIndicator::GetInstance()->SetVisible(true);
	// 軸方向が参照するビュープロジェクションを指定する(アドレス渡し)
	AxisIndicator::GetInstance()->SetTargetViewProjection(&viewProjection_);

	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("mario.jpg");
	// レティクルのテクスチャ
	TextureManager::Load("Reticle.png");
	// 3Dモデルの生成
	model_ = Model::Create();
	// ビュープロジェクションの初期化
	viewProjection_.Initialize();
	// ライン描画が参照するビュープロジェクションを指定する(アドレス渡し)
	PrimitiveDrawer::GetInstance()->SetViewProjection(&viewProjection_);

	// ビュープロジェクションの初期化
	//viewProjection_.farZ = 0.1f;
	viewProjection_.Initialize();
	
	isSceneEndO_ = false;
	isSceneEndC_ = false;

}

void GameScene::Update() {
	isSceneEndC_ = false;
	isSceneEndO_ = false;
	// カメラの処理
	if (isDebugCameraActive_) {
		// デバックカメラの更新処理入れる
		debugCamera_->Update();
		viewProjection_.matView = debugCamera_->GetViewProjection().matView;
		viewProjection_.matProjection = debugCamera_->GetViewProjection().matProjection;
		// ビュープロジェクション行列の転送
		viewProjection_.TransferMatrix();
	} else {
		// ビュープロジェクション行列のの更新と転送
		viewProjection_.UpdateMatrix();
	}
	
}


void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

	// #pragma region背景スプライト描画

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	
	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);
	
	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}



void GameScene::LoadEnemyPopData() {

	// ファイルを開く
	std::ifstream file;
	file.open("enemyPop.csv");
	assert(file.is_open());

	// ファイルの内容を文字列ストリームコピーにコピー
	enemyPopCommands << file.rdbuf();

	// ファイルを閉じる
	file.close();

}

void GameScene::UpdateEnemyPopCommands() {

	// 待機処理
	if (isWait_) {
		    waitTime_--;
		    if (waitTime_ <= 0) {
			// 待機完了
			isWait_ = false;
		    }
		    return;
	}

	//1行分の文字列を入れる変数
	    std::string line;

		//コマンド実行ループ
	    while (getline(enemyPopCommands, line)) {
		    // 1行分の文字列をストリームに変婚して解析しやすくする
		    std::istringstream line_stream(line);

		    std::string word;
		    // ,区切りで行の先頭文字列を取得
		    getline(line_stream, word, ',');

		    // "//"から始まる行はコメント
		    if (word.find("//") == 0) {
			// コメント行を飛ばす
			continue;
		    }
		    // POPコマンド
		    if (word.find("POP") == 0) {
			// x座標
			getline(line_stream, word, ',');
			//float x = (float)std::atof(word.c_str());

			// y座標
			getline(line_stream, word, ',');
			//float y = (float)std::atof(word.c_str());

			// z座標
			getline(line_stream, word, ',');
			//float z = (float)std::atof(word.c_str());

			
		    }
		    // WAITコマンド
		    else if (word.find("WAIT") == 0) {
			getline(line_stream, word, ',');

			// 待ち時間
			int32_t waitTime = atoi(word.c_str());
			// 待機開始
			 isWait_ = true;
			waitTime_ = waitTime;

			// コマンドループを抜ける
			break;
		    }
	    }

}

