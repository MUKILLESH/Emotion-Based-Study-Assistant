#ifndef EMOTION_SIMULATOR_H
#define EMOTION_SIMULATOR_H

#include <string>

class EmotionSimulator {
private:
    std::string emotions[5]; // Array to hold 5 emotions

public:
    // Constructor
    EmotionSimulator();

    // Returns a randomly generated emotion string
    std::string getRandomEmotion();
};

#endif
