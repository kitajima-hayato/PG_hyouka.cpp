#pragma once
#include"Vector2.h"
#include<Novice.h>
class Bullet
{
private:
public:
	Vector2 posbullet_;
	Vector2 buck_;
	float rad_;
	float spe_;
	
public:
	Bullet();
	~Bullet();
	Vector2 Getposbullet() { return posbullet_; }
	void Init(int &isbullet_);
	void Draw(int isbullet_);
	void Reboot();
};

