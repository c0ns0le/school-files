function grafice(px, py, n)

    [opx, opy] = resampling(px, py, n);

    subplot(1, 2, 1);

    plot(px, py);

    subplot(1, 2, 2);

    plot(opx, opy);

end
