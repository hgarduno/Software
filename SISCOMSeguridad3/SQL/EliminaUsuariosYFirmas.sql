
delete 
from firmas
where idUsuario in( select idUsuario
		    from usuarios
		    where idAplicacion in(select idAplicacion
		                          from aplicaciones
		                          where nmbaplicacion='SISCOMClinicas2'));
delete 
from usuarios
where idUsuario in( select idUsuario
		    from usuarios
		    where idAplicacion in(select idAplicacion
		                          from aplicaciones
		                          where nmbaplicacion='SISCOMClinicas2'));

