#include "../../includes/includelib.h"

#include "lugar.h"

THIS(obj_Lugar)// crea definicion de funcion this para este modulo. .. Macro en config.h
//----------------------------------------------------
static void toString_LugarImpl(void *self)
{
     obj_Lugar *obj=this(self);
     printf("%d %s\n",obj->getCodigo(obj),obj->getNombre(obj));
}
//----------------------------------------------------
//implementacion de getters
//----------------------------------------------------
static int getCodigoLugar_Impl(void *self)
{
  return *( (int *) getValue(self,POS_ID));
}
//----------------------------------------------------
static char *getNombreLugar_Impl(void *self)
{
  return  (char *) getValue(self,POS_NOMBRE_TIPOACT);
}
//----------------------------------------------------
//implementacion setters
//----------------------------------------------------
static void setCodigoLugar_Impl(void *self,int val)
{ 
	setValue(self,POS_ID,&val);
}
//----------------------------------------------------
static void setNombreLugar_Impl(void *self,char *nombre)
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
static void *init_Lugar(void *self)
{
  obj_Lugar *obj  = this(self);
  obj->ds  				  = &table_Lugar;
  obj->constructor 		  = Lugar_new;
  obj->sizeObj 			  = sizeof(obj_Lugar*);
  //incializacion de la interfaz de la entidad  
  obj->toString    		  = toString_LugarImpl;
  // Inicializar handlers de getters y setters
  /// getters
  obj->getCodigo  		  = getCodigoLugar_Impl;
  obj->getNombre		  = getNombreLugar_Impl;  
  /// setters  
  obj->setCodigo     	  = setCodigoLugar_Impl;
  obj->setNombre   		  = setNombreLugar_Impl;  
  return obj;
}
//----------------------------------------------------
//constructor de TipoActividad
obj_Lugar *Lugar_new()
{
  return (obj_Lugar *)init_obj(sizeof(obj_Lugar), init_Lugar);
}
//----------------------------------------------------

