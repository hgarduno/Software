create table Camiones(IdCamion integer unique,
		      Nombre varchar(60),
		      Marca varchar(40),
		      Tipo varchar(40),
		      Modelo integer,
		      Placas varchar(30));

create table EstatusCamion(IdCamion integer references Camiones(IdCamion),
			    IdEstatus integer references Estatus(IdEstatus));
