% ..........................................................................................................................
% filenmae : dsp3.m
% Auother :  Jing-Wen.Lai 
% 操作     :  在 Matlab 底下執行本 .m 檔
% 程式描述 : Window Size and the Spectrogram  
% date     :       01/04 2003 ver1.0
% Remark   : matlab scripts :: getting SPECGRAM
%                  SPECGRAM(A, NFFT, Fs, WINDOW, NOVERLAP)
% ref.to  :      DSP First
%    path::  DSP First - Text Book\CHAPTERS\9SPECTA\DEMOS\SPECGRAM\INDEX.HTM 
% ..........................................................................................................................
close all;
clear all;

fs=6000;  
n=1;f0=920;f1=500;f2=1000;f3=1500;f4=2000;f5=2500;

% ................. 信號 生成 .............
for t=0:1/fs:1 
    if 0.1<t & t<0.24
        s(n)=cos(2*pi*f0*t)+cos(2*pi*f1*t);
    elseif 0.24<t & t<0.4
        s(n)=cos(2*pi*f0*t)+cos(2*pi*f2*t);
    elseif 0.4<t & t<0.54
        s(n)=cos(2*pi*f0*t)+cos(2*pi*f3*t);
    elseif 0.54<t & t<0.7
        s(n)=cos(2*pi*f0*t)+cos(2*pi*f4*t);
    elseif 0.7<t & t<0.83
        s(n)=cos(2*pi*f0*t)+cos(2*pi*f5*t);
    else 
        s(n)=cos(2*pi*f0*t);         
    end         
    n=n+1; 
end

% ....... display 原始信號 ....................
t=0:1/fs:1;plot(t,s);
ylabel('AMPLITUDE');xlabel('TIME(sec)');title('S(n) waveform');

% ....... display Specgram using Hamming windows ....................

k=input('請按下 任一鍵 顯示 SPECGRAM - Hamming window');

subplot(211);specgram(s,256,fs,hamming(256),64);         
ylabel('FREQUENCY');xlabel('TIME(sec)');
title('SPECGRAM (256 points FFT,Hamming window & 64 points overlap)');

subplot(212);specgram(s,1024,fs,hamming(1024),512);
ylabel('FREQUENCY');xlabel('TIME(sec)');
title('SPECGRAM of o/p (1024 points FFT,Hamming window & 512 points overlap');

% ....... display Specgram using Blackman windows ....................

k=input('請按下 任一鍵 顯示 SPECGRAM - Blackman window');

subplot(211);specgram(s,256,fs,blackman(256),64);
ylabel('FREQUENCY');xlabel('TIME(sec)');
title('SPECGRAM (256 points FFT,Blackman window & 64 points overlap)');

subplot(212);specgram(s,1024,fs,blackman(1024),512);
ylabel('FREQUENCY');xlabel('TIME(sec)');
title('SPECGRAM (1024 points FFT,Blackman window & 512 points overlap');