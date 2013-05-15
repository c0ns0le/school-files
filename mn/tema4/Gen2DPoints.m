function [x,y] = Gen2DPoints(N,a,b,c,d)

    % Apelăm funcția privată cu listele inițiale de coordonate vide
    [x,y] = _Gen2DPoints(N,a,b,c,d,[],[]);

    % Sortăm după x (opțional)
    [x,s] = sort(x);
    y = y(s);

end

function [x,y] = _Gen2DPoints(N,a,b,c,d,x,y)

    if ~N
        return;
    end

    % dimensiunile dreptunghiului în care distribuim
    u = b-a;
    v = d-c;

    if u < v
        m = 1;
        % întâi dublăm, pentru convergență mai rapidă
        while 2*m*floor(v*2*m/u) <= N;
            m *= 2;
        end

        % apoi adăugăm câte 1, pentru finețe :)
        while (m+1)*floor(v*(m+1)/u) <= N;
            m += 1;
        end

        % dacă m este 1, distribuim 'liniar'
        if m == 1
            for i = 0:N-1
                x = [x,a+u*rand];
                y = [y,c+v/N*i+v/N*rand];
            end
            return;
        end

        % latura pătratelor
        l = u / m;

        % u este împărțit în m
        % v este împărțit în n și ceva

        n = floor(v*m/u);
        _v = v - l * n;   % restul rămas pe latura mai mare

        % distribuim N - _N = m*n puncte
        for i = 0:m-1
            for j = 0:n-1
                x = [x,a+i*l+l*rand];
                y = [y,c+j*l+l*rand];
            end
        end
    else
        % pentru detalii, vedeți cazul u<v, este analog

        n = 1;
        while 2*n*floor(u*2*n/v) <= N;
            n *= 2;
        end

        while (n+1)*floor(u*(n+1)/v) <= N;
            n += 1;
        end

        if n == 1
            for i = 0:N-1
                x = [x,a+u/N*i+u/N*rand];
                y = [y,c+v*rand];
            end
            return;
        end

        l = v / n;

        m = floor(u*n/v);
        _u = u - l * m;   % restul rămas pe latura mai mare

        for i = 0:m-1
            for j = 0:n-1
                x = [x,a+i*l+l*rand];
                y = [y,c+j*l+l*rand];
            end
        end
    end

    % acum distribuim restul de _N puncte, auto-apelând recursiv aceeași funcție
    _N = N - m*n;
    if _N
        [x,y] = _Gen2DPoints(_N,a,b,c,d,x,y);
    end

end
