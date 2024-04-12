#pragma once
#include "Struct.h"
#include <stdlib.h>
#include <Player.h>
#include "Novice.h"

class Enemy
{
public:

	Transform pos_;
	Transform velocity_;
	Transform vector_;
	Transform n_;

	float length_;

	float speed_;
	float radius_;
	bool isAlive_;

	int enemyGhd = Novice::LoadTexture("./Resources/Enemy/enemy.png");

public:
	Enemy(Transform pos, float speed, float radius, bool isAlive);

	void Update();
	void Draw(int scrollX, int scrollY);
};

