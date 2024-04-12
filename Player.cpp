#include "Player.h"
#include "Novice.h"
#include "Bullet.h"
#include "Vector2.h"
#include <math.h>
#include <stdlib.h>

Player::Player(Transform pos, float radius, float speed, bool isPlayer)
{
	pos_ = pos;
	radius_ = radius;
	speed_ = speed;
	isAlive_ = isPlayer;

	shotCounter = 90;
}

Player::~Player()
{
}

void Player::Update(char* keys, char* preKeys)
{
	if (pos_.y >= -70 && keys[DIK_W] && preKeys[DIK_W])
	{
		pos_.y -= speed_;
		scrollY = int(pos_.y - 540);
	}
	if (pos_.y <= 1270 && keys[DIK_S] && preKeys[DIK_S])
	{
		pos_.y += speed_;
		scrollY = int(pos_.y - 540);
	}
	if (pos_.x >= 100 && keys[DIK_A] && preKeys[DIK_A])
	{
		pos_.x -= speed_;
		scrollX = int(pos_.x - 960);
	}
	if (pos_.x <= 1840 && keys[DIK_D] && preKeys[DIK_D])
	{
		pos_.x += speed_;
		scrollX = int(pos_.x - 960);
	}
	
	//Y
	if (scrollY < -200)
	{
		scrollY = -200;
	}
	if (scrollY > 320)
	{
		scrollY = 320;
	}

	//X
	if (scrollX < -80)
	{
		scrollX = -80;
	}
	if (scrollX > 100)
	{
		scrollX = 100;
	}

	shotCounter--;
	if (shotCounter <= 0)
	{
		if (bullet == nullptr)
		{
			bullet = new Bullet(pos_, bulletDirection, true);

			shotCounter = 90;
			Novice::StopAudio(voiceHandle3);
			voiceHandle3 = Novice::PlayAudio(soundHandle3, 0, 1.0f);
		}
	}

	if (bullet != nullptr)
	{
		bullet->Update();
		bullet->Draw(scrollX, scrollY);

		if (bullet->IsDead()) {
			delete(bullet);
			bullet = nullptr;
		}
	}
}

void Player::Draw(char* keys, char* preKeys)
{
	if (isAlive_ == true) 
	{
		Novice::DrawEllipse((int)pos_.x - scrollX, (int)pos_.y - scrollY, (int)radius_, (int)radius_, 0.0f, BLACK, kFillModeWireFrame);
	}

	Novice::DrawSprite((int)pos_.x - 32 - scrollX, (int)pos_.y - 32 - scrollY, playerGhd[p], 1, 1, 0.0f, WHITE);
	if (keys[DIK_W] && preKeys[DIK_W] || keys[DIK_S] && preKeys[DIK_S] || keys[DIK_A] && preKeys[DIK_A] || keys[DIK_D] && preKeys[DIK_D])
	{
		playerTimer = playerTimer - 1;
		if (playerTimer <= 0)
		{
			p = p + 1;
			playerTimer = 10;
			if (p >= 5)
			{
				p = 0;
			}
		}
	}
}

void Player::SetBulletDirection(const Transform& direction)
{
	bulletDirection = direction;
}
