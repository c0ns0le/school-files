%
% Nume: Duma Andrei Dorian
% Grupa: 315CA
%

function new_brightness = brightness(input_img_path, x)
    new_brightness = 0;

    % Reading the image from file
    img = imread(input_img_path);

    img = min(255, max(0, img + x));

    new_brightness = mean(mean(img));
end
