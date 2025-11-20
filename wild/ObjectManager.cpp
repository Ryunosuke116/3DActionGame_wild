#include "ObjectManager.h"
#include "BaseChara.h"
#include "Player.h"

ObjectManager::ObjectManager()
{
	//ˆ—‚È‚µ
}

ObjectManager::~ObjectManager()
{
	//ˆ—‚È‚µ
}

void ObjectManager::Create()
{
	m_objects.push_back(std::make_shared<Player>());

	for (auto& spObject : m_objects)
	{
		spObject->CreateComponent();
	}
}

void ObjectManager::Load()
{
	for (auto& spObject : m_objects)
	{
		spObject->Load(spObject->GetName());
	}
}

void ObjectManager::Initialize()
{
	for (auto& spObject : m_objects)
	{
		spObject->Initialize(spObject->GetName());
	}
}

void ObjectManager::Update()
{
	for (auto& spObject : m_objects)
	{
		spObject->Update();
	}
}

void ObjectManager::Draw()
{
	for (auto& spObject : m_objects)
	{
		spObject->Draw();
	}
}