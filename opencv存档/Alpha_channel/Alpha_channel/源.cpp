#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
using namespace cv;

#define win_name  "[混合实例]"

const int max_alpha_value = 100;
double alpha_value;
double bate_value;

Mat src_image1;
Mat src_image2;
Mat dst_mage;

void track_bar(int pos)
{
	alpha_value = (double)pos / max_alpha_value;
	bate_value = (1.0 - alpha_value);

	addWeighted(src_image1, alpha_value, src_image2, bate_value, 0.0, dst_mage);
	imshow(win_name, dst_mage);
	imwrite("G://My picture//memery2.jpg",dst_mage);

}

int main()
{
	int alpha_value_slider;
	src_image1 = imread("G://My picture//7511-106.jpg");
	src_image2 = imread("G://My picture//191099-106.jpg");
	alpha_value_slider = 50;
	namedWindow(win_name, WINDOW_NORMAL);
	char trackbar_name[50];
	sprintf(trackbar_name, "透明值 %d", max_alpha_value);
	cvCreateTrackbar(trackbar_name, win_name, &alpha_value_slider, max_alpha_value, track_bar);
	track_bar(alpha_value_slider);
	waitKey(0);
	return 0;

}