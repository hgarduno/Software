create table SalidaMaterial(
		IdRegistro	integer unique,
		IdMotivo	integer references MotivosSalidaMaterial(IdMotivo),
		Fecha		timestamp without time zone);
