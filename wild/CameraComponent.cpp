#include "BaseComponent.h"
#include "CameraComponent.h"
#include "GameObject.hpp"

/// <summary>
/// コンストラクタ
/// </summary>
CameraComponent::CameraComponent():
	m_cameraPosition(VGet(-1.0f, -1.0f, -1.0f)),
	m_lookPosition(VGet(-1.0f, -1.0f, -1.0f)),
	m_centerPosition(VGet(-1.0f, -1.0f, -1.0f)),
	m_cameraDirection(VGet(-1.0f, -1.0f, -1.0f))
{

}

/// <summary>
/// デストラクタ
/// </summary>
CameraComponent::~CameraComponent()
{

}

void CameraComponent::Initialize(const nlohmann::json& data)
{

}

void CameraComponent::UpdateCameraDatas(
	std::shared_ptr<GameObject>& lookObject)
{
	lookObject->
}
