#include "BaseComponent.h"
#include "TransformComponent.h"

/// <summary>
/// コンストラクタ
/// </summary>
TransformComponent::TransformComponent() :
	m_position(VGet(-1.0f, -1.0f, -1.0f)),
	m_rotation(VGet(-1.0f, -1.0f, -1.0f)),
	m_scale(VGet(-1.0f, -1.0f, -1.0f))
{
	//処理なし
}

/// <summary>
/// デストラクタ
/// </summary>
TransformComponent::~TransformComponent()
{
	//処理なし
}