#ifndef DSL_H
#define DSL_H

#include <functional>
#include "core/RuleEngine.h"

// DSL simplu: when(cond) -> do(act)
class WhenBuilder {
public:
    WhenBuilder(RuleEngine& engine, std::function<bool(const Event&)> cond);

    void Do(std::function<void()> action);

private:
    RuleEngine& _engine;
    std::function<bool(const Event&)> _cond;
};

inline WhenBuilder when(RuleEngine& engine, std::function<bool(const Event&)> cond) {
    return WhenBuilder(engine, cond);
}

#endif