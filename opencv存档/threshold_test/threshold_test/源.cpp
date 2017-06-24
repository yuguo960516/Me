#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

#define win_name "程序窗口"

int threshold_value = 100;
int threshold_type = 3;
Mat src, gray, dst;

void on_threshold(int,void*);

int main()
{
	src = imread("G://My picture//323781-106.jpg");
	cvtColor(src,gray,COLOR_BGR2GRAY);
	namedWindow(win_name,WINDOW_NORMAL);
	cvCreateTrackbar2("阀值",win_name,&threshold_value,255,on_threshold);
	cvCreateTrackbar2("模式", win_name, &threshold_type,4,on_threshold);
	on_threshold(0, 0);

	while (1)
	{
		int key;
		key = waitKey(10);
		if ((char)key == 27)break;

	}
}

void on_threshold(int, void*)
{
	threshold(gray,dst,threshold_value,255,threshold_type);
	imshow(win_name,dst);
}
