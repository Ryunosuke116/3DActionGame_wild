#pragma once
#include "Dxlib.h"

class RigidbodyComponent :
    public BaseComponent
{
public:
    RigidbodyComponent();
    ~RigidbodyComponent();

    VECTOR GetTopCapsulePosition()      const { return m_topCapsulePosition; }
    VECTOR GetBottomCapsulePosition()   const { return m_topCapsulePosition; }
    VECTOR GetCenterPosition()          const { return m_topCapsulePosition; }

    void SetTopCapsulePosition(const VECTOR& setPos)    { m_topCapsulePosition = setPos; }
    void SetBottomCapulePosition(const VECTOR& setPos)  { m_bottomCapulePosition= setPos; }
    void SetCenterPosition(const VECTOR& setPos)        { m_centerPosition = setPos; }

private:
    VECTOR m_topCapsulePosition;
    VECTOR m_bottomCapulePosition;
    VECTOR m_centerPosition;
};

