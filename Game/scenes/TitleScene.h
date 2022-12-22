#pragma once
#include "../../ExtendLib/GameSystemObject/GameSystemObjects.h"

//	__________の書かれた3か所には、ファイル名の拡張子を抜いた文字を入れる
//	例）「PlayScene.h」の場合は
//	class PlayScene
//	となる、など
class TitleScene
{
private:
public:

private:
	GameSystemObjects* pGameSystem;
	bool	changeSceneFlag;
public:

private:



	//	変数宣言終了！

public:
	TitleScene();							//	コンストラクタと呼ばれる関数
	~TitleScene();							//	デストラクタと呼ばれる関数


	void Initialize(int screenWidth, int screenHeight);						//	ゲームの初期化を行う関数
	void Update(float deltaTime);					//	ゲームの更新処理を行う関数
	void Render();							//	ゲームの描画を行う関数。Drawと書く場合もある
	void Finalize();						//	ゲームの終了処理を行う関数。解放処理が必要な場合（Release関数などを呼び出す）は、この関数内で処理する

	void SetGameSystemObject(GameSystemObjects* pObj);
	bool GetChangeSceneFlag();
	//	関数宣言終了！
};

