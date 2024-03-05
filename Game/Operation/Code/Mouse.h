#pragma once
class Data2D;
enum MouseFlagStorage
{
	MOUSE_LEFTCLICK,
	MOUSE_RIGHTCLICK ,
	MOUSE_FLICK
};
class Mouse : public IGameObject
{
public:
	bool Start();
	void Update();
	
	void MouseCurSorSetPosition(Vector3& Position);

	void MouseMove();
	void MouseSet();

	void MouseFlagJudge();
	bool GetMouseFlag(int Number);
	
	Vector3 GetMousePosition()
	{return M_MouseCursorPosition; }
	Vector3 GetMouseMoveSpeed()
	{return M_MouseCursorMoveSpeed;}
	Vector2 GetDelta()
	{return M_Delta;}
private:
	Vector3 M_MouseCursorPosition;
	Vector3 M_MouseCursorMoveSpeed;//�}�E�X�J�[�\���̈ړ���

	POINT M_CursorPosition = {};
	HWND M_HWnd = GetConsoleWindow();

	Vector2 M_Client      = { 1535.0f , 863.0f };//�E�B���h�E�̏c��
	Vector2 M_Window      = { 1920.0f , 1080.0f };//���K�E�B���h�E�̏c��
	Vector2 M_PrevMouse   = { 0.0f    , 0.0f };//�O��̃}�E�X���W
	Vector2 M_Delta       = { 0.0f    , 0.0f };//�}�E�X�̑��ΓI�Ȉړ���
	Vector2 M_DeltaSpeed  = { 0.0f    , 0.0f };//Delta���t���[���ԂŊ��������l
	Vector2 M_Converted   = { 0.0f    , 0.0f };//���݂̃}�E�X���W

	bool M_LeftClickFlag  = false;
	bool M_RightClickFlag = false;
	bool M_FlickFlag      = false;

	float M_DeltaTime = 0.0f;
	float FlickSpeedThreshold = 6000.0f;

	Data2D* P_Data2D = nullptr;
};