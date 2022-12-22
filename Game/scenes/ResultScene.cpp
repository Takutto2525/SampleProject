//	__________の書かれた8か所には、ファイル名の拡張子を抜いた文字を入れる
//	例）「PlayScene.cpp」の場合は
//	#include "PlayScene.h"
//	となる、など
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


