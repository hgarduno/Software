create table ModuloImpresion(IdModuloImpresion integer unique,
			     Modulo varchar(128));


create table Impresiones(IdModuloImpresion integer references ModuloImpresion(IdModuloImpresion),
			 IdCampo integer,
		         Campo	varchar(28),
			 primary key(IdModuloImpresion,IdCampo));

create table TiposCampo(IdTipoCampo integer unique,
			TipoCampo varchar(12));

create table TipoCampo(IdModuloImpresion integer references ModuloImpresion(IdModuloImpresion),
			IdCampo integer,
		        IdTipoCampo integer references TiposCampo(IdTipoCampo),
			primary key(IdModuloImpresion,IdCampo),
			foreign key(IdModuloImpresion,IdCampo) 
			references Impresiones(IdModuloImpresion,IdCampo));

create table PosicionesCampo(IdModuloImpresion integer,
			     IdCampo integer,
			     X		integer,
			     Y		integer,
			     AnchoX	integer,
			     AnchoY	integer,
			    foreign key(IdModuloImpresion,IdCampo) 
			    references Impresiones(IdModuloImpresion,IdCampo));


create table NombresCampoRegistro(IdModuloImpresion integer,
				  IdRegistro integer,
				  IdCampo integer,
				  Campo varchar(128),
				  foreign key(IdModuloImpresion,IdRegistro)
				  references Impresiones(IdModuloImpresion,IdCampo),
				  primary key(IdModuloImpresion,IdRegistro,IdCampo));

create table CamposRegistro(IdModuloImpresion integer,
			    IdRegistro integer,
			    IdCampo integer,
			    X	integer,
			    Y	integer,
			    AnchoX	integer,
			    AnchoY	integer,
			    foreign key(IdModuloImpresion,IdCampo)
			    references Impresiones(IdModuloImpresion,IdCampo),
			    foreign key(IdModuloImpresion,IdRegistro,IdCampo) 
			    references NombresCampoRegistro(IdModuloImpresion,IdRegistro,IdCampo));
