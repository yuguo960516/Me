#!usr/bin/python
#coding:utf-8

import numpy as np
import matplotlib.pyplot as plt

# plt.figure(figsize=(8,4))
# x=np.random.random(100)
# y=np.random.random(100)
# plt.scatter(x,y,s=x*1000,c='y',marker=(5,1),alpha=0.5,lw=2,facecolors='9999ff')
# plt.xlim(0,1)
# plt.ylim(0,1)



theta=np.arange(0,2*np.pi,0.02)
plt.subplot(121,polar=True)
plt.plot(theta,2*np.ones_like(theta),'-',lw=2,c='r')
plt.plot(theta,theta/6,'--',lw=2,c='r')

plt.subplot(122,polar=True)
plt.plot(theta,np.cos(5*theta),'--',lw=2)
plt.plot(theta,2*np.cos(4*theta),lw=2)
plt.rgrids(np.arange(0.5,2,0.5),angle=45)
plt.thetagrids([0,45,90])

plt.show()