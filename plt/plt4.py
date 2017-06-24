#!usr/bin/python
#coding:utf-8

import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

fig=plt.figure()
ax=Axes3D(fig)

X=np.arange(-5,5,0.2)
Y=np.arange(-5,5,0.2)
X,Y=np.meshgrid(X,Y)
Z=(X**2+Y**2)**0.25*(np.sin(50*((X**2+Y**2)**0.1))**2+1)

ax.plot_surface(X,Y,Z,rstride=1,cstride=1,cmap=plt.get_cmap('rainbow'))
ax.contourf(X,Y,Z,zdir='z',offset=0,cmap='rainbow')

plt.show()