
create table RegistroProgramaCurso(
			IdProgramacion integer unique,
			Programacion	varchar(56));

create table ProgramacionCursos(
		IdProgramacion	integer references RegistroProgramaCurso(IdProgramacion),
		IdCurso	integer	references cursos(idCurso),
		Fecha	date, --- La Fecha de inicio 
		primary key(IdProgramacion,IdCurso)
		);

