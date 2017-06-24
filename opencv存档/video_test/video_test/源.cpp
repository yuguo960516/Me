#include<opencv2\opencv.hpp>   
#include <opencv\highgui.h>
using namespace cv;

//int g_slide_position = 0;
CvCapture* g_capture = NULL;

//void onTrackbarSlide(int pos)
//{
//	cvSetCaptureProperty(
//		g_capture,
//		CV_CAP_PROP_POS_FRAMES,
//		pos
//		);
//}
int main()
{
	cvNamedWindow("Example3", CV_WINDOW_AUTOSIZE);
	g_capture = cvCreateFileCapture("E:\\ÊÓÆµÔÓÀý\\ÌùÆ¬Æ÷¼þº¸½ÓÁ·Ï°½Ì³Ì.flv");
	//g_capture = cvCreateCameraCapture(1);
	//	int frame = cvGetCaptureProperty(
	//		g_capture,
	//		CV_CAP_PROP_FRAME_COUNT
	//		);
	//	if (frame != 0)
	//	{
	//		cvCreateTrackbar(
	//			"Position",
	//			"Example3",
	//			&g_slide_position,
	//			frame,
	//			onTrackbarSlide
	//			);
	//	}

	IplImage* frames;
	//	int NewPos = g_slide_position;
	while (1)
	{
		frames = cvQueryFrame(g_capture);
		if (!frames)
			break;
		cvShowImage("Example3", frames);
		//	cvCreateTrackbar("position", "Example3", &NewPos, frame, onTrackbarSlide);

		/*cvSetTrackbarPos(
		"Position",
		"Example3",
		g_slide_position++
		);*/
		char c = cvWaitKey(33);
		if (c == 27)
			break;
		//NewPos++;

	}

	cvReleaseCapture(&g_capture);
	cvDestroyWindow("Example3");

	return 0;
}

