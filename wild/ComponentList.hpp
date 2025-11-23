#pragma once
#include <vector>
#include <memory>
#include "IComponentList.h"
#include "BaseComponent.h"

extern size_t g_nextComponentTypeID;

template<typename componentType>
class ComponentList : public IComponentList
{
public:
	ComponentList()
	{
		m_components.reserve(100);
	}

	~ComponentList()
	{
		m_components.clear();
	}

	void Update()override
	{
		for (auto&& component : m_components)
		{
			component->Update();
		}
	}

	std::weak_ptr<componentType> AddComponent()
	{
		m_components.emplace_back(std::make_shared<componentType>());
		return m_components.back();
	}

public:
	static const size_t GetID()
	{
		if (!ComponentList<componentType>::m_componentTypeID)
		{
			ComponentList<componentType>::m_componentTypeID = ++g_nextComponentTypeID;
		}
		return ComponentList<componentType>::m_componentTypeID;
	}

private:
	std::vector<std::shared_ptr<componentType>> m_components;
	static inline size_t m_componentTypeID = 0;
};

