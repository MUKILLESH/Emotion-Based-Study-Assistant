#include "emotion_simulator.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

// Constructor
EmotionSimulator::EmotionSimulator() {
    // Seed the random number generator using current time
    srand(time(0));
    
    // Store possible emotions
    emotions[0] = "Happy";
    emotions[1] = "Sad";
    emotions[2] = "Angry";
    emotions[3] = "Neutral";
    emotions[4] = "Sleepy";
}

// Randomly select an emotion from the array
std::string EmotionSimulator::getRandomEmotion() {
    int randomIndex = rand() % 5;
    return emotions[randomIndex];
}
