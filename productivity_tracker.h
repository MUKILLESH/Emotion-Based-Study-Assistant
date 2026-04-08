#ifndef PRODUCTIVITY_TRACKER_H
#define PRODUCTIVITY_TRACKER_H

#include <string>

class ProductivityTracker {
private:
    int focusedCount;
    int totalCount;

public:
    // Constructor
    ProductivityTracker();

    // Check if the student is focused or distracted based on emotion
    void updateState(const std::string& emotion);

    // Calculate percentage score
    double getProductivityScore();
};

#endif
