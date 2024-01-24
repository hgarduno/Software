create table InicioCurso(IdCurso integer references cursos(IdCurso),
			 Fecha date,
			 HoraInicio 	time,
			 HoraFin 	time,
			 IdProgramacion	integer); 
