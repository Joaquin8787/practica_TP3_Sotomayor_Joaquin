#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "joaquin.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int mostrarEmpleados(LinkedList* listaLinkedList);

int main()
{
	setbuf(stdout,NULL);

    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        switch(menuOpciones())
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados)==0){
                	printf("TODO OK \n");
                }
                else{
                	printf("TODO MAL \n");
                }
                break;
            case 2:
            	mostrarEmpleados(listaEmpleados);
            	break;
            case 2:

            break;
        }
    }while(option != 10);
    return 0;
}
int mostrarEmpleados(LinkedList* listaLinkedList){
	int tam;
	Employee* auxEmpleado;
	tam = ll_len(listaLinkedList);
	for(int i= 0; i<tam;i++){
	auxEmpleado = (Employee*) ll_get(listaLinkedList, i);
	printf("%d      %s       %d        %d \n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
		}
	return 0;
}
