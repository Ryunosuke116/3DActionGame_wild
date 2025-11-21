#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "BaseComponent.h"
#include "nlohmann/json.hpp"
#include "JsonLoader.h"

class GameObject : public std::enable_shared_from_this<GameObject>
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	GameObject() = default;

	/// <summary>
	/// コンポーネント生成
	/// </summary>
	virtual void CreateComponent()
	{
		//処理なし
	}

	/// <summary>
	/// Jsonからデータを読み込む
	/// </summary>
	/// <param name="fileName"></param>
	virtual void Load(const std::string& fileName)
	{
		nlohmann::json data = JsonLoader::GetInstance().LoadFromFile(fileName.c_str());
		for (auto& spComponent : spComponentList)
		{
			spComponent->Load(data);
		}
	}

	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="data"></param>
	virtual void Initialize(const nlohmann::json& data)
	{
		for (auto& spComponent : spComponentList)
		{
			spComponent->Initialize(data);
		}
	}

	/// <summary>
	/// 更新
	/// </summary>
	virtual void Update()
	{
		for (auto& spComponent : spComponentList)
		{
			spComponent->Update();
		}
	}

	/// <summary>
	/// 描画
	/// </summary>
	virtual void Draw()
	{
		for (auto& spComponent : spComponentList)
		{
			spComponent->Draw();
		}
	}

	//オブジェクトが持っているコンポーネントを追加
	template<class T>
	std::shared_ptr<T> AddComponent()
	{
		auto self = shared_from_this();
		std::shared_ptr<T> spComponent = std::make_shared<T>();
		spComponent->parent = self;
		spComponentList.push_back(spComponent);
		return spComponent;
	}

	//オブジェクトが持っているコンポーネントを取得
	template<class T>
	std::weak_ptr<T> GetComponent()
	{
		for (auto& component : spComponentList)
		{
			std::shared_ptr<T> com = std::dynamic_pointer_cast<T>(component);

			if (com != nullptr)
			{
				return com;
			}
		}
		return nullptr;
	}

	std::string GetName() const { return m_name; }

protected:
	std::string m_name;
	std::vector<std::shared_ptr<BaseComponent>> spComponentList;

};