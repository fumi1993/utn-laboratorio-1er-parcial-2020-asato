#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include "validaciones.h"
#include "loan.h"

int findLoanEmpty(eLoan loanList[], int Qty)
{

	int index = -1;
	int i;
	for(i=0;i<Qty;i++)
{
	if(loanList[i].isEmpty!=FILLED)
{
	index = i;
	break;
}
}
	return index;
}

void loadLoanList(eLoan loanList[],eCustomer customerList[],int Qty,int *id, int *loanId)// me trabe aca no pude continuar.
{
	    int index;
	    int aux;
	    showCustomerList(customerList, Qty);
	    if(index!=-1)
	    {
	    index = findLoanEmpty(loanList, Qty);
	    aux = customerList[index];
	    showCustomer(aux);
	    printf("Indice: %d\n", index);
	    aux = loanList[index].active;
	    aux++;
	    }
	    else if(index!=-1)
	    {
	    	loanList[index] = loadLoan();
	    	loanList[index].id = *loanId;
	    	loanList[index].active = aux;
	    }
	    else
	    {
	        printf("\nNo se pueden aprobar mas prestamos");
	    }
}

eLoan loadLoan(void)
{
	eLoan Loan;

	if(getInt(&Loan.amount,"ingrese el monto del prestamo:","opción invalida\n",1,50000)==0)
		{
		}
	if(getInt(&Loan.fee,"ingrese la cantidad de cuotas:","opción invalida\n",1,24)==0)
		{
		}
    Loan.active = 0;
	Loan.isEmpty = 1;

    return Loan;
}


int searchLoanById(eLoan* loanList, int Qty, int loanId)
{
    int i;
    int retorno = -1;

    if(loanList!=NULL && Qty>0)
    {

     for(i=0; i<Qty; i++)
    {
        if(loanList[i].id==loanId && loanList[i].isEmpty==FILLED)
        {
            retorno = i;
            break;
        }
    }
    }
    return retorno;
}

int loanPayOff(eLoan loanList[],eCustomer customerList[],int Qty,int loanId)
{

		int index;
		int ok = -1;
		char answer;

		eLoan aux;

		index = searchLoanById(loanList,Qty,loanId);
		//showCustomerList( customerList , Qty); esto no va muestra la lista de clientes y necesitas que muestre el cliente asignado al prestamo
	    if(index!=-1)
	    {
	        aux = loanList[index];
	      //  showCustomer(aux);
	        if(getChar(&answer,"Esta seguro que desea saldar el pago? : s/n\n","opcion invalida\n",110,115))
	              {
	              }
	              else if(answer=='s')
	              {
	            	  loanList[index] = aux;
	                  ok = 1;
	              }
	              else
	              {
	            	  ok = 0;
	              }
	    }
	    return ok;
}
