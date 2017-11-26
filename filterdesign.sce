clear;

fs = 3000
fc = 20

hz=iir(2,'lp','cheb1',(fc/fs),[.08 .03]);
[hzm,fr]=frmag(hz,256);
plot2d('ln',fr',hzm');
//xtitle('Discrete IIR filter band pass  0.15&lt;fr&lt;0.25 ',' ',' ');
q=poly(0,'q');     //to express the result in terms of the delay operator q=z^-1
hzd=horner(hz,1/q)

[p,z,g]=iir(2,'lp','cheb1',(fc/fs),[.08 .03]);
h=g*poly(z,'z')/poly(p,'z')

r=poly(z,'s','roots')
b=g*coeff(r);
r=poly(p,'s','roots')
a=coeff(r);

scalea = 1024;
scaleb = 1024*1024;

a(1:3) = round(scalea*a(3:-1:1));
b(1:3) = round(scaleb*b(3:-1:1));

//a(1:3) = a(3:-1:1);
//b(1:3) = b(3:-1:1);

shift = log2(scalea);
