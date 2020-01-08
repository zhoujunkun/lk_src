%exp(sin(millis()/2000.0*PI)) - 0.36787944)*108.0

%plot(x,exp(sin(x))) min= exp(sin(-1.7183))=0.3719  max(exp(sin(x)))=2.7181
%min(exp(sin(x)))=0.3679
clear;
% x = -pi:0.01:pi;
x = linspace(-pi,pi,128);
y=32767*sin(x);
r=round(y);
minMum = min(r);
[m,index_min]=min(r);
maxMum=max(r);
[m,index_max]=max(r);
tm8211=round(32767/0.75*0.5); %0.75~2.25 -32767~32767
fp = fopen('D:\workz_zjk\work\lk_src\arithmetic\sin\zjk.txt','wt');
fprintf(fp, 'int index_min=%d;//最小值位置\n', index_min);
fprintf(fp, 'int tm8211_diff=%d;//相差值\n', tm8211);
fprintf(fp, 'int waveArray[]={ //波形数组 \n' );
fprintf(fp, '%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,\n', r);
fprintf(fp, '};\n');
fclose(fp);
plot(x,y);