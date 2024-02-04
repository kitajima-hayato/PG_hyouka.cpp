#pragma once
#include"Vector2.h"
#include"Bullet.h"
#include<Novice.h>
#include"Enemy.h"
class Player
{
private:
	Vector2 posplayer_;
	float rad_;
	float spe_;
	int isalive_;
	int isbullet_;
public:
	Bullet* bullet_ = new Bullet;
	Enemy* enemy_ = new Enemy;
	int Getisbullet() { return isbullet_; }
	Player();
	~Player();
	void Init(char* keys, char* preKeys);
	void Draw();
	void Reboot();
};

