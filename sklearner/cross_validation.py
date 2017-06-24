#!usr/bin/python
#coding:utf-8

import numpy as np
from sklearn import datasets
from sklearn.cross_validation import train_test_split
from sklearn.neighbors import KNeighborsClassifier

iris=datasets.load_iris()
iris_X=iris.data
iris_y=iris.target

# X_train,X_test,y_train,y_test=train_test_split(iris_X,iris_y,random_state=4)
# knn=KNeighborsClassifier(n_neighbors=5)
# knn.fit(X_train,y_train)
# pred=knn.predict(X_test)
# print knn.score(X_test,y_test)



#from sklearn.cross_validation import cross_val_score
# knn=KNeighborsClassifier(n_neighbors=10)
# scores=cross_val_score(knn,iris_X,iris_y,cv=5,scoring='accuracy')
# print scores
# print scores.mean()



from sklearn.cross_validation import cross_val_score
import matplotlib.pyplot as plt
k_range=range(1,31)
k_scoers=[]
for i in k_range:
    knn=KNeighborsClassifier(n_neighbors=i)
    loss = -cross_val_score(knn, iris_X, iris_y, cv=10, scoring='mean_squared_error')    #usaully for regression
    k_scoers.append(loss.mean())
    #scores=cross_val_score(knn,iris_X,iris_y,cv=10,scoring='accuracy')    #for classification
    #k_scoers.append(scores.mean())
plt.plot(k_range,k_scoers)
plt.xlabel('K')
plt.ylabel('loss')
#plt.ylabel('accuracy')
plt.show()





