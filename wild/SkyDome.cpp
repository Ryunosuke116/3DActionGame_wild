#include "GameObject.hpp"
#include "SkyDome.h"
#include "ModelRendererComponent.h"
#include "TransformComponent.h"

SkyDome::SkyDome():
	GameObject("skyDome")
{
	//ˆ—‚È‚µ
}

SkyDome::~SkyDome()
{
	//ˆ—‚È‚µ
}

void SkyDome::CreateComponent()
{
	AddComponent<ModelRendererComponent>();
	AddComponent<TransformComponent>();
}