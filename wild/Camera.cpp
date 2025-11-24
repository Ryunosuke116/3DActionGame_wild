#include "Common.h"
#include "GameObject.hpp"
#include "Camera.h"

#include "CameraComponent.h"

/// <summary>
/// インストラクタ
/// </summary>
Camera::Camera():
	GameObject("camera")
{
	// グラフィックの描画先を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);

	//奥行0.1～1000までをカメラの描画範囲とする
	SetCameraNearFar(3.5f, 5000.0f);
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
	AddComponent<CameraComponent>();
}
