create table CoberturasJTExpress(IdCobertura serial primary key,
				 CP		integer,
				 Municipio 	varchar(128),
				 Estado		varchar(58),
				 Cobertura	varchar(2),
				 Dias		integer);

create table EntreCalles(idPersona integer,
			          Calle1 varchar(128),
			          Calle2 varchar(128));
