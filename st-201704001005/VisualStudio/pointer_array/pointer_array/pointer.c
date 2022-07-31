#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define PR(...) printf_s(__VA_ARGS__)            //��κ�
typedef void(*VD_PTR_CHAR)(char *);

void bit_open(void);                  //����ĳһ����ֵ��λ������

struct book{
	char name[30];
	char author[20];
	float price;
};

void pointer_array();                 //ָ������������ָ��
void struct_show();                   //���ṹ��Ϣ�����ļ��ٶ���
//void getbook(struct book inmess[]);    //����ṹ��Աֵ

int main()
{
	VD_PTR_CHAR pfun;
	printf_s("The time is: %s\n", __DATE__);
	PR("HELLO\n");                       //��κ�
	struct_show();
	pointer_array();
	bit_open();
	putchar(getchar());
	getchar();
	return 0;
}

/********ָ������������ָ��*********/
void pointer_array()
{
	char *ptr1[5] = {
		"Everything I Never Told You",
		"Hello World",
		"Triple Man"
	};
	int arr[3][2] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
	int(*ptr2)[2] = arr;
	for (int i = 0; i < 5; i++)
		printf_s("%s\n",ptr1[i]);                    //��������÷�ʹ�ã������������Լ�
	for (int j = 0; j < 3; j++)
		printf_s("%d\n",*((*ptr2++)+1));             //��ָ���������÷�ʹ�ã�����㲻���Լӣ���ʱָ���ѱ�Ϊ���� *ptr2=&arr[0][0]
}

/****���ṹ��Ϣ�����ļ��ٶ���*****/
void struct_show(void)
{
	struct book booknum[2] = {                                      //��ʼ���ṹ
			{ "Everything I Never Told You", "Edward", 45.9 },
			{ "Hello World", "Stevince", 34.5 }
	};
	int count = 0;
	FILE *fp;
	if (fopen_s(&fp, "struct.txt", "a+b"))                         // if==1,error to open the file
	{
		puts("Can't open/create the file \'struct.dat\'");
		exit(1);
	}
	for (int i = 0; i < 2; i++)                                   //input information to the file
	{
		fwrite(&booknum[i], sizeof(struct book), 1, fp);
		//fprintf_s(fp, "\'%s\' by %s:$%.2f\n", booknum[i].name, booknum[i].author, booknum[i].price);
	}
	rewind(fp);                                                  //let the pointer point to the beginning of the file
	puts("The information of all books has been saved in the file.");
	puts("Here's what in the file:");
	while (count < 2 && fread(&booknum[count], sizeof(struct book), 1, fp) == 1)            //output the struct information to the stdout board
	{
		//fseek(fp, sizeof(struct book), SEEK_SET);
		fprintf_s(stdout, "\'%s\' by %s:$%.2f\n", booknum[count].name, booknum[count].author, booknum[count].price);
		count++;
	}
	if (fclose(fp))
		puts("Can't close file normally.");
	else
		puts("Has closed the file normally.");
	puts("Bye!");
}

/*********����ĳһ����ֵ��λ������***********/
void bit_open(void)
{
	int count=0,num,num1;
	puts("Input the number which you're calculating its opened bit(by %x).");
	scanf_s("%x", &num);
	num1 = num;
	while (num1 > 0)
	{
		num1 &= (num1 - 1);
		count++;
	}
	printf_s("The number %#x(%d) has %d bits.\n",num,num, count);
}