%
% Nume: Duma Andrei Dorian
% Grupa: 315CA
%

function h = histogram(input_img_path)
    h = zeros(1, 256);
    
    % Reading the image from file
    img = imread(input_img_path);

    for i = [1:256]
	    h(i) = sum( sum( img == (i - 1) ) );
    end
end
