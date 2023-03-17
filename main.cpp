#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {

    VideoCapture cap(0);

    if (cap.isOpened() == false) {
        cout << "Can't open camera\n";
        cin.get();
        return -1; 
    }

    double dWidth = cap.get(CAP_PROP_FRAME_WIDTH);
    double dHeight = cap.get(CAP_PROP_FRAME_HEIGHT);

    namedWindow("Camera Feed");

    while (true) {
        Mat frame;

        bool bSuccess = cap.read(frame);

        if (bSuccess = false) {
            cout << "Camera Disconnected\n";
            cin.get();
            break;
        }

        imshow("Camera Feed", frame);

        if (waitKey(10) == 27) {
            cout << "Esc pressed\n";
            break;
        } 

    }

    return 0;
}
