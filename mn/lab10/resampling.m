function [opx, opy] = resampling(px, py, n)

    pn = length(px);
    opx = linspace(px(1), px(pn), n);

    for i = 1:n
        opy(i) = lagrange(opx(i), px, py);
    end

end
