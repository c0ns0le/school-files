function L = chol_fact (A)
	 
	 ## usage: L = chol_fact (A)
	 ## 
	 ## 
	 
	 n = length(A);
	 L = zeros(n);

	 for i=[1:n]
	     L(i,i) = sqrt(A(i,i) - L(i,1:i-1)*transpose(L(i,1:i-1)));
	     for j=[1:i-1]
		 L(i,j) = (A(i,j) - L(i,1:i-1)*transpose(L(j,1:i-1))) / L(j,j);
	     end
	 end

endfunction
