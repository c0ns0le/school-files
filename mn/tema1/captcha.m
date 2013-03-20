%
% Nume: Duma Andrei Dorian
% Grupa: 315CA
%

function str = captcha(input_img_path)
    str = "";

    % Reading the image from file
    img = imread(input_img_path);

    global HTable

    % Populate the hash table
    ls = readdir("letter_images/");
    for d=3:length(ls)
        pth=strcat("letter_images/",ls{d},"/");
        fs = readdir(pth);
        for i=3:length(fs)
            im=imread(strcat(pth,fs{i}));
            HTable{hash(im)} = tolower(ls{d});
        end
    end

    % Make it black&white
    img_gray = (img(:,:,1)==255) & (img(:,:,2)==255) & (img(:,:,3)==255);

    % Extract letters from files
    col = 1;
    let = 0;
    [height,len] = size(img_gray);
    while col<=len
        if not(is_white(img_gray(:,col)))
            col_end = col;
            while col_end<=len && not(is_white(img_gray(:,col_end)))
                col_end++;
            end
            str = strcat(str, detect(img_gray(:,col:col_end-1)));

            col = col_end;
        else
            while col<=len && is_white(img_gray(:,col))
                col++;
            end
        end
    end
end

function b = is_white(v)
    b = (min(v)==1);
end

function s = detect(img)
    global HTable

    [n,m] = size(img);
    first = 1;
    last = n;

    % Trim white lines from top and bottom
    while is_white(img(first,:))
        first++;
    end
    while is_white(img(last,:))
        last--;
    end

    s = HTable{hash(img(first:last,:))};
end

function h = hash(img)
    h = mod(sum(diag((13*img*img'+17)^5)), 196613);
end
