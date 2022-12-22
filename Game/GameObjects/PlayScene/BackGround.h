#pragma once

#include "../../GameDatas/Utility.h"

class BackGround
{
public:
	//雲の数
	const static int cloudNum = 5;

private:

	int mountID;						//山の画像ハンドル
	int cloudID;						//雲の画像ハンドル

	float mountPos[2];					//山の座標（２枚）
	Position cloudPos[cloudNum];		//雲の座標（雲の枚数分）

	int speed;							//背景が流れる速度

public:
	BackGround();
	~BackGround();

	void Initialize();
	void Update(float deltaTime);
	void Render();

	void Finalize();

	void SetSpeed(int speed);
};