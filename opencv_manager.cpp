#include "opencv_manager.h"
#include <omp.h>

openCV_manager::openCV_manager(String image_path) {
    std::cout<<"Constructor de openCV_manager"<<std::endl;
    harcascade_file_path = "/Users/felipearredondo/dev/uni/parcial-2/data/haarcascades/haarcascade_frontalface_default.xml";
    if (!face_cascade.load(harcascade_file_path)) {
        std::cout << "Error al cargar el archivo de cascada" << std::endl;
    }
    if (face_cascade.empty()) {
        std::cout << "Error al cargar el archivo de cascada" << std::endl;
    }
    image = imread(image_path);
}

openCV_manager::~openCV_manager() {}

String openCV_manager::get_harcascade_file_path() {
    return harcascade_file_path;
}

std::vector<Rect> openCV_manager::get_faces() {
    return faces;
}

void openCV_manager::convert_gray_image() {
    cvtColor(image, gray_image, COLOR_BGR2GRAY);
}

void openCV_manager::detect_faces() {
    face_cascade.detectMultiScale(gray_image, faces, 1.1, 3, 0, Size(30, 30));
}

void openCV_manager::show_image() {
    imwrite("detected_faces.jpg", image);
}

void openCV_manager::saveFaces(const Mat& image, const std::vector<Rect>& faces) {
    #pragma omp parallel for
    for (int i = 0; i < faces.size(); ++i) {
        Mat faceROI = image(faces[i]);
        String filename = "face_" + std::to_string(i) + ".jpg";
        imwrite(filename, faceROI);
    }
}