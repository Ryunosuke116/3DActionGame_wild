#pragma once
#include <vector>

template<typename componentType>
class ComponentList
{
public:
	ComponentList();
	~ComponentList();

public:
	static const size_t GetID()
	{
		if (!ComponentList<componentType>::m_compTypeID)
		{

		}
	}

private:
	std::vector<componentType> m_components;
	static size_t m_compTypeID;
};

