function [l,X] = qrEig(A)
% Calculează vectorii si valorile proprii ale matricii A
    e = 0.1e-10;
    maxiter = 1000;

    i = 0;
    [n,n] = size(A);
    X = eye(n);
    while i < maxiter
        A_ = A;
        [Q,R] = gramSchmidtMod(A);
        X = X * Q;
        A = R*Q;
        l = diag(A)';

        if norm(A - A_, inf) < e
            break;
        end

        i = i + 1;
    end

end
