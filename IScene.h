#pragma once

//シーンクラスを作るたびにここに種類を追加
enum SceneType {
	kTitle,   //タイトルシーン
	kStage,   //ステージシーン
	kClear,   //クリアシーン
	kSceneMax //シーンの最大数
};

class IScene {
protected:
	//シーン番号を管理する変数
	static int sceneNo;
	const char* keys_;
	const char* preKeys_;

public:
	//継承先で実装される関数
	//抽象クラスなので純粋仮想関数とする
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	//仮想デストラクタを用意しないと警告される
	virtual ~IScene();

	//シーン番号のゲッター
	int GetSceneNo();

	//各シーンにキー入力用のセッターを持たせる
	//ただ各シーンキー入力用のセッターを持たせる
	//入力用マネージャーを作った方がいい
	void SetKeys(char* keys, char* preKeys);
};