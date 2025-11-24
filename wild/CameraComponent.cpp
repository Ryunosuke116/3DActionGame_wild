#include "BaseComponent.h"
#include "CameraComponent.h"
#include "GameObject.hpp"
#include "TransformComponent.h"

#include <cmath>

/// <summary>
/// コンストラクタ
/// </summary>
CameraComponent::CameraComponent() :
	m_cameraPosition(VGet(-1.0f, -1.0f, -1.0f)),
	m_lookPosition(VGet(-1.0f, -1.0f, -1.0f)),
	m_centerPosition(VGet(-1.0f, -1.0f, -1.0f)),
	m_cameraDirection(VGet(-1.0f, -1.0f, -1.0f)),
	m_cameraDegree(-1.0f),
	m_cameraAndCenterDistance(-1.0f)
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

	m_cameraDegree				= data["degree"].get<float>();
	m_cameraAndCenterDistance	= data["distance"].get<float>();

	LookPosUpdate();

	SetCameraPositionAndTarget_UpVecY(m_cameraPosition, m_lookPosition);
}

void CameraComponent::Update()
{

}

void CameraComponent::UpdateCameraDatas(
	std::shared_ptr<GameObject>& playerObject)
{
	m_centerPosition = playerObject->GetComponent<TransformComponent>().lock()->GetPosition();
	m_centerPosition.y += kAddCenterPositionY;
}

/// <summary>
/// カメラが注視するものを変更する
/// </summary>
/// <param name="newLookObject"></param>
void CameraComponent::ChangeLookObject(std::shared_ptr<GameObject>& newLookObject)
{
	////同じオブジェクトであれば変更しない
	//if (lookObject.lock()->GetName() == newLookObject->GetName())
	//{
	//	return;
	//}

	//lookObject = std::move(newLookObject);
}

void CameraComponent::CenterPosUpdate(std::shared_ptr<GameObject>& object)
{
	const float kAddCenterPosY = 14.0f;

	m_centerPosition = object->GetComponent<TransformComponent>().lock()->GetPosition();
	m_centerPosition.y += kAddCenterPosY;
}

void CameraComponent::RotateUpdate()
{
	float cameraRadian = m_cameraDegree * DX_PI_F / 180.0f;

	m_cameraPosition.x = m_centerPosition.x + m_cameraAndCenterDistance * cos(cameraRadian);
	m_cameraPosition.z = m_centerPosition.z + m_cameraAndCenterDistance * sin(cameraRadian);
}

void CameraComponent::LookPosUpdate()
{
	//通常時の視点座標
	VECTOR dir = VSub(m_centerPosition, m_cameraPosition);
	dir = VNorm(dir);
	VECTOR scale = VScale(dir, kLookScale);
	m_lookPosition = VAdd(m_centerPosition, scale);
}