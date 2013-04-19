function a = levinson(R0, R)
% Calculează coeficienții a

    R0 += eps; R += eps;

    p = length(R);
    a = zeros(p,1);
    E = R0;
    a(1) = -R(1) / R0;
    k(1) = a(1);
    q = R(1);

    for i=1:p-1
        E += abs(q * k(i));
        q = R(i+1);
        q += sum( R(1:i) .* a(i:-1:1) );
        k(i+1) = -q / E;
        tmp(1:i) = k(i+1) .* a(i:-1:1);
        a(1:i) += tmp(1:i)';
        a(i+1) = k(i+1);
    end

end
