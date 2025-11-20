#pragma once
#include <iostream>

class BaseChara :
	public GameObject
{
public:
	BaseChara(const std::string& name);
	~BaseChara();

	void CreateComponent()override;
};

