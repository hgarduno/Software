alter table ProgramacionCursos 
	add constraint llave_primaria 
	primary key(idprogramacion,idcurso,fecha);
alter table FechasCursos 
	add constraint ProgramacionCursosPKey
	primary key(idcurso,fecha);

alter table HorariosCursos 
	add constraint HorariosCursosPKey
	primary key(idcurso,fecha);
