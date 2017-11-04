#include <opencv2/core/core.hpp>  
#include<opencv2/highgui/highgui.hpp>  
#include"opencv2/imgproc/imgproc.hpp"  
#include <iostream>  
using namespace std;
using namespace cv;

Mat g_pSrcImage, g_pCannyImg;
const char *pstrWindowsCannyTitle = "candy边缘检测";
//cvCreateTrackbar的回调函数  
void on_trackbar(int threshold,void*)
{
	//canny边缘检测  
	Canny(g_pSrcImage, g_pCannyImg, threshold, threshold * 3);
	imshow(pstrWindowsCannyTitle, g_pCannyImg);
}
int main()
{
	const char *pstrImageName = "picture.jpg";
	const char *pstrWindowsToolBar = "阈值";

	//从文件中载入图像的灰度图
	g_pSrcImage = imread(pstrImageName, IMREAD_GRAYSCALE);
	g_pCannyImg.create(g_pSrcImage.size(), IPL_DEPTH_8U);

	//创建窗口  
	namedWindow("Image");
	namedWindow(pstrWindowsCannyTitle);

	//创建滑动条  
	int nThresholdEdge = 1;
	createTrackbar(pstrWindowsToolBar, pstrWindowsCannyTitle, &nThresholdEdge, 100, on_trackbar);

	//在指定窗口中显示图像  
	imshow("Image", g_pSrcImage);
	on_trackbar(1,0);

	//等待按键事件  
	waitKey();

	return 0;
}
