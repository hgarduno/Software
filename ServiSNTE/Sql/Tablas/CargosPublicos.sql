create table CargosPublicos(IdCargoPublico integer unique,
                Especificacion varchar(120),
                Dependencia varchar(120),
                Puesto varchar(30),
                PrincipalesFunciones varchar(120),
                PeriodoEjercicio varchar(120));

create table CargoPublicoPersona(IdPersona integer references Personas(IdPersona),
				 IdCargoPublico integer references CargosPublicos(IdCargoPublico));
