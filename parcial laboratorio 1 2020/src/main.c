/*
 ============================================================================
 Name        : parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "validaciones.h"
#include "loan.h"
#define Qty 50
int main(void) {

		eCustomer customerList[Qty];
		eLoan loanList[Qty];
		int i;
		int id = 1;
		int loanId = 1001;
		int choice;
		setbuf(stdout,NULL);

		for(i=0; i<Qty; i++)
			    {
				customerList[i].isEmpty=EMPTY;
				loanList[i].isEmpty=EMPTY;
			    }

		do{
			if(getInt(&choice,"\nElija una opcion: \n\t 1- Alta de cliente\n\t 2- Modificar cliente\n\t 3- Baja de cliente\n\t 4- cargar prestamo\n\t 5- saldar prestamo\n","opción invalida",1,10)==0)
			{
			}

		switch(choice){

						case 1:

							loadCustomerList(customerList,Qty,&id);
							id++;
							break;

						case 2:

							showCustomerList(customerList,Qty);
							if(getInt(&id,"\nelija el id del cliente a modificar","opción invalida",1,5)==0)
							{
							}
							modifyName(customerList,Qty,id);
							modifyLastName(customerList,Qty,id);
							modifyCuil(customerList,Qty,id);

							break;

						case 3:

							deleteCustomer(customerList,Qty);

							break;

						case 4:
							loadLoanList(loanList,customerList,Qty,&id,&loanId);


							break;

						case 5:
							loanPayOff(loanList,customerList,Qty,loanId);
					/*	5) Saldar préstamo: Se pedirá el ID del préstamo y se imprimirá la información del
											cliente al que pertenece, luego se pedirá confirmación para cambiarse de estado y se
											cambiará al estado "saldado". */

		}

		}while(choice!=4);

		return 0;

	return 0;
}
