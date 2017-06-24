#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
int main() {
	VideoCapture capture(0);
	if (!capture.isOpened())
		return -1;
	Mat frame;
	Mat edges;
	while (1) {
		capture >> frame;
		cvtColor(frame, edges, CV_BGR2GRAY);
		blur(edges,edges,Size(7,7));
		Canny(edges, edges, 0, 30, 3);
		imshow("读取视频", edges);
		waitKey(30);//给图像绘制留点时间
	}
	return 0;
}