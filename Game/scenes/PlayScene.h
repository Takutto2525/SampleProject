#pragma once
#include "../../ExtendLib/GameSystemObject/GameSystemObjects.h"

#include "../GameObjects/PlayScene/WaveManager.h"
#include "../GameObjects/PlayScene/Player.h"
#include "../GameObjects/PlayScene/BackGround.h"

//-------------------
//class PlayScene
//--------------------

class PlayScene
{
private:
public:

private:
	GameSystemObjects* pGameSystem;
	bool	changeSceneFlag;
	Player player;

	WaveManager waveManager;

	BackGround backGround;
public:

private:



	//	�ϐ��錾�I���I

public:
	PlayScene();							//	�R���X�g���N�^�ƌĂ΂��֐�
	~PlayScene();							//	�f�X�g���N�^�ƌĂ΂��֐�


	void Initialize(int screenWidth, int screenHeight);						//	�Q�[���̏��������s���֐�
	void Update(float deltaTime);					//	�Q�[���̍X�V�������s���֐�
	void Render();							//	�Q�[���̕`����s���֐��BDraw�Ə����ꍇ������
	void Finalize();						//	�Q�[���̏I���������s���֐��B����������K�v�ȏꍇ�iRelease�֐��Ȃǂ��Ăяo���j�́A���̊֐����ŏ�������

	void SetGameSystemObject(GameSystemObjects* pObj);
	bool GetChangeSceneFlag();
	//	�֐��錾�I���I
};

