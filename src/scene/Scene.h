#ifndef SCENE_H
#define SCENE_H

#include <Arduino.h>
#include <functional>
#include <vector>
#include "core/EventBus.h"

class Scene {
public:
    String name;
    std::function<void()> action;

    Scene();
    Scene(const String& name, std::function<void()> action);
};

class SceneManager {
public:
    SceneManager(EventBus& bus);

    void addScene(const Scene& s);
    void load(const String& name);

private:
    EventBus& _bus;
    std::vector<Scene> _scenes;
};

#endif