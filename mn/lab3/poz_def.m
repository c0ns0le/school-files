function t = poz_def (A)
	 
	 ## usage: t = poz_def (A)
	 ## 
	 ## 
	 
	 t = min(eig(A)) > 0;
endfunction
