#include <iostream>
#include <string>
#include <sstream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>    
#include <opencv2/opencv.hpp> 
#include <opencv2/aruco.hpp>
using namespace std;
using namespace cv;

uchar HNY_CV_002 = 0;

#define Image_Width   1280
#define Image_height  960


int main(int argc, const char** argv)

{
    //    cv::Mat distortion_matrixL=(cv::Mat_<double>(5,1)<<0.0128,-0.0343,0.0023,-0.0011,0);
    //    cv::Mat intrinsic_matrixL=(cv::Mat_<double>(3,3)<<921.6992,0,653.3826,
    //                       0,918.4418,364.1299,
    //                       0,0,1);
    //    cv::Mat distortion_matrixR=(cv::Mat_<double>(5,1)<<0.0135,-0.0339,0.0032,-0.0011,0);
    //    cv::Mat intrinsic_matrixR=(cv::Mat_<double>(3,3)<<920.5909,0,646.5033,
    //                       0,917.4791,370.2785,
    //                       0,0,1);
    VideoCapture cap,cap2;
    cap.open(0);
    cap2.open(4);

    cap.set(cv::CAP_PROP_FRAME_WIDTH,  Image_Width*2);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, Image_height);
    cap2.set(cv::CAP_PROP_FRAME_WIDTH,  Image_Width*2);
    cap2.set(cv::CAP_PROP_FRAME_HEIGHT, Image_height);

    if (!cap.isOpened())
        return -1;
    if (!cap2.isOpened())
        return -1;

    Mat frame,frame2,frame_L,frame_R;
    char file_name[100];
    uchar num = 1;
    int key = 0;
    int i=0;
    while (1)
    {

        key = waitKey(1);
        cap >> frame;
        cap2>>frame2;

        if (HNY_CV_002 == 0)
        {
            frame_L = frame(Rect(0, 0, Image_Width, Image_height));
            frame_R = frame2(Rect(Image_Width, 0, Image_Width, Image_height));
        }
        else
        {
            frame_L = frame(Rect(Image_Width, 0, Image_Width, Image_height));
            frame_R = frame2(Rect(0, 0, Image_Width, Image_height));
        }

        //for(;i<10;i++){
        //    sprintf(file_name, "/home/jqzlca/workspace/demo1/image//left/Left%u.jpg", num);
        //    imwrite(file_name, frame_L);
        //    sprintf(file_name, "/home/jqzlca/workspace/demo1/image/right/Right%u.jpg", num);
        //    imwrite(file_name, frame_R);
        //    num++;
        //}


        if (key == 's')    //s save
        {
            sprintf(file_name, "/home/jqzlca/workspace/demo1/image//left/Left%02d.jpg", num);
            imwrite(file_name, frame_L);
            sprintf(file_name, "/home/jqzlca/workspace/demo1/image/right/Right%02d.jpg", num);
            imwrite(file_name, frame_R);
            num++;
            key = 0;
        }
        if(key=='q')// q quit
            break;

        //        cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_5X5_250);
        //        std::vector<std::vector<cv::Point2f>> markCorners;
        //        std::vector<int> markIds;
        //        cv::aruco::detectMarkers(frame_L, dictionary, markCorners, markIds);
        //        std::vector<cv::Vec3d> rvecs,tvecs;
        //        if(markIds.size()>0){
        //            cv::aruco::drawDetectedMarkers(frame_L,markCorners,markIds);
        //            cv::aruco::estimatePoseSingleMarkers(markCorners,0.029,intrinsic_matrixL,distortion_matrixL,rvecs,tvecs);
        //            for(unsigned int i=0;i<markIds.size();i++){
        //                cv::aruco::drawAxis(frame_L,intrinsic_matrixL,distortion_matrixL,rvecs[i],tvecs[i],0.1);

        //            }
        //        }
        cv::Mat resizeL,resizeR;
        cv::resize(frame_L,resizeL,Size(0,0),0.5,0.5);
        cv::resize(frame_R,resizeR,Size(0,0),0.5,0.5);
        namedWindow("Video_L", 1);


        imshow("Video_L", resizeL);
        namedWindow("Video_R", 1);
        imshow("Video_R", resizeR);
    }
    cap.release();
    return 0;
}
