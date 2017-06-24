#!usr/bin/python
#coding:utf-8

import numpy as np
import matplotlib.pyplot as plt

x=np.linspace(-2,3,100)
y1=x**2
y2=3*x+1

plt.figure()
# plt.plot(x,y1,label='up')
# plt.plot(x,y2,color='red',linewidth=1.0,linestyle='--',label='down')
# plt.legend(loc='upper_right')
plt.xlim((-2,2))
plt.ylim((-2,3))
plt.xlabel('X')
plt.ylabel('Y')

new_ticks=np.linspace(-1,2,5)
plt.xticks(new_ticks)
plt.yticks([-2,-1.8,-1,1.22,3],['really bad','bad','normal','good','really good'])

ax=plt.gca()
ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')
ax.xaxis.set_ticks_position('bottom')
ax.yaxis.set_ticks_position('left')
ax.spines['bottom'].set_position(('data',0))
ax.spines['left'].set_position(('data',0))

# l1,=plt.plot(x,y1,label='up')
l2,=plt.plot(x,y2,color='red',linewidth=1.0,linestyle='-',label='down')
# plt.legend(handles=[l1,l2,],loc='upper_right',labels=['Wow','Oh'])

#plt.scatter(x,y2)

x0=0.5
y0=3*x0+1
plt.scatter(x0,y0,s=50,color='b')
plt.plot([x0,x0],[y0,0],'k--',lw=2)

#method 1
plt.annotate(r'$3x+1=%s$'%y0,xy=(x0,y0),xycoords='data',xytext=(+30,-30),textcoords='offset points',fontsize=16,arrowprops=dict(arrowstyle='->',connectionstyle='arc3,rad=.2'))
#method 2
plt.text(-1.85,1,r'$This\ is\ the\ some\ text\ \mu\ \sigma_i\ \alpha_t$',fontdict={'size':16,'color':'green'})

for label in ax.get_xticklabels()+ax.get_yticklabels():
    label.set_fontsize(9)
    label.set_bbox(dict(facecolor='red',edgecolor='None',alpha=0.3))

plt.show()




