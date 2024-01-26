select *,
	CASE WHEN c.idproducto is null THEN 0
	else
	 a.existencia
	END as stock

from existencia as a inner join					
     productos as b using(idproducto) left outer join		
     productostock	as c using(idproducto) inner join	
	productoproveedor as d using(idproducto) inner join 	
	empresas as e using(idempresa)				
order by a.existencia desc

