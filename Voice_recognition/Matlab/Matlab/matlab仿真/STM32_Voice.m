clear;
fs=8000;

noise=load('E:\DSP\voice_recognition\stm32-speech-recognition-master\Matlab\��������\STM32 noise.txt');
noise=(noise-2048)/2048;
sound(noise,fs);

Voice123=load('E:\DSP\voice_recognition\stm32-speech-recognition-master\Matlab\��������\STM32 123.txt');
Voice123=(Voice123-2048)/2048;
sound(Voice123,fs);

Voice456=load('E:\DSP\voice_recognition\stm32-speech-recognition-master\Matlab\��������\STM32 456.txt');
Voice456=(Voice456-2048)/2048;
sound(Voice456,fs);

subplot(311)
plot(noise)
ylabel('����')
grid on

subplot(312)
plot(Voice123)
ylabel('����')
grid on

subplot(313)
plot(Voice456)
ylabel('����')
grid on