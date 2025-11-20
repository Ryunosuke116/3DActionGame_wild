#pragma once


class SceneManager;
class ObjectManager;

class BaseScene
{
public:

    BaseScene(SceneManager& manager);
    ~BaseScene();

    virtual void ReleaseResource();
    virtual void Create();
    virtual void Initialize();
    virtual void Update();
    virtual void Draw();

protected:
    void ChangeScene(std::string_view);

protected:
    std::shared_ptr<ObjectManager> objectManager = NULL;

private:
    SceneManager& manager;
};

