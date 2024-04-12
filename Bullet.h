#pragma once
#include "Struct.h"
#include "Novice.h"

class Bullet
{
public:

	Transform pos_;

	Transform velocity_;
	float radius_;
	bool isBullet_;

	int bulletTime_;

	int bulletGhd = Novice::LoadTexture("./Resources/Player/bullet.png");

public:

	Bullet(Transform Bpos, Transform velocity, bool isBullet);
	~Bullet();
	void Update();
	void Draw(int scrollX, int scrollY);
	bool IsDead();
};

