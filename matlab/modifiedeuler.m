x=input x0;
y=input y0;
f=input func;
h=input step value;
r=input required point;
n=ceil((r-x)/h);
disp val at x0 is y0;
prev_x=x;
sy=y+h*f(x,y);
x=x+h;
y=y+(h/2)*(f(prev_x,y)+f(x,sy));
for i=1:n-1
    disp value at x,y
    sy=y+f(x,y);
    x=x+h;
    y=y+(h/2)*(f(prev_x,y)+f(x,sy));
    prev_x=x;
end

