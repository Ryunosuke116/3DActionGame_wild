#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "GameObject.hpp"

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void Create();
	void Load();
	void Initialize();
	void Update();
	void Draw();
private:
	std::vector<std::shared_ptr<GameObject>> m_objects;
};

