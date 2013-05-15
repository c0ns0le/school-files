function F = SplineL(x,f,X)

    n = length(x);

    % Calculăm coeficienții a(i) și b(i)
    a = diff(f) ./ diff(x);
    b = (x(2:n).*f(1:n-1) - x(1:n-1).*f(2:n)) ./ (x(2:n)-x(1:n-1));

    N = length(X);
    for i=1:N
        for j=1:n-1
            if X(i) <= x(j+1)
                % Valoarea în punctul X(i)
                F(i) = a(j)*X(i) + b(j);
                break;
            end
        end
    end

end
