function [Q,R] = hh(A)

    [m,n] = size(A);
    Q = eye(m);

    for i=1:n
        u = zeros(m,1);
        u(i:m) = A(i:m,i);
        sigma = norm(u);
        if u(i) < 0
            sigma = -sigma;
        end
        u(i) += sigma;
        v = u / norm(u);
        H = eye(m) - 2*v*v';
        A = H*A;
        Q = H*Q;
    end

    R = A;
    Q = Q';
end
