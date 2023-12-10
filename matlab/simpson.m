f=input function
a=input lower limit
b=input upper limit
n=input subintervals
h=(b-a)/n
sum=0;
res=0;
for i=1:n
    x=a+(h*i);
    if rem(i,2)==0
        sum=sum+(2*f(x))
    else
        sum=sum+(4*f(x))
    end
end
sum=sum+f(a)+f(b);
res=sum*(h/3);
disp res