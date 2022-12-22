#pragma once

#include "../../GameDatas/Utility.h"
#include "../../GameDatas/Collision.h"
#include "../../../ExtendLib/GameSystemObject/GameSystemObjects.h"


class Player
{
public:
	const static int MAX_JUMP = 2;

private:
	//�ʒu
	Position position;

	//���x
	Vector velocity;

	//�����x
	float acceleration;

	//�d��
	float gravity;

	//�W�����v�\��
	int jumpNum;

	//�Q�i�W�����v�̉�]
	int jumpRot;

	//�v���C���[�摜�̃n���h��
	int textureHandle;


	GameSystemObjects* pSystemObject;

	//���s���̃A�j���[�V�����L�[
	int animationKey;
	//�����t���O
	bool isAlive;
public:
	Player();
	~Player();

	//������
	void Initialize();

	//�X�V
	void Update();

	//�`��
	void Render();

	Position GetPosition();
	float GetVelocityY();

	void SetSystemObject(GameSystemObjects* pObj);

	//�W�����v���x�̏������i���ł���n�ʁj
	void ResetJunp();

	//�W�����v�񐔂̏������i�n�ʁj
	void ResetJunpCount();

	void SetPosition(Position pos);

	void Finalize();

	bool IsAlive();
};