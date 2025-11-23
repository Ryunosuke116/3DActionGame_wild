#include "GameObject.hpp"
#include "BaseChara.h"

#include "CommonCharaComponent.h"
#include "JsonLoader.h"

/// <summary>
/// コンストラクタ
/// </summary>
BaseChara::BaseChara(const std::string& name):
	GameObject(name)
{
	
}

/// <summary>
/// デストラクタ
/// </summary>
BaseChara::~BaseChara()
{

}

/// <summary>
/// コンポーネントの生成
/// </summary>
void BaseChara::CreateComponent()
{
	AddComponent<TransformComponent>();
	AddComponent<TransformComponent>();
	AddComponent<RigidbodyComponent>();
	AddComponent<ModelRendererComponent>();
}

