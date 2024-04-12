#pragma once
#include "Struct.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Novice.h"

class Player
{
public:

	Transform pos_;
	float radius_;
	float speed_;
	bool isAlive_;

	int scrollX = 0;
	int scrollY = 0;

	int scrollSpeedX = 4;
	int scrollSpeedY = 4;

	int shotCounter = 0;
	Bullet* bullet;

	Transform bulletDirection;

	int playerGhd[6] = {
	Novice::LoadTexture("./Resources/Player/player0.png"),
	Novice::LoadTexture("./Resources/Player/player1.png"),
	Novice::LoadTexture("./Resources/Player/player2.png"),
	Novice::LoadTexture("./Resources/Player/player3.png"),
	Novice::LoadTexture("./Resources/Player/player4.png"),
	Novice::LoadTexture("./Resources/Player/player5.png")};
	int p;
	int playerTimer = 10;

	int soundHandle3 = Novice::LoadAudio("./sound/Shot.mp3");
	int voiceHandle3 = 0;

public:

	Player(Transform pos, float radius, float speed, bool isAlive);
	~Player();

	void Update(char* keys, char* preKeys);
	void Draw(char* keys, char* preKeys);
	void SetBulletDirection(const Transform& direction);
};

