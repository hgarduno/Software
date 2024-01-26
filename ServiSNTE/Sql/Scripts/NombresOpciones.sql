select idmenu,
	nombre,
	modulo,
	valor as textomenu
from menus  inner join menuspropiedades using(idmenu)
where idtipopersona =0 and 
	idpropiedad = 0 and 
	idmenu>=0
order by idmenu
