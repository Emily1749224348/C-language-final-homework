#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"relics.h"


int main() {
    int i;

    while (1) {
       // Load();
        printf("\t\t\t\t\t-------- 文物信息管理系统-------\n\n\n\n");     //菜单 
        printf("\t\t\t\t\t1. 增加文物信息\n\n");
        printf("\t\t\t\t\t2. 修改文物信息\n\n");
        printf("\t\t\t\t\t3. 删除文物信息\n\n");
        printf("\t\t\t\t\t4. 查询文物信息\n\n");
        printf("\t\t\t\t\t5. 按文物名称排序\n\n");
        printf("\t\t\t\t\t0. 退出\n\n\n");

        printf("请选择(0-5):");
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

