function conv = nsiConv(epsilon, func)

    % Valorile posibile pentru nsi
    nsis = [10,20,30,40,50,100,150,200,250,300];

    % Calculăm toate erorile
    errs = [];
    for nsi = nsis
        errs = [errs,Error(nsi,func)];
    end

    % Testăm condiția de monotonie și cea ca eroarea să fie < epsilon
    for i=1:10
        if errs(i)<epsilon
            if prod(diff(errs(i:10))<=0) == 1
                conv = nsis(i);
                return;
            end
        end
    end

    % Dacă am ajuns aici, nu converge
    conv = Inf;
end
