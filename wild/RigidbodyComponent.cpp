#include "BaseComponent.h"
#include "RigidbodyComponent.h"

/// <summary>
/// コンストラクタ
/// </summary>
RigidbodyComponent::RigidbodyComponent() :
	m_topCapsulePosition(VGet(-1.0f, -1.0f, -1.0f)),
	m_bottomCapulePosition(VGet(-1.0f, -1.0f, -1.0f)),
	m_centerPosition(VGet(-1.0f, -1.0f, -1.0f))
{

}

/// <summary>
/// デストラクタ
/// </summary>
RigidbodyComponent::~RigidbodyComponent()
{

}

