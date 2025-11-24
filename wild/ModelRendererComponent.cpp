#include "BaseComponent.h"
#include "ModelRendererComponent.h"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <nlohmann/json.hpp>

/// <summary>
/// コンストラクタ
/// </summary>
ModelRendererComponent::ModelRendererComponent():
	m_modelHandle(-1)
{

}

/// <summary>
/// デストラクタ
/// </summary>
ModelRendererComponent::~ModelRendererComponent()
{
	MV1DeleteModel(m_modelHandle);
}

/// <summary>
/// Jsonからデータ読み込み
/// </summary>
/// <param name="data"></param>
void ModelRendererComponent::Load(const nlohmann::json& data)
{
	std::string modelPath = data["modelPath"];
	m_modelHandle = MV1LoadModel(modelPath.c_str());
}

/// <summary>
/// 描画
/// </summary>
void ModelRendererComponent::Draw()
{
	MV1DrawModel(m_modelHandle);
}