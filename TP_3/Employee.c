#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "parser.h"
#include "joaquin.h"

/** \brief Libera el espacio en memoria apuntado por "this"
 *
 * \param this Employee*
 * \return int retorna 0 si pudo y 1 si no lo logro
 *
 */
int employee_delete(Employee* this)
{
	int retorno=1;
	if(this!=NULL)
	{
		free(this);
		retorno=0;
	}
	return retorno;
}

/** \brief asigna un lugar de la memoria dinamica para un elemento de tipo Employee y deja todos sus campos inicializados
 *
 * \return Employee* retorna un puntero al lugar de la memoria asignado o devuelve NULL si no lo logro
 *
 */
Employee* employee_new(){
	Employee* nuevoEmpleado = NULL;
	nuevoEmpleado = (Employee*)malloc(sizeof(Employee));
	if(nuevoEmpleado != NULL){
		employee_setId(nuevoEmpleado, 0);
		employee_setNombre(nuevoEmpleado," ");
		employee_setHorasTrabajadas(nuevoEmpleado,0);
		employee_setSueldo(nuevoEmpleado,0);
	}

	return nuevoEmpleado;
}


/** \brief reserva espacio de memoria dinamica para un elemento de tipo Employee cargando en todos sus campos los datos pasados como parametros en formato de cadena de caracteres
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee* retorna un puntero al lugar de la memoria asignado o devuelve NULL si no lo logro
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){
	Employee* nuevoEmpleado = NULL;
	if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL){

		nuevoEmpleado = employee_new();

		if(nuevoEmpleado != NULL){
			if(!employee_setId(nuevoEmpleado, atoi(idStr))||
					!employee_setNombre(nuevoEmpleado,nombreStr)||
					!employee_setHorasTrabajadas(nuevoEmpleado,atoi(horasTrabajadasStr))||
					!employee_setSueldo(nuevoEmpleado,atoi(sueldoStr))){
				employee_delete(nuevoEmpleado);
				nuevoEmpleado = NULL;

			}

		}
	}
	return nuevoEmpleado;
}

/** \brief reserva espacio de memoria dinamica para un elemento de tipo Employee cargando en todos sus campos los datos pasados como parametros en los formatos correspondientes
 *
 * \param id int
 * \param nombre char*
 * \param horasTrabajadas int
 * \param sueldo int
 * \return Employee* retorna un puntero al lugar de la memoria asignado o devuelve NULL si no lo logro
 *
 */
Employee* employee_newParametrosCorrespondientes(int* id,char* nombre,int* horasTrabajadas, int* sueldo){
	Employee* nuevoEmpleado = NULL;
	if(id != NULL && nombre != NULL && horasTrabajadas != NULL && sueldo != NULL){
		nuevoEmpleado = employee_new();
		if(nuevoEmpleado != NULL){
			if(!employee_setId(nuevoEmpleado,(*id))||
					!employee_setNombre(nuevoEmpleado,nombre)||
					!employee_setHorasTrabajadas(nuevoEmpleado,*horasTrabajadas)||
					!employee_setSueldo(nuevoEmpleado,*sueldo)){

				employee_delete(nuevoEmpleado);
				nuevoEmpleado = NULL;
			}
		}
	}
	return nuevoEmpleado;

}

/** \brief Imprime por pantalla un unico empleado
 *
 * \param this Employee*
 * \return int retorna 1 si pudo y 0 si no lo logro
 *
 */
int employee_showOneEmployee(Employee* empleado){
	int retorno = 0;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	if(empleado != NULL){
		employee_getId(empleado,&id);
		employee_getNombre(empleado,nombre);
		employee_getHorasTrabajadas(empleado,&horasTrabajadas);
		employee_getSueldo(empleado,&sueldo);

		printf("%-10d      %-20s       %-15d        %-10d \n",id,nombre,horasTrabajadas,sueldo);
		retorno = 1;
	}
	return retorno;
}

//FUNCIONES PARA COMPARAR

/** \brief Compara a los empleados del LinkedList por sus Id
 *
 * \param empleado1 void*
 * \param empleado2 void*
 * \return int retorna 1 si el primer valor es mas grande, -1 si el segundo es mas grande o 0 si son iguales
 *
 */
int employee_compareById(void* employee1, void* employee2)
{
	int retorno;
	int id;
	int id2;
	if(employee1 != NULL && employee2 != NULL){
		employee_getId((Employee*)employee1,&id);
		employee_getId((Employee*)employee2,&id2);

		if( id > id2)
		{
			retorno = -1;
		}
		else if(id < id2)
		{
			retorno = 1;
		}
		else
		{
			retorno = 0;
		}
	}

	return retorno;
}
/** \brief Compara a los empleados del LinkedList por sus nombres
 *
 * \param empleado1 void*
 * \param empleado2 void*
 * \return int retorna 1 si el primer valor es mas grande, -1 si el segundo es mas grande o 0 si son iguales
 *
 */
int employee_compareByNombre(void* employee1, void* employee2)
{
	int retorno;
	char nombre1[128];
	char nombre2[128];
	if(employee1 != NULL && employee2 != NULL){
		employee_getNombre((Employee*)employee1,nombre1);
		employee_getNombre((Employee*)employee2,nombre2);
		if(strcmpi(nombre1,nombre2)>0){
			retorno = -1;
		}
		else if(strcmpi(nombre1,nombre2)<0){
			retorno = 1;
		}
		else{
			retorno = 0;
		}
	}

	return retorno;
}
/** \brief Compara a los empleados del LinkedList por sus horas trabajadas
 *
 * \param empleado1 void*
 * \param empleado2 void*
 * \return int retorna 1 si el primer valor es mas grande, -1 si el segundo es mas grande o 0 si son iguales
 *
 */
int employee_compareByHorasTrabajadas(void* employee1, void* employee2)
{
	int retorno;
	int emp1;
	int emp2;
	if(employee1 != NULL && employee2 != NULL){

		employee_getHorasTrabajadas((Employee*)employee1,&emp1);
		employee_getHorasTrabajadas((Employee*)employee2,&emp2);

		if( emp1 > emp2)
		{
			retorno = -1;
		}
		else if(emp1 < emp2)
		{
			retorno = 1;
		}
		else
		{
			retorno = 0;
		}
	}


	return retorno;
}

/** \brief Compara a los empleados del LinkedList por su sueldo
 *
 * \param empleado1 void*
 * \param empleado2 void*
 * \return int retorna 1 si el primer valor es mas grande, -1 si el segundo es mas grande o 0 si son iguales
 *
 */
int employee_compareBySueldo(void* employee1, void* employee2)
{
	int retorno;
	int emp1;
	int emp2;
	if(employee1 != NULL && employee2 != NULL){
		employee_getSueldo((Employee*)employee1,&emp1);
		employee_getSueldo((Employee*)employee2,&emp2);

		if( emp1 > emp2)
		{
			retorno = -1;
		}
		else if(emp1 < emp2)
		{
			retorno = 1;
		}
		else
		{
			retorno = 0;
		}

	}

	return retorno;
}


//SETTERS Y GETTERS
int employee_setId(Employee* this, int id)
{
	int retorno=0;
	if(this!=NULL && id>0)
	{
		this->id=id;
		retorno=1;
	}
	return retorno;
}

int employee_getId(Employee* this, int* id)
{
	int retorno=0;
	if(this!=NULL)
	{
		*id = this->id;
		retorno=1;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno=0;
	if(this!=NULL && nombre!=NULL && strlen(nombre)>1 && strlen(nombre)<30)
	{
		strcpy(this->nombre,nombre);

		retorno=1;
	}
	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno=0;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		retorno=1;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno=0;
	if(this!=NULL && horasTrabajadas>=0)
	{
		this->horasTrabajadas=horasTrabajadas;
		retorno=1;
	}
	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno=0;
	if(this!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		retorno=1;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno=0;
	if(this!=NULL && sueldo>0)
	{
		this->sueldo=sueldo;
		retorno=1;
	}
	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno=0;
	if(this!=NULL && sueldo!=NULL)
	{
		*sueldo=this->sueldo;
		retorno=1;
	}
	return retorno;
}
