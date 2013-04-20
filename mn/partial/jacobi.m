function X = jacobi(A, b)
    maxiter = 1000;

    [n,n] = size(A);

    X = zeros(n,1);

    i = 0;
    while i < maxiter
        D = diag(diag(A));
        R = A - D;
        X = diag(1./diag(D)) * (b - R*X);

        i += 1;
    end

end
