#include "BackGround.h"
#include "WaveManager.h"
#include <DxLib.h>

//画像のサイズ
#define SCREEN_WIDTH				(800)
#define SCREEN_HEIGHT				(600)

//コンストラクタ
BackGround::BackGround() :
	mountPos{ 0,0 },
	cloudPos{
	Position{0,0},
	Position{0,0},
	Position{0,0},
	Position{0,0},
	Position{0,0} },
	speed(0)
{
	mountID = LoadGraph("Resources/Textures/mountain.png");
	cloudID = LoadGraph("Resources/Textures/cloud.png");
}

BackGround::~BackGround()
{
}

//初期化
void BackGround::Initialize()
{
	//山の初期位置を設定
	mountPos[0] = 0;
	mountPos[1] = SCREEN_WIDTH;


	//雲の初期位置を設定
	for (int i = 0; i < cloudNum; i++)
	{
		//170に近い意味はなし
		cloudPos[i].x = i * 170.0f;
		//高さはランダム
		cloudPos[i].y = (float)(rand() % (SCREEN_HEIGHT / 3));

	}
}

void BackGround::Update(float deltaTime)
{
	//山の位置をずらして、画面外に消えたらリセット
	for (int i = 0; i < 2; i++)
	{
		mountPos[i] -= deltaTime * speed * 0.5f;
		if (mountPos[i] < -SCREEN_WIDTH)
		{
			mountPos[i] = SCREEN_WIDTH;
		}
	}
	//雲の位置をずらす
	for (int i = 0; i < cloudNum; i++)
	{
		cloudPos[i].x -= deltaTime * 0.7f;
		if (cloudPos[i].x < -100)
		{
			cloudPos[i].x = SCREEN_WIDTH;
			cloudPos[i].y = (float)(rand() % (SCREEN_HEIGHT / 3));

		}

	}
}

void BackGround::Render()
{
	//空の青（徐々に青がなくなる）
	int blue = 255 - (speed - WaveManager::WAVE_SPEED);
	blue = max(100, blue);

	//空の赤
	int red = 100 + (speed - WaveManager::WAVE_SPEED);
	red = min(255, red);

	//空の描画
	DrawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, GetColor(red, 100, blue), 1);

	//山の描画
	for (int i = 0; i < 2; i++)
	{
		DrawGraph((int)(mountPos[i]), 0, mountID, 1);
	}
	//雲の描画
	for (int i = 0; i < cloudNum; i++)
	{
		DrawGraph((int)(cloudPos[i].x), (int)(cloudPos[i].y), cloudID, 1);
	}
}

void BackGround::Finalize()
{
	DeleteGraph(mountID);
	DeleteGraph(cloudID);
}

void BackGround::SetSpeed(int speed)
{
	this->speed = speed;
}
