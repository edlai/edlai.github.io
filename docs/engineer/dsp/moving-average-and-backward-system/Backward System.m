%........................................................................................................
% filenmae :  b.m
% auother  :  Jing-Wen.Lai 
% �ާ@     :  �b Matlab ���U���楻 .m ��
% �{���y�z : high-pass filter, ���q�o�i��
%
%  Date    : 10/21 2002 ver1.0
%  �ǳ��ɮ� : speech.wav (PCM �榡)
%  �����ɮ� : speech_m.wav(PCM �榡)
% 
%  ref.  :   Backward System
%            book :: Discrete-Time Signal Processing 
%            (isbn::0-13-0834443-2 p.21(2.45��)
%........................................................................................................

fs=8000;

%  ..........................  �y�����˶}�l  .........................................

[ x,fs ] = wavread('speech.wav');    % Ū�� speech.wav �ɮפ����y���˥�
k=input('�Ы��U ���@�� ����B�z �e �n��');
wavplay(x,fs);                                 % �B�z�e����ť�ӻy���˥�

% ............   �i�� DSP �B�z  �i  Backward System �j.............

fprintf('�B�z��,�еy��...\n');
len=length(x);
for n = 1:len,                         % n  :: �y����Ƽƥ�
    if n == 1
        y(n) = x(n);                   % Backward System �Ĥ@�����@�֭p      
    else
        y(n) = x(n)- x(n-1);       % �N���e���˭Ȯ��ӻP�ثe���۴�
    end  
end

% ......... DSP �B�z�ᵲ�G::���ͪi���ϻP�W�� ............               

k=input('�Ы��U ���@�� ����B�z �� �n��');
wavplay(y,fs);                                        % ť�B�z�Z�n��
wavwrite(y, fs, 16, 'speech_b.wav');       % �g�J speech_b.wav ��

subplot(221), plot((1:length(x)),x);
subplot(223), specgram(x(:));
subplot(222), plot((1:length(y)),y);
subplot(224), specgram(y(:));
shg
