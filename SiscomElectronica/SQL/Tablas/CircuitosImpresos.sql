create table CircuitoImpreso(IdImpreso integer unique,
			     IdVenta integer,
			     IdPersona integer references personas(idpersona),
			     CveProducto varchar(125)
			     references productos(cveproducto));

create table CircuitoImpresoInformacion(IdImpreso integer references CircuitoImpreso(IdImpreso),
					Archivo text,
					Memoria text);


create table EstadosCircuitoImpreso(IdEstado integer unique ,
				    Descripcion varchar(125));
create table EstadoCircuitoImpreso(IdImpreso integer references CircuitoImpreso(IdImpreso),
				   IdEstado integer references EstadosCircuitoImpreso(IdEstado),
				   Fecha timestamp without time zone,
				   primary key(IdImpreso,IdEstado));
create table UltimoEstadoCircuitoImpreso(
			IdImpreso integer references CircuitoImpreso(IdImpreso),
			IdEstado integer references EstadosCircuitoImpreso(IdEstado));

create table FechaEntregaImpreso(IdImpreso integer unique references CircuitoImpreso(IdImpreso),
				 Fecha timestamp without time zone);
				   


