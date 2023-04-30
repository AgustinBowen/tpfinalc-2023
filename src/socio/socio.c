#include "../../includes/includelib.h"
#include "../localidad/localidad.h"
#include "socio.h"

THIS(obj_Socio)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_SocioImpl(void *self)
{
     obj_Socio *obj=this(self);     
     obj_Localidad *loc = obj->getLocalidadObj(obj);
     // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
     printf("Nro.Socio: %d - Apellido,Nombres:%s,%s - Activo:%d  - Localidad:%s\n",
	 obj->getNroSocio(obj), 
	 obj->getApellido(obj), 
	 obj->getNombres(obj),
	 obj->getActivo(obj),
	 loc->getNombre(loc)
	 ); // 1:true(en la base) - 0:false(en la base) -- activo / moroso
}
//----------------------------------------------------
//implementacion de getters
//----------------------------------------------------
static int getNroSocio_Impl(void *self)
{ return *((int *) getValue(self,POS_ID)); }
//----------------------------------------------------
static int getDniSocio_Impl(void *self)
{ return *((int *) getValue(self,POS_DNI_SOC)); }
//----------------------------------------------------
static char *getNombresSocio_Impl(void *self)
{ return  (char *) getValue(self,POS_NOMBRES_SOC); }
//----------------------------------------------------
static char *getApellidoSocio_Impl(void *self)
{ return  (char *) getValue(self,POS_APELLIDO_SOC); }
//----------------------------------------------------
static char *getDomicilioSocio_Impl(void *self)
{ return  (char *) getValue(self,POS_DOMICILIO_SOC); }
//----------------------------------------------------
static char *getTelefonoSocio_Impl(void *self)
{ return  (char *) getValue(self,POS_TELEFONO_SOC); }
//----------------------------------------------------
static int getCodPostalSocio_Impl(void *self)
{ return *( (int *) getValue(self,POS_COD_POSTAL_SOC)); }
//----------------------------------------------------
static char *getObservacionesSocio_Impl(void *self)
{ return  (char *) getValue(self,POS_OBS_SOC); }
//----------------------------------------------------
static int getActivoSocio_Impl(void *self)
{ return *( (int *) getValue(self,POS_ACTIVO_SOC)); }
//----------------------------------------------------
static int getMorosoSocio_Impl(void *self)
{ return *( (int *) getValue(self,POS_MOROSO_SOC)); }
//----------------------------------------------------
//implementacion setters
//----------------------------------------------------
static void setNroSocio_Impl(void *self,int val)
{ setValue(self,POS_ID,&val); }
//----------------------------------------------------
static void setDniSocio_Impl(void *self,int val)
{ setValue(self,POS_DNI_SOC,&val); }
//----------------------------------------------------
static void setNombresSocio_Impl(void *self,char *nombres_Socio)
{ setValue(self,POS_NOMBRES_SOC,nombres_Socio); }
//----------------------------------------------------
static void setApellidoSocio_Impl(void *self,char *apellido_Socio)
{ setValue(self,POS_APELLIDO_SOC,apellido_Socio); }
//----------------------------------------------------
static void setDomicilioSocio_Impl(void *self,char *domicilio_Socio)
{ setValue(self,POS_DOMICILIO_SOC,domicilio_Socio); }
//----------------------------------------------------
static void setTelefonoSocio_Impl(void *self,char *telefono_Socio)
{ setValue(self,POS_TELEFONO_SOC,telefono_Socio); }
//----------------------------------------------------
static void setCodPostalSocio_Impl(void *self,int val)
{ setValue(self,POS_COD_POSTAL_SOC,&val); }
//----------------------------------------------------
static void setObservacionesSocio_Impl(void *self,char *obs)
{ setValue(self,POS_OBS_SOC,obs); }
//----------------------------------------------------
static void setActivoSocio_Impl(void *self,int val)
{ setValue(self,POS_ACTIVO_SOC,&val); }
//----------------------------------------------------
static void setMorosoSocio_Impl(void *self,int val)
{ setValue(self,POS_MOROSO_SOC,&val); }
//----------------------------------------------------
static void destroyInternalCli_Impl(void *self)
{
	obj_Socio *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
	if(obj->localidad!=NULL)
	{
		destroyObj(obj->localidad);
		obj->localidad= NULL;
	}	
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
/// ....
obj_Localidad *getLocalidadSocioObj_Impl(void *self)
{
	obj_Socio *obj = this(self);	
	if(obj->localidad == NULL)
	{
		obj->localidad = Localidad_new();
		obj->localidad->findbykey(obj->localidad,obj->getCodPostal(obj));
		return obj->localidad;
	}
	//acceso a la informacion relacionada
	return NULL;
}
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Socio(void *self)
{
  obj_Socio *obj      = this(self);
  obj->ds  			    = &table_Socio;
  obj->constructor 	    = Socio_new;
  obj->sizeObj 		    = sizeof(obj_Socio*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
  obj->localidad 	    = NULL;
  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_SocioImpl;
  // Inicializar handlers de getters y setters
  /// getters
  obj->getNroSocio 		= getNroSocio_Impl;
  obj->getDni  	  		= getDniSocio_Impl;
  obj->getNombres 		= getNombresSocio_Impl;
  obj->getApellido 		= getApellidoSocio_Impl;
  obj->getDomicilio 	= getDomicilioSocio_Impl;
  obj->getTelefono 		= getTelefonoSocio_Impl;    
  obj->getCodPostal 	= getCodPostalSocio_Impl;  
  obj->getObservaciones	= getObservacionesSocio_Impl;  
  obj->getActivo 		= getActivoSocio_Impl;
  obj->getMoroso 		= getMorosoSocio_Impl;
  /// setters  
  obj->setNroSocio 		= setNroSocio_Impl;
  obj->setDni     		= setDniSocio_Impl;    
  obj->setNombres 		= setNombresSocio_Impl;
  obj->setApellido 		= setApellidoSocio_Impl;
  obj->setDomicilio 	= setDomicilioSocio_Impl;
  obj->setTelefono 		= setTelefonoSocio_Impl;  
  obj->setCodPostal     = setCodPostalSocio_Impl;  
  obj->setObservaciones = setObservacionesSocio_Impl;
  obj->setActivo 		= setActivoSocio_Impl;
  obj->setMoroso 		= setMorosoSocio_Impl;
  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalCli_Impl;
  //---- acceso a relaciones  
  obj->getLocalidadObj 	= getLocalidadSocioObj_Impl;  
  return obj;
}
//----------------------------------------------------
//constructor de Socio
obj_Socio *Socio_new()
{
  return (obj_Socio *)init_obj(sizeof(obj_Socio), init_Socio);
}
//----------------------------------------------------

