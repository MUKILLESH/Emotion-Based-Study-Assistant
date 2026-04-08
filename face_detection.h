#ifndef FACE_DETECTION_H
#define FACE_DETECTION_H

#include <opencv2/opencv.hpp>

class FaceDetector {
private:
    // OpenCV Haar Cascade classifier object for face detection
    cv::CascadeClassifier faceCascade;

public:
    // Constructor
    FaceDetector();

    // Detects faces and draws rectangles on the given video frame
    void detectAndDraw(cv::Mat& frame);
};

#endif
