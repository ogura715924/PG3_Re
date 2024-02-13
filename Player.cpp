#include "Player.h"

Player::Player() { Initialize(); }

void Player::Initialize() {
	pos_ = {0.0f, 300.0f};
	speed_ = 2.0f;
}

void Player::Update() {}

void Player::Draw() {
	Novice::DrawBox((int)pos_.x, (int)pos_.y, 16, 16, 0.0f, WHITE, kFillModeSolid);
}

void Player::MoveRight() { pos_.x += speed_; }

void Player::MoveLeft() { pos_.x -= speed_; }

void Player::MoveUp() { pos_.y -= speed_; }

void Player::MoveDown() { pos_.y += speed_; }