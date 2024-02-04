#pragma once
#include"Vector2.h"
#include<Novice.h>
#include <corecrt_math.h>

class Enemy
{
private:
	Vector2 posenemy_;
	Vector2 between_bullet;
	Vector2 between_player;
	float rad_;
	float spe_;
	float distance_bullet;
	float distance_player;
	int isenemy_;
	int reborn_;
	int life_;
public:
	Enemy();
	~Enemy();
	int Getisenemy() { return isenemy_; }
	int Getlife() { return life_; }
	void Init();
	void Hit(Vector2 posbullet, float bulletrrad);
	void Engage(Vector2 posplayer, float playerrad);
	void Draw();
	void Reboot();
};

