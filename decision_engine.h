#ifndef DECISION_ENGINE_H
#define DECISION_ENGINE_H

#include <string>

class DecisionEngine {
public:
    // Takes the current emotion and returns a matching study suggestion
    std::string getSuggestion(const std::string& emotion);
};

#endif
