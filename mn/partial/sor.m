function x = sor(A,b,w)

% A = D - U - L
% wA = wD - wU - wL = (D - wL) - ((1-w)D + wU)
% (D - wL)x = ((1-w)D + wU)x + b

    [n,n] = size(A);

    D = diag(diag(A));
    L = tril(A) - D;
    U = triu(A) - D;

    I = inverse(D-w*L);
    G = I * ((1-w)*D + w*U);
    c = I * b;
    x = zeros(n,1);

    iter = 0;

    while 1
        x_ = x;
        x = G*x + c;

        iter += 1;
        if norm(x - x_, inf) < eps
            disp('iterations: ');
            disp(iter);
            return;
        end
    end

end
