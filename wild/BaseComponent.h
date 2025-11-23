#pragma once
#include <iostream>
#include <memory>
#include "nlohmann/json.hpp"

class GameObject;

class BaseComponent
{
public:
	BaseComponent() {}
	virtual ~BaseComponent() {}

	void SetOwner(std::weak_ptr<GameObject> owner)
	{
		m_owner = owner;
	}

	std::weak_ptr<GameObject> GetOwner()const { return m_owner; }

	virtual void Load(const nlohmann::json& data)			{};
	virtual void Initialize(const nlohmann::json& data)		{};
	virtual void Update()									{};
	virtual void Draw()										{};

protected:
	std::weak_ptr<GameObject> m_owner;
};