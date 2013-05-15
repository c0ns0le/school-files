function HeartModel(path)

    % Fișierele .dat conținând secțiunile inimii
    files = sort(ls(strcat(path,'/*.dat')));

    [n,m] = size(files);

    % Toleranța utilizată în Monte-Carlo
    tol = 0.1;

    for i = 1:n
        data = load(files(i,:));
        x = data(:,1);
        y = data(:,2);

        % Vector-ul coordonatelor z
        z(i) = data(1,3);

        % Ariile calculate cu cele două metode
        A1(i) = Trapez(x,y);
        A2(i) = MonteCarlo(x,y,tol);
    end

    disp(A1);   % better OUTPUT!!
    disp(A2);

    _A1 = A1(2:n);
    A1_ = A1(1:n-1);

    _A2 = A2(2:n);
    A2_ = A2(1:n-1);

    h = diff(z);

    % Integrare cu metoda „trapezului”,
    % după formula V = h/3 * (A1 + A2 + sqrt(A1*A2))
    V1 = sum(( h.*A1_ + h.*_A1 + h.*sqrt(A1_.*_A1) ) / 3)
    V2 = sum(( h.*A2_ + h.*_A2 + h.*sqrt(A2_.*_A2) ) / 3)

end
