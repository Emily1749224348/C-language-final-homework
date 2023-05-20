#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Relic {   //ÿ�������Ӧһ���ṹ�� 

    char Name[100];
    char Museum[100];
    char Year[100];
    char Introduction[100];
}Relics[10000];


int num = 0; //������

void Copy(struct Relic* arr, int i, int j)
{
    strcpy_s(arr[i].Name, arr[j].Name);
    strcpy_s(arr[i].Museum, arr[j].Museum);
    strcpy_s(arr[i].Year, arr[j].Year);
    strcpy_s(arr[i].Introduction, arr[j].Introduction);
}
  


int Reclic_SearchByName(char name[])//ͨ����������������
{
    
    for (int i = 0; i < num; i++)
    {
        if (strcmp(Relics[i].Name, name) == 0)  //ͨ��strcmp�������Ա��������ҵ������������λ�� 
        {
            return i;
        }
    }
    return -1;    //δ¼�뷵�� -1 
}




void Reclics_DisplaySingle(int index)//�����ͷ
{
    printf("%20s%30s%15s%30s\n","����", "�ֲز����", "���", "���");
    printf("-------------------------------------------------------------\n");
    printf("%20s%30s%15s%30s\n", Relics[index].Name, Relics[index].Museum,
        Relics[index].Year, Relics[index].Introduction);
}


void inputt()//����ѭ��¼����Ϣ
{
    while (1)
    {
        
        printf("����������:");
        scanf_s("%s", Relics[num].Name,sizeof(Relics[num].Name));
        getchar();
        printf("�������ֲز����:");
        scanf_s("%s", Relics[num].Museum, sizeof(Relics[num].Museum));
        getchar();
        printf("���������:");
        scanf_s("%s", Relics[num].Year, sizeof(Relics[num].Year));
        getchar();
        printf("��������:");
        scanf_s("%s", Relics[num].Introduction, sizeof(Relics[num].Introduction));
        getchar();
        
        if (Reclic_SearchByName(Relics[num].Name) == -1)
        {
            num++;  //������һ��λ�� 
        }
        else
        {
            printf("�������Ѵ���\n");
        }

        printf("�Ƿ����?(y/n)");
        if (getchar() == 'n')
        {
            break;
        }
    }
}


void modify()//�޸�������Ϣ
{
    while (1)
    {
        char name[20];
        int index;
        printf("������Ҫ�޸ĵ����������:");
        scanf_s("%s", name, sizeof(name));
        getchar();
        index = Reclic_SearchByName(Relics[num].Name);
        if (index == -1)//�ж������Ƿ�¼��ϵͳ
        {
            printf("���ﲻ����!\n");
        }
        else
        {
            printf("��Ҫ�޸ĵ�������ϢΪ:\n");
            Reclics_DisplaySingle(index);

            printf("-- ����������Ϣ--\n");
            printf("����������:");
            scanf_s("%s", Relics[index].Name, sizeof(Relics[num].Name));
            getchar();
            printf("�������ִ沩���:");
            scanf_s("%s", Relics[index].Museum, sizeof(Relics[num].Museum));
            getchar();
            printf("���������:");
            scanf_s("%s", Relics[index].Year, sizeof(Relics[num].Year));
            getchar();
            printf("��������:");
            scanf_s("%s", Relics[index].Introduction, sizeof(Relics[num].Introduction));
            getchar();
        }
        printf("�Ƿ����?(y/n)");

      
        if (getchar() == 'n')
        {
            break;
        }
    }
}
void deletee()//ɾ��������Ϣ
{
    int i;
    while (1)
    {
        char name[20];
        int index;
        printf("������Ҫɾ������������:");
        scanf_s("%s", name, sizeof(name));
        getchar();
        index = Reclic_SearchByName(name);   //�����Ѳ��������ƣ������䷵��ֵȷ��λ�� 
        if (index == -1)
        {
            printf("�����ﲻ����!\n");
        }
        else
        {
            printf("��Ҫɾ����������ϢΪ:\n");
            Reclics_DisplaySingle(index);

            printf("�Ƿ����Ҫɾ��?(y/n)");
            if (getchar() == 'y')
            {
                for (i = index; i < num - 1; i++)
                {
                    Copy(Relics, i, i + 1);
                    //students[i]=students[i+1];    //�Ѻ�ߵĶ�����ǰ�ƶ�
                }
                num--;
            }
            getchar();
        }
        printf("�Ƿ����?(y/n)");
        if (getchar() == 'n')
        {
            break;
        }
    }
}




void search()//��ѯ������Ϣ
{
    while (1)
    {
        char name[20];
        int index;
        printf("������Ҫ��ѯ������:");
        scanf_s("%s", name, sizeof(name));
        getchar();
        index = Reclic_SearchByName(name);   //�����Ѳ�name�����������䷵��ֵȷ��λ�� 
        if (index == -1)
        {
            printf("������!\n");
        }
        else
        {
            printf("��Ҫ��ѯ��������ϢΪ:\n");
            Reclics_DisplaySingle(index);
        }
        printf("�Ƿ����?(y/n)");
        if (getchar() == 'n')
        {
            break;
        }
    }
}

void sort()//������������
{
    int i, j;
   
    for (i = 0; i < num; i++)
    {
        for (j = 1; j < num - i; j++)
        {
            if (strcmp(Relics[j - 1].Name,Relics[j].Name)<=0)
            {

                Copy(Relics, num, j - 1);
                Copy(Relics, j - 1, j);
                Copy(Relics, j, num);
                //tmp=students[j-1];
                //students[j-1]=students[j];
                //students[j]=tmp;      //ð������ 
            }
        }
    }
    int a;
    printf("%20s%30s%15s%30s\n", "����", "�ֲز����", "���", "���");
    printf("-------------------------------------------------------------\n");
    for (a = 0; a < num; a++)
    {
        printf("%20s%30s%15s%30s\n", Relics[a].Name, Relics[a].Museum,
            Relics[a].Year, Relics[a].Introduction);
    }
}




/*void Save()
{
    FILE* fp;
    fopen_s(&fp,"temp.txt", "w+");
    fprintf(fp, "%d\n", num);
    for (int i = 0; i < num; i++)
    {
        fprintf(fp, "%s %s %s %s\n", Relics[i].Name, Relics[i].Museum, Relics[i].Year, Relics[i].Introduction);
    }
    fclose(fp);
}


void Load()
{
    FILE* fp;
     fopen_s(&fp, "temp.txt", "r");
    fscanf_s(fp, "%d", &num,sizeof(num));
    for (int i = 0; i < num; i++)
    {
        fscanf_s(fp, "%s %s %s %s\n", Relics[i].Name, Relics[i].Museum, Relics[i].Year, Relics[i].Introduction, sizeof(Relics[i].Name), sizeof(Relics[i].Museum), sizeof(Relics[i].Year), sizeof(Relics[i].Introduction));
    }
    fclose(fp);
}
*/