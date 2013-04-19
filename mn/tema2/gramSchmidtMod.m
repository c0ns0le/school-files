function [Q,R] = gramSchmidtMod(A)
% Descompune matricea A într-o matrice ortogonală Q
% și una superior triunghiulară R.

    [n,n] = size(A);
    Q = zeros(n,n);
    R = zeros(n,n);
    for i = 1:n
        R(i,i) = norm(A(:,i));
        Q(:,i) = A(:,i) / R(i,i);
        for j=i+1:n
            R(i,j) = Q(:,i)' * A(:,j);
            A(:,j) = A(:,j) - Q(:,i) * R(i,j);
        end
    end

end
