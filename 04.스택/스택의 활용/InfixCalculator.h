//기능의 통합
#ifndef __INFIXCALCULATOR_H__
#define __INFIXCALCULATOR_H__

#include "PostCalculator.h"
#include "InfixToPostfix.h"

// 중위 -> 후위 -> 계산의 모든 기능을 담는 함수
int InfixExp(char exp[]);

#endif