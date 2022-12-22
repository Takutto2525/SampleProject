/*
	Game.cpp
	�Q�[���ōs�����ۂ̏������Ăяo�����߁A���ۂɃN���X���֏������L�q���邽�߂̃t�@�C���B
	���̃t�@�C���ɃQ�[���̏������������āA�Q�[������낤�I

	�쐬�ҁ@�F�@�x��@�a��
	�쐬���@�F�@2021/03/15
*/

#include <DxLib.h>						//	������ł��g�����߁ADxLib.h���C���N���[�h���Ă���
#include "Game.h"

//	�R���X�g���N�^�ƌĂ΂��֐�
Game::Game():
	sceneID(SceneID::PlayScene),
	screenWidth(0),
	screenHeight(0),
	oldTime((LONGLONG)0),
	nowTime((LONGLONG)0),
	deltaTime(0.0f),
	firstWait(0.0f),
	pGameSystem(nullptr)
{
	//	����Ȃ������́A���̊֐����ɏ����͏����Ȃ���OK
}

//	�f�X�g���N�^�ƌĂ΂��֐�
Game::~Game()
{
	//	����Ȃ������́A���̊֐����ɏ����͏����Ȃ���OK
}


//	�Q�[���̏��������s���֐�
void Game::Initialize()
{
	//	�������珉���������������Ă����B
	//	�����ɏ��������́A�Q�[���N�������1�񂵂����s����Ȃ��悤�ɏ�����������Ă���B

	titleScene.Initialize(screenWidth, screenHeight);
	playScene.Initialize(screenWidth, screenHeight);
	resultScene.Initialize(screenWidth, screenHeight);
	//	���������������I
}

//	�Q�[���̍X�V�������s���֐�
void Game::Update()
{
	//	�Q�[���̍X�V�����������Ă����B
	//	1�t���[����1����s�����悤�ɁA�Ăяo��������������Ă���B
	//	Render�֐����������Ă΂��B
	//	���̊֐����ł́A�`��̏������������Ƃ��ł��Ȃ��B
	oldTime = nowTime;
	nowTime = GetNowHiPerformanceCount();

	deltaTime = (float)((nowTime - oldTime) / 1000000.0f);

	bool changeSceneFlag = false;
	if (!firstWait && deltaTime < 1.0f)
	{
		firstWait = true;
	}
	else if (!firstWait)
	{
		return;
	}
	 
	switch (sceneID)
	{
	case SceneID::TitleScene:
		titleScene.Update(deltaTime);
		changeSceneFlag = titleScene.GetChangeSceneFlag();
		break;
	case SceneID::PlayScene:
		playScene.Update(deltaTime);
		changeSceneFlag = playScene.GetChangeSceneFlag();
		break;
	case SceneID::ResultScene:
		resultScene.Update(deltaTime);
		changeSceneFlag = resultScene.GetChangeSceneFlag();
		break;
	}

	if (changeSceneFlag)
	{
		switch (sceneID)
		{
		case SceneID::TitleScene:
			sceneID = SceneID::PlayScene;
			playScene.Initialize(screenWidth, screenHeight);
			break;
		case SceneID::PlayScene:
			sceneID = SceneID::ResultScene;
			resultScene.Initialize(screenWidth, screenHeight);
			break;
		case SceneID::ResultScene:
			sceneID = SceneID::PlayScene;
			playScene.Initialize(screenWidth, screenHeight);//koko
			break;
		}
	}
	//	�Q�[���̍X�V�����I���I
}

//	�Q�[���̕`����s���֐��BDraw�Ə����ꍇ������
void Game::Render()
{
	//	�Q�[���̕`�揈���������Ă����B
	//	1�t���[����1����s�����悤�ɁA�Ăяo��������������Ă��āA
	//	���̊֐����Ă΂ꂽ�i�K�ł́A��ʂ����h��Ń��Z�b�g����Ă���B
	//	Update�֐��̌�ɌĂ΂��B
	//	���̊֐����ł́A�ł������v�Z�����Ȃǂ��s��Ȃ��悤�ɐS�����邱�ƁB
	//	�����Ȃ���Ώ��Ȃ��قǁA�������B

	switch (sceneID)
	{
	case SceneID::TitleScene:
		titleScene.Render();
		break;
	case SceneID::PlayScene:
		playScene.Render();
		break;
	case SceneID::ResultScene:
		resultScene.Render();
		break;
	}


	//	�e�X�g�̕����`��
	DrawFormatString(0, 0, GetColor(255, 255, 255), "�A�N�V�����Q�[���J���I");

	//	�Q�[���̕`�揈���I���I
}

//	�Q�[���̏I���������s���֐��B����������K�v�ȏꍇ�iRelease�֐��Ȃǂ��Ăяo���j�́A���̊֐����ŏ�������
void Game::Finalize()
{
	//	�I�������������Ă����B
	//	�����ɏ��������́A�Q�[���I�����O��1�񂵂����s����Ȃ��悤�ɏ�����������Ă���B


	//	�I�����������I
}

void Game::SetScreenSize(int width, int height)
{
	screenWidth = width;
	screenHeight = height;
}

void Game::SetGameSystemObjects(GameSystemObjects* pObj)
{
	pGameSystem = pObj;

	titleScene.SetGameSystemObject(pObj);
	playScene.SetGameSystemObject(pObj);
	resultScene.SetGameSystemObject(pObj);
}




