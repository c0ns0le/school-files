function [R0, R] = mycor(x, p)
% Calculează R0, R1, .. , Rp
% x - semnalul

    n = length(x);

    R = zeros(p,1);

    R0 = sum( x(1:n) .* x(1:n) );

    for i=1:p
        R(i) = sum( x(i+1:n) .* x(1:n-i) );
    end

end
