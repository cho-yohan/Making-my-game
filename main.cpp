#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include <math.h>
#include <stdlib.h>

const char kWindowTitle[] = "作品";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1920, 1080);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	int title = Novice::LoadTexture("./Resources/Background/Title.png");
	int titlePlayer = Novice::LoadTexture("./Resources/Background/BIGplayer.png");

	int back = Novice::LoadTexture("./Resources/Background/Back.png");
	int end = Novice::LoadTexture("./Resources/Background/endBack.png");
	int bloadGhd = Novice::LoadTexture("./Resources/Background/bload.png");

	int time = Novice::LoadTexture("./Resources/Count/timeLimit.png");

	int count[101] = { 
	Novice::LoadTexture("./Resources/Count/100.png"),
	Novice::LoadTexture("./Resources/Count/99.png"),
	Novice::LoadTexture("./Resources/Count/98.png"),
	Novice::LoadTexture("./Resources/Count/97.png"),
	Novice::LoadTexture("./Resources/Count/96.png"),
	Novice::LoadTexture("./Resources/Count/95.png"),
	Novice::LoadTexture("./Resources/Count/94.png"),
	Novice::LoadTexture("./Resources/Count/93.png"),
	Novice::LoadTexture("./Resources/Count/92.png"),
	Novice::LoadTexture("./Resources/Count/91.png"),
	Novice::LoadTexture("./Resources/Count/90.png"),
	Novice::LoadTexture("./Resources/Count/89.png"),
	Novice::LoadTexture("./Resources/Count/88.png"),
	Novice::LoadTexture("./Resources/Count/87.png"),
	Novice::LoadTexture("./Resources/Count/86.png"),
	Novice::LoadTexture("./Resources/Count/85.png"),
	Novice::LoadTexture("./Resources/Count/84.png"),
	Novice::LoadTexture("./Resources/Count/83.png"),
	Novice::LoadTexture("./Resources/Count/82.png"),
	Novice::LoadTexture("./Resources/Count/81.png"),
	Novice::LoadTexture("./Resources/Count/80.png"),
	Novice::LoadTexture("./Resources/Count/79.png"),
	Novice::LoadTexture("./Resources/Count/78.png"),
	Novice::LoadTexture("./Resources/Count/77.png"),
	Novice::LoadTexture("./Resources/Count/76.png"),
	Novice::LoadTexture("./Resources/Count/75.png"),
	Novice::LoadTexture("./Resources/Count/74.png"),
	Novice::LoadTexture("./Resources/Count/73.png"),
	Novice::LoadTexture("./Resources/Count/72.png"),
	Novice::LoadTexture("./Resources/Count/71.png"),
	Novice::LoadTexture("./Resources/Count/70.png"),
	Novice::LoadTexture("./Resources/Count/69.png"),
	Novice::LoadTexture("./Resources/Count/68.png"),
	Novice::LoadTexture("./Resources/Count/67.png"),
	Novice::LoadTexture("./Resources/Count/66.png"),
	Novice::LoadTexture("./Resources/Count/65.png"),
	Novice::LoadTexture("./Resources/Count/64.png"),
	Novice::LoadTexture("./Resources/Count/63.png"),
	Novice::LoadTexture("./Resources/Count/62.png"),
	Novice::LoadTexture("./Resources/Count/61.png"),
	Novice::LoadTexture("./Resources/Count/60.png"),
	Novice::LoadTexture("./Resources/Count/59.png"),
	Novice::LoadTexture("./Resources/Count/58.png"),
	Novice::LoadTexture("./Resources/Count/57.png"),
	Novice::LoadTexture("./Resources/Count/56.png"),
	Novice::LoadTexture("./Resources/Count/55.png"),
	Novice::LoadTexture("./Resources/Count/54.png"),
	Novice::LoadTexture("./Resources/Count/53.png"),
	Novice::LoadTexture("./Resources/Count/52.png"),
	Novice::LoadTexture("./Resources/Count/51.png"),
	Novice::LoadTexture("./Resources/Count/50.png"),
	Novice::LoadTexture("./Resources/Count/49.png"),
	Novice::LoadTexture("./Resources/Count/48.png"),
	Novice::LoadTexture("./Resources/Count/47.png"),
	Novice::LoadTexture("./Resources/Count/46.png"),
	Novice::LoadTexture("./Resources/Count/45.png"),
	Novice::LoadTexture("./Resources/Count/44.png"),
	Novice::LoadTexture("./Resources/Count/43.png"),
	Novice::LoadTexture("./Resources/Count/42.png"),
	Novice::LoadTexture("./Resources/Count/41.png"),
	Novice::LoadTexture("./Resources/Count/40.png"),
	Novice::LoadTexture("./Resources/Count/39.png"),
	Novice::LoadTexture("./Resources/Count/38.png"),
	Novice::LoadTexture("./Resources/Count/37.png"),
	Novice::LoadTexture("./Resources/Count/36.png"),
	Novice::LoadTexture("./Resources/Count/35.png"),
	Novice::LoadTexture("./Resources/Count/34.png"),
	Novice::LoadTexture("./Resources/Count/33.png"),
	Novice::LoadTexture("./Resources/Count/32.png"),
	Novice::LoadTexture("./Resources/Count/31.png"),
	Novice::LoadTexture("./Resources/Count/30.png"),
	Novice::LoadTexture("./Resources/Count/29.png"),
	Novice::LoadTexture("./Resources/Count/28.png"),
	Novice::LoadTexture("./Resources/Count/27.png"),
	Novice::LoadTexture("./Resources/Count/26.png"),
	Novice::LoadTexture("./Resources/Count/25.png"),
	Novice::LoadTexture("./Resources/Count/24.png"),
	Novice::LoadTexture("./Resources/Count/23.png"),
	Novice::LoadTexture("./Resources/Count/22.png"),
	Novice::LoadTexture("./Resources/Count/21.png"),
	Novice::LoadTexture("./Resources/Count/20.png"),
	Novice::LoadTexture("./Resources/Count/19.png"), 
	Novice::LoadTexture("./Resources/Count/18.png"), 
	Novice::LoadTexture("./Resources/Count/17.png"), 
	Novice::LoadTexture("./Resources/Count/16.png"), 
	Novice::LoadTexture("./Resources/Count/15.png"),
	Novice::LoadTexture("./Resources/Count/14.png"),
	Novice::LoadTexture("./Resources/Count/13.png"),
	Novice::LoadTexture("./Resources/Count/12.png"),
	Novice::LoadTexture("./Resources/Count/11.png"),
	Novice::LoadTexture("./Resources/Count/10.png"), 
	Novice::LoadTexture("./Resources/Count/9.png"),
	Novice::LoadTexture("./Resources/Count/8.png"), 
	Novice::LoadTexture("./Resources/Count/7.png"), 
	Novice::LoadTexture("./Resources/Count/6.png"),
	Novice::LoadTexture("./Resources/Count/5.png"),
	Novice::LoadTexture("./Resources/Count/4.png"),
	Novice::LoadTexture("./Resources/Count/3.png"),
	Novice::LoadTexture("./Resources/Count/2.png"), 
	Novice::LoadTexture("./Resources/Count/1.png"),
	Novice::LoadTexture("./Resources/Count/0.png") };

	int playerGhd[5] = { 
	Novice::LoadTexture("./Resources/Player/player0.png"), 
	Novice::LoadTexture("./Resources/Player/player1.png"),
	Novice::LoadTexture("./Resources/Player/player2.png"),
	Novice::LoadTexture("./Resources/Player/player3.png"),
	Novice::LoadTexture("./Resources/Player/player4.png") };

	int text[2] = {
	Novice::LoadTexture("./Resources/Text/gameclear.png"),
	Novice::LoadTexture("./Resources/Text/gameover.png") };

	int titleText[2] = {
	Novice::LoadTexture("./Resources/Text/pressEnter0.png"),
	Novice::LoadTexture("./Resources/Text/pressEnter1.png") };

	//======================================================================================================================================

	int soundHandle1 = Novice::LoadAudio("./sound/MusMus-BGM-089.mp3");
	int voiceHandle1 = 0;

	int soundHandle2 = Novice::LoadAudio("./sound/MusMus-BGM-085.mp3");
	int voiceHandle2 = 0;

	//======================================================================================================================================

	//プレイヤーのインスタンス
	Player* player = new Player({ 1920 / 2 , 1080 / 2 }, 32.0f, 4, true);

	const int MAX = 300;

	//敵のインスタンス
	Enemy* enemy[MAX]{};
	for (int i = 0; i < MAX; i++) {
		enemy[i] = { new Enemy({ float(200 + rand() % 1700), float(200 + rand() % 1000 - 200) }, float(1.5 + rand() % 2), 32, false)};
	}

	int startTimer = 100;

	int enter = 0;
	int space = 0;

	int countX = 840, countY = 10;

	//--------------------------------

	int countTimer = 60;
	int c1 = 0;

	float playerR1, enemyR2;
	float p, e, pe;

	float bulletR1, b1, b2, be;

	bool isCollision = false;

	int bPosX = 70, bPosY = 20;
	int bloadX = 200, bloadY = 30;

	int backX = -80, backY = -200;

	//--------------------------------

	Transform enemyToPlayer = {};

	int respawnTimer = 50;

	int clearX = 320, clearY = -150;
	int overX = 400, overY = -150;

	int clearTimer = 50;
	int overTimer = 50;

	bool isCount = true;

	int textTimer = 30;
	int t = 0;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		float minLength = 99999;
		int nearestEnemy = 0;

		// 敵の移動
		for (int i = 0; i < MAX; i++)
		{
			if (enemy[i]->isAlive_ == true)
			{
				enemy[i]->vector_.x = player->pos_.x - enemy[i]->pos_.x;
				enemy[i]->vector_.y = player->pos_.y - enemy[i]->pos_.y;

				enemy[i]->length_ = sqrtf(((player->pos_.x - enemy[i]->pos_.x) * (player->pos_.x - enemy[i]->pos_.x)) +
					((player->pos_.y - enemy[i]->pos_.y) * (player->pos_.y - enemy[i]->pos_.y)));

				if (enemy[i]->length_ < minLength)
				{
					nearestEnemy = i;
					minLength = enemy[i]->length_;
				}
				enemy[i]->Update();
			}
		}

		//弾の処理。enemy[nearestEnemy] が一番近い敵
		enemyToPlayer.x = enemy[nearestEnemy]->pos_.x - player->pos_.x;
		enemyToPlayer.y = enemy[nearestEnemy]->pos_.y - player->pos_.y;

		enemyToPlayer.x = enemyToPlayer.x / enemy[nearestEnemy]->length_;
		enemyToPlayer.y = enemyToPlayer.y / enemy[nearestEnemy]->length_;

		int bulletSpeed = 70;
		enemyToPlayer.x *= bulletSpeed;
		enemyToPlayer.y *= bulletSpeed;

		player->SetBulletDirection(enemyToPlayer);


		for (int i = 0; i < MAX; i++)
		{
			if (isCollision == true)
			{
				if (enemy[i]->isAlive_ == true)
				{
					playerR1 = player->radius_;
					enemyR2 = enemy[i]->radius_;

					p = player->pos_.x - enemy[i]->pos_.x;
					e = player->pos_.y - enemy[i]->pos_.y;

					pe = sqrtf(p * p + e * e);

					if (pe <= playerR1 + enemyR2)
					{
						if (bloadX >= 0)
						{
							bloadX -= 1;
						}
					}
				}
			}
		}

		if (player->bullet != nullptr) {
			for (int i = 0; i < MAX; i++)
			{
				if (isCollision == true)
				{
					enemyR2 = enemy[i]->radius_;
					bulletR1 = player->bullet->radius_;

					b1 = player->bullet->pos_.x - enemy[i]->pos_.x;
					b2 = player->bullet->pos_.y - enemy[i]->pos_.y;

					be = sqrtf(b1 * b1 + b2 * b2);

					if (be <= bulletR1 + enemyR2)
					{
						enemy[i]->isAlive_ = false;
					}
				}
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		enum Scene
		{
			TITLE,
			GAME,
			STATUS,
			GAMEOVER,
			GAMECLEAR
		};

		enum Scene2
		{
			WAVE
		};

		switch (enter)
		{
		case TITLE:

			if (Novice::IsPlayingAudio(voiceHandle1) == 0) {
				voiceHandle1 = Novice::PlayAudio(soundHandle1, true, 1.0f);
			}

			Novice::StopAudio(voiceHandle2);

			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN])
			{
				enter = GAME;
			}

			Novice::DrawSprite(0, 0, title, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(700, 200, titlePlayer, 1, 1, 0.0f, WHITE);

			Novice::DrawSprite(430, 800, titleText[t], 1, 1, 0.0f, WHITE);
			textTimer = textTimer - 1;
			if (textTimer <= 0) {
				t = t + 1;
				textTimer = 30;
				if (t >= 2) {
					t = 0;
				}
			}

			minLength = 99999;
			nearestEnemy = 0;

			startTimer = 100;

			//--------------------------------

			countTimer = 60;
			c1 = 0;
			
			isCollision = false;

			bPosX = 70, bPosY = 20;
			bloadX = 200, bloadY = 30;

			backX = -80, backY = -200;

			//--------------------------------

			enemyToPlayer = {};

			respawnTimer = 50;

			clearX = 320, clearY = -150;
			overX = 400, overY = -150;

			clearTimer = 50;
			overTimer = 50;

			isCount = true;

			//--------------------------------

			player = new Player({ 1920 / 2 , 1080 / 2 }, 32.0f, 4, true);

			for (int i = 0; i < MAX; i++)
			{
				enemy[i]->speed_ = float(1.5 + rand() % 2);
			}

			for (int i = 0; i < MAX; i++) {
				enemy[i] = { new Enemy({ float(200 + rand() % 1700), float(200 + rand() % 1000 - 200) }, float(1.5 + rand() % 2), 32, false) };
			}

			break;

		case GAME:

			Novice::StopAudio(voiceHandle1);
			if (Novice::IsPlayingAudio(voiceHandle1) == 0) {
				voiceHandle1 = Novice::PlayAudio(soundHandle1, true, 1.0f);
			}

			Novice::DrawSprite(backX - player->scrollX, backY - player->scrollY, back, 1, 1, 0.0f, WHITE);

			switch (space)
			{
			case WAVE:

				if (Novice::IsPlayingAudio(voiceHandle2) == 0) {
					voiceHandle2 = Novice::PlayAudio(soundHandle2, true, 1.0f);
				}

				Novice::DrawSprite(countX, countY, time, 1, 1, 0.0f, WHITE);

				player->Draw(keys, preKeys);

				startTimer--;

				if (startTimer <= 0) {
					
					player->Update(keys, preKeys);

					isCollision = true;

					respawnTimer--;
					if (respawnTimer <= 0)
					{
						for (int i = 0; i < MAX; i++)
						{
							if (enemy[i]->isAlive_ == false)
							{
								enemy[i]->isAlive_ = true;
								enemy[i]->pos_.x = float(200 + rand() % 1700); 
								enemy[i]->pos_.y = float(200 + rand() % 1000 - 200);

								break;
							}
						}
						respawnTimer = 50;
						if (c1 >= 50)
						{
							respawnTimer = 30;
						}
						if (c1 >= 100 || bloadX <= 0)
						{
							respawnTimer = 1000000;
						}
					}

					//敵の描画
					for (int i = 0; i < MAX; i++) {
						enemy[i]->Draw(player->scrollX, player->scrollY);
					}

					//ウエーブのタイマー
					if (isCount == true)
					{
						Novice::DrawSprite(930, 50, count[c1], 1, 1, 0.0f, WHITE);
						countTimer = countTimer - 1;
						if (countTimer <= 0) {
							c1 = c1 + 1;
							countTimer = 60;
							if (c1 >= 101) {
								c1 = 100;
							}
						}
						if (c1 == 100) {

							Novice::StopAudio(voiceHandle2);

							for (int i = 0; i < MAX; i++) {
								enemy[i]->speed_ = 0;
							}
							player->speed_ = 0;
							player->shotCounter = 1000000;

							isCollision = false;

							Novice::DrawSprite(clearX, clearY, text[0], 1, 1, 0.0f, WHITE);
							if (clearY <= 430)
							{
								clearY += 3;
							}
							if (clearY >= 430)
							{
								clearTimer--;
							}
							if (clearTimer <= 0)
							{
								enter = GAMECLEAR;
							}
						}
					}
				}

				//プレイヤーのHP
				Novice::DrawBox(bPosX, bPosY, bloadX, bloadY, 0.0f, RED, kFillModeSolid);
				Novice::DrawSprite(bPosX, bPosY, bloadGhd, 1, 1, 0.0f, WHITE);

				if (bloadX <= 0) {

					Novice::StopAudio(voiceHandle2);

					for (int i = 0; i < MAX; i++) {
						enemy[i]->speed_ = 0;
					}
					player->speed_ = 0;

					player->shotCounter = 1000000;

					isCollision = false;
					isCount = false;

					Novice::DrawSprite(overX, overY, text[1], 1, 1, 0.0f, WHITE);

					if (overY <= 430)
					{
						overY += 3;
					}
					if (overY >= 430)
					{
						overTimer--;
					}
					if (overTimer <= 0)
					{
						enter = GAMEOVER;
					}
				}

				break;
			}

			break;

		case GAMECLEAR:

			Novice::StopAudio(voiceHandle1);

			Novice::StopAudio(voiceHandle2);

			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN])
			{
				enter = TITLE;
			}

			Novice::DrawSprite(0, 0, end, 1, 1, 0.0f, WHITE);

			Novice::DrawSprite(320, 430, text[0], 1, 1, 0.0f, WHITE);

			break;

		case GAMEOVER:

			Novice::StopAudio(voiceHandle1);

			Novice::StopAudio(voiceHandle2);

			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN])
			{
				enter = TITLE;
			}

			Novice::DrawSprite(0, 0, end, 1, 1, 0.0f, WHITE);

			Novice::DrawSprite(400, 430, text[1], 1, 1, 0.0f, WHITE);

			break;
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete player;

	for (int i = 0; i < MAX; i++)
	{
		delete enemy[i];
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
