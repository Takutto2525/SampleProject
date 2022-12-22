#include "BackGround.h"
#include "WaveManager.h"
#include <DxLib.h>

//�摜�̃T�C�Y
#define SCREEN_WIDTH				(800)
#define SCREEN_HEIGHT				(600)

//�R���X�g���N�^
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

//������
void BackGround::Initialize()
{
	//�R�̏����ʒu��ݒ�
	mountPos[0] = 0;
	mountPos[1] = SCREEN_WIDTH;


	//�_�̏����ʒu��ݒ�
	for (int i = 0; i < cloudNum; i++)
	{
		//170�ɋ߂��Ӗ��͂Ȃ�
		cloudPos[i].x = i * 170.0f;
		//�����̓����_��
		cloudPos[i].y = (float)(rand() % (SCREEN_HEIGHT / 3));

	}
}

void BackGround::Update(float deltaTime)
{
	//�R�̈ʒu�����炵�āA��ʊO�ɏ������烊�Z�b�g
	for (int i = 0; i < 2; i++)
	{
		mountPos[i] -= deltaTime * speed * 0.5f;
		if (mountPos[i] < -SCREEN_WIDTH)
		{
			mountPos[i] = SCREEN_WIDTH;
		}
	}
	//�_�̈ʒu�����炷
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
	//��̐i���X�ɐ��Ȃ��Ȃ�j
	int blue = 255 - (speed - WaveManager::WAVE_SPEED);
	blue = max(100, blue);

	//��̐�
	int red = 100 + (speed - WaveManager::WAVE_SPEED);
	red = min(255, red);

	//��̕`��
	DrawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, GetColor(red, 100, blue), 1);

	//�R�̕`��
	for (int i = 0; i < 2; i++)
	{
		DrawGraph((int)(mountPos[i]), 0, mountID, 1);
	}
	//�_�̕`��
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
