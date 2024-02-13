#include "ClearScene.h"
#include "Novice.h"

void ClearScene ::Initialize()
{
}

void ClearScene::Update()
{
	if (keys_[DIK_SPACE] != 0 && preKeys_[DIK_SPACE] == 0) {
		sceneNo = kTitle;
	}
}

void ClearScene::Draw()
{
	Novice::ScreenPrintf(0, 0, "ClearScene");
}