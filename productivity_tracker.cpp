#include "productivity_tracker.h"

// Constructor starts counts at 0
ProductivityTracker::ProductivityTracker() {
    focusedCount = 0;
    totalCount = 0;
}

// Update the score based on whether the emotion is a focused state or not
void ProductivityTracker::updateState(const std::string& emotion) {
    totalCount++;
    // Happy and Neutral are counted as "focused"
    if (emotion == "Happy" || emotion == "Neutral") {
        focusedCount++;
    }
    // Anything else (Sad, Angry, Sleepy) is implicitly "distracted" by not adding to focusedCount
}

// Computes the productivity percentage
double ProductivityTracker::getProductivityScore() {
    // Avoid dividing by zero at the start
    if (totalCount == 0) return 0.0;
    
    // Convert to double to get decimal precision before multiplying by 100
    return ((double)focusedCount / totalCount) * 100.0;
}
