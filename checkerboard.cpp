#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>

int main()
{
    //---生成标定图
    IplImage *img;
    int dx=80;//棋盘格大小，像素为单位
    int dy=5;//棋盘格数目
    img = cvCreateImage(cvSize(2*dx*dy, 2*dx*dy), IPL_DEPTH_8U, 1);
    cvZero(img);
    int flag=0;
    for(int i=0;i<2*dy;i++)
        for(int j=0;j<2*dy;j++)
        {
            flag = (i+j)%2;
            if (flag == 0)
            {
                for (int m=i*dx; m<(i+1)*dx; m++)
                    for(int n=j*dx; n<(j+1)*dx; n++)
                        ((uchar *)(img->imageData +  m * img->widthStep ))[n] = 255;
                //*(img->imageData+m*img->widthStep+n)=255;
            }

        }
    //---END生成标定图
    cvSaveImage("棋盘格标定图.bmp",img);
    cvNamedWindow("棋盘格", 1);
    cvShowImage("棋盘格",img);
    cvWaitKey(0);

    cvReleaseImage(&img);
    cvDestroyWindow("棋盘格");

    return 0;
}

