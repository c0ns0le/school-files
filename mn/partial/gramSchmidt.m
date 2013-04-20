function [Q, R] = gramSchmidt(A)

    [n,n] = size(A);
    Q = A;

    Q(:,1) /= norm(Q(:,1));
    for i=2:n
        for j=1:i-1
            Q(:,i) -= Q(:,i)'*Q(:,j)*Q(:,j);
        end
        Q(:,i) /= norm(Q(:,i));
    end

    R = Q'*A;
end
