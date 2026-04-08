#include "face_detection.h"
#include <iostream>

// Constructor to load the Haar Cascade model
FaceDetector::FaceDetector() {
    // We try to load the default face detection model. 
    // IMPORTANT: Make sure the file 'haarcascade_frontalface_default.xml' is in your project folder!
    if (!faceCascade.load("haarcascade_frontalface_default.xml")) {
        std::cerr << "Warning: Could not load haarcascade_frontalface_default.xml!" << std::endl;
        std::cerr << "Face detection lines will not be drawn. Please download it from OpenCV." << std::endl;
    }
}

// Function to detect faces and draw a rectangle around them
void FaceDetector::detectAndDraw(cv::Mat& frame) {
    if (frame.empty() || faceCascade.empty()) return;

    std::vector<cv::Rect> faces;
    cv::Mat grayFrame;

    // Convert frame to grayscale for faster processing
    cv::cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY);
    cv::equalizeHist(grayFrame, grayFrame);

    // Detect faces in the image
    faceCascade.detectMultiScale(grayFrame, faces, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));

    // Draw a green rectangle around each detected face
    for (size_t i = 0; i < faces.size(); i++) {
        cv::rectangle(frame, faces[i], cv::Scalar(0, 255, 0), 2);
    }
}
