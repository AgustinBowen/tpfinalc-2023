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
  obj_Lugar *lugar;
  
  
  void *list,*itm;
  int i=0,size=0, sizeEnf=0;
  
  if(!init_config(argv[POS_CONFIG]))
  	 exit(-1);
  
  
  // ejemplo para agregar Localidad nueva.
  //setDebug(true);
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
    void listar(void *obj){
		size = ((Object *)obj)->findAll(obj,&list,NULL);
		for(i=0;i<size;++i)
  		{
    		itm = ((Object **)list)[i];    
    		((Object *)itm)->toString(itm);
  		}
  		destroyObjList(list,size);	
	} 
   /*-------------------------------ACTUALIZAR LUGAR-------------------------------------*/	
  	void actualizarLugar(){
		lugar = Lugar_new();
		int codigo;  
		char nombre[60];		
  		
  		listar(lugar);
		printf("Ingrese el codigo del lugar que quiere modificar:");
		fflush(stdin);
		scanf("%d",&codigo);
		if(lugar->findbykey(lugar,codigo) != NOT_FOUND){
			printf("Ingrese la nueva descripcion del lugar:");
			fflush(stdin);		
			gets(nombre);	
	  		lugar->setNombre(lugar,nombre);
	  		if(!lugar->saveObj(lugar)){
	  			printf("Ocurrio un error al actualizar el tipo de actividad:\n%s\n",getLastError());
	  		}
 		}
 		destroyObj(lugar);		 
  		system("cls");	
		return;
  	} 
  /*-------------------------------ACTUALIZAR LOCALIDAD-------------------------------------*/	
  	void actualizarLocalidad(){
		localidad = Localidad_new();
		int codigoPostal;  
		char nombre[60];		
  		
  		listar(localidad);
		printf("Ingrese el codigo postal de la localidad que quiere modificar:");
		fflush(stdin);
		scanf("%d",&codigoPostal);
		if(localidad->findbykey(localidad,codigoPostal) != NOT_FOUND){
			printf("Ingrese el nuevo nombre de la localidad:");
			fflush(stdin);		
			gets(nombre);	
	  		localidad->setNombre(localidad,nombre);
	  		if(!localidad->saveObj(localidad)){
	  			printf("Ocurrio un error al actualizar el tipo de actividad:\n%s\n",getLastError());
	  		}
 		}
 		destroyObj(localidad);		 
  		system("cls");	
		return;
  	} 
   /*-------------------------------ACTUALIZAR PROFESOR-------------------------------------*/  	
	void modificarDniProfesor(int codigo){
		int legajo = codigo,dni;
		if(profesor->findbykey(profesor,legajo) != NOT_FOUND){
			printf("Ingrese el nuevo dni:");
			fflush(stdin);		
			scanf("%d",&dni);	
	  		profesor->setDni(profesor,dni);
	  		if(!profesor->saveObj(profesor)){
	  			printf("Ocurrio un error al actualizar el tipo de actividad:\n%s\n",getLastError());
	  		}
 		}
  		system("cls");		 			
	}
	void modificarTelefonoProfesor(int codigo){
		int legajo = codigo;
		char telefono[80];
		if(profesor->findbykey(profesor,legajo) != NOT_FOUND){
			printf("Ingrese el nuevo telefono:");
			fflush(stdin);		
			gets(telefono);	
	  		profesor->setTelefono(profesor,telefono);
	  		if(!profesor->saveObj(profesor)){
	  			printf("Ocurrio un error al actualizar el tipo de actividad:\n%s\n",getLastError());
	  		}
 		}
  		system("cls");		 			
	}	
	
	void modificarNombresProfesor(int codigo){
		int legajo = codigo;
		char nombres[80];
		if(profesor->findbykey(profesor,legajo) != NOT_FOUND){
			printf("Ingrese el nuevo nombre:");
			fflush(stdin);		
			gets(nombres);	
	  		profesor->setNombres(profesor,nombres);
	  		if(!profesor->saveObj(profesor)){
	  			printf("Ocurrio un error al actualizar el tipo de actividad:\n%s\n",getLastError());
	  		}
 		}
  		system("cls");		 			
	}	
	
	void modificarDomicilioProfesor(int codigo){
		int legajo = codigo;
		char domicilio[120];
		if(profesor->findbykey(profesor,legajo) != NOT_FOUND){
			printf("Ingrese el nuevo domicilio:");
			fflush(stdin);		
			gets(domicilio);	
	  		profesor->setDomicilio(profesor,domicilio);
	  		if(!profesor->saveObj(profesor)){
	  			printf("Ocurrio un error al actualizar el tipo de actividad:\n%s\n",getLastError());
	  		}
 		}
  		system("cls");		 			
	}
		
	void modificarApellidoProfesor(int codigo){
		int legajo = codigo;
		char apellido[90];

		if(profesor->findbykey(profesor,legajo) != NOT_FOUND){
			printf("Ingrese el nuevo apellido:");
			fflush(stdin);		
			gets(apellido);	
	  		profesor->setApellido(profesor,apellido);
	  		if(!profesor->saveObj(profesor)){
	  			printf("Ocurrio un error al actualizar el tipo de actividad:\n%s\n",getLastError());
	  		}
 		}	
		system("cls"); 		
	}   

  	void actualizarProfesor(){
 		profesor = Profesor_new();  		
		int legajo,opcion;  		
		system("cls");
		listar(profesor);
		printf("Ingrese el legajo del profesor que quiere modificar:");
		fflush(stdin);
		scanf("%d",&legajo);
		if(profesor->findbykey(profesor,legajo) != NOT_FOUND){
  			printf("[ Menu profesor ]\n[ 1 - DNI]\n[ 2 - Nombres]\n[ 3 - Apellido]\n[ 4 - Domicilio]\n[ 5 - Telefono]\n[ 6 - Volver]\n");
  			scanf("%d",&opcion);
			switch(opcion){
				case 1:
					modificarDniProfesor(legajo);
					break;
				case 2:
					modificarNombresProfesor(legajo);
					break;
				case 3:
					modificarApellidoProfesor(legajo);
					break;
				case 4:
					modificarDomicilioProfesor(legajo);
					break;
				case 5:
					modificarTelefonoProfesor(legajo);
					break;
				case 6:
					return;						
				default:
					printf("Ingrese una opcion valida");																
			}  
 		}
		destroyObj(profesor);		 			
  	}	

  /*-------------------------------ACTUALIZAR TIPO ACTIVIDAD-------------------------------------*/
  	void actualizarTipoActividad(){
		tipoActividad = TipoActividad_new();  		
		char nombre[20];
  		int codigo;
  		
  		listar(tipoActividad);
		printf("Ingrese el codigo del tipo de actividad que quiere modificar:");
		fflush(stdin);
		scanf("%d",&codigo);
		if(tipoActividad->findbykey(tipoActividad,codigo) != NOT_FOUND){
			printf("Ingrese la nueva descripcion del tipo de actividad:");
			fflush(stdin);		
			fgets(nombre, sizeof(nombre), stdin);	
	  		tipoActividad->setNombre(tipoActividad,nombre);
	  		if(!tipoActividad->saveObj(tipoActividad)){
	  			printf("Ocurrio un error al actualizar el tipo de actividad:\n%s\n",getLastError());
	  		}	
 		}
		return;
		destroyObj(tipoActividad);
  	}  
  /*-------------------------------INGRESAR ACTIVIDAD-------------------------------------*/   
    void ingresarActividad(){
  		int codigoTipoActividad;
  		int legajoProfesor;
		actividad = Actividad_new();
  		profesor = Profesor_new();
  		tipoActividad = TipoActividad_new();
  		
		printf("Ingrese el codigo del tipo de actividad:");
   		scanf("%d",&codigoTipoActividad);
		fflush(stdin);

    	printf("Ingrese el legajo del profesor:");
    	scanf("%d",&legajoProfesor);
		fflush(stdin);

  		if(!actividad->saveObj(actividad))
  		{
  			printf("Ocurrio un error al agregar la actividad:\n%s\n",getLastError());
  		}
  		destroyObj(actividad); 
  	}
  /*-----------------------------INGRESAR LUGAR----------------------------------*/
  	void ingresarLugar(){
		char nombre[90];
		lugar = Lugar_new();
		
		printf("Ingrese la descripcion del lugar:");
    	fflush(stdin);		
    	fgets(nombre, sizeof(nombre), stdin);
   		lugar->setNombre(lugar,nombre);
    	fflush(stdin);
		  
		if(!lugar->saveObj(lugar)){
  			printf("Ocurrio un error al agregar Localidad:\n%s\n",getLastError());
  		}
     	destroyObj(lugar); 		
  	}  	
  /*-----------------------------INGRESAR LOCALIDAD----------------------------------*/
  	void ingresarLocalidad(){
		int codigoPostal;
		char nombre[60];
		localidad = Localidad_new();
	
		printf("Ingrese el codigo postal de la localidad:");
    	scanf("%d",&codigoPostal);
    	fflush(stdin);	
		localidad->setId(localidad,codigoPostal);
  	
		printf("Ingrese el nombre de la localidad:");
    	fgets(nombre, sizeof(nombre), stdin);
   		localidad->setNombre(localidad,nombre);
    	fflush(stdin);
		  
		if(!localidad->saveObj(localidad)){
  			printf("Ocurrio un error al agregar Localidad:\n%s\n",getLastError());
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
	
		printf("Ingrese el dni del profesor:");
    	scanf("%d",&dni);
    	fflush(stdin);
    	profesor->setDni(profesor,dni);
 		printf("Ingrese el nombre del profesor:");
    	fgets(nombre, sizeof(nombre), stdin);
    	profesor->setNombres(profesor,nombre);
    
    	printf("Ingrese el apellido del profesor:");
    	fgets(apellido, sizeof(apellido), stdin);
    	profesor->setApellido(profesor,apellido);
    
    	printf("Ingrese el domicilio del profesor:");
    	fgets(domicilio, sizeof(domicilio), stdin);
    	profesor->setDomicilio(profesor,domicilio);
    
    	printf("Ingrese el telefono del profesor:");
    	fgets(telefono, sizeof(telefono), stdin);
    	profesor->setTelefono(profesor,telefono);
    	profesor->saveObj(profesor);   
		
		if(!profesor->saveObj(profesor)){
  			printf("Ocurrio un error al agregar el profesor:\n%s\n",getLastError());
  		}
		return;
  		destroyObj(profesor);
  	}

  /*------------------------------INGRESAR TIPO ACTIVIDAD----------------------------------------*/  
  	void ingresarTipoActividad(){
  		char nombre[20];
		tipoActividad = TipoActividad_new();
		
		printf("Ingrese el nombre de la actividad \n");
		fflush(stdin);
    	fgets(nombre, sizeof(nombre), stdin);
    	tipoActividad->setNombre(tipoActividad,nombre);
		tipoActividad->saveObj(tipoActividad);
	
		if(!tipoActividad->saveObj(tipoActividad)){
  			printf("Ocurrio un error al agregar el tipo de actividad:\n%s\n",getLastError());
  		}	
		return;
		destroyObj(tipoActividad);
  	}
  /*-------------------------------MENU ACTUALIZAR---------------------------------------*/     
  	void menuActualizar(){
  		int opcion;
		do{
			system("cls");
  			printf("[ Menu actualizar ]\n[ 1 - Tipo Actividad]\n[ 2 - Profesor]\n[ 3 - Localidad]\n[ 4 - Actividad]\n[ 5 - Lugar]\n[ 11 - Volver]\n");			
			scanf("%d",&opcion);
			switch(opcion){
				case 1:
					actualizarTipoActividad();
					break;
				case 2:
					actualizarProfesor();
					break;
				case 3:
					actualizarLocalidad();
					break;
				case 5:
					actualizarLugar();
					break;					
				case 11:
					system("cls");
					return;										
				default:
					printf("Ingrese una opcion valida ingresos \n");					
			}
		}while (1);
  	}  	
  /*-------------------------------MENU INGRESOS---------------------------------------*/     
  	void menuIngresos(){
  		int opcion;
  		do{
  			system("cls");
   			printf("[ Menu ingresos ]\n[ 1 - Tipo Actividad]\n[ 2 - Profesor]\n[ 3 - Localidad]\n[ 4 - Actividad]\n[ 5 - Lugar]\n[ 6 - Volver]\n");
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
				case 5:
					ingresarLugar();
					break;					
				case 6:
					system("cls");
					return;					
				default:
					printf("Ingrese una opcion valida ingresos \n");					
    		}  			
		}while(1);
  	}	
  /*-------------------------------MENU GENERAL------------------------------------*/    
  	void menuGeneral(){
  		int opcion;
  		do{
    		printf("[ Menu general ]\n[ 1 - Ingresos]\n[ 2 - Actualizaciones]\n[ 3 - Listados ]\n[ 4 - Salir ]\n");
			scanf("%d",&opcion);
			switch(opcion){
				case 1:
					menuIngresos();
					break;
				case 2:
					menuActualizar();
					break;
				/*case 3:
					menuListados();*/
				case 4:
					return;
				default:
					printf("Ingrese una opcion valida general \n");					
					break;
			}			
		}while(1);		
 	 }	
  
  	menuGeneral();
  return 0;
}
