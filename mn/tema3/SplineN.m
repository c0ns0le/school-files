function F = SplineN(x,f,X)

    n = length(x);

    % Coeficienții a(i)
    a = f;

    h = diff(x);

    H = zeros(n,n);
    H(1,1) = h(1);
    H(n,n) = h(n-1);

    for i=2:n-1
        H(i,i-1) = h(i-1);
        H(i,i) = 2*(h(i-1)+h(i));
        H(i,i+1) = h(i);
    end

    G = zeros(n,1);
    for i=2:n-1
        G(i) = 3*(a(i+1)-a(i))/h(i) - 3*(a(i)-a(i-1))/h(i-1);
    end

    % Coeficienții c(i)
    c = solve(H,G);

    % Coeficienții b(i) și d(i)
    for i=1:n-1
        b(i) = (a(i+1)-a(i))/h(i) - h(i)/3*(2*c(i)+c(i+1));
        d(i) = (c(i+1)-c(i))/(3*h(i));
    end

    N = length(X);
    for i=1:N
        for j=1:n-1
            if X(i) <= x(j+1)
                % Valoarea funcției în X(i) va fi:
                F(i) = a(j)+b(j)*(X(i)-x(j))+c(j)*(X(i)-x(j))^2+d(j)*(X(i)-x(j))^3;
                break;
            end
        end
    end

end
