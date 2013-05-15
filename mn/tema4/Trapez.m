function I = Trapez(x,y)

    % ne asigurăm că x și y sunt vectori coloană
    if isrow(x)
        x = x';
    end

    if isrow(y)
        y = y';
    end

    % numărul de puncte
    n = length(x);

    % y rotit spre stânga cu o poziție
    _y = [y(2:n);y(1)];

    % y rotit spre dreapta cu o poziție
    y_ = [y(n);y(1:n-1)];

    I = sum(x.*_y - x.*y_)/2;

end
