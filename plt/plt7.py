#!usr/bin/python
#coding:utf-8

import numpy as np
import matplotlib.pyplot as plt
from matplotlib import animation

fig,ax=plt.subplots()

x=np.arange(0,2*np.pi,0.01)
line,=ax.plot(x,np.sin(x))

def animate(i):
    line.set_ydata(np.sin(x+i/6))
    return line,

def init():
    line.set_ydata(np.sin(x))
    return line,

ani=animation.FuncAnimation(fig=fig,func=animate,frames=100,init_func=init,interval=10,blit=True)

plt.show()





