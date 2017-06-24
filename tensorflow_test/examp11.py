#!usr/bin/python
#coding:utf-8

import tensorflow as tf

W=tf.Variable([[1,2,3],[3,5,6]],dtype=tf.float32,name='weights')
b=tf.Variable([[1,2,3]],dtype=tf.float32,name='bias')

init=tf.initialize_all_variables()

saver=tf.train.Saver()

with tf.Session() as sess:
    sess.run(init)
    save_path=saver.save(sess,'save/save_net.ckpt')
    print 'Save to path:',save_path 

