#include "JsonLoader.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>

/// <summary>
/// インスタンスを取得
/// </summary>
/// <returns></returns>
JsonLoader& JsonLoader::GetInstance()
{
	static JsonLoader instance;
	return instance;
}

nlohmann::json JsonLoader::LoadFromFile(const char* path)
{
	//検索するディレクトリのパス
	std::string filePath = "Json";
	
	//検索したいファイル名
	std::string patternPath = static_cast<std::string>(path) + ".Json";
	std::regex pattern(patternPath);

	for (const auto& entry : std::filesystem::directory_iterator(filePath))
	{
		if (std::regex_match(entry.path().filename().string(), pattern))
		{
			std::ifstream file(entry.path());
			return nlohmann::json::parse(file);
		}
	}

	//検索失敗
	return NULL;
}