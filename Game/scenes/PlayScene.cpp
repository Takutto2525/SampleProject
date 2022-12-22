//	__________�̏����ꂽ8�����ɂ́A�t�@�C�����̊g���q�𔲂�������������
//	��j�uPlayScene.cpp�v�̏ꍇ��
//	#include "PlayScene.h"
//	�ƂȂ�A�Ȃ�
#include "PlayScene.h"



PlayScene::PlayScene() :
	pGameSystem(nullptr),
	changeSceneFlag(false)
{

}

PlayScene::~PlayScene()
{

}

void PlayScene::Initialize(int screenWidth, int screenHeigh)
{
	backGround.Initialize();
	waveManager.Initialize();
	player.Initialize();
}

void PlayScene::Update(float deltaTime)
{
	backGround.Update(deltaTime);
	waveManager.Update(deltaTime);
	player.Update();
	waveManager.CheckHitPlayer(&player);
	backGround.SetSpeed(waveManager.GetSpeed());
}

void PlayScene::Render()
{
	backGround.Render();
	waveManager.Render();
	player.Render();
}

void PlayScene::Finalize()
{
	player.Finalize();
}

void PlayScene::SetGameSystemObject(GameSystemObjects* pObj)
{
	pGameSystem = pObj;
	player.SetSystemObject(pObj);
}

bool PlayScene::GetChangeSceneFlag()
{
	return changeSceneFlag;
}


