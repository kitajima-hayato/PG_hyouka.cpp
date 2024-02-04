#include "Bullet.h"
Bullet::Bullet() {
	buck_ = { -50.0f,-50.0f, };
	posbullet_ = { buck_.x,buck_.y };
	rad_ = 15.0f;
	spe_ = 5;
}
void Bullet::Reboot() {
	buck_ = { -50.0f,-50.0f, };
	posbullet_ = { buck_.x,buck_.y };
	rad_ = 15.0f;
	spe_ = 5;
}
void Bullet::Init(int &isbullet_) {
	if (isbullet_ == 1) {
		posbullet_.y -= spe_;
	}if (posbullet_.y <= buck_.y) {
		isbullet_ = 0;
		posbullet_.y = buck_.y;
	}
}
void Bullet::Draw(int isbullet_) {
	if (isbullet_==1) {
		Novice::DrawEllipse((int)posbullet_.x, (int)posbullet_.y, (int)rad_, (int)rad_, 0.0f, RED, kFillModeSolid);
	}
}
Bullet::~Bullet() {

}