function Locatie

    points_17 = -8:1:8;
    values_17 = [-5,1,0,5,-1,3,2,5,3,4,2,0,1,-1,1,3,-5];
    points_500 = linspace(-8,8,500);
    values_500 = interp1(points_17,values_17,points_500,'spline');

    % Păstrăm toate graficele
    hold on

    % Graficul interp1
    plot(points_500,values_500,'-0');

    % Graficele interpolărilor implementate
    plot(points_500,SplineL(points_17,values_17,points_500),'-b');
    plot(points_500,SplineN(points_17,values_17,points_500),'-r');
    plot(points_500,SplineT(points_17,values_17,points_500),'-g');

    hold off

end
