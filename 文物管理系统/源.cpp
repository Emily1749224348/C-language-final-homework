#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"relics.h"


int main() {
    int i;

    while (1) {
       // Load();
        printf("\t\t\t\t\t-------- ������Ϣ����ϵͳ-------\n\n\n\n");     //�˵� 
        printf("\t\t\t\t\t1. ����������Ϣ\n\n");
        printf("\t\t\t\t\t2. �޸�������Ϣ\n\n");
        printf("\t\t\t\t\t3. ɾ��������Ϣ\n\n");
        printf("\t\t\t\t\t4. ��ѯ������Ϣ\n\n");
        printf("\t\t\t\t\t5. ��������������\n\n");
        printf("\t\t\t\t\t0. �˳�\n\n\n");

        printf("��ѡ��(0-5):");
        scanf_s("%d", &i);
     

        switch (i) {
        case 1:inputt(); break;
        case 2:modify(); break;
        case 3:deletee(); break;
        case 4:search(); break;
        case 5:sort(); break;
        case 0:exit(0);
        default:break;
        }

       // Save();
    }
    return 0;
}

