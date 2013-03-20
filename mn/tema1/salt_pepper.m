%
% Nume: Duma Andrei Dorian
% Grupa: 315CA
%

function salt_pepper(input_img_path, mask, output_img_path)

    % Reading the image from file
    img = imread(input_img_path);

    % Coordinates of 'broken' pixels
    [xs, ys] = find(mask);

    for i=1:length(xs)
        x=xs(i);
        y=ys(i);

        % Mean of the 8 adjacent pixels
        img(x,y,:)=floor((sum(sum(img(x-1:x+1,y-1:y+1,:))) \
                        - int16(img(x,y,:)))/8);
    end

    imwrite(img, output_img_path);

end
