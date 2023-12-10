p=input points
f=input vals at points
x= input initial x
n=length(p);
d=zeros(n,n);
for i=1:n
    d(i,1)=f(i);
end
for j=2:n
    for i=1:(n-j+1)
        d(i,j)=(d(i+1,j-1)-d(i,j-1))/(p(i+j-1)-p(i));
    end
end
disp d;
a=1;
s=d(1,1);
for i=2:n
    a=a*(x-p(i-1));
    s=s+(a*d(i,1));
end
disp s;