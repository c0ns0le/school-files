function F = SplineT(x,f,X)

    n = length(x);

    % Coeficienții a(i)
    a = f;

    h = diff(x);

    H = zeros(n,n);
    H(1,1) = 2*h(1);
    H(1,2) = h(1);
    H(n,n) = 2*h(n-1);
    H(n,n-1) = h(n-1);

    for i=2:n-1
        H(i,i-1) = h(i-1);
        H(i,i) = 2*(h(i-1)+h(i));
        H(i,i+1) = h(i);
    end

    G = zeros(n,1);
    d1 = (f(2)-f(1))/(x(2)-x(1));
    dn = (f(n)-f(n-1))/(x(n)-x(n-1));
    G(1) = 3*(a(2)-a(1))/h(1) - 3*d1;
    G(n) = 3*dn - 3*(a(n)-a(n-1))/h(n-1);

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
                % Valoarea în X(i) va fi:
                F(i) = a(j)+b(j)*(X(i)-x(j))+c(j)*(X(i)-x(j))^2+d(j)*(X(i)-x(j))^3;
                break;
            end
        end
    end

end
