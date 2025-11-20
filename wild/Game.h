#pragma once
#include "BaseScene.h"

class Game : public BaseScene
{
public:
	Game(SceneManager& manager);
	~Game();

	void Create()			override;
	void ReleaseResource()	override;
	void Initialize()		override;
	void Update()			override;
	void Draw()				override;
};

