create table CargoResponsable(
			idPersona	integer references Personas(idPersona),
			Cargo		text);
			
