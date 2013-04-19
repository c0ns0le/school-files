function y = predict(x, a, n)
% Calculează predicția liniară
% x - p semnale
% a - p coeficienți
% n - lungimea predicției

    p = length(a);

    y = zeros(n, 1);
    y(1:p) = x;

    for k=p+1:n
        for i=1:p
            y(k) -= a(i)*y(k-i);
        end
    end

end
