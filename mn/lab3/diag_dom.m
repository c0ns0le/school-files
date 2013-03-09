function t = diag_dom (A)
	 
	 ## usage: t = diag_dom (A)
	 ## 
	 ## 

	 for i = [1:length(A)]
	   if norm(A(i,:),1) > 2*abs(diag(A)(i))
	     t = 0;
	     return
	   endif
	 endfor

	 t = 1;
endfunction
