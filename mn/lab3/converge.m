function t = converge (A)

  ## usage: t = converge (A)
  ## 
  ## 
	 
  if poz_def(A) || diag_dom(A)
    t = 1;
  else
    t = 0;
  end

endfunction
