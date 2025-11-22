#include "BaseComponent.h"
#include "CameraComponent.h"
#include "GameObject.hpp"
#include "TransformComponent.h"

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
	m_cameraPosition = VGet(data["cameraPosition"][0].get<float>(),
		data["cameraPosition"][1].get<float>(),
		data["cameraPosition"][2].get<float>());

	m_centerPosition = VGet(data["centerPosition"][0].get<float>(),
		data["centerPosition"][1].get<float>(),
		data["centerPosition"][2].get<float>());

	//通常時の視点座標
	VECTOR dir = VSub(m_centerPosition, m_cameraPosition);
	dir = VNorm(dir);
	VECTOR scale = VScale(dir, 40.0f);
	m_lookPosition = VAdd(m_centerPosition, scale);

	SetCameraPositionAndTarget_UpVecY(m_cameraPosition, m_lookPosition);
}

void CameraComponent::UpdateCameraDatas(
	std::shared_ptr<GameObject>& playerObject)
{
	m_centerPosition = playerObject->GetComponent<TransformComponent>().lock()->GetPosition();
	m_centerPosition.y += kAddCenterPositionY;
}
