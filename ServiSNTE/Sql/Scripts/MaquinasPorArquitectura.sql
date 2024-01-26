select idmaquina,
	Maquina,
	kernel,
	a.nombre as equipo,
	dirip,
	puerto,
	c.nombre as tienda
from arquitecturamaquinas as a inner join
	maquinas as b using(idmaquina) left outer join
	tiendas as c on a.idmaquina=c.idtienda

		
