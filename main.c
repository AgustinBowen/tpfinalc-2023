#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h> 
#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "includes/includes.h"

int main(int argc, char *argv[])
{
  
  obj_Localidad *localidad;
  obj_Socio *socio;
  obj_TipoActividad *tipoActividad;
  obj_Profesor *profesor;
  obj_Actividad *actividad;
  
  
  void *list,*itm;
  int i=0,size=0, sizeEnf=0;
  
  if(!init_config(argv[POS_CONFIG]))
  	 exit(-1);
  
  
  // ejemplo para agregar Localidad nueva.
  setDebug(true);
  /*soc = Socio_new();
  
  

  soc->setActivo(soc,true);
  soc->setApellido(soc,"Santander");
  soc->setNombres(soc,"Marcelo");
  soc->setDomicilio(soc,"moreno 222");
  soc->setDni(soc,30123456);
  soc->setObservaciones(soc,"");
  soc->setCodPostal(soc,9100);
  soc->setTelefono(soc,"15456789");
  soc->setMoroso(soc,false);
  if(!soc->saveObj(soc))
  {
  	printf("Ocurrio un error al agregar Localidad:\n%s\n",getLastError());
  }
  destroyObj(soc);
  */
  
  /*if(soc->findbykey(soc,1) != NOT_FOUND)
  {
  	soc->toString(soc);
  	//soc->setActivo(soc,true);
  	//soc->saveObj(soc);
  }
  destroyObj(soc);
  
  
  /*
  loc =  Localidad_new();
  loc->setId(loc,9121);
  loc->setNombre(loc,"Puerto Piramides");
  if(!loc->saveObj(loc))
  {
  	printf("Ocurrio un error al agregar Localidad:\n%s\n",getLastError());
  }
  destroyObj(loc);
  */
  
  // codigo para buscar por codigo y actualizar informacion
  /*
  loc =  Localidad_new();
  if(loc->findbykey(loc,9120) != NOT_FOUND)
  {
	  loc->setNombre(loc,"puerto madryn"); // Puerto Madryn
	  if(!loc->saveObj(loc))
	  {
	  	printf("Ocurrio un error al agregar Localidad:\n%s\n",getLastError());
	  }
  }
  destroyObj(loc);
  */
  // ejemplo para listar todas las localidades en el sistema
  /*
  loc =  Localidad_new();
  
  size = loc->findAll(loc,&list,NULL);
  for(i=0;i<size;++i)
  {
    itm = ((Object **)list)[i];    
    ((Object *)itm)->toString(itm);
  }
  destroyObjList(list,size);
  destroyObj(loc);
  
  
  size = soc->findAll(soc,&list,NULL);
  for(i=0;i<size;++i)
  {
    itm = ((Object **)list)[i];    
    ((Object *)itm)->toString(itm);
  }
  destroyObjList(list,size);
  destroyObj(soc);
 */
 
 
  /*void listarObjeto(void *obj){
	tipoActividad =  TipoActividad_new();
  
  	size = obj->findAll(obj,&list,NULL);
  	for(i=0;i<size;++i)
  	{
    	itm = ((Object **)list)[i];    
    	((Object *)itm)->toString(itm);
  	}
  	destroyObjList(list,size);
  	destroyObj(tipoActividad);
  	return;
  }	PARA SOLUCIONAR!!!!!!!*/
  /*-------------------------------INGRESAR ACTIVIDAD-------------------------------------*/   
   void ingresarActividad(){
  	int codigoTipoActividad;
  	int legajoProfesor;
	actividad = Actividad_new();
  	profesor = Profesor_new();
  	tipoActividad = TipoActividad_new();

  	/*-----------------------------------------------------------------------------------*/
  	
  	//LISTADO DE TIPO DE ACTIVIDAD CON SU CODIGO
  	//listarObjeto(tipoActividad); // MUESTRA LOS CODIGO PERO NO LOS NOMBRES, SOLUCIONAR!!!!!!!!!!
  	printf("Ingrese el codigo del tipo de actividad \n");
    scanf("%d",&codigoTipoActividad);
    fflush(stdin);
    if(tipoActividad->findbykey(tipoActividad,codigoTipoActividad) != NOT_FOUND){
        actividad->setCodTipoAct(actividad,codigoTipoActividad);	
	}else{
		printf("Tipo de actividad no encontrada \n");
	}

    printf("Ingrese el legajo del profesor \n");
    scanf("%d",&legajoProfesor);
   	fflush(stdin);
	if(profesor->findbykey(profesor,legajoProfesor) != NOT_FOUND){
	    actividad->setLegajoProfe(actividad,legajoProfesor);
	}else{
		printf("Profesor no encontrado \n");		
	}

  	if(!actividad->saveObj(actividad))
  	{
  		printf("Ocurrio un error al agregar Localidad:\n%s\n",getLastError());
  	}
  	destroyObj(actividad);
  }
  /*-----------------------------INGRESAR LOCALIDAD----------------------------------*/
  void ingresarLocalidad(){
	localidad =  Localidad_new();
	int codigoPostal;
	char nombre[60];
	
	printf("Ingrese el codigo postal de la localidad \n");
    scanf("%d",&codigoPostal);
    fflush(stdin);

	if(localidad->findbykey(localidad,codigoPostal) != NOT_FOUND){	
	    localidad->setId(localidad,codigoPostal);
  		printf("Ingrese el nombre de la localidad \n");
    	fgets(nombre, sizeof(nombre), stdin);
   		localidad->setNombre(localidad,nombre);
    	fflush(stdin);
		  
		if(!localidad->saveObj(localidad))
  		{
  			printf("Ocurrio un error al agregar Localidad:\n%s\n",getLastError());
  		}
    }else{
    	printf("La localidad ya se encuentra cargada \n");
	}
  	destroyObj(localidad);
  }
  /*-----------------------------INGRESAR PROFESOR-------------------------------------*/
  void ingresarProfesor(){
  	char nombre[20];
  	char apellido[20];
  	char domicilio[40];
  	char telefono[20];
  	int dni;

	profesor = Profesor_new();
	
	printf("Ingrese el dni del profesor \n");
    scanf("%d",&dni);
    fflush(stdin);
    if(profesor->findbykey(profesor,dni) != NOT_FOUND){ //PREGUNTAR PARA BUSCAR POR ATRIBUTO Y NO POR FUNCION
    	profesor->setDni(profesor,dni);
 		printf("Ingrese el nombre del profesor \n");
    	fgets(nombre, sizeof(nombre), stdin);
    	profesor->setNombres(profesor,nombre);
    
    	printf("Ingrese el apellido del profesor \n");
    	fgets(apellido, sizeof(apellido), stdin);
    	profesor->setApellido(profesor,apellido);
    
    	printf("Ingrese el domicilio del profesor \n");
    	fgets(domicilio, sizeof(domicilio), stdin);
    	profesor->setDomicilio(profesor,domicilio);
    
    	printf("Ingrese el telefono del profesor \n");
    	fgets(telefono, sizeof(telefono), stdin);
    	profesor->setTelefono(profesor,telefono);
    	profesor->saveObj(profesor);   
		
		if ( profesor->saveObj(profesor) == true ){
 			printf("Profesor ingresado correctamente!\n");
		}	
	}else{
		printf("El profesor ya se encuentra cargado \n");
	}
	destroyObj(profesor);
	return;
  }

  /*------------------------------INGRESAR TIPO ACTIVIDAD----------------------------------------*/  
  void ingresarTipoActividad(){
  	char nombre[20];

	tipoActividad = TipoActividad_new();
	printf("Ingrese el nombre de la actividad \n");
	fflush(stdin);
    fgets(nombre, sizeof(nombre), stdin);
    if(sizeof(nombre) != 0){
    	tipoActividad->setNombre(tipoActividad,nombre);
		tipoActividad->saveObj(tipoActividad);
		if ( tipoActividad->saveObj(tipoActividad) == true )
		{
 			printf("Tipo de actividad ingresada correctamente!\n");
		}	
	}else{
		printf("NO INGRESO NINGUN NOMBRE, REINTENTE \n");
	}

	destroyObj(tipoActividad);
	return;
  }
  /*-------------------------------MENU INGRESOS---------------------------------------*/     
  void menuIngresos(){
  	int opcion;
  	printf("[ Menu ingresos ]\n[ 1 - Tipo Actividad]\n[ 2 - Profesor]\n[ 3 - Localidad]\n[ 4 - Actividad]\n");
	do{
		scanf("%d",&opcion);
		switch(opcion){
			case 1:
				ingresarTipoActividad();
				break;
			case 2:
				ingresarProfesor();
				break;
			case 3:
				ingresarLocalidad();
				break;
			case 4:
				ingresarActividad();
				break;
			default:
				printf("Ingrese una opcion valida ingresos \n");					
		}
	}while (1);
	return;
  }	
  /*-------------------------------MENU GENERAL------------------------------------*/    
  void menuGeneral(){
  	int opcion;
  	printf("[ Menu general ]\n[ 1 - Ingresos]\n[ 2 - Actualizaciones]\n[ 3 - Listados ]\n[ 4 - Salir ]\n");
	do{
		scanf("%d",&opcion);
		switch(opcion){
			case 1:
				menuIngresos();
				break;
			case 2:
				return;
			/*case 3:
				menuListados();*/
			default:
				printf("Ingrese una opcion valida general \n");					
				break;
		}		
	}while (1);
  }	
  
  menuGeneral();
  return 0;
}
