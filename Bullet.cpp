#include "Bullet.h"
#include "Novice.h"


Bullet::Bullet(Transform Bpos, Transform velocity, bool isBullet)
{
	pos_ = Bpos;
	velocity_ = velocity;
	radius_ = 16;
	isBullet_ = isBullet;

	bulletTime_ = 90;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	pos_.x += velocity_.x;
	pos_.y += velocity_.y;
	bulletTime_--;
}

void Bullet::Draw(int scrollX, int scrollY)
{
	Novice::DrawEllipse((int)pos_.x - scrollX, (int)pos_.y - scrollY, (int)radius_, (int)radius_, 0.0f, WHITE, kFillModeSolid);
	Novice::DrawSprite((int)pos_.x - 16 - scrollX, (int)pos_.y - 16 - scrollY, bulletGhd, 1, 1, 0.0f, WHITE);
}

bool Bullet::IsDead()
{
	return bulletTime_ <= 0;
}
