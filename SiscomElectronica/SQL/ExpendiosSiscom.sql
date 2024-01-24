select idempresa as idmaquina,
	diripsvrad as dirip,
	b.puerto,
	'Servidor' as tipoequipo
from expendios as a inner join 
     servidoressiscom4 as b using(idempresa) 
where idempresa != (select idempresa from matriz)
union 
select idempresa as idmaquina,
	diripsvrad as dirip,
	b.puerto,
	'Matriz' as tipoequipo
from matriz as a inner join 
	servidoressiscom4 as b using(idempresa) inner join 
	expendios as c using(idempresa)
order by idmaquina
	

