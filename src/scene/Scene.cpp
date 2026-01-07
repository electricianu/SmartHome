#include "Scene.h"

Scene::Scene() {}

Scene::Scene(const String& n, std::function<void()> a)
    : name(n), action(a) {}

SceneManager::SceneManager(EventBus& bus)
    : _bus(bus) {}

void SceneManager::addScene(const Scene& s) {
    _scenes.push_back(s);
}

void SceneManager::load(const String& name) {
    for (auto &s : _scenes) {
        if (s.name == name) {
            Event e;
            e.type = "scene.loaded";
            e.source = name;
            e.value = 0;
            _bus.emit(e);

            if (s.action) s.action();
            return;
        }
    }
}