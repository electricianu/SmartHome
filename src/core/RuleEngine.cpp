#include "RuleEngine.h"

RuleEngine::RuleEngine(EventBus& bus)
    : _bus(bus) {}

void RuleEngine::addRule(const Rule& rule) {
    _rules.push_back(rule);
}

void RuleEngine::process(const Event& e) {
    for (auto &r : _rules) {
        if (r.condition && r.condition(e)) {
            if (r.action) {
                r.action();
            }
        }
    }
}

void RuleEngine::evaluate() {
    // aici poți adăuga reguli bazate pe timp / stare internă
}