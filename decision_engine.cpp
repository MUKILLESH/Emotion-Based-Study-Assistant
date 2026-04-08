#include "decision_engine.h"

// Map the generated emotion to actionable study suggestions
std::string DecisionEngine::getSuggestion(const std::string& emotion) {
    if (emotion == "Happy") {
        return "Continue studying";
    } else if (emotion == "Sad") {
        return "Take a short break";
    } else if (emotion == "Angry") {
        return "Relax and calm down";
    } else if (emotion == "Sleepy") {
        return "Take rest";
    } else if (emotion == "Neutral") {
        return "Keep going";
    } else {
        return "Unknown state";
    }
}
