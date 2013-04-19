function [l, X] = eigenValuesVectors(A)
% Calculează valorile și vectorii proprii pentru matricea A

    [X, l] = eig(A);

    l = diag(l);
    l = sqrt(l*1000) / ( 2 * pi );

    [n, n] = size(A);
    for i = 1 : n
        X(:,i) = X(:,i) / X(n,i);
    end

end
