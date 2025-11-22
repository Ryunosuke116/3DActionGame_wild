#include "BaseComponent.h"
#include "TransformComponent.h"
#include "ModelRendererComponent.h"
#include "GameObject.hpp"

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

void TransformComponent::Load(const nlohmann::json& data)
{
	m_scale = VGet(data["scale"][0].get<float>(),
		data["scale"][0].get<float>(),
		data["scale"][0].get<float>());

	//オブジェクトがmodelRendererを持っていたら
	// モデルのスケールを調整する
	const auto& modelRenderer = GetOwner().lock()->GetComponent<ModelRendererComponent>().lock();
	
	if (modelRenderer != nullptr)
	{
		MV1SetScale(modelRenderer->GetModelHandle(), m_scale);
	}
}

void TransformComponent::Initialize(const nlohmann::json& data)
{
	m_position = VGet(data["position"][0].get<float>(),
		data["position"][1].get<float>(),
		data["position"][2].get<float>());

	m_rotation= VGet(data["rotation"][0].get<float>(),
		data["rotation"][1].get<float>(),
		data["rotation"][2].get<float>());

	//オブジェクトがmodelRendererを持っていたら
	// モデルの座標と向く方向を調整する
	const auto& modelRenderer = GetOwner().lock()->GetComponent<ModelRendererComponent>().lock();
	
	if (modelRenderer != nullptr)
	{
		MV1SetRotationXYZ(modelRenderer->GetModelHandle(), m_rotation);

		MV1SetPosition(modelRenderer->GetModelHandle(), m_position);
	}
}