//	__________�̏����ꂽ8�����ɂ́A�t�@�C�����̊g���q�𔲂�������������
//	��j�uPlayScene.cpp�v�̏ꍇ��
//	#include "PlayScene.h"
//	�ƂȂ�A�Ȃ�
#include "titleScene.h"

TitleScene::TitleScene() :
	pGameSystem(nullptr),
	changeSceneFlag(false)
{

}

TitleScene::~TitleScene()
{

}

void TitleScene::Initialize(int screenWidth, int screenHeigh)
{

}

void TitleScene::Update(float deltaTime)
{

}

void TitleScene::Render()
{

}

void TitleScene::Finalize()
{

}

void TitleScene::SetGameSystemObject(GameSystemObjects* pObj)
{
	pGameSystem = pObj;
}

bool TitleScene::GetChangeSceneFlag()
{
	return changeSceneFlag;
}


