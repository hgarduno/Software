create table AmbienteTimbrado(IdAmbiente integer primary key,
			      Usuario varchar(125),
			      URLServidor varchar(256),
			      RFCEmisor varchar(20));

create table AmbienteActivoTimbrado(IdAmbiente integer references AmbienteTimbrado(IdAmbiente),
				    Descripcion varchar(50));
