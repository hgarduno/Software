select a.*,
	b.nombre,
	c.maquina	
from maquinas as a  inner join
     tiendas  as b on a.idmaquina=b.idtienda left outer join
     arquitecturamaquinas as c on a.idmaquina=c.idmaquina

--where a.idmaquina in (8,9,18,20,21,46,37)
where a.idmaquina in (46,37,18,20) --Maquinas Activas
order by nombre
