select a.idventa,
	a.idcliente,
	b.total,
	c.pagototal,						
	c.pagoquincenal,					
	e.nombre as plazo,					
	f.tasa,							
	f.tasa*100 as porcentajetasa,
	g.*
from ventas as a inner join					
	importeventa as b using(idventa) inner join		
	ventacredito as c using(idventa) inner join 		
	financiadoras as d using(idfinanciadora) inner join 	
	plazos as e using(idplazo)  inner join			
	tasainteres as f on (e.idplazo=f.idplazo  and		
	c.idfinanciadora=f.idfinanciadora) inner join
	personas as g on g.idpersona=a.idcliente
where idcliente in (select idcliente 
		    from ventas as a inner join 
		    	  ventacredito using(idventa) 
		    where idtipoventa =2 and idfinanciadora=4
		    ) and 			
	 idtipoventa=2
