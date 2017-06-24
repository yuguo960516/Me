clc;
clear;
interval=0.01;
x1=-1:interval:1.5;
x2=1:interval:3.5;
x1_test=1.5:interval:1.8;
x2_test=3.5:interval:3.8;
F=20+x1.^2-10*cos(2*pi*x1)+x2.^2-10*cos(2*pi*x2);
RBF_net=newrbe([x1;x2],F);
pred=sim(RBF_net,[x1_test;x2_test]);
figure(1);
plot3(x1,x2,F,'rd');
hold on;
plot3(x1_test,x2_test,pred,'b-.');
view(113,36);
title('基于RBF神经网络的回归效果');
xlabel('x1');
ylabel('x2');
zlabel('F');
legend('Z_True','Z_prediction');
grid on;





