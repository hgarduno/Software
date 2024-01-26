select idplazo,								
	folio,								
	fecha,								
	idfinanciadora,							
	idventa,							
	idtipoventa,							
	c.nombre as NomTipoVenta,					
	total,								
	e.nombre as financiadora,					
	f.nombre as plazo						
from ventas as a  inner  join						
     importeventa as b using(idventa) inner join			
     tipoventas as c using(idtipoventa)   left outer join		
     ventacredito as d using(idventa) left outer join			
     financiadoras as e using(idfinanciadora) left outer join		
     plazos as f using(idplazo)						
where idcliente in (select  idpersona					
		    from personas 					
		    where rfc='CUBM790205DH2');
