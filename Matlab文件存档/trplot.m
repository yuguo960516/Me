 figure(1); 
 subplot(221);
 T1=se2(1,2,pi/6);
 trplot2(T1,'frame','1','color','b');
 axis([0 5 0 5]);
 hold on;
 T2=se2(2,1,0);
 trplot2(T2,'frame','2','color','b');
 axis([0 5 0 5]);
 hold on;
 T3=T1*T2;
 trplot2(T3,'frame','3','color','b');
 axis([0 5 0 5]);
 hold on;
 T4=T2*T1;
 trplot2(T4,'frame','4','color','b');
 axis([0 5 0 5]);
 hold on;
 P=[3;2];
 plot_point(P,'*');
 P1=T1\[P;1];
 P2=homtrans(inv(T2),P);
 subplot(222);
 R=rotx(pi/2)*roty(pi/2);
 trplot(R);
 hold on;
 subplot(223);
 W=rpy2tr(pi/6,pi/4,pi/3);
 tr2rpy(W);
 q=Quaternion(rpy2tr(pi/6,pi/4,pi/3));
 q.R;
 q.plot();
 hold on;
 subplot(224);
 Y=transl(1,2,3)*trotx(pi/2);
 trplot(Y);



 
 
 
 
 
 
 
 
 
 
 
 