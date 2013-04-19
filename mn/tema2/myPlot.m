function myPlot(X)
% Reprezintă grafic vectorii proprii normalizați
%      pentru fiecare valoare proprie

    [n, n] = size(X);

    x = [ 0 : n ];
    x_ = [ 0 : 0.01 : n ];

    for i = 1 : n
        y = X(:, i)';

        y = [ 0, y ];
        spl = interp1(x, y, x_, "spline");
        subplot(1, n, i);
        plot(spl, x_);
    end

end
