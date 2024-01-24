create table EscuelaPrincipalExpendio(IdExpendio integer references Empresas(IdEmpresa),
				      IdEscuela integer references Escuelas(IdEscuela));
