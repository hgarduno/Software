--select * 						
--from servidores as a inner join
--     maquinas using(idmaquina) left outer join
--     servidoractivo using(idmaquina) inner join 
--     tiendas as d on a.idmaquina=d.idtienda
--where servidoractivo.activo=1

select * 
from servidoractivo as a inner join 
	maquinas as b using(idmaquina) inner join 
	servidores as c using(idmaquina) left outer join 
	tiendas as d on a.idmaquina=d.idtienda 
where activo = 1;
