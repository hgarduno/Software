create table HorariosCursos(
			IdCurso		integer references Cursos(IdCurso),
			Fecha		date,
			HoraInicio 	time,
			HoraFin		time);
