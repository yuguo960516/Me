figure(1);
[s,sd,sdd]=tpoly(0,1,50,0,0);
subplot(311);
plot(s);
subplot(312);
plot(sd);
subplot(313);
plot(sdd);
figure(2);
[a,ad,add]=lspb(0,1,50,0.025);
subplot(311);
plot(a);
subplot(312);
plot(ad);
subplot(313);
plot(add);
figure(3);%error path
W=transl(1,2,3)*rpy2tr(pi/6,pi/4,pi/3);
Q=tr2rpy(W);
E=transl(W)';
x=mtraj(@lspb,[0,0,0,0,0,0],[E,Q],50);
plot(x);
figure(4);%correct path
W1=transl(0,0,0)*rpy2tr(0,0,0);
W2=transl(3,2,1)*rpy2tr(pi/3,pi/4,pi/6);
%Ts=trinterp(W1,W2,(0:49)/49);
%Ts=trinterp(W1,W2,lspb(0,1,50));%有起始加速和结束减速(更平滑)
Ts=ctraj(W1,W2,50);
about(Ts)
tranimate(Ts);
figure(5);
subplot(211);
P=transl(Ts);
plot(P);
subplot(212);
RPY=tr2rpy(Ts);
plot(RPY);




