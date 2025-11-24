#pragma once
#include "DxLib.h"
#include <memory>

class CameraComponent :
    public BaseComponent
{
public:
    CameraComponent();
    ~CameraComponent();

    void UpdateCameraDatas(std::shared_ptr<GameObject>& newLookObject);
    void Initialize(const nlohmann::json& data) override;
    void Update()override;

    VECTOR GetCameraPosition()  const { return m_cameraPosition; }
    VECTOR GetLookPosition()    const { return m_lookPosition; }
    VECTOR GetCenterPosition()  const { return m_centerPosition; }
    VECTOR GetCameraDirection() const { return m_cameraDirection; }

private:
    void ChangeLookObject(std::shared_ptr<GameObject>& newLookObject);
    void CenterPosUpdate(std::shared_ptr<GameObject>& object);
    void RotateUpdate();
    void LookPosUpdate();

private:
    VECTOR m_cameraPosition;
    VECTOR m_lookPosition;
    VECTOR m_centerPosition;
    VECTOR m_cameraDirection;

    float m_cameraDegree;
    float m_cameraAndCenterDistance;

    static constexpr float kAddCenterPositionY = 14.0f;
    static constexpr float kLookScale = 40.0f;
};

