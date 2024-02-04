#include "Enemy.h"
Enemy::Enemy() {
	posenemy_ = { 500.0f,150.0f };
	between_bullet = { 0.0f,0.0f };
	between_player = { 0.0f,0.0f };
	rad_ = 20.0f;
	spe_ = 3;
	distance_bullet = 0.0f;
	distance_player = 0.0f;
	isenemy_ = 1;
	reborn_ = 0;
	life_ = 0;
}
void Enemy::Reboot() {
	posenemy_ = { 500.0f,150.0f };
	between_bullet = { 0.0f,0.0f };
	between_player = { 0.0f,0.0f };
	rad_ = 20.0f;
	spe_ = 3;
	distance_bullet = 0.0f;
	distance_player = 0.0f;
	isenemy_ = 1;
	reborn_ = 0;
	life_ = 0;
}
void Enemy::Init() {
	if (posenemy_.x <=     0 + rad_) {
		spe_ = 3;
	}if (posenemy_.x >= 1000 - rad_) {
		spe_ = -3;
	}if (isenemy_ == 1){
		posenemy_.x += spe_;
	}
}
void Enemy::Hit(Vector2 posbullet,float bulletrrad) {
	between_bullet.x = posbullet.x - posenemy_.x;
	between_bullet.y = posbullet.y - posenemy_.y;
	distance_bullet = sqrtf((between_bullet.x) * (between_bullet.x)) + sqrtf((between_bullet.y) * (between_bullet.y));
	if (distance_bullet <= rad_ + bulletrrad) {
		isenemy_ = 0;
	}
}
void Enemy::Engage(Vector2 posplayer,float playerrad) {
	between_player.x = posplayer.x - posenemy_.x;
	between_player.y = posplayer.y - posenemy_.y;
	distance_player = sqrtf((between_player.x) * (between_player.x)) + sqrtf((between_player.y) * (between_player.y));
	if (distance_player <= rad_ + playerrad) {
		isenemy_ = 0;
	}
}
void Enemy::Draw() {
	if (isenemy_ == 1) {
		Novice::DrawEllipse((int)posenemy_.x, (int)posenemy_.y, (int)rad_, (int)rad_, 0.0f, BLUE, kFillModeSolid);
	}if (isenemy_ == 0) {
		reborn_++;
		if (reborn_ >= 180) {
			reborn_ = 0;
			isenemy_ = 1;
			life_ += 1;
		}
	}
}
Enemy::~Enemy() {

}
