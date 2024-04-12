#include "Enemy.h"
#include "Novice.h"
#include "Player.h"

Enemy::Enemy(Transform Epos, float speed, float radius, bool isAlive)
{
	pos_ = Epos;
	speed_ = speed;
	radius_ = radius;
	isAlive_ = isAlive;
}

void Enemy::Update()
{
	if (isAlive_ == true)
	{
		n_.x = vector_.x / length_;
		n_.y = vector_.y / length_;

		velocity_.x = n_.x * speed_;
		velocity_.y = n_.y * speed_;

		pos_.x += velocity_.x;
		pos_.y += velocity_.y;
	}
}

void Enemy::Draw(int scrollX, int scrollY)
{
	if (isAlive_ == true)
	{
		Novice::DrawEllipse((int)pos_.x - scrollX, (int)pos_.y - scrollY, (int)radius_, (int)radius_, 0.0f, BLACK, kFillModeSolid);

		Novice::DrawSprite((int)pos_.x - 32 - scrollX, (int)pos_.y - 32 - scrollY, enemyGhd, 1, 1, 0.0f, WHITE);
	}
}
