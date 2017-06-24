#include<opencv2\opencv.hpp>    
using namespace cv;
int main(int argc, char** argv)
{
	// read image  
	Mat picture = imread("G://My picture//301158-106.jpg");
	// create window  
	namedWindow("My Test", CV_WINDOW_NORMAL);
	// display  
	imshow("My Test", picture);

	// ¹Ø±Õ  
	waitKey(0);
	destroyWindow("My Test");
	return 0;
}