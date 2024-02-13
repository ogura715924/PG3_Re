#pragma once
#include "Vector2.h"
#include <Novice.h>

class Player {
private:
	Vector2 pos_;
	float speed_;

public:
	Player();

	void Initialize();
	void Update();
	void Draw();

	// キーごとにコマンドを作る
	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();
};