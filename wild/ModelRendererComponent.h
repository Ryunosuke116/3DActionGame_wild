#pragma once
#include "DxLib.h"

class ModelRendererComponent : public BaseComponent
{
public:
	ModelRendererComponent();
	~ModelRendererComponent();

	void Load(const nlohmann::json& data)override;
	void Draw()override;

	int GetModelHandle()const { return m_modelHandle; }

private:
	int m_modelHandle;
};

