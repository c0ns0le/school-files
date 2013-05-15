function F = Trig(x,f,X)

    _n = length(x);
    n = (_n - 1) / 2;

    k = 0:2*n;
    teta = 2*pi/_n * k;

    a0 = 1/_n * sum(f);

    % Calculăm indicii a(i) și b(i)
    for j=1:n
        a(j) = 2/_n * sum(f .* cos(j*teta));
        b(j) = 2/_n * sum(f .* sin(j*teta));
    end

    N = length(X);

    for i=1:N
        % Noul teta, adus în intervalul [0, 2*pi]
        t = (X(i)-X(1))/(X(N)-X(1)) * (_n - 1) / _n * 2*pi;

        % Calculul valorii funcției în X(i)
        F(i) = a0 + sum(b .* sin(t*(1:n))) + sum(a .* cos(t*(1:n)));
    end

end

