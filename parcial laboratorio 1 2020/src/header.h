/*
 * header.h
 *
 *  Created on: 14 may. 2020
 *      Author: Asato fumihito
 */

#ifndef HEADER_H_
#define HEADER_H_
#define EMPTY 0
#define FILLED 1

typedef struct //declaro una estructura con los datos de los prestamos
{
    int id;
    int fee;
    int amount;
    int active;
    int settled;
    int isEmpty;
}eLoan;

typedef struct //declaro una estructura con los datos de un clientes
{
    int id;
    char name[51];
    char lastName[51];
    char cuil[14];
    int isEmpty;
}eCustomer;

int findEmpty(eCustomer*, int);
void loadCustomerList(eCustomer[],int,int*);
eCustomer loadCustomer(void);
int searchCustomerById(eCustomer[], int,int);
void modifyCustomer(eCustomer[],int);
int modifyName(eCustomer[], int,int );
int modifyLastName(eCustomer[],int,int);
int modifyCuil(eCustomer[] ,int,int);
int deleteCustomer(eCustomer[] ,int );
void showCustomerList(eCustomer[], int );
void sortCustomer(eCustomer[], int );

#endif /* HEADER_H_ */
