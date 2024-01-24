create table RegimenFiscal(IdConsecutivo serial,
			   Regimen integer primary key,
			   Descripcion text);

alter table expendios add constraint unique_idempresa unique(idempresa);
create table BodegaExpendio(IdEmpresa integer references expendios(idEmpresa),
			    IdBodega integer references bodegas(idBodega));
alter table ambientetimbrado add column RazonSocial text;
alter table empresas add column regimenfiscal integer references regimenfiscal(regimen);
create index IdPersona on personas using hash (idpersona);
create index IdPersona on telefonos using hash (idPersona);
create index idescuela on escuelas using hash (idescuela);
create index IdPersona_index on telefonos using hash (idPersona);
create index IdVenta_indice on ventas using hash(IdVenta);
create index CveProducto_indice on ventas using hash(cveproducto);

insert into BodegaExpendio values(-1165857915,0);
insert into BodegaExpendio values(-1165857915,1);

insert into RegimenFiscal(Regimen,Descripcion) values(601, 'General de Ley Personas Morales');
insert into RegimenFiscal(Regimen,Descripcion) values(603, 'Personas Morales con Fines no Lucrativos');
insert into RegimenFiscal(Regimen,Descripcion) values(605, 'Sueldos y Salarios e Ingresos Asimilados a Salarios');
insert into RegimenFiscal(Regimen,Descripcion) values(606, 'Arrendamiento');
insert into RegimenFiscal(Regimen,Descripcion) values(607, 'R�gimen de Enajenaci�n o Adquisici�n de Bienes');
insert into RegimenFiscal(Regimen,Descripcion) values(608, 'Dem�s ingresos');
insert into RegimenFiscal(Regimen,Descripcion) values(610, 'Residentes en el Extranjero sin Establecimiento Permanente en M�xico');
insert into RegimenFiscal(Regimen,Descripcion) values(611, 'Ingresos por Dividendos (socios y accionistas)');
insert into RegimenFiscal(Regimen,Descripcion) values(612, 'Personas F�sicas con Actividades Empresariales y Profesionales');
insert into RegimenFiscal(Regimen,Descripcion) values(614, 'Ingresos por intereses');
insert into RegimenFiscal(Regimen,Descripcion) values(615, 'R�gimen de los ingresos por obtenci�n de premios');
insert into RegimenFiscal(Regimen,Descripcion) values(616, 'Sin obligaciones fiscales');
insert into RegimenFiscal(Regimen,Descripcion) values(620, 'Sociedades Cooperativas de Producci�n que optan por diferir sus ingresos');
insert into RegimenFiscal(Regimen,Descripcion) values(621, 'Incorporaci�n Fiscal');
insert into RegimenFiscal(Regimen,Descripcion) values(622, 'Actividades Agr�colas, Ganaderas, Silv�colas y Pesqueras');
insert into RegimenFiscal(Regimen,Descripcion) values(623, 'Opcional para Grupos de Sociedades');
insert into RegimenFiscal(Regimen,Descripcion) values(624, 'Coordinados');
insert into RegimenFiscal(Regimen,Descripcion) values(625, 'R�gimen de las Actividades Empresariales con ingresos a trav�s de Plataformas Tecnol�gicas');
insert into RegimenFiscal(Regimen,Descripcion) values(626, 'R�gimen Simplificado de Confianza');
update empresas set rfc='SSC160604EF3',razonsocial='SISCOM Zacatenco' where razonsocial='SISCOM I.P.N.';
delete from empresas where idempresa=1509255252; --IPN Esime Zacatenco
alter table empresas add constraint razon_social_U Unique(razonsocial);
update ambientesfacturacionphp set binariophp ='php',scriptfacturacion='SiscomFacturacion4.php' ;
update ambientetimbrado set razonsocial ='INDISTRIA ILUMINADORA DE ALMACENES',rfcemisor='IIA040805DZ4'  where idambiente=2;
update ambientetimbrado set razonsocial ='SOLUCIONES EN SISTEMAS DE COMPUTO Y ELECTRONICA' where idambiente=3;
update empresas set rfc ='IPN811229H26' where idempresa=1534705937;
