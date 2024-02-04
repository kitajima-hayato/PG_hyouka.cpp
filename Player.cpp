#include "Player.h"

Player::Player() {
	posplayer_ = { 500.0f,600.0f };
	rad_ = 30.0f;
	spe_ = 5.0f;
	isalive_ = 1;
	isbullet_ = 0;
}void Player::Reboot() {
	posplayer_ = { 500.0f,600.0f };
	rad_ = 30.0f;
	spe_ = 5.0f;
	isalive_ = 1;
	isbullet_ = 0;
	enemy_->Reboot();
	bullet_->Reboot();
}

void Player::Init(char* keys, char* preKeys) {
	if (keys[DIK_W]) {
		posplayer_.y -= spe_;
	}if (keys[DIK_A]) {
		posplayer_.x -= spe_;
	}if (keys[DIK_S]) {
		posplayer_.y += spe_;
	}if (keys[DIK_D]) {
		posplayer_.x += spe_;
	}if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] && isbullet_ == 0) {
		isbullet_ = 1;
		bullet_->posbullet_ = { posplayer_.x,posplayer_.y };
	}
	bullet_->Init(isbullet_);
	enemy_->Init();
	enemy_->Hit(bullet_->posbullet_, rad_);
	enemy_->Engage(posplayer_, rad_);
	

}
void Player::Draw() {
	if (isalive_ == 1) {
		Novice::DrawEllipse((int)posplayer_.x, (int)posplayer_.y, (int)rad_, (int)rad_, 0.0f, WHITE, kFillModeSolid);
		bullet_->Draw(isbullet_);
	}
	enemy_->Draw();
}
Player::~Player() {

}