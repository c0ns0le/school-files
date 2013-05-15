function x = solve(A,b)
% Rezolva sistemul A * x = b
% Q * R * x = b
% R * x = Q' * b

    [Q,R] = gramSchmidtMod(A);
    b = Q' * b;
    x = SST(R,b);

end

function x = SST(A,b)
% Rezolva sistemul superior triunghiular A*x=b

    [n,n] = size(A);
    x = zeros(n,1);

    x(n) = b(n) / A(n,n);
    for i = n-1:-1:1
        x(i) = (b(i) - A(i,i+1:n)*x(i+1:n)) / A(i,i);
    end

end
