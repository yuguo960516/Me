clc;
clear;
x=linspace(1,1000,1000);
y=x.^3+2*x.^2+3*x+4;
 k=rand(1,1000);
[m,n]=sort(k);
input_train=x(:,n(1:900));
output_train=y(:,n(1:900));
input_test=x(:,n(901:1000));
output_test=y(:,n(901:1000));
[inputn,inputs]=mapminmax(input_train);
[outputn,outputs]=mapminmax(output_train);
net=newff(inputn,outputn,[5,4]);
net.trainParam.epochs=1000;
net.trainParam.lr=0.1;
net.trainParam.goal=0.000000001;
net=train(net,inputn,outputn);
inputn_test=mapminmax('apply',input_test,inputs);
an=sim(net,inputn_test);
BPoutput=mapminmax('reverse',an,outputs);
figure(1);
plot(BPoutput,'-');
hold on;
plot(output_test,'*');
legend('Ô¤²âÊä³ö','ÆÚÍûÊä³ö');
figure(2);
error=output_test-BPoutput;
plot(error,'-');
legend('Îó²î');




