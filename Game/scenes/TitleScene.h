#pragma once
#include "../../ExtendLib/GameSystemObject/GameSystemObjects.h"

//	__________�̏����ꂽ3�����ɂ́A�t�@�C�����̊g���q�𔲂�������������
//	��j�uPlayScene.h�v�̏ꍇ��
//	class PlayScene
//	�ƂȂ�A�Ȃ�
class TitleScene
{
private:
public:

private:
	GameSystemObjects* pGameSystem;
	bool	changeSceneFlag;
public:

private:



	//	�ϐ��錾�I���I

public:
	TitleScene();							//	�R���X�g���N�^�ƌĂ΂��֐�
	~TitleScene();							//	�f�X�g���N�^�ƌĂ΂��֐�


	void Initialize(int screenWidth, int screenHeight);						//	�Q�[���̏��������s���֐�
	void Update(float deltaTime);					//	�Q�[���̍X�V�������s���֐�
	void Render();							//	�Q�[���̕`����s���֐��BDraw�Ə����ꍇ������
	void Finalize();						//	�Q�[���̏I���������s���֐��B����������K�v�ȏꍇ�iRelease�֐��Ȃǂ��Ăяo���j�́A���̊֐����ŏ�������

	void SetGameSystemObject(GameSystemObjects* pObj);
	bool GetChangeSceneFlag();
	//	�֐��錾�I���I
};

