#!usr/bin/python
#!coding:utf-8

import tensorflow as tf
from tensorflow.examples.tutorials.mnist import input_data

mnist=input_data.read_data_sets('MNIST_data',one_hot=True)

lr=0.001
train_iters=100000
batch_size=128

n_inputs=28
n_steps=28
n_hidden_units=128
n_classes=10

x=tf.placeholder(tf.float32,[None,n_steps,n_inputs])
y=tf.placeholder(tf.float32,[None,n_classes])

weights={
'in':tf.Variable(tf.random_normal([n_inputs,n_hidden_units])),
'out':tf.Variable(tf.random_normal([n_hidden_units,n_classes]))
}

biases={
'in':tf.Variable(tf.constant(0.1,shape=[n_hidden_units])),
'out':tf.Variable(tf.constant(0.1,shape=[n_classes]))
}

def RNN(X,weights,biases):
    X=tf.reshape(X,[-1,n_inputs])    #!!!!!!!X(128 n_batches,28 n_steps,28 n_inputs)--->X(128 n_batches*28 n_steps,28 n_inputs)
    X_in=tf.matmul(X,weights['in'])+biases['in']    #(128 n_batches*28 n_steps,128 n_hiddens)
    X_in=tf.reshape(X_in,[-1,n_steps,n_hidden_units])     #(128 n_batches,28 n_steps,128 n_hiddens)
    
    lstm_cell=tf.nn.rnn_cell.BasicLSTMCell(n_hidden_units,forget_bias=1.0,state_is_tuple=True)    #lstm_cell is divided into two parts(c_state主要,m_state次要)
    _init_state=lstm_cell.zero_state(batch_size,dtype=tf.float32)
    
    outputs,states=tf.nn.dynamic_rnn(lstm_cell,X_in,initial_state=_init_state,time_major=False)
    
    #result=tf.matmul([states[1],weights['out']])+biases['out']    #states[1]=outputs[-1]
    #or
    outputs=tf.unpack(tf.transpose(outputs,[1,0,2]))
    result=tf.matmul(outputs[-1],weights['out'])
    
    return result

pred=RNN(x,weights,biases)
cost=tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(pred,y))
train_op=tf.train.AdamOptimizer(lr).minimize(cost)

correct_pred=tf.equal(tf.argmax(pred,1),tf.argmax(y,1))
accuracy=tf.reduce_mean(tf.cast(correct_pred,tf.float32))

init=tf.initialize_all_variables()

with tf.Session() as sess:
    sess.run(init)
    step=0
    while step*batch_size<train_iters:
        batch_xs,batch_ys=mnist.train.next_batch(batch_size)
        batch_xs=batch_xs.reshape([batch_size,n_steps,n_inputs])
        sess.run(train_op,feed_dict={x:batch_xs,y:batch_ys})
        if step%20==0:
            print sess.run(accuracy,feed_dict={x:batch_xs,y:batch_ys})






























