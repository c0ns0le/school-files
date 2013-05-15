function err = Error(nsi,str_func)

    % Obținem handler-ul funcție din string
    func = str2func(str_func);

    points_17 = -8:1:8;
    values_17 = [-5,1,0,5,-1,3,2,5,3,4,2,0,1,-1,1,3,-5];
    
    points_nsi = linspace(-8,8,nsi);
    values_nsi = interp1(points_17,values_17,points_nsi,'spline');

    points_500 = linspace(-8,8,500);

    % Valorile de referință
    values_500_ref = interp1(points_17,values_17,points_500,'spline');

    % Valorile obținute cu funcția dată
    values_500_func = func(points_nsi,values_nsi,points_500);

    % Calculăm eroarea
    err = sqrt(0.032 * sum((values_500_ref-values_500_func).^2));

end
