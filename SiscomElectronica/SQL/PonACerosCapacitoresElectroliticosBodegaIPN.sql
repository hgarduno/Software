
update materialbodega set existencia=0 
where idbodega=0 and cveproducto in(
				    select cveproducto
				    from productos 
				    where cveproducto like 'CE%' and 
				      dscproducto like '%Electrolitico%');
  
