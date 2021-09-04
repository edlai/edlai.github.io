%........................................................................................................
% filenmae :  b.m
% auother  :  Jing-Wen.Lai 
% 操作     :  在 Matlab 底下執行本 .m 檔
% 程式描述 : high-pass filter, 高通濾波器
%
%  Date    : 10/21 2002 ver1.0
%  準備檔案 : speech.wav (PCM 格式)
%  產生檔案 : speech_m.wav(PCM 格式)
% 
%  ref.  :   Backward System
%            book :: Discrete-Time Signal Processing 
%            (isbn::0-13-0834443-2 p.21(2.45式)
%........................................................................................................

fs=8000;

%  ..........................  語音取樣開始  .........................................

[ x,fs ] = wavread('speech.wav');    % 讀取 speech.wav 檔案內的語音樣本
k=input('請按下 任一鍵 撥放處理 前 聲音');
wavplay(x,fs);                                 % 處理前先試聽該語音樣本

% ............   進行 DSP 處理  【  Backward System 】.............

fprintf('處理中,請稍候...\n');
len=length(x);
for n = 1:len,                         % n  :: 語音資料數目
    if n == 1
        y(n) = x(n);                   % Backward System 第一筆不作累計      
    else
        y(n) = x(n)- x(n-1);       % 將之前取樣值拿來與目前的相減
    end  
end

% ......... DSP 處理後結果::產生波型圖與頻譜 ............               

k=input('請按下 任一鍵 撥放處理 後 聲音');
wavplay(y,fs);                                        % 聽處理后聲音
wavwrite(y, fs, 16, 'speech_b.wav');       % 寫入 speech_b.wav 檔

subplot(221), plot((1:length(x)),x);
subplot(223), specgram(x(:));
subplot(222), plot((1:length(y)),y);
subplot(224), specgram(y(:));
shg
