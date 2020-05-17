/*
 * funciones.c
 *
 *  Created on: 14 may. 2020
 *      Author: Asato fumihito
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include "validaciones.h"
#include "loan.h"

int findEmpty(eCustomer customerList[], int Qty)
{

	int index = -1;
	int i;
	for(i=0;i<Qty;i++)
{
	if(customerList[i].isEmpty!=FILLED)
{
	index = i;
	break;
}
}
	return index;
}

void loadCustomerList(eCustomer customerList[],int Qty,int *id)
{
	    int index;
	    index = findEmpty(customerList, Qty);
	    printf("Indice: %d\n", index);
	    if(index!=-1)

	    {
	    	customerList[index] = loadCustomer();
	    	customerList[index].id = *id;
	    }
	    else
	    {
	        printf("\nNo hay espacio disponible ");
	    }
}

eCustomer loadCustomer(void)
{
	eCustomer Customer;

    if(getName(Customer.name,"ingrese el nombre:","error solo se admiten caracteres aflabeticos\n",2,sizeof(Customer.name))==0)
    	{
    	}
    if(getName(Customer.lastName,"ingrese el apellido:","error solo se admiten caracteres aflabeticos\n",2,sizeof(Customer.lastName))==0)
    	{
    	}
    printf("ingrese el cuil");
    scanf("%s",Customer.cuil);
	Customer.isEmpty = 1;

    return Customer;
}
void showCustomer(eCustomer Customer)
{
    printf("id:%d\t nombre:%s\t apellido:%s\t cuil:%s\n",Customer.id,Customer.name, Customer.lastName, Customer.cuil);
}

void showCustomerList(eCustomer customerList[], int Qty)
{
    int i;

    for(i=0; i<Qty; i++)
    {
        if(customerList[i].isEmpty==FILLED)
        {
        	showCustomer(customerList[i]);
        }

    }
}

int searchCustomerById(eCustomer* customerList, int Qty, int id)
{
    int i;
    int retorno = -1;

    if(customerList!=NULL && Qty>0)
    {

     for(i=0; i<Qty; i++)
    {
        if(customerList[i].id==id && customerList[i].isEmpty==FILLED)
        {
            retorno = i;
            break;
        }
    }
    }
    return retorno;
}

int modifyName(eCustomer customerList[], int Qty, int id)
{
    int index;
    eCustomer aux;

    index = searchCustomerById(customerList, Qty , id);
    if(index!=-1)
    {
        aux = customerList[index];
        showCustomer(aux);

        if(getName(aux.name,"ingrese el nuevo nombre:","error solo se admiten caracteres aflabeticos\n",2,sizeof(aux.name))==0)
        	{
        	}
        customerList[index] = aux;
    }
    return 0;
}

int modifyLastName(eCustomer customerList[],int Qty ,int id)
{
    int index;
    eCustomer aux;

    index = searchCustomerById(customerList,Qty, id);
    if(index!=-1)
    {
        aux = customerList[index];
        showCustomer(aux);

        if(getName(aux.lastName,"ingrese el nuevo apellido:","error solo se admiten caracteres aflabeticos\n",2,sizeof(aux.lastName))==0)
        	{
        	}
        customerList[index] = aux;

    }
    return 0;
}

int modifyCuil(eCustomer customerList[] ,int Qty ,int id)
{
	   int index;

	    eCustomer aux;


	    index = searchCustomerById(customerList,Qty, id);
	    if(index!=-1)
	    {
	        aux = customerList[index];
	        showCustomer(aux);
	        printf("ingrese el cuil");
	        scanf("%s",customerList[index].cuil);
	    	customerList[index] = aux;
	        }
	    return 0;
}

int deleteCustomer(eCustomer customerList[], int Qty)
{
    int id;
    int i;
    char answer;

    int ok = -1;

    showCustomerList(customerList,Qty);

    printf("Ingrese el id: ");
    scanf("%d", &id);

    for(i=0; i<Qty; i++)
    {
        if(customerList[i].id==id && customerList[i].isEmpty==FILLED)
        {
            showCustomer(customerList[i]);
            if(getChar(&answer,"Esta seguro que desea eliminar este cliente? : s/n\n","opcion invalida\n",110,115))
		    {
		    }
            else if(answer=='s')

            {
            	customerList[i].isEmpty = EMPTY;
                ok = 1;
            }
            else
            {
                ok = 0;
            }
        }

    }

    return ok ;
}



