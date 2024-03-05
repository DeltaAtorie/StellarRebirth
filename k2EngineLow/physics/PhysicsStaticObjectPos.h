/*!
 * @brief	�ړ��\�ȐÓI�I�u�W�F�N�g�B
 */

#pragma once

#include "physics/MeshCollider.h"
#include "physics/RigidBody.h"

namespace nsK2EngineLow {
	/// <summary>
	/// �ÓI�����I�u�W�F�N�g
	/// </summary>
	class PhysicsStaticObjectPos : public Noncopyable {
	public:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		PhysicsStaticObjectPos();
		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~PhysicsStaticObjectPos();
		/// <summary>
		/// ���f������̐ÓI�I�u�W�F�N�g�̍쐬�B
		/// </summary>
		/// <param name="model">���f��</param>
		/// <param name="worldMatrix">���[���h�s��</param>
		/// <param name="restitution">������</param>
		void CreateFromModel(Model& model, const Matrix& worldMatrix, const float restitution = 0.0f);
		/// <summary>
		/// ���C�͂�ݒ肷��B
		/// </summary>
		/// <param name="friction">���C�́B10���ő�l�B</param>
		void SetFriction(float friction)
		{
			m_rigidBody.SetFriction(friction);
		}
		btCollisionObject* GetbtCollisionObject()
		{
			return m_rigidBody.GetBody();
		}
		/// <summary>
		/// ���̂�j���B
		/// </summary>
		void Release()
		{
			m_rigidBody.Release();
		}
		/// <summary>
		/// ���W��ݒ�B
		/// </summary>
		/// <param name="pos">���W�B</param>
		void SetPosition(const Vector3& pos)
		{
			auto& btTrans = m_rigidBody.GetBody()->getWorldTransform();
			btVector3 btPos;
			btPos = btVector3(pos.x, pos.y, pos.z);
			btTrans.setOrigin(btPos);
		}
	private:
		MeshCollider m_meshCollider;		//���b�V���R���C�_�[�B
		RigidBody m_rigidBody;				//���́B
	};
}