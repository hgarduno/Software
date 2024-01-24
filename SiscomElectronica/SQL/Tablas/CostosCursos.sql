-- IdEstatus 
-- 	0 Precio normal
-- 	1 Precio especial para identificar a dos alumnos que se inscriben a un curso
--	2 Precio especial alumno que se inscribe a 2 cursos
--

create table CostosCursos(
		IdCurso integer references cursos(idcurso),
		IdEstatus	integer references ExplicacionPromocion(idestatus),
		Costo		numeric(7,2));


