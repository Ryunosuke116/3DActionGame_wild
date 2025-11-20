#pragma once
#include <memory>

class Camera : 
	public GameObject
{
public:
	Camera();
	~Camera();

	void CreateComponent()override;

	void ChangeLookObject(std::shared_ptr<GameObject>& newLookObject);

private:
	std::weak_ptr<GameObject> lookObject;
};

