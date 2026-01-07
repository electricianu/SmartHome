#include "DSL.h"

WhenBuilder::WhenBuilder(RuleEngine& engine, std::function<bool(const Event&)> cond)
    : _engine(engine), _cond(cond) {}

void WhenBuilder::Do(std::function<void()> action) {
    Rule r;
    r.condition = _cond;
    r.action = action;
    _engine.addRule(r);
}