a=input('Matrix: ');
n=length(a);
e=input("Error: ");
x=ones(n,1);
y=a*x;
k=max(abs(y));
x=y/k;
y=a*x;
if abs(k-max(abs(y)))<e
    eigen value:k
    eigen vector: x;
else
    while abs(k-max(abs(y)))>e
        k=max(abs(y));
        x=y/k;
        y=a*x;
    end
    eigen val: k;
    eigen vector: y/k;
end
