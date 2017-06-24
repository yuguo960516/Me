#!usr/bin/python
#coding:utf-8

import tensorflow as tf
import numpy as np

W=tf.Variable(np.arange(6).reshape((2,3)),dtype=tf.float32,name='weights')
b=tf.Variable(np.arange(3).reshape((1,3)),dtype=tf.float32,name='bias')

saver=tf.train.Saver()
with tf.Session() as sess:
    saver.restore(sess,'save/save_net.ckpt')
    print 'weights',sess.run(W)
    print 'bias',sess.run(b)


