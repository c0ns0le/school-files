function writeResults(l, X, filename)
% Scrie rezultatele in fiesierul filename

    f = fopen(filename, 'w');

    n = length(l);
    fprintf(f, '%d\n', n);

    for i = 1 : n
        fprintf(f, '%f\n', l(i));
        for j = 1 : n
            fprintf(f, '%f ', X(j,i));
        end
        fprintf(f, '\n');
    end

    fclose(f);

end
