G0=tf(1,[1,3,3,1]);
Kp=1;
Ti=1;
Td=1;
t=0:0.1:50;
Gc=tf(Kp*[Ti*Td,Ti,1],[Ti,0])
G=feedback(G0*Gc,1);
y=step(G,t);
figure(1);
plot(t,y);
grid on;
axis([0,50,0,1.6]);
err=1-y;
figure(2);
plot(t,err);
grid on;





