#include "common.h"
#include <memory>
#include "SceneManager.h"
#include "BaseScene.h"
#include "ObjectManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
BaseScene::BaseScene(SceneManager& manager) :manager{ manager } {}

/// <summary>
/// デストラクタ
/// </summary>
BaseScene::~BaseScene()
{

}

/// <summary>
/// リソースを開放する
/// </summary>
void BaseScene::ReleaseResource()
{
    objectManager.reset();
}

/// <summary>
/// 生成時に一度だけ呼ぶ
/// </summary>
void BaseScene::Create()
{
    objectManager = std::make_shared<ObjectManager>();
    objectManager->Create();
}

/// <summary>
/// 初期化
/// </summary>
void BaseScene::Initialize()
{
    objectManager->Initialize();
}

/// <summary>
/// 更新
/// </summary>
void BaseScene::Update()
{
    objectManager->Update();
}

/// <summary>
/// 描画
/// </summary>
void BaseScene::Draw()
{
    objectManager->Draw();
}

void BaseScene::ChangeScene(const std::string_view name)
{
    manager.ChangeScene(name);
}