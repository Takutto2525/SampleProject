#include <DxLib.h>

#include "Player.h"
#include "StageWave.h"

//コンストラクタ
StageWave::StageWave():
	waveSpeed(0),
	waveWidth(0),
	positionX(0),
	ResetCount(0)
{
}

//デストラクタ
StageWave::~StageWave()
{
}

//初期化
void StageWave::Initialize(float x, float step, float ground)
{
	ResetCount = 0;
	boxObject[0].Initialize(x, step, x + waveWidth, step + 50);
	boxObject[1].Initialize(x, ground, x + waveWidth, 800);
}


//足場の幅セット
void StageWave::SetWidth(int width)
{
	waveWidth = width;
}


//足場のスピードセット
void StageWave::SetSpeed(int speed)
{
	waveSpeed = speed;
}

void StageWave::Update(float deltaTime)
{
	//指定の速度で足場を動かす
	for (int i = 0; i < 2; i++)
	{
		Position pos = boxObject[i].GetPosition();
		pos.x -= waveSpeed * deltaTime;
		boxObject[i].SetPosition(pos.x, pos.y);
	}
	positionX = boxObject[0].GetPosition().x;
}

bool StageWave::ResetCheck(float pos)
{
	//特定の位置の到達したかのチェック
	bool ret = false;
	for (int i = 0; i < 2; i++)
	{
		if (boxObject[i].GetPosition().x < pos)
		{
			ret = true;
		}

	}
	return ret;
}

void StageWave::Render()
{
	for (int i = 0; i < 2; i++)
	{
		boxObject[i].Render();
	}
}

void StageWave::CheckHitPlayer(Player* player)
{
	for (int i = 0; i < 2; i++)
	{
		Position p = player->GetPosition();
		//当たり判定処理
		unsigned int ret = boxObject[i].GetBoxCollider().CheckHit(
			p.x - 24,
			p.y - 48,
			p.x + 24,
			p.y
		);
		if (ret == 0)
		{
			continue;
		}

		//足場と当たった時の処理（足場から見てプレイヤーがどちらにあるか）
		if (ret == BoxCollider::AABB_TOP)	//地面についた
		{
			//座標を設定
			p.y = boxObject[i].GetBoxCollider().GetTop();

			if (player->GetVelocityY() < 0.0f)
			{
				player->ResetJunpCount();
				player->ResetJunp();
			}
		}
		else if (ret == BoxCollider::AABB_BOTTOM)	//頭を打った
		{
			//座標を設定
			p.y = boxObject[i].GetBoxCollider().GetBottom() + 48;
			if (player->GetVelocityY() > 0.0f)
			{
				player->ResetJunp();
			}
		}
			else if (ret == BoxCollider::AABB_LEFT)	//右側に壁がある
			{
				//座標を設定
				p.x = boxObject[i].GetBoxCollider().GetLeft() - 24;
			}
			else if (ret == BoxCollider::AABB_RIGHT)	//左側に壁がある
			{
				//座標を設定
				p.x = boxObject[i].GetBoxCollider().GetRight() + 24;
			}
			player->SetPosition(p);
	}
}

float StageWave::GetPositionX()
{
	return positionX;
}
