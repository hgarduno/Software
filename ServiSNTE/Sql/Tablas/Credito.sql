create table TasaInteres(IdTasa integer unique,
			 IdFinanciadora integer references 
			 		Financiadoras(idFinanciadora),
			 IdPlazo integer references Plazos(idplazo),
			Tasa float);

create table NumeroCreditos(IdNumeroCreditos integer unique,
			    Numero	integer,
			    IdFinanciadora integer references 
			    Financiadoras(IdFinanciadora));
