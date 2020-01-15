%exp(sin(millis()/2000.0*PI)) - 0.36787944)*108.0

%plot(x,exp(sin(x))) min= exp(sin(-1.7183))=0.3719  max(exp(sin(x)))=2.7181
%min(exp(sin(x)))=0.3679
clear;
% x = -pi:0.01:pi;
pwmPluse=500;   %64ÂúÂö¿í
size = 64;
% x = linspace(0,pi,256);
% y=pwmPluse*sin(x); %ÕýÏÒ²¨
x=linspace(-1.7183,4.5,size);
y=(exp(sin(x)) - 0.36787944)*(pwmPluse/(exp(1)-1/exp(1)));

r=round(y);

x1 = linspace(0,2*pi,size);  %¾â³Ý²¨
y1=pwmPluse/2*(sawtooth(x1)+1);
y1=round(y1);


x1_1 = linspace(0,2*pi,size);  %¾â³Ý²¨·´Ïò
y1_1=pwmPluse/2*(sawtooth(-x1_1)+1);
y1_1=round(y1_1);

x2 = linspace(0,2*pi,size);  %Èý½Ç²¨
y2 = pwmPluse/2*(sawtooth(x2,0.5)+1);
y2=round(y2);

%½×ÌÝÍ¼
   
offset=pwmPluse/4;
xnum=64/4;

y3_1=ones(1,xnum)*(offset*1);
y3_2=ones(1,xnum)*(offset*2);
y3_3=ones(1,xnum)*(offset*3);
y3_4=ones(1,xnum)*(offset*4);
x3=0:1:63;
y3=[y3_1,y3_2,y3_3,y3_4];
y3=round(y3);

x4 = linspace(0,2*pi,64);
y4=(square(x4,50)+1)*pwmPluse/2;


x5 = linspace(-pi,pi,64);
y5 = sin(x5);






fp = fopen('D:\Personal\Desktop\lk_src\arithmetic\sin\pwmMotor.txt','wt');
fprintf(fp, '#define MOTOR_ARRY_SIZE %d', size);
fprintf(fp, '\n');
fprintf(fp, 'uint16_t sinMotor[]={ //ÕýÏÒ²¨ \n' );
fprintf(fp, '%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,\n', r);
fprintf(fp, '};\n');


fprintf(fp, 'uint16_t sawtooth_motor[]={ // \n' );
fprintf(fp, '%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,\n', y1);
fprintf(fp, '};\n');


fprintf(fp, 'uint16_t triangle_motor[]={ //Èý½Ç \n' );
fprintf(fp, '%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,\n', y2);
fprintf(fp, '};\n');


fprintf(fp, 'uint16_t ladder_motor[]={ //½×ÌÝ \n' );
fprintf(fp, '%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,\n', y3);
fprintf(fp, '};\n');

subplot(2,4,1);plot(x,y);
subplot(2,4,2);plot(x1,y1);
subplot(2,4,3);plot(x1_1,y1_1);
subplot(2,4,4);plot(x2,y2);
subplot(2,4,5);plot(x3,y3);
subplot(2,4,6);plot(x4,y4);

subplot(2,4,6);plot(x5,y5);
