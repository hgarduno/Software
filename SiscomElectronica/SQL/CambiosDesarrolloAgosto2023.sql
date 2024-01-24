update empresas set rfc='SSC160604EF3',razonsocial='SISCOM Zacatenco' where razonsocial='SISCOM I.P.N.';
delete from empresas where idempresa=1509255252; --IPN Esime Zacatenco
alter table empresas add constraint razon_social_U Unique(razonsocial);
update ambientesfacturacionphp set binariophp ='php',scriptfacturacion='SiscomFacturacion4.php' ;
update ambientetimbrado set razonsocial ='INDISTRIA ILUMINADORA DE ALMACENES',rfcemisor='IIA040805DZ4'  where idambiente=2;
update ambientetimbrado set razonsocial ='SOLUCIONES EN SISTEMAS DE COMPUTO Y ELECTRONICA' where idambiente=3;
update empresas set rfc ='IPN811229H26' where idempresa=1534705937;
