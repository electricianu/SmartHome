#ifndef RULEENGINE_H
#define RULEENGINE_H

#include <Arduino.h>
#include <functional>
#include <vector>
#include "EventBus.h"

// O regulă simplă: condiție(event) + acțiune()
struct Rule {
    std::function<bool(const Event&)> condition;
    std::function<void()> action;
};

class RuleEngine {
public:
    RuleEngine(EventBus& bus);

    void addRule(const Rule& rule);
    void process(const Event& e);
    void evaluate(); // pentru reguli fără eveniment (ex: bazate pe timp)

private:
    EventBus& _bus;
    std::vector<Rule> _rules;
};

#endif