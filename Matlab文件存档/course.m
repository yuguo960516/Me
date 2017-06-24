
fs=100;N=1280;  %采样频率fs=100，采样点N=1280
n=0:N-1;
t=n/fs;  %时间t
y=square(2.*pi.*t)+rand(1,length(t));   %产生带噪声的方波信号
figure(1);
subplot(311);
plot(t,y);  %画出时间域图像
axis([0,10,-1.5,2.5]);
Y1=abs(fft(y,N));   %对时间域信号做傅里叶变换
subplot(312);
f=n*fs/N;
plot(f,Y1); %画出频域图像
xlabel('fft');
Y2=abs(fftshift(fft(y,N))); %将频域的直流分量移到频谱中心
f2=linspace(-fs/2,fs/2,length(Y2));
subplot(313)
plot(f2,Y2);    %画出频域图像
xlabel('shiftfft');
figure(2);
B = fir1(42,0.1);   %返回6dB截止频率为0.1Hz的42阶FIR低通滤波器系数向量，默认哈明窗
freqz(B,1,512); %画出该低通滤波器频率响应图像
figure(3);
subplot(311);
plot(t,y);
axis([0,10,-1.5,2.5]);
R = filter(B, 1, y);    %计算滤波后时间域的信号
subplot(312);
plot(t,R);  %画出时间域图像
axis([0,10,-1.5,2.5]);
Y3=abs(fftshift(fft(R,N)));     %计算滤波后频域信号
f3=linspace(-fs/2,fs/2,length(Y3));
subplot(313)
plot(f3,Y3);    %%画出频域图像
xlabel('shiftfft after filter')










