create table ReferenciaPersonal(IdReferencia integer unique,
				IdPersona integer unique references Personas(IdPersona));
create table PersonaReferencia(
                IdReferencia integer references ReferenciaPersonal(IdReferencia),
                IdPersona integer references Personas(Idpersona), 
                Parentesco varchar(20));
Create table TelefonoReferencia(
                IdReferencia integer references ReferenciaPersonal(IdReferencia),
		IdPersona integer references Personas(IdPersona),
		IdTelefono integer references Telefonos(IdTelefono));
create table DireccionesReferencia(
                IdReferencia integer references ReferenciaPersonal(IdReferencia),
		IdPersona integer references Personas(IdPersona), 
                IdDireccion integer references Direcciones(IdDireccion));


