function A = readFile(filename)
% Construiește matricea A din fișierul indicat de filename

    f = fopen(filename);
    n = fscanf(f, '%d', 1);
%disp(n);
    values = fscanf(f, '%lf %lf', [2, n]);
    fclose(f);
%disp(values);
    m = values(1,:);
    k = values(2,:);

    A = zeros(n, n);

    if n == 1
        A(1,1) = k(1)/m(1);
        return
    end

    A(1,1) = (k(1)+k(2))/m(1);
    A(1,2) = -k(2)/m(1);
    for i = 2 : n-1
        A(i,i-1) = -k(i)/m(i);
        A(i,i)   = (k(i)+k(i+1)) / m(i);
        A(i,i+1) = -k(i+1) / m(i);
    end
    A(n,n-1) = -k(n)/m(n);
    A(n,n)   = k(n) / m(n);

end
