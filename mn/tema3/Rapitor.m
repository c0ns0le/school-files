function Rapitor

    % Corectarea raportului dimensiunilor plot-ului
    axes('Xlim', [-15 15], 'Ylim', [-10 10]);

    % Mai multe grafice suprapuse
    hold on

    % Definim ecuațiile ca string-uri - ezplot poate primi string-uri
    f1 = '(x/7)^2 * sqrt(abs(abs(x)-3)/(abs(x)-3)) + (y/3)^2 * sqrt(abs(y+3*sqrt(33)/7)/(y+3*sqrt(33)/7)) - 1';
    f2 = 'abs(x/2) - ((3*sqrt(33)-7)/112)*(x^2) - 3 - y + sqrt(1-(abs(abs(x)-2)-1)^2)';
    f3 = '9*sqrt(abs((abs(x)-1)*(abs(x)-0.75))/((1-abs(x))*(abs(x)-0.75))) - (8*abs(x) + y)';
    f4 = '3*abs(x) - y + 0.75*sqrt(abs((abs(x)-0.75)*(abs(x)-0.5))/((0.75-abs(x))*(abs(x)-0.5)))';
    f5 = '2.25*sqrt(abs((x-0.5)*(x+0.5))/((0.5-x)*(0.5+x))) - y';
    f6 = '6*sqrt(10)/7 + (1.5-0.5*abs(x))*sqrt(abs(abs(x)-1)/(abs(x)-1)) - 6*sqrt(10)/14 * sqrt(4-(abs(x)-1)^2) - y';

    % Plot-urile efective
    ezplot(f1,[-8 8 -3*sqrt(33)/7 6-4*sqrt(33)/7]);
    ezplot(f2,[-4 4]);
    ezplot(f3,[-1 -0.75 -5 5]);
    ezplot(f3,[0.75 1 -5 5]);
    ezplot(f4,[-0.75 0.75 2.25 5]);
    ezplot(f5,[-0.5 0.5 -5 5]);
    ezplot(f6,[-3 -1 -5 5]);
    ezplot(f6,[1 3 -5 5]);

    xlabel('');
    ylabel('');
    title('Poza (sigla) rapitor');
    hold off

end
