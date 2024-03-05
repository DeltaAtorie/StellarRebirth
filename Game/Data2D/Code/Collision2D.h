#pragma once
struct ObjectData
{
	char ObjectName[256]            = "nullptr";//�I�u�W�F�N�g�̖��O
	char Tag[256]                   = "nullptr";//�I�u�W�F�N�g�̃^�O
	int Direction                   = 0;//�I�u�W�F�N�g�̋����
	float UpperLeftVertexPositionX  = 0;//��`�̍���X
	float UpperLeftVertexPositionY  = 0;//��`�̍���Y
	float LowerRightVertexPositionX = 0;//��`�̉E��X
	float LowerRightVertexPositionY = 0;//��`�̉E��Y
	float Wide                      = 0;
	float Height                    = 0;
};
enum
{
	DIRECTION_NON   = 0,
	DIRECTION_UP    = 1,
	DIRECTION_RIGHT = 2,
	DIRECTION_DOWN  = 3,
	DIRECTION_LEFT  = 4
};
class Collision2D : public IGameObject
{
public:

	Collision2D();
	void Reset();

	//�����蔻��̐���
	void BodyDataSet(float  Wide , float Height , float PositionX , float PositionY , const char* ObjectName , const char* Tag);

	//�R�s�[
	bool CopyBodyData(ObjectData& Decision   , const char* ObjectName);//�y�{�́z�̃R�s�[
	bool CopyBodysData(ObjectData& Decision  , const char* Tag        , int Count);//�y�^�O���t���������̖{�́z�̃R�s�[
	bool CopyEmptyData(ObjectData& Decision  , const char* ObjectName , int Direction);//�y��z�̃R�s�[
	bool CopyEmptysData(ObjectData& Decision , const char* Tag        , int Direction , int Count);//�y�^�O���t���������̋�z�̃R�s�[

	//���W�X�V
	void BodySetPosition(float PositionX , float PositionY , const char* ObjectName);

	//�Փ˔���
	bool EmptyAndEmptyCollision(const char* ObjectName1 , int Direction1 , const char* ObjectName2 , int Direction2);//�y�󓯎m�z�̏Փ�
	bool BodyAndBodyCollision(const char* ObjectName1   , const char* ObjectName2);//�y�{�̓��m�z�̏Փ�

	bool EmptyAndBodyCollision(const char* ObjectName1 , int Direction1 , const char* ObjectName2);//�y��z�Ɓy�{�́z�̏Փ�

	bool EmptyAndBodysCollision(const char* ObjectName1  , int Direction1 , const char* Tag2);//�y��z�Ɓy�^�O���t���������̖{�́z�̏Փ�
	bool EmptyAndEmptysCollision(const char* ObjectName1 , int Direction1 , const char* Tag2 , int Direction2);//�y��z�Ɓy�^�O���t���������̋�z�̏Փ�

	bool BodyAndBodysCollision(const char* ObjectName1  , const char* Tag2);//�y�{�́z�Ɓy�^�O���t���������̖{�́z�̏Փ�
	bool BodyAndEmptysCollision(const char* ObjectName1 , const char* Tag2 , int Direction2);//�y�{�́z�Ɓy�^�O���t���������̋�z�̏Փ�
private:
	void BodyInSideDataSet(int Count);
	void BodyUpSetPosition(int Count);
	void BodyRightSetPosition(int Count);
	void BodyDownSetPosition(int Count);
	void BodyLeftSetPosition(int Count);
private:
	ObjectData BodyData[256][5];
	float EmptyWidth = 15.0f;
	float InitValue  = 50000.0f;
};
