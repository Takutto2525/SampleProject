/*
	Game.cpp
	ゲームで行う実際の処理を呼び出すため、実際にクラス内へ処理を記述するためのファイル。
	このファイルにゲームの処理を実装して、ゲームを作ろう！

	作成者　：　堀川　和雅
	作成日　：　2021/03/15
*/

#include <DxLib.h>						//	こちらでも使うため、DxLib.hをインクルードしておく
#include "Game.h"

//	コンストラクタと呼ばれる関数
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
	//	慣れないうちは、この関数内に処理は書かなくてOK
}

//	デストラクタと呼ばれる関数
Game::~Game()
{
	//	慣れないうちは、この関数内に処理は書かなくてOK
}


//	ゲームの初期化を行う関数
void Game::Initialize()
{
	//	ここから初期化処理を書いていく。
	//	ここに書く処理は、ゲーム起動直後に1回しか実行されないように処理が書かれている。

	titleScene.Initialize(screenWidth, screenHeight);
	playScene.Initialize(screenWidth, screenHeight);
	resultScene.Initialize(screenWidth, screenHeight);
	//	初期化処理完了！
}

//	ゲームの更新処理を行う関数
void Game::Update()
{
	//	ゲームの更新処理を書いていく。
	//	1フレームに1回実行されるように、呼び出し処理が書かれている。
	//	Render関数よりも早く呼ばれる。
	//	この関数内では、描画の処理を書くことができない。
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
	//	ゲームの更新処理終了！
}

//	ゲームの描画を行う関数。Drawと書く場合もある
void Game::Render()
{
	//	ゲームの描画処理を書いていく。
	//	1フレームに1回実行されるように、呼び出し処理が書かれていて、
	//	この関数が呼ばれた段階では、画面が黒塗りでリセットされている。
	//	Update関数の後に呼ばれる。
	//	この関数内では、できる限り計算処理などを行わないように心がけること。
	//	※少なければ少ないほど、嬉しい。

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


	//	テストの文字描画
	DrawFormatString(0, 0, GetColor(255, 255, 255), "アクションゲーム開発！");

	//	ゲームの描画処理終了！
}

//	ゲームの終了処理を行う関数。解放処理が必要な場合（Release関数などを呼び出す）は、この関数内で処理する
void Game::Finalize()
{
	//	終了処理を書いていく。
	//	ここに書く処理は、ゲーム終了直前に1回しか実行されないように処理が書かれている。


	//	終了処理完了！
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





