#ifndef OPENCV_MANAGER_H
#define OPENCV_MANAGER_H

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

class openCV_manager {
    
    private:

        CascadeClassifier face_cascade;
        String harcascade_file_path;
        Mat gray_image;
        std::vector<Rect> faces;

    public:
        openCV_manager(String image_path);
        ~openCV_manager();
        Mat image;

        String get_harcascade_file_path();
        std::vector<Rect> get_faces();
        void convert_gray_image();
        void detect_faces();
        void show_image();

};
#endif // OPENCV_MANAGER_H