function g = lagrange(x, px, py)

    n = length(px);

    g = 0;

    for i = 1:n
        pr = py(i);
        for j = 1:n
            if j ~= i
                pr *= (x-px(j))/(px(i)-px(j));
            end
        end
        g += pr;
    end

end
