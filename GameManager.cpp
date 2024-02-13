#include"GameManager.h"
#include"Novice.h"

//コンストラクタ
GameManager::GameManager() {
	//各シーンの配列
	sceneArr_[kTitle] = std::make_unique<TitleScene>();
	sceneArr_[kStage] = std::make_unique<StageScene>();
	sceneArr_[kClear] = std::make_unique<ClearScene>();

	for (int i = 0; i < kSceneMax; i++) {
		//ゲームマネージャーのキーを全てのシーンに反映させる
		sceneArr_[i]->SetKeys(keys_, preKeys_);
	}

	//初期シーンの設定
	currentSceneNo_ = kTitle;
	//こっちでも良い
	//currentSceneNo_ = sceneArr_[kTitle]->GetSceneNo();
}

GameManager::~GameManager() {}

int GameManager::Run() {
	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame();//フレームの開始

		//キー入力を受け取る
		memcpy(preKeys_, keys_, 256);
		Novice::GetHitKeyStateAll(keys_);

		//シーンチェック
		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		// シーン要チェック
		if (prevSceneNo_ != currentSceneNo_) {
			sceneArr_[currentSceneNo_]->Initialize();
		}

		//更新処理
		sceneArr_[currentSceneNo_]->Update();//シーンごとの更新処理

		//描画処理
		sceneArr_[currentSceneNo_]->Draw();

		Novice::EndFrame();//フレーム終了

		// ESCキーが押されたらループを抜ける
		if (keys_[DIK_ESCAPE] == 0 && preKeys_[DIK_ESCAPE] != 0) {
			break;
		}
	}
	return 0;
}