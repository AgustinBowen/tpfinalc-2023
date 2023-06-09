#include "../../includes/includelib.h"

#include "tipo_actividad.h"

THIS(obj_TipoActividad)// crea definicion de funcion this para este modulo. .. Macro en config.h
//----------------------------------------------------
static void toString_TipoActividadImpl(void *self)
{
     obj_TipoActividad *obj=this(self);
     printf("%d %s\n",obj->getCodigo(obj),obj->getNombre(obj));
}
//----------------------------------------------------
//implementacion de getters
//----------------------------------------------------
static int getCodigoTipoActividad_Impl(void *self)
{
  return *( (int *) getValue(self,POS_ID));
}
//----------------------------------------------------
static char *getNombreTipoActividad_Impl(void *self)
{
  return  (char *) getValue(self,POS_NOMBRE_TIPOACT);
}
//----------------------------------------------------
//implementacion setters
//----------------------------------------------------
static void setCodigoTipoActividad_Impl(void *self,int val)
{ 
	setValue(self,POS_ID,&val);
}
//----------------------------------------------------
static void setNombreTipoActividad_Impl(void *self,char *nombre)
{ 
	setValue(self,POS_NOMBRE_TIPOACT,nombre);
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
/// ....
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_TipoActividad(void *self)
{
  obj_TipoActividad *obj  = this(self);
  obj->ds  				  = &table_TipoActividad;
  obj->constructor 		  = TipoActividad_new;
  obj->sizeObj 			  = sizeof(obj_TipoActividad*);
  //incializacion de la interfaz de la entidad  
  obj->toString    		  = toString_TipoActividadImpl;
  // Inicializar handlers de getters y setters
  /// getters
  obj->getCodigo  		  = getCodigoTipoActividad_Impl;
  obj->getNombre		  = getNombreTipoActividad_Impl;  
  /// setters  
  obj->setCodigo     	  = setCodigoTipoActividad_Impl;
  obj->setNombre   		  = setNombreTipoActividad_Impl;  
  return obj;
}
//----------------------------------------------------
//constructor de TipoActividad
obj_TipoActividad *TipoActividad_new()
{
  return (obj_TipoActividad *)init_obj(sizeof(obj_TipoActividad), init_TipoActividad);
}
//----------------------------------------------------
