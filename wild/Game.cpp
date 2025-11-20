#include "Common.h"
#include "Game.h"

/// <summary>
/// インスタンス化
/// </summary>
/// <param name="manager"></param>
Game::Game(SceneManager& manager) :BaseScene{ manager }
{
	
}

/// <summary>
/// デストラクタ
/// </summary>
Game::~Game()
{

}

/// <summary>
/// リソースを開放する
/// </summary>
void Game::ReleaseResource()
{
	BaseScene::ReleaseResource();
}

/// <summary>
/// 生成
/// </summary>
void Game::Create()
{
	BaseScene::Create();
}

/// <summary>
/// 初期化
/// </summary>
void Game::Initialize()
{
	BaseScene::Initialize();
}

/// <summary>
/// 更新
/// </summary>
void Game::Update()
{
	BaseScene::Update();
}

void Game::Draw()
{
	BaseScene::Draw();
}