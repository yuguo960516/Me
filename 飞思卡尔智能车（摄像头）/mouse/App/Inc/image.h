#ifndef __IMAGE_H__
#define __IMAGE_H__



extern   int8 medium_line[CAMERA_H];
extern   int8 left_line[CAMERA_H];
extern   int8 right_line[CAMERA_H];

//struct


void scan_line();   
uint8 check_medium(uint8 flag,uint8 h1,uint8 h2);
float slope(uint8 flag,uint8 h1,uint8 h2);
//void check_left(void);
//void check_right(void);
uint8 check_road_flag();
//void check_lim();




#endif