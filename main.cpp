#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {

    VideoCapture cap(0);

    
    CascadeClassifier faceCascade;
    faceCascade.load("C:\\Users\\sasan\\OneDrive\\Desktop\\Learning\\Open CV\\pose_estimation\\haarcascade_frontalface_default.xml");

    while (true) {
        Mat frame;

        cap.read(frame);

        vector<Rect> faces;

        faceCascade.detectMultiScale(frame, faces, 1.1, 10);
        
        if (faces.size() > 0) {
            for (int i = 0; i < faces.size(); i++) {
                rectangle(frame, faces[i].tl(), faces[i].br(), Scalar(0, 255, 0), 3);
                cout << faces[i].area() << ", ";

            }
        }

        cout << "\n";

        imshow("Camera Feed", frame);

        if (waitKey(10) == 'q') {
            cout << "Esc pressed\n";
            break;
        } 

    }

    return 0;
}
