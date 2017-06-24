#!usr/bin/python
#coding:utf-8

import numpy as np
from sklearn import svm
from sklearn import datasets

# clf=svm.SVC()
iris=datasets.load_iris()
X,y=iris.data,iris.target
# clf.fit(X,y)
#
# #method 1:pckle
#Save
# import pickle
# with open('save/clf.pickle','wb') as f:
#     pickle.dump(clf,f)

#Restore
# import pickle
# with open('save/clf.pickle','rb') as f:
#     clf2=pickle.load(f)
#     print clf2.predict(X[0:60])



#method 2:joblib
#Save
# from sklearn.externals import joblib
# joblib.dump(clf,'save/clf.pkl')

#Restore
from sklearn.externals import joblib
clf3=joblib.load('save/clf.pkl')
print clf3.predict(X[0:60])


