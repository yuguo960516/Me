#!usr/bin/python
#coding:utf-8

import numpy as np
from sklearn.svm import SVC
import matplotlib.pyplot as plt
from sklearn.learning_curve import learning_curve
from sklearn.datasets import load_digits

digits=load_digits()
X=digits.data
y=digits.target

#gama--->reduce overfiting
train_sizes,train_loss,test_loss=learning_curve(SVC(gamma=0.0000001),X,y,cv=10,scoring='mean_squared_error',train_sizes=[0.1,0.25,0.5,0.75,1])
train_loss_mean=-np.mean(train_loss,axis=1)
test_loss_mean=-np.mean(test_loss,axis=1)

plt.plot(train_sizes,train_loss_mean,'o-',color='r',label='Train_loss_mean')
plt.plot(train_sizes,test_loss_mean,'o-',color='g',label='Test_loss_mean')
plt.xlabel('Training_examples')
plt.ylabel('Mean_loss')
plt.legend(loc='best')
plt.show()







