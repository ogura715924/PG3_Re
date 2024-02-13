#include "StageScene.h"

#include "Novice.h"

    void
    StageScene::Initialize() {
	
}

void StageScene::Update() {
	    if (keys_[DIK_SPACE]!=0 && preKeys_[DIK_SPACE]==0) {
		    sceneNo = kClear;
	    }
    }

void StageScene::Draw() {
	
	Novice::ScreenPrintf(0, 0,  "StageScene"); }