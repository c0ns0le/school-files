function t = cholesky (A)
  	 
  ## usage: t = cholesky (A)
  ## 
  ## 

  if sym(A) && poz_def(A)
    t = 1;
  else
    t = 0;
  end
	 
endfunction
