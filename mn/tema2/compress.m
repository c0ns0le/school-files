function compress(filename)
% Comprimă fișierul audio dat de filename
% Rezultatul se pune în filename.compressed

    n = 160;
    p = 27;

    [raw, fs, bps] = wavread(filename);

    filename_c = strcat(strtrunc(filename,
        rindex(filename,'.')), 'compressed');

    f = fopen(filename_c, "w");

    fwrite(f, [n, p, fs, bps], "double");

    N = length(raw);
    i = 0;
    while i < N
        q = min(n, N-i);
        if q >= 2*p
            fwrite(f, raw(i+1:i+p), "double");
            [r0, r] = mycor(raw(i+1:i+q), p);
            a = levinson(r0, r);
            fwrite(f, a, "double");
        else
            fwrite(f, raw(i+1:i+q), "double");
        end
        i += n;
    end

    fclose(f);

end
