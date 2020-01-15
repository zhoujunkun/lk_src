%exp(sin(millis()/2000.0*PI)) - 0.36787944)*108.0

%plot(x,exp(sin(x))) min= exp(sin(-1.7183))=0.3719  max(exp(sin(x)))=2.7181
%min(exp(sin(x)))=0.3679
clear;
x=linspace(-1.7183,4.5,60);
y=(exp(sin(x)) - 0.36787944)*(375/(exp(1)-1/exp(1)));
r=round(y);
fp = fopen('D:\workz_zjk\work\510\lk_510\app\arithmetic\zjk.txt','wt');
fprintf(fp, '%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,\n', r);
fclose(fp);
plot(x,y);