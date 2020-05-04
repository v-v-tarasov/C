// КУРСОВАЯ РАБОТА
// По дисциплине: Информатика (часть 2)
// Гр. ТБ-92, Тарасов В.В., Вариант № 5
// Версия: Windows (Windows 7)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct students{
    char surname [20];
    char name [20];
    char patronymic [28];
    char group_number [20];
    int rating [3];
};

void message();
void w_menu();
void w_new();
void w_edit();
void w_find();
void w_all();

int main(void){
    system ("chcp 65001");
    system ("cls");
    loop: w_menu();
    goto loop;
    return 0;
}

void message(){
    printf("\n\n");
    printf("Вернуться в главное меню [1]+[Enter], завершить работу [2]+[Enter]: ");
    int input;
    scanf("%d", &input);
    switch (input){
        case 1:
            system("cls");
            main();
            break;
        case 2:
            system("cls");
            exit(1);
            break;
        default:
            system("cls");
            exit(1);
    }
}

void w_menu(){
    printf("МЕНЮ:\n");
    printf("- Создать новый файл ведомости:        - [1]\n");
    printf("- Внести запись в ведомость:           - [2]\n");
    printf("- Сформировать ведомость успеваемости: - [3]\n");
    printf("- Вывести все записи ведомости:        - [4]\n");
    printf("- Закончить работу и выйти:            - [5]\n\n");
    printf("Выберите действие, введите [№] действия и нажмите [Enter]: ");
    int menu = 0;
    scanf("%d", &menu);
    switch(menu){
        case 1:
            system("cls");
            w_new();
            break;
        case 2:
            system("cls");
            w_edit();
            break;
        case 3:
            system("cls");
            w_find();
            break;
        case 4:
            system("cls");
            w_all();
            break;
        case 5:
            system("cls");
            exit(1);
        default:
            system("cls");
            printf("Ошибка ввода!");
            message();
    }
}

void w_new(){
    FILE *wd;
    wd = fopen("Wedomosti.dat", "wd");
    if (wd == NULL){
        system("cls");
        printf("Ошибка при создании файла!\n");
        message();
    }
    fclose(wd);
    system("cls");
    printf("Новый файл ведомости успешно создан!\n");
    message();
}

void w_edit(){
    FILE *wd;
    wd = fopen("Wedomosti.dat", "ab");
    if (wd == NULL){
        system("cls");
        printf("Ошибка при редактировании файла!\n");
        message();
    }
    system("cls");
    struct students stu;
    memset(&stu.surname, '\0', 20);
    memset(&stu.name, '\0', 20);
    memset(&stu.patronymic, '\0', 28);
    memset(&stu.group_number, '\0', 20);
    memset(&stu.rating, '\0', 3);
    printf("Фамилия: ");
    scanf("%s", stu.surname);
    printf("Имя: ");
    scanf("%s", stu.name);
    printf("Отчество: ");
    scanf("%s", stu.patronymic);
    printf("Группа: ");
    scanf("%s", stu.group_number);
    printf("Итоговая оценка по истории: ");
    scanf("%d", &(stu.rating [0]));
    printf("Итоговая оценка по математике: ");
    scanf("%d", &(stu.rating [1]));
    printf("Итоговая оценка по экологии: ");
    scanf("%d", &(stu.rating [2]));
    fwrite(&stu, sizeof(stu), 1, wd);
    fclose(wd);
    message();
}

void w_find(){
    struct students stu;
    int file_read = 0;
    int line = 0;
    int find_rat;
    char s [102];
    FILE *wd;
    wd = fopen("Wedomosti.dat", "rb");
    if (wd == NULL){
        system("cls");
        printf("Ошибка при чтении файла!\n");
        message();
    }
    while (fgets(s, 100, wd) != NULL){
        line++;
    }
    fclose(wd);
    printf("Введите оценку для вывода ведомости успеваемости:");
    scanf("%d", &find_rat);
    printf("\n");
    printf("Студенты имеющие итоговую оценку %d:", find_rat);
    printf("\n\n");
    wd = fopen("Wedomosti.dat","rb");
    if (wd == NULL){
        system("cls");
        printf("Ошибка при чтении файла!\n");
        message();
    }
    printf("#  ");
    printf("ФАМИЛИЯ: \t");
    printf("ИМЯ:\t\t");
    printf("ОТЧЕСТВО: \t");
    printf("ГРУППА: \t ");
    printf(" ОЦЕНКИ:");
    printf("\n");
    for (int i = 1; i < line; i++){
        file_read=fread(&stu, sizeof(stu), 1, wd);
            if (stu.rating[0] == find_rat || stu.rating[1] == find_rat || stu.rating[2] == find_rat){
                printf("%2d ", i); 
                printf("%-11s", stu.surname);
                printf("\t%-15s", stu.name);
                printf("\t%-12s", stu.patronymic);
                printf("\t%-12s", stu.group_number);
                printf("\t%3d", stu.rating[0]);
                printf("%3d", stu.rating[1]);
                printf("%3d", stu.rating[2]);
                printf("\n");
            }
            else if (i == 1){
                system ("cls");
                printf("Студентов с оценкой %d не найдено!", find_rat);
                message();
            }
    }
    fclose(wd);
    int i = 1;
    message();
}

void w_all(){
    struct students stu;
    int file_read = 0;
    int line = 0;
    char s [102];
    FILE *wd;
    wd = fopen("Wedomosti.dat", "rb");
    if (wd == NULL){
        system("cls");
        printf("Ошибка при чтении файла!\n");
        message();
    }
    while (fgets(s, 100, wd) != NULL){
        line++;
    }
    fclose(wd);
    wd = fopen("Wedomosti.dat","rb");
    if (wd == NULL){
        system("cls");
        printf("Ошибка при чтении файла!\n");
        message();
    }
    printf("#  ");
    printf("ФАМИЛИЯ: \t");
    printf("ИМЯ:\t\t");
    printf("ОТЧЕСТВО: \t");
    printf("ГРУППА: \t ");
    printf(" ОЦЕНКИ:");
    printf("\n");
    for (int i = 1; i < line; i++){
        file_read=fread(&stu, sizeof(stu), 1, wd);
        printf("%2d ", i); 
        printf("%-11s", stu.surname);
        printf("\t%-15s", stu.name);
        printf("\t%-12s", stu.patronymic);
        printf("\t%-12s", stu.group_number);
        printf("\t%3d", stu.rating[0]);
        printf("%3d", stu.rating[1]);
        printf("%3d", stu.rating[2]);
        printf("\n");
    }
    fclose(wd);
    message();
}