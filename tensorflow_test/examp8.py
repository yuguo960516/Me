#!usr/bin/python
#coding:utf-8

import cv2
import struct
import numpy as np

names='one'
fn="train-images.idx3-ubyte"

f=open(fn,'rb')
index=0
buf=f.read()

f.close()

magic,pictures,rows,columns=struct.unpack_from('>IIII',buf,index)
index+=struct.calcsize('>IIII')

for i in xrange(900):
    image=np.zeros((rows,columns,1), np.uint8)
    for y in xrange(rows):
        for x in xrange(columns):
            image[y,x]=int(struct.unpack_from('>B',buf,index)[0])
            index+=struct.calcsize('>B')
    cv2.imwrite('%s.jpg'%i,image)
#cv2.namedWindow(names)   
#cv2.imshow(names, image)   
#cv2.waitKey (0)  
#cv2.destroyaAllWindows()
