//	__________�̏����ꂽ8�����ɂ́A�t�@�C�����̊g���q�𔲂�������������
//	��j�uPlayScene.cpp�v�̏ꍇ��
//	#include "PlayScene.h"
//	�ƂȂ�A�Ȃ�
#include "ResultScene.h"


ResultScene::ResultScene() :
	pGameSystem(nullptr),
	changeSceneFlag(false)
{

}

ResultScene::~ResultScene()
{

}

void ResultScene::Initialize(int screenWidth, int screenHeigh)
{

}

void ResultScene::Update(float deltaTime)
{

}

void ResultScene::Render()
{

}

void ResultScene::Finalize()
{

}

void ResultScene::SetGameSystemObject(GameSystemObjects* pObj)
{
	pGameSystem = pObj;
}

bool ResultScene ::GetChangeSceneFlag()
{
	return changeSceneFlag;
}


