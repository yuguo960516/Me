
fs=100;N=1280;  %����Ƶ��fs=100��������N=1280
n=0:N-1;
t=n/fs;  %ʱ��t
y=square(2.*pi.*t)+rand(1,length(t));   %�����������ķ����ź�
figure(1);
subplot(311);
plot(t,y);  %����ʱ����ͼ��
axis([0,10,-1.5,2.5]);
Y1=abs(fft(y,N));   %��ʱ�����ź�������Ҷ�任
subplot(312);
f=n*fs/N;
plot(f,Y1); %����Ƶ��ͼ��
xlabel('fft');
Y2=abs(fftshift(fft(y,N))); %��Ƶ���ֱ�������Ƶ�Ƶ������
f2=linspace(-fs/2,fs/2,length(Y2));
subplot(313)
plot(f2,Y2);    %����Ƶ��ͼ��
xlabel('shiftfft');
figure(2);
B = fir1(42,0.1);   %����6dB��ֹƵ��Ϊ0.1Hz��42��FIR��ͨ�˲���ϵ��������Ĭ�Ϲ�����
freqz(B,1,512); %�����õ�ͨ�˲���Ƶ����Ӧͼ��
figure(3);
subplot(311);
plot(t,y);
axis([0,10,-1.5,2.5]);
R = filter(B, 1, y);    %�����˲���ʱ������ź�
subplot(312);
plot(t,R);  %����ʱ����ͼ��
axis([0,10,-1.5,2.5]);
Y3=abs(fftshift(fft(R,N)));     %�����˲���Ƶ���ź�
f3=linspace(-fs/2,fs/2,length(Y3));
subplot(313)
plot(f3,Y3);    %%����Ƶ��ͼ��
xlabel('shiftfft after filter')










