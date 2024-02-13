#include "TitleScene.h"
#include "Novice.h"

void TitleScene::Initialize() {}

void TitleScene::Update() {
	if (keys_[DIK_SPACE] != 0 && preKeys_[DIK_SPACE] == 0) {
		sceneNo = kStage;
	}
}

void TitleScene::Draw() { Novice::ScreenPrintf(0, 0, "TitleScene"); }