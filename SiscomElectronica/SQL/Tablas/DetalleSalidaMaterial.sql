create table DetalleSalidaMaterial(
		IdRegistro	integer references SalidaMaterial(IdRegistro),
		Clave		varchar(50),
		Cantidad	numeric(10,2));
