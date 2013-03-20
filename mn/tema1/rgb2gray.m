%
% Nume: Duma Andrei Dorian
% Grupa: 315CA
%

function rgb2gray(input_img_path, output_img_path)
    % Reading the image from file
    img = imread(input_img_path);

    % Grayscaling
    gray_img = floor( 0.2989 * img(:,:,1) + 0.5870 * img(:,:,2) + 0.1140 * img(:,:,3) );

    % Writing the output to file
    imwrite(gray_img, output_img_path);

end
