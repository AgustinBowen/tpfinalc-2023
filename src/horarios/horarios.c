#include "../../includes/includelib.h"
#include "../tipo_actividad/tipo_actividad.h"
#include "../profesor/profesor.h"
#include "../actividad/actividad.h"

#include "horarios.h"

THIS(obj_Horario)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_HorarioImpl(void *self)
{
     obj_Horario *obj=this(self);     
     
     // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
     printf("\n"); 
}
//----------------------------------------------------
//implementacion de getters
//----------------------------------------------------
static int getCodigoHorario_Impl(void *self)
{ return *((int *) getValue(self,POS_ID)); }
//----------------------------------------------------
static int getDiaHorario_Impl(void *self)
{ return *((int *) getValue(self,POS_DIA_HOR)); }
//----------------------------------------------------
static int getCodActHorario_Impl(void *self)
{ return *((int *) getValue(self,POS_COD_ACT_HOR)); }
//----------------------------------------------------
static char *getHoraDesdeHorario_Impl(void *self)
{ return  (char *) getValue(self,POS_HORA_DESDE_HOR); }
//----------------------------------------------------
static char *getHoraHastaHorario_Impl(void *self)
{ return  (char *) getValue(self,POS_HORA_HASTA_HOR); }
//----------------------------------------------------
static char *getLugarHorario_Impl(void *self)
{ return  (char *) getValue(self,POS_LUGAR_HOR); }
//----------------------------------------------------
//implementacion setters
//----------------------------------------------------
static void setCodigoHorario_Impl(void *self,int val)
{ setValue(self,POS_ID,&val); }
//----------------------------------------------------
static void setDiaHorario_Impl(void *self,int val)
{ setValue(self,POS_DIA_HOR,&val); }
//----------------------------------------------------
static void setCodActHorario_Impl(void *self,int val)
{ setValue(self,POS_COD_ACT_HOR,&val); }
//----------------------------------------------------
static void setHoraDesdeHorario_Impl(void *self,char *hdesde)
{ setValue(self,POS_HORA_DESDE_HOR,hdesde); }
//----------------------------------------------------
static void setHoraHastaHorario_Impl(void *self,char *hhasta)
{ setValue(self,POS_HORA_HASTA_HOR,hhasta); }
//----------------------------------------------------
static void setLugarHorario_Impl(void *self,char *fdesde)
{ setValue(self,POS_LUGAR_HOR,fdesde); }
//----------------------------------------------------
static void destroyInternalAct_Impl(void *self)
{
	obj_Horario *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
	//obj->actividad
	
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
/// ....
obj_Actividad *getActividad_HorarioObj_Impl(void *self)
{
	obj_Horario *obj = this(self);	
	//acceso a la informacion relacionada
	return NULL;
}
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Horario(void *self)
{
  obj_Horario *obj      = this(self);
  obj->ds  			    = &table_Horario;
  obj->constructor 	    = Horario_new;
  obj->sizeObj 		    = sizeof(obj_Horario*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
  obj->actividad        = NULL;
  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_HorarioImpl;
  // Inicializar handlers de getters y setters
  /// getters
  obj->getCodigo 		= getCodigoHorario_Impl;
  obj->getDia			= getDiaHorario_Impl;
  obj->getCodAct		= getCodActHorario_Impl;
  obj->getHoraDesde		= getHoraDesdeHorario_Impl;
  obj->getHoraHasta		= getHoraHastaHorario_Impl;
  obj->getLugar			= getLugarHorario_Impl;
  /// setters  
  obj->setCodigo 		= setCodigoHorario_Impl;
  obj->setDia			= setDiaHorario_Impl;    
  obj->setCodAct 		= setCodActHorario_Impl;
  obj->setHoraDesde		= setHoraDesdeHorario_Impl;
  obj->setHoraHasta		= setHoraHastaHorario_Impl;
  obj->setLugar			= setLugarHorario_Impl;
  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalAct_Impl;
  //---- acceso a relaciones  
  obj->getActividadObj 	= getActividad_HorarioObj_Impl;  
  return obj;
}
//----------------------------------------------------
//constructor de Horario
obj_Horario *Horario_new()
{
  return (obj_Horario *)init_obj(sizeof(obj_Horario), init_Horario);
}
//----------------------------------------------------

