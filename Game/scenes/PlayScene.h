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



	//	変数宣言終了！

public:
	PlayScene();							//	コンストラクタと呼ばれる関数
	~PlayScene();							//	デストラクタと呼ばれる関数


	void Initialize(int screenWidth, int screenHeight);						//	ゲームの初期化を行う関数
	void Update(float deltaTime);					//	ゲームの更新処理を行う関数
	void Render();							//	ゲームの描画を行う関数。Drawと書く場合もある
	void Finalize();						//	ゲームの終了処理を行う関数。解放処理が必要な場合（Release関数などを呼び出す）は、この関数内で処理する

	void SetGameSystemObject(GameSystemObjects* pObj);
	bool GetChangeSceneFlag();
	//	関数宣言終了！
};

