
#include "WaveManager.h"
#include "Player.h"
#include <DxLib.h>

//コンストラクタ
WaveManager::WaveManager():
	stepPosition{1000, 300, 250, 200 },
	groundPosition{ 1000, 500, 450, 400 },
	resetCount(0),
	speed(0),
	lastGroundPos(FOOT_POS::Bottom)
{
	for (int i = 0; i < WAVES; i++)
	{
		stageWave[i].SetSpeed(WAVE_SPEED);
		stageWave[i].SetWidth(WAVE_WIDTH);
		stageWave[i].Initialize(i * 200.0f, stepPosition[(int)FOOT_POS::None],
	groundPosition[(int)FOOT_POS::Bottom]);
	}
}

//デストラクタ
WaveManager::~WaveManager()
{
}


//初期化
void WaveManager::Initialize()
{
	for (int i = 0; i < WAVES; i++)
	{
		stageWave[i].SetSpeed(WAVE_SPEED);
		stageWave[i].SetWidth(WAVE_WIDTH);
		stageWave[i].Initialize(i * 200.0f, stepPosition[(int)FOOT_POS::None],
			groundPosition[(int)FOOT_POS::Bottom]);
	}
	speed = WAVE_SPEED;
}


//更新

void WaveManager::Update(float deltaTime)
{
	//足場の更新
	for (int i = 0; i < WAVES; i++)
	{
		stageWave[i].Update(deltaTime);
	}
	//足場が画面外に消えたら一番右端の足場がすぐ隣に配置する
	for (int i = 0; i < WAVES; i++)
	{
		if (stageWave[i].ResetCheck(-WAVE_WIDTH))
		{
			float resetPosX = stageWave[(WAVES + i - 1) % WAVES].GetPositionX() +
				WAVE_WIDTH;
				FOOT_POS step = (FOOT_POS)(rand() % 4);
				
				//足場は50％(正直には37.5％)で出現
				if (rand() % 2)
				{
					step = FOOT_POS::None;
				}
				FOOT_POS ground = (FOOT_POS)(rand() % 4);

				//下の足場は2個連続で穴にならないようにする
				if (ground == FOOT_POS::None)
				{
					if (lastGroundPos == FOOT_POS::None)
					{
						ground = FOOT_POS::Bottom;
					}
				}

				//指定した位置に足場を配置
				float stepPosY = stepPosition[(int)step];
				float groundPosY = groundPosition[(int)ground];

				stageWave[i].Initialize(resetPosX, stepPosY, groundPosY);

				lastGroundPos = ground;
				//足場が消えたらカウントを増やす
				resetCount++;
		}
	}

	//10回消えたら加速してカウントをリセットする
	if (resetCount > 10)
	{
		speed += 10;
		for (int i = 0; i < WAVES; i++)
		{
			stageWave[i].SetSpeed(speed);
		}
		resetCount = 0;
	}
}

void WaveManager::CheckHitPlayer(Player* p)
{
	for (int i = 0; i < WAVES; i++)
	{
		stageWave[i].CheckHitPlayer(p);
	}
}


//描画
void WaveManager::Render()
{
	for (int i = 0; i < WAVES; i++)
	{
		stageWave[i].Render();
	}

	//現在の速度チェック用表示
	DrawFormatString(0,0,GetColor(255, 255, 255), "%d",speed);
	
}

int WaveManager::GetSpeed()
{
	return speed;
}
