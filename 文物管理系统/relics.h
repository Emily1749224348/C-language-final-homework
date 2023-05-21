#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Relic {   //每个文物对应一个结构体 

    char Name[100];
    char Museum[100];
    char Year[100];
    char Introduction[100];
}Relics[10000];


int num; //计数器


void Copy(struct Relic* arr, int i, int j)
{
    strcpy_s(arr[i].Name, arr[j].Name);
    strcpy_s(arr[i].Museum, arr[j].Museum);
    strcpy_s(arr[i].Year, arr[j].Year);
    strcpy_s(arr[i].Introduction, arr[j].Introduction);
}
  


int Reclic_SearchByName(char name[])//通过姓名来检索文物
{
    
    for (int i = 0; i < num; i++)
    {
        if (strcmp(Relics[i].Name, name) == 0)  //通过strcmp函数来对比姓名，找到返回在数组的位置 
        {
            return i;
        }
    }
    return -1;    //未录入返回 -1 
}




void Reclics_DisplaySingle(int index)//输出表头
{
    printf("%20s%30s%15s%30s\n","名称", "现藏博物馆", "年代", "简介");
    printf("------------------------------------------------------------------------------------------------------\n");
    printf("%19s%25s%20s%30s\n", Relics[index].Name, Relics[index].Museum,
        Relics[index].Year, Relics[index].Introduction);
}


void inputt()//利用循环录入信息
{
    while (1)
    {
       
        printf("请输入名称:");
        scanf_s("%s", Relics[num].Name, sizeof(Relics[num].Name));
        getchar();
        printf("请输入现藏博物馆:");
        scanf_s("%s", Relics[num].Museum, sizeof(Relics[num].Museum));
        getchar();
        printf("请输入年代:");
        scanf_s("%s", Relics[num].Year, sizeof(Relics[num].Year));
        getchar();
        printf("请输入简介:");
        scanf_s("%s", Relics[num].Introduction, sizeof(Relics[num].Introduction));
        getchar();
        
        if (Reclic_SearchByName(Relics[num].Name) == -1)
        {
            num++;  //移向下一个位置 
        }
        else
        {
            printf("该文物已存在\n");
        }

        printf("是否继续?(y/n)");
        char ch= getchar();
        while (ch != 'y' && ch != 'n')
        {
          
            printf("输入有误，请重新输入(y/n):");
            getchar();
            ch = getchar();
            
        }
        if (ch == 'n')
        {
            break;
        }
    }
}


void modify()//修改文物信息
{
    while (1)
    {
        char name[20];
        int index;
        printf("请输入要修改的文物的名称:");
        scanf_s("%s", name, sizeof(name));
        getchar();
        index = Reclic_SearchByName(Relics[num].Name);
        if (index == -1)//判断文物是否录入系统
        {
            printf("文物不存在!\n");
        }
        else
        {
            printf("你要修改的文物信息为:\n");
            Reclics_DisplaySingle(index);

            printf("-- 请输入新信息--\n");
            printf("请输入名称:");
            scanf_s("%s", Relics[index].Name, sizeof(Relics[num].Name));
            getchar();
            printf("请输入现存博物馆:");
            scanf_s("%s", Relics[index].Museum, sizeof(Relics[num].Museum));
            getchar();
            printf("请输入年代:");
            scanf_s("%s", Relics[index].Year, sizeof(Relics[num].Year));
            getchar();
            printf("请输入简介:");
            scanf_s("%s", Relics[index].Introduction, sizeof(Relics[num].Introduction));
            getchar();
        }
        printf("是否继续?(y/n)");

      
        char ch = getchar();
        while (ch != 'y' && ch != 'n')
        {

            printf("输入有误，请重新输入(y/n):");
            getchar();
            ch = getchar();

        }
        if (ch == 'n')
        {
            break;
        }
    }
}
void deletee()//删除文物信息
{
    int i;
    while (1)
    {
        char name[20];
        int index;
        printf("请输入要删除的文物名称:");
        scanf_s("%s", name, sizeof(name));
        getchar();
        index = Reclic_SearchByName(name);   //调用搜查文物名称，根据其返回值确定位置 
        if (index == -1)
        {
            printf("该文物不存在!\n");
        }
        else
        {
            printf("你要删除的文物信息为:\n");
            Reclics_DisplaySingle(index);

            printf("是否真的要删除?(y/n)");
            if (getchar() == 'y')
            {
                for (i = index; i < num - 1; i++)
                {
                    Copy(Relics, i, i + 1);
                    //students[i]=students[i+1];    //把后边的对象都向前移动
                }
                num--;
            }
            getchar();
        }
        printf("是否继续?(y/n)");
        char ch = getchar();
        while (ch != 'y' && ch != 'n')
        {

            printf("输入有误，请重新输入(y/n):");
            getchar();
            ch = getchar();

        }
        if (ch == 'n')
        {
            break;
        }
    }
}




void search()//查询文物信息
{
    while (1)
    {
        char name[20];
        int index;
        printf("请输入要查询的名称:");
        scanf_s("%s", name, sizeof(name));
        getchar();
        index = Reclic_SearchByName(name);   //调用搜查name函数，根据其返回值确定位置 
        if (index == -1)
        {
            printf("不存在!\n");
        }
        else
        {
            printf("你要查询的文物信息为:\n");
            Reclics_DisplaySingle(index);
        }
        printf("是否继续?(y/n)");
        char ch = getchar();
        while (ch != 'y' && ch != 'n')
        {

            printf("输入有误，请重新输入(y/n):");
            getchar();
            ch = getchar();

        }
        if (ch == 'n')
        {
            break;
        }
    }
}

void sort()//根据名称排序
{
    int i, j;
   
    for (i = 0; i < num; i++)
    {
        for (j = 1; j < num - i; j++)
        {
            if (strcmp(Relics[j - 1].Name,Relics[j].Name)>=0)
            {

                Copy(Relics, num, j - 1);
                Copy(Relics, j - 1, j);
                Copy(Relics, j, num);
                //tmp=students[j-1];
                //students[j-1]=students[j];
                //students[j]=tmp;      //冒泡排序 
            }
        }
    }
    int a;
    printf("%20s%30s%15s%30s\n", "名称", "现藏博物馆", "年代", "简介");
    printf("-----------------------------------------------------------------------------------------------------------\n");
    for (a = 0; a < num; a++)
    {
        printf("%20s%30s%15s%30s\n\n", Relics[a].Name, Relics[a].Museum,
            Relics[a].Year, Relics[a].Introduction);
    }
}




void Save()
{
    FILE* fp;
    if (fopen_s(&fp, "test.txt", "w+") == 0)
    {
        fprintf(fp, "%d\n", num);
        for (int i = 0; i < num; i++)
        {
            fprintf(fp, "%s %s %s %s\n", Relics[i].Name, Relics[i].Museum, Relics[i].Year, Relics[i].Introduction);
        }
        fclose(fp);
    }
    else
    {
        printf("error");
    }
}


void Load()
{
    FILE* fp;

    if (fopen_s(&fp,"test.txt", "r") == 0)
    {

        fscanf_s(fp, "%d\n",&num);
        

        for (int i = 0; i < num; i++)
        {

            fscanf_s(fp, "%s %s %s %s\n", Relics[i].Name, sizeof(Relics[i].Name),
                Relics[i].Museum, sizeof(Relics[i].Museum),
                Relics[i].Year, sizeof(Relics[i].Year),
                Relics[i].Introduction, sizeof(Relics[i].Introduction));

        }
        fclose(fp);
    }
    else
    {
        printf("文件打开失败");
    }

}