/*
 * Loan.h
 *
 *  Created on: 17 may. 2020
 *      Author: katon
 */

#ifndef LOAN_H_
#define LOAN_H_


int findLoanEmpty(eLoan[],int);
void loadLoanList(eLoan[],eCustomer[],int,int*,int*);
eLoan loadLoan(void);
int searchLoanById(eLoan[],int,int );
int loanPayOff(eLoan[],eCustomer[],int ,int);
#endif /* LOAN_H_ */
