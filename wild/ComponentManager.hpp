#pragma once
#include <unordered_map>
#include <memory>
#include "IComponentList.h"
#include "ComponentList.hpp"

class ComponentManager
{
public:
	static ComponentManager& GetInstance()
	{
		static ComponentManager instance;
		return instance;
	}

	void Update()
	{
		for (auto&& componentList : m_typeToComponentList)
		{
			componentList.second->Update();
		}
	}

	template<typename ComponentType>
	std::weak_ptr<ComponentType> AddComponent()
	{
		size_t type = ComponentList<ComponentType>::GetID();

		//リストに無いコンポーネントだった場合追加する
		if (m_typeToComponentList.find(type) == m_typeToComponentList.end())
		{
			m_typeToComponentList[type] = std::make_shared<ComponentList<ComponentType>>();
		}
		
		auto spComponentList = std::dynamic_pointer_cast<ComponentList<ComponentType>>(m_typeToComponentList[type]);
		return spComponentList->AddComponent();
	}

private:
	ComponentManager() {}

private:
	std::unordered_map <size_t, std::shared_ptr<IComponentList>> m_typeToComponentList;
};

