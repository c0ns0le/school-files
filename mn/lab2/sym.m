function t = sym (A)
	 
	 ## usage: t = sym (A)
	 ## 
	 ## 
	 
	 t = norm(A-transpose(A), 1) == 0;
endfunction
