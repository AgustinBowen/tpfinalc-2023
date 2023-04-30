#include "../../includes/includelib.h"
#include "../tipo_actividad/tipo_actividad.h"
#include "../profesor/profesor.h"
#include "actividad.h"

THIS(obj_Actividad)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_ActividadImpl(void *self)
{
     obj_Actividad *obj=this(self);     
     obj_TipoActividad *t_act = obj->getTipoActividadObj(obj);
     // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
     printf("\n"); 
}
//----------------------------------------------------
//implementacion de getters
//----------------------------------------------------
static int getCodigoActividad_Impl(void *self)
{ return *((int *) getValue(self,POS_ID)); }
//----------------------------------------------------
static int getCodTipoActActividad_Impl(void *self)
{ return *((int *) getValue(self,POS_CODTIPO_ACT)); }
//----------------------------------------------------
static int getLegajoProfeActividad_Impl(void *self)
{ return *((int *) getValue(self,POS_LEGAJO_PROFE_ACT)); }
//----------------------------------------------------
static char *getFechaDesdeActividad_Impl(void *self)
{ return  (char *) getValue(self,POS_FECHA_DESDE_ACT); }
//----------------------------------------------------
static char *getFechaFinActividad_Impl(void *self)
{ return  (char *) getValue(self,POS_FECHA_FIN_ACT); }
//----------------------------------------------------
//implementacion setters
//----------------------------------------------------
static void setCodigoActividad_Impl(void *self,int val)
{ setValue(self,POS_ID,&val); }
//----------------------------------------------------
static void setCodTipoActActividad_Impl(void *self,int val)
{ setValue(self,POS_CODTIPO_ACT,&val); }
//----------------------------------------------------
static void setLegajoProfeActividad_Impl(void *self,int val)
{ setValue(self,POS_LEGAJO_PROFE_ACT,&val); }
//----------------------------------------------------
static void setFechaDesdeActividad_Impl(void *self,char *fdesde)
{ setValue(self,POS_FECHA_DESDE_ACT,fdesde); }
//----------------------------------------------------
static void setFechaFinActividad_Impl(void *self,char *ffin)
{ setValue(self,POS_FECHA_FIN_ACT,ffin); }
//----------------------------------------------------
static void destroyInternalAct_Impl(void *self)
{
	obj_Actividad *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
	//obj->tipo_actividad
	//obj->profesor
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
/// ....
obj_TipoActividad *getTipoActividad_ActividadObj_Impl(void *self)
{
	obj_Actividad *obj = this(self);	
	//acceso a la informacion relacionada
	return NULL;
}
//----------------------------------------------------
obj_Profesor *getProfesor_ActividadObj_Impl(void *self)
{
	obj_Actividad *obj = this(self);	
	//acceso a la informacion relacionada
	return NULL;
}
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Actividad(void *self)
{
  obj_Actividad *obj      = this(self);
  obj->ds  			    = &table_Actividad;
  obj->constructor 	    = Actividad_new;
  obj->sizeObj 		    = sizeof(obj_Actividad*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
  obj->tipo_actividad   = NULL;
  obj->profesor   		= NULL;
  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_ActividadImpl;
  // Inicializar handlers de getters y setters
  /// getters
  obj->getCodigo 		= getCodigoActividad_Impl;
  obj->getCodTipoAct	= getCodTipoActActividad_Impl;
  obj->getLegajoProfe	= getLegajoProfeActividad_Impl;
  obj->getFechaDesde 	= getFechaDesdeActividad_Impl;
  obj->getFechaFin 		= getFechaFinActividad_Impl;
  /// setters  
  obj->setCodigo 		= setCodigoActividad_Impl;
  obj->setLegajoProfe	= setLegajoProfeActividad_Impl;    
  obj->setFechaDesde	= setFechaDesdeActividad_Impl;
  obj->setFechaFin 		= setFechaFinActividad_Impl;
  
  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalAct_Impl;
  //---- acceso a relaciones  
  obj->getTipoActividadObj 	= getTipoActividad_ActividadObj_Impl;  
  obj->getProfesorObj		= getProfesor_ActividadObj_Impl;
  return obj;
}
//----------------------------------------------------
//constructor de Actividad
obj_Actividad *Actividad_new()
{
  return (obj_Actividad *)init_obj(sizeof(obj_Actividad), init_Actividad);
}
//----------------------------------------------------

