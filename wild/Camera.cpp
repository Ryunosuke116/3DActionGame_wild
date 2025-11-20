#include "Common.h"
#include "GameObject.hpp"
#include "Camera.h"

#include "TransformComponent.h"

/// <summary>
/// インストラクタ
/// </summary>
Camera::Camera()
{
	// グラフィックの描画先を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);

	//奥行0.1～1000までをカメラの描画範囲とする
	SetCameraNearFar(0.1f, 1000.0f);
}

/// <summary>
/// デストラクタ
/// </summary>
Camera::~Camera()
{

}

/// <summary>
/// コンポーネントの生成
/// </summary>
void Camera::CreateComponent()
{
	AddComponent<TransformComponent>();
}

/// <summary>
/// カメラが注視するものを変更する
/// </summary>
/// <param name="newLookObject"></param>
void Camera::ChangeLookObject(std::shared_ptr<GameObject>& newLookObject)
{
	//同じオブジェクトであれば変更しない
	if (lookObject.lock()->GetName() == newLookObject->GetName())
	{
		return;
	}

	lookObject = std::move(newLookObject);
}