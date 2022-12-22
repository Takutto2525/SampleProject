//	__________の書かれた8か所には、ファイル名の拡張子を抜いた文字を入れる
//	例）「PlayScene.cpp」の場合は
//	#include "PlayScene.h"
//	となる、など
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


