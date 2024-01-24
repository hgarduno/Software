select *
from 	pedidos as a
	inner join  estadodelpedido as b using(NumPedido) 
	inner join personas as c on (a.idCliente=c.idPersona) 
	inner join formapago as d using(NumPedido) 
where b.idEdoPedido=1 and
      cast (a.FechaRegistro as date)='2006-07-19';


