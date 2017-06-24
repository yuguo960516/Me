#!usr/bin/python
#coding:utf-8

import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt

def add_layer(inputs,in_size,out_size,n_layer,activation_function=None):
    layer_name='layer%s'%n_layer
    with tf.name_scope(layer_name):
        with tf.name_scope('Weights'):
            Weights=tf.Variable(tf.random_normal([in_size,out_size]),name='W')
            tf.histogram_summary(layer_name+'/weights',Weights)
        with tf.name_scope('baises'):
            baises=tf.Variable(tf.zeros([1,out_size])+0.1,name='b')
            tf.histogram_summary(layer_name+'/baises',baises)
        with tf.name_scope('Wx_plus_b'):
            Wx_plus_b=tf.add(tf.matmul(inputs,Weights),baises)
        if activation_function is None:
            outputs=Wx_plus_b
        else:
            outputs=activation_function(Wx_plus_b)
            tf.histogram_summary(layer_name+'/outputs',outputs)
        return outputs

x_date=np.linspace(-1,1,300)[:,np.newaxis]
nosie=np.random.normal(0,0.05,x_date.shape)
y_date=x_date**2-0.5+nosie

with tf.name_scope('inputs'):
    xs=tf.placeholder(tf.float32,[None,1],name='x_input')
    ys=tf.placeholder(tf.float32,[None,1],name='y_input')

l1=add_layer(xs,1,10,n_layer=1,activation_function=tf.nn.relu)
prediction=add_layer(l1,10,1,n_layer=2,activation_function=None)

with tf.name_scope('loss'):
    loss=tf.reduce_mean(tf.reduce_sum(tf.square(ys-prediction),reduction_indices=[1]))
    tf.scalar_summary('loss',loss)
with tf.name_scope('train'):
    train_step=tf.train.GradientDescentOptimizer(0.1).minimize(loss)

sess=tf.Session()
merged=tf.merge_all_summaries()
writer=tf.train.SummaryWriter('/home/yuguo/tensorflow_test',sess.graph)

init=tf.initialize_all_variables()
sess.run(init)

for i in range(1000):
    sess.run(train_step,feed_dict={xs:x_date,ys:y_date})
    if i%50==0:
        result=sess.run(merged,feed_dict={xs:x_date,ys:y_date})
    writer.add_summary(result,i)    




