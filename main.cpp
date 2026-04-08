#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>
#include "face_detection.h"
#include "emotion_simulator.h"
#include "decision_engine.h"
#include "productivity_tracker.h"

int main() {
    // 1. Initialize all our modules classes
    FaceDetector faceDetector;
    EmotionSimulator emotionSimulator;
    DecisionEngine decisionEngine;
    ProductivityTracker productivityTracker;

    // 2. Open the default webcam (ID 0)
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Error: Cannot open the webcam!" << std::endl;
        return -1;
    }

    cv::Mat frame;
    std::cout << "Starting Emotion-Based Study Assistant..." << std::endl;
    std::cout << "Make sure your face is visible." << std::endl;
    std::cout << "Press 'q' in the video window to quit." << std::endl;

    // Record the session start time
    auto sessionStartTime = std::chrono::steady_clock::now();

    // Main running loop
    while (true) {
        // Capture frame-by-frame from webcam
        cap >> frame;
        if (frame.empty()) {
            std::cerr << "Error: Blank frame grabbed" << std::endl;
            break;
        }

        // 3. Detect Face and draw a rectangle on the frame
        faceDetector.detectAndDraw(frame);

        // 4. Simulate a new emotion
        std::string currentEmotion = emotionSimulator.getRandomEmotion();

        // 5. Get a suggestion based on the simulated emotion
        std::string suggestion = decisionEngine.getSuggestion(currentEmotion);

        // 6. Update Productivity Score
        productivityTracker.updateState(currentEmotion);
        double score = productivityTracker.getProductivityScore();

        // Calculate session elapsed time
        auto currentSessionTime = std::chrono::steady_clock::now();
        int elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(currentSessionTime - sessionStartTime).count();
        int mins = elapsedSeconds / 60;
        int secs = elapsedSeconds % 60;

        // 7. Setup the text to display on screen
        std::string emotionText = "Emotion: " + currentEmotion;
        std::string suggestionText = "Suggestion: " + suggestion;
        std::string scoreText = std::to_string((int)score) + "%";
        std::string timeText = "Session Time: " + std::to_string(mins) + "m " + std::to_string(secs) + "s";

        // 8. Draw text on the frame (Image, Text, Position, Font, Scale, Color, Thickness)
        cv::putText(frame, emotionText, cv::Point(10, 30), cv::FONT_HERSHEY_SIMPLEX, 0.8, cv::Scalar(255, 255, 255), 2);
        cv::putText(frame, suggestionText, cv::Point(10, 60), cv::FONT_HERSHEY_SIMPLEX, 0.8, cv::Scalar(0, 255, 255), 2);
        cv::putText(frame, timeText, cv::Point(10, 90), cv::FONT_HERSHEY_SIMPLEX, 0.8, cv::Scalar(255, 165, 0), 2);

        // --- GRAPHICAL PRODUCTIVITY BAR ---
        int barMaxWidth = 300;
        int barHeight = 25;
        cv::Point barTopLeft(10, 110);
        cv::Point barBottomRight(10 + barMaxWidth, 110 + barHeight);
        
        // Determine color based on score
        cv::Scalar barColor;
        if (score >= 75) {
            barColor = cv::Scalar(0, 255, 0); // Green (BGR format)
        } else if (score >= 50) {
            barColor = cv::Scalar(0, 255, 255); // Yellow
        } else {
            barColor = cv::Scalar(0, 0, 255); // Red
        }
        
        // Draw the background outline (White)
        cv::rectangle(frame, barTopLeft, barBottomRight, cv::Scalar(255, 255, 255), 2);
        
        // Draw the filled portion
        int currentBarWidth = (int)((score / 100.0) * barMaxWidth);
        cv::Point filledBottomRight(10 + currentBarWidth, 110 + barHeight);
        
        // -1 thickness fills the rectangle
        if (currentBarWidth > 0) {
            cv::rectangle(frame, barTopLeft, filledBottomRight, barColor, -1);
        }
        
        // Draw the score text inside or next to the bar
        cv::putText(frame, scoreText, cv::Point(12 + barMaxWidth, 130), cv::FONT_HERSHEY_SIMPLEX, 0.6, cv::Scalar(255, 255, 255), 2);

        // 9. Show the final output window
        cv::imshow("Emotion-Based Study Assistant", frame);

        // We use waitKey(1000) so the loop processes 1 frame per second.
        // This is done to give users enough time to read the randomly generated string.
        // Otherwise, it flickers by in milliseconds. 'q' will break the loop. 
        if (cv::waitKey(1000) == 'q') {
            break;
        }
    }

    // Clean up
    cap.release();
    cv::destroyAllWindows();
    return 0;
}
