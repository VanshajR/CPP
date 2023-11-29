x=x0;
y=y0;
h=step val;
r=req index;
n=ceil((r-x)/h);
disp x0,y0;
k1=h*f(x,y);
k2=h*(f(x+(h/2),y+(k1/2)));
k3=h*(f(x+(h/2),y+(k2/2)));
k4=h*f(x+h,y+k3);
y=y+(k1+2+k3+k4)/6;
for i=1:n-1
    x=x+h;
    k1=h*f(x,y);
    k2=h*(f((x+h/2),y+(k1/2)));
    k3=h*(f((x+h/2),y+(k2/2)));
    k4=h*(f(x+h,y+k3));
    disp value at x is y;
    y=y+(k1+k2+k3+k4)/6;
end

