#!usr/bin/python
#coding:utf-8

import numpy as np
import matplotlib.pyplot as plt

def f(x,y):
    return (1-x/2+x**5+y**3)*np.exp(-x**2-y**2)

n=256
x=np.linspace(-3,3,n)
y=np.linspace(-3,3,n)

X,Y=np.meshgrid(x,y)

plt.contourf(X,Y,f(X,Y),18,alpha=0.75)#,cmap=plt.cm.hot)
C=plt.contour(X,Y,f(X,Y),18,colors='green',linewidth=0.1)
plt.clabel(C,incine=True,fontsize=9)

plt.xticks(())
plt.yticks(())
plt.show()

