/*
 * result_Report.h
 *
 *  Created on: 2025Äê11ÔÂ12ÈÕ
 *      Author: yzy
 */

#ifndef RESULT_REPORT_H_
#define RESULT_REPORT_H_
#include"Result.h"
#include"c6748.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

extern volatile int sendTime;
void myprint(char* temp);

void result_send_test();

void PrintResult_O(RESULT* myResult);
void PrintResult_P(RESULT* myResult);
void PrintResult_M(RESULT* myResult);


#endif /* RESULT_REPORT_H_ */
