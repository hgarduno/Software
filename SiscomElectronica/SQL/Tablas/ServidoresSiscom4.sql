create table ServidoresSiscom4(IdEmpresa integer references empresas(idempresa),
			       puerto integer, primary key(IdEmpresa,Puerto));
