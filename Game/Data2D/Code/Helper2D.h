#pragma once
class Helper2D : public IGameObject
{
public:
//////�l�̍X�V//////
	//����
	void Increase(Vector2& Alpha , float Speed)
	{
		Alpha.x += Speed * g_gameTime->GetFrameDeltaTime();
		Alpha.y -= Speed * g_gameTime->GetFrameDeltaTime();
	}
	void Increase(float& Alpha   , float Speed)
	{
		Alpha += Speed * g_gameTime->GetFrameDeltaTime();
	}
	//����
	void Decrease(Vector2& Alpha , float Speed)
	{
		Alpha.x -= Speed * g_gameTime->GetFrameDeltaTime();
		Alpha.y += Speed * g_gameTime->GetFrameDeltaTime();
	}
	void Decrease(float& Alpha   , float Speed)
	{
		Alpha -= Speed * g_gameTime->GetFrameDeltaTime();
	}

//////�摜�̍X�V�E�`��ꊇ����//////
		//�S����
	void SpriteUpdate(SpriteRender* Sprite , Vector4* Color , Vector3* Position  , Vector3* Scale, Vector2* Pivot, int Size = 1, bool Common = false)
	{
		if (Size == 1)
		{
			Sprite->SetMulColor(*Color);
			Sprite->SetPosition(*Position);
			Sprite->SetScale(*Scale);
			Sprite->SetPivot(*Pivot);
			Sprite->Update();
		}else {
			for (int i = 0 ; i < Size ; i++)
			{
				if (!Common)
				{
					Sprite[i].SetMulColor(Color[i]);
					Sprite[i].SetPosition(Position[i]);
					Sprite[i].SetScale(Scale[i]);
					Sprite[i].SetPivot(Pivot[i]);
					Sprite[i].Update();
				}else {
					if (Common)
					{
						Sprite[i].SetMulColor(*Color);
						Sprite[i].SetPosition(*Position);
						Sprite[i].SetScale(*Scale);
						Sprite[i].SetPivot(*Pivot);
						Sprite[i].Update();
					}
				}
			}
		}
	}
//�F����
	void SpriteUpdate(SpriteRender* Sprite , Vector4* Color , int Size = 1  , bool Common = false)
	{
		if (Size == 1)
		{
			Sprite->SetMulColor(*Color);
			Sprite->Update();
		}else {
			for (int i = 0 ; i < Size ; i++)
			{
				if (!Common)
				{
					Sprite[i].SetMulColor(Color[i]);
					Sprite[i].Update();
				}else {
					if (Common)
					{
						Sprite[i].SetMulColor(*Color);
						Sprite[i].Update();
					}
				}
			}
		}
	}
//���W�E�䗦����
	void SpriteUpdate(SpriteRender* Sprite , Vector3* Position , Vector3* Scale = nullptr , int Size = 1, bool Common = false)
	{
		if (Size == 1)
		{
			Sprite->SetPosition(*Position);
			if (Scale != nullptr)
			{
				Sprite->SetScale(*Scale);
			}
			Sprite->Update();
		}else {
			for (int i = 0 ; i < Size ; i++)
			{
				if (!Common)
				{
					Sprite[i].SetPosition(Position[i]);
					if (Scale != nullptr)
					{
						Sprite->SetScale(*Scale);
					}
					Sprite[i].Update();
				}else {
					if (Common)
					{
						Sprite[i].SetPosition(*Position);
						if (Scale != nullptr)
						{
							Sprite->SetScale(*Scale);
						}
						Sprite[i].Update();
					}
				}
			}
		}
	}
//������
	void SpriteUpdate(SpriteRender* Sprite , Vector2* Pivot , int Size = 1 , bool Common = false)
	{
		if (Size == 1)
		{
			Sprite->SetPivot(*Pivot);
			Sprite->Update();
		}else {
			for (int i = 0 ; i < Size ; i++)
			{
				if (!Common)
				{
					Sprite[i].SetPivot(Pivot[i]);
					Sprite[i].Update();
				}else {
					if (Common)
					{
						Sprite[i].SetPivot(*Pivot);
						Sprite[i].Update();
					}
				}

			}
		}
	}
//�`�揈��
	void SpriteDraw(SpriteRender* Sprite , RenderContext& rc , int Size = 1 , bool Common = false)
	{
		if (Size == 1)
		{
			Sprite->Draw(rc);
		}else {
			for (int i = 0 ; i < Size ; i++)
			{
				Sprite[i].Draw(rc);
			}
		}
	}

//////���W�̐ݒ�//////
	//����l
	bool OverflowUp(int& Position     , int LimitPosition)
	{
		if (Position >= LimitPosition)
		{
			Position = LimitPosition;
			return true;
		}
		return false;
	}
	bool OverflowUp(float& Position   , float LimitPosition)
	{
		if (Position >= LimitPosition)
		{
			Position = LimitPosition;
			return true;
		}
		return false;
	}
	bool OverflowUp(Vector2& Position , Vector2 LimitPosition)
	{
		if (Position.x >= LimitPosition.x && Position.y >= LimitPosition.y)
		{
			Position = LimitPosition;
			return true;
		}
		return false;
	}
	bool OverflowUp(Vector3& Position , Vector3 LimitPosition)
	{
		if (Position.x >= LimitPosition.x && Position.y >= LimitPosition.y && Position.z >= LimitPosition.z)
		{
			Position = LimitPosition;
			return true;
		}
		return false;
	}
	//�����l
	bool OverflowDown(int& Position     , int LimitPosition)
	{
		if (Position <= LimitPosition)
		{
			Position = LimitPosition;
			return true;
		}
		return false;
	}
	bool OverflowDown(float& Position   , float LimitPosition)
	{
		if (Position <= LimitPosition)
		{
			Position = LimitPosition;
			return true;
		}
		return false;
	}
	bool OverflowDown(Vector2& Position , Vector2 LimitPosition)
	{
		if (Position.x <= LimitPosition.x && Position.y <= LimitPosition.y)
		{
			Position = LimitPosition;
			return true;
		}
		return false;
	}
	bool OverflowDown(Vector3& Position , Vector3 LimitPosition)
	{
		if (Position.x <= LimitPosition.x && Position.y <= LimitPosition.y && Position.z <= LimitPosition.z)
		{
			Position = LimitPosition;
			return true;
		}
		return false;
	}

//////�ȈՏ���//////
	void FlagReverse(bool& Flag)
	{
		if (Flag == true)
		{
			Flag = false;
		}else {
			if (Flag == false)
			{
				Flag = true;
			}
		}
	}
};
