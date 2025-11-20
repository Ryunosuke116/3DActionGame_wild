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
	std::weak_ptr<GameObject> parent;

	virtual void Load(const nlohmann::json& data)		{};
	virtual void Initialize(const nlohmann::json& data)	{};
	virtual void Update()									{};
	virtual void Draw()										{};
};