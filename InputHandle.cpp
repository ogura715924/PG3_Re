#include "InputHandle.h"

ICommand* InputHandler::HandleInput() {
	if (Novice::CheckHitKey(DIK_D)) {
		return pressKeyD_;
	}
	if (Novice::CheckHitKey(DIK_A)) {
		return pressKeyA_;
	}
	if (Novice::CheckHitKey(DIK_W)) {
		return pressKeyW_;
	}
	if (Novice::CheckHitKey(DIK_S)) {
		return pressKeyS_;
	}
	return nullptr;
}

void InputHandler::AssignMoveLeftCommand2PressKeyA() {
	ICommand* command = new LeftCommand();
	pressKeyA_ = command;
}

void InputHandler::AssignMoveRightCommand2PressKeyD() {
	ICommand* command = new RightCommand();
	pressKeyD_ = command;
}

void InputHandler::AssignMoveUpCommand2PressW() {
	ICommand* command = new UpCommand();
	pressKeyW_ = command;
}

void InputHandler::AssignMoveDownCommand2PressKeyS() {
	ICommand* command = new DownCommand();
	pressKeyS_ = command;
}