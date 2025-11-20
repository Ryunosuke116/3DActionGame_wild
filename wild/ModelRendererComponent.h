#pragma once
#include <iostream>

class ModelRendererComponent : public BaseComponent
{
public:
	ModelRendererComponent();
	~ModelRendererComponent();

	void Load(const nlohmann::json& data)override;
	void Draw()override;

private:
	int m_modelHandle;

};

