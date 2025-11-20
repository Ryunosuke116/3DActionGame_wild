#pragma once
#include <nlohmann/json.hpp>

class JsonLoader
{
public:
	static JsonLoader& GetInstance();  // シングルトン取得

	JsonLoader() = default;
	~JsonLoader() = default;

	//jsonデータを読み込む
	static nlohmann::json LoadFromFile(const char* path);
};

