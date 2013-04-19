function decompress(compressed_file_name)
% Decomprimă fișierul compressed_file_name

    f = fopen(compressed_file_name, "r");
    
    n = fread(f, 1, "double");
    p = fread(f, 1, "double");
    fs = fread(f, 1, "double");
    bps = fread(f, 1, "double");

    [data, N] = fread(f, "double");

    fclose(f);

    audio = [ ];
    i = 0;
    while i < N
        q = min(2*p, N-i);
        if q == 2*p
            audio = [audio; predict(data(i+1:i+p),data(i+p+1:i+2*p),n)];
        else
            audio = [audio; data(i+1:i+q)];
        end
        i += 2*p;
    end

    filename_d = strcat(strtrunc(compressed_file_name,
        rindex(compressed_file_name,'.')-1), '2.wav');
    wavwrite(audio, fs, bps, filename_d);

end
