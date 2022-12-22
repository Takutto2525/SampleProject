#pragma once
#include "StageWave.h"

class Player;

class WaveManager
{
private:
	enum class FOOT_POS {
		None,
		Bottom,
		Width,
		TOP,

		OverID
	};
	const static int STEP_TYPE = 4;
public:
	const static int WAVE_WIDTH = 200;
	const static int WAVE_SPEED = 200;
	const static int WAVES = 5;

private:
	float stepPosition[STEP_TYPE];
	float groundPosition[STEP_TYPE];

	StageWave stageWave[WAVES];

	int resetCount;

	FOOT_POS lastGroundPos;

	int speed;

public:
	WaveManager();
	~WaveManager();

	void Initialize();
	void Update(float deltaTime);

	void CheckHitPlayer(Player* p);

	void Render();

	int GetSpeed();

};