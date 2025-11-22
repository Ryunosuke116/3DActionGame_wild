#pragma once
#include "Dxlib.h"

class TransformComponent : public BaseComponent
{
public:
	TransformComponent();
	~TransformComponent();

	void Load(const nlohmann::json& data)override;
	void Initialize(const nlohmann::json& data)override;

	VECTOR GetPosition()	const { return m_position; }
	VECTOR GetRotation()	const { return m_rotation; }
	VECTOR GetScale()		const { return m_scale; }

	void SetPosition(const VECTOR& setPos)		{ m_position = setPos; }
	void SetRotation(const VECTOR& setRotation) { m_rotation = setRotation; }
	void SetScale(const VECTOR& setScale)		{ m_scale = setScale; }

private:
	VECTOR m_position;
	VECTOR m_rotation;
	VECTOR m_scale;
};