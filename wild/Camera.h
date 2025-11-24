#pragma once
#include <memory>

class Camera : 
	public GameObject
{
public:
	Camera();
	~Camera();

	void CreateComponent()override;

private:
	std::weak_ptr<GameObject> lookObject;
	std::weak_ptr<GameObject> centerObject;
};

