function [x Q R] = householder(A, b)
    [m,n] = size(A);
    Q = eye(m); x=zeros(n,1);
    for p=1:n
        s=norm(A(p:m,p)); beta=s*(s+A(p,p));
        if A(p,p) < 0
            s = -s;
        end
        u = zeros(m,1);
        u(p) = A(p,p) + s;
        u(p+1:m) = A(p+1:m,p);
        A(p,p)=-s;
        A(p+1:m,p)=0;
        for j=p+1:n
            ro = u' * A(:,j) / beta;
            A(p:m,j) = A(p:m,j) - ro*u(p:m);
        end
        ro = u' * b / beta;
        b(p:m) = b(p:m) - ro * u(p:m);
        for j=p+1:m
            ro = u' * Q(:,j) / beta;
            Q(p:m,j) = Q(p:m,j) - ro*u(p:m);
        end
    end
    Q = Q'; R = A;
end
