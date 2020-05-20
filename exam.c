// Задать натуральное число N. Уменьшить число в 2 раза (деление нацело). 
// Проверить, изменилось ли в числе после деления количество разрядов (написать
// функцию для определения количества разрядов числа).

#include <stdio.h>
#include <stdlib.h>

int func(int);

int main(){
    system("chcp 65001");
    system("clear");
    printf("Введите натуральное число: ");
    int naturalNumber;
    scanf("%d", &naturalNumber);
    int answer;
    answer = func(naturalNumber);
    if (answer == 0){
	printf("\nКоличество разрядов после деления не изменилось.\n\n");
    }
    else if (answer == 1){
	printf("\nКоличество разрядов после деления изменилось на: %d \n\n", answer);
    }
    return 0;
}

int func(int n){
    int q = 0;
    int i = 0;
    int j = 0;
    q = n / 2;
    while (n > 0){
	n = n / 10;
	i += 1;
    }
    printf("\n - разрядов в натуральном числе: %d ", i); 
    while (q > 0){
	q = q / 10;
	j += 1;
    }
    printf("\n - разрядов после деления на 2: %d \n", j);
    int result;
    result = i - j;
    return result;
}

