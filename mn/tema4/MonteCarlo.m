function A = MonteCarlo(x,y,tol)
% Calculează aria curbei date de vectorii de coordonate x și y

    % coordonatele dreptunghiului care încadrează curba
    a = min(x);
    b = max(x);
    c = min(y);
    d = max(y);

    % Număr inițial de puncte
    N = 64;

    A = Area(x,y,N,a,b,c,d);

    while 1
        _A = A;
        N *= 2;
        A = Area(x,y,N,a,b,c,d);
        if abs(A - _A) < tol
            return;
        end
    end

end

function A = Area(x,y,N,a,b,c,d)
% Calculează aria curbei date de vectorii de coordonate x și y,
% folosind o distribuție de N puncte în dreptunghiul [a,b]x[c,d]

    % Generăm puncte aleator și uniform în dreptunghiul [a,b]x[c,d]
    [_x,_y] = Gen2DPoints(N,a,b,c,d);

    % Numărăm punctele interioare
    N_inside = 0;
    for i = 1:N
        if isinside(x,y,_x(i),_y(i))
            N_inside += 1;
        end
    end

    % Determinăm aria, făcând raportul
    A = N_inside * (b-a)*(d-c) / N;

end

function z = isinside(x,y,u,v)
% Determină dacă punctul (u,v) este în interiorul curbei
% determinate de vectori de coordonate x și y

    n = length(x);
    z = 0;
    i = 1;
    j = n;
    while i <= n
        if ((y(i)>v) != (y(j)>v)) && (u<(x(j)-x(i))*(v-y(i))/(y(j)-y(i))+x(i))
            z = ~z;
        end
        j = i;
        i += 1;
    end

end
