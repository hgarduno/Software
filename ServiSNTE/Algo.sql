 select a.idregistro,				
 		a.idcampo,								
		a.campo,								
		x,									
		y,									
		anchox,									
		anchoy									
from nombrescamporegistro as a inner join					
     camposregistro as b on (a.idmoduloimpresion=b.idmoduloimpresion and 	
                             a.idregistro=b.idregistro and 			
			     a.idcampo=b.idcampo)				
where a.idregistro in (select idcampo 						
                       from tipocampo 						
		       where idtipocampo=1) 					
     and a.idmoduloimpresion=10
