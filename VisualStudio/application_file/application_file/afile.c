#include<stdio.h>
#include<stdlib.h>              //提供exit()函数源文件
#include<string.h>
#define NAME_LEN 20             //文件名长度

void t_size();       
/*
int main()           
{
	int ch,count=0;                           //储存读取的字符
	char wt[40],word[40]="Hello World!!";
	FILE *fp1,*fp2;                    //文件指针
	char r_name[20] = "tryfile.txt";
	char w_name[]="ffile.txt";     
	printf("%d", sizeof(long));
	puts("Input the file name:");
//	fgets(w_name, NAME_LEN, stdin);
	if ( fopen_s(&fp1,r_name, "rb") !=0)
	{
		fprintf(stderr, "Can't open file %s.\n",r_name);
		exit(EXIT_FAILURE);
	}
	fprintf(stderr, "Have open the file %s.\n", r_name);
	if ( fopen_s(&fp2,w_name, "wb") !=0)
	{
		fprintf(stderr, "Can't create output file %s.\n",w_name);
		exit(1);
	}
	fprintf(stderr, "Have create a output file %s.\n", w_name);
	fprintf_s(fp2, "Has open or create a output file \'ffile.txt\'\n");
	while ((fgets(wt,39,stdin)!=NULL)&&wt[0]!='#')               //以‘#’为结尾字符标志
	{
		fputs(wt,fp2);
		count++;                                       //计数写入多少个字符串
	}
	while ((fgets(wt, 39, fp1) != NULL))
	{
		fputs(wt, fp2);
		count++;
	}
	fprintf(fp2, "You have input %d strings,not this sentence included.~.~\n", count);
//	rewind(fp2);                                 //指针指向文件起始处
	if (fclose(fp2) == 0)
		fprintf(stderr, "the file has been closed,you can open it again now.\n");
	if (fopen_s(fp2, w_name, "rb") != 0)
		fprintf(stderr, "Can't open the file.\n");
	else
		while ((ch = getc(fp2)) != EOF)
		{
		putc(ch, stdout);
		}
	puts("Hello world!!");
	puts("Why it like this?");
	fprintf(stdout, "You have input %d strings.\n", count);
	if (fclose(fp1) != 0||fclose(fp2)!=0)
		fprintf(stderr, "file can't mormally close.\n");
	else
		fprintf(stderr, "file has mormally closed.\n");
	getchar();
	return 0;
}
*/

void t_size()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	int *ptr = arr;
	printf("sizeof(arr)=%d\n", sizeof(arr));
	printf("sizeof(arr+0)=%d\n", sizeof(arr + 0));
	printf("sizeof(arr+1)=%d\n", sizeof(arr + 1));
	printf("sizeof(arr[0])=%d\n", sizeof(arr[0]));
	printf("sizeof(&arr)=%d\n", sizeof(&arr));
	printf("sizeof(&arr[0])=%d\n", sizeof(&arr[0]));
	printf("sizeof(*arr)=%d\n", sizeof(*arr));
	printf("sizeof(ptr)=%zd\n", sizeof(ptr));
	printf("sizeof(ptr+0)=%d\n", sizeof(ptr + 0));
	printf("sizeof(ptr+1)=%d\n", sizeof(ptr + 1));
	printf("sizeof(ptr[0])=%d\n", sizeof(ptr[0]));
	printf("sizeof(&ptr)=%d\n", sizeof(&ptr));
	printf("sizeof(&ptr[0])=%d\n", sizeof(&ptr[0]));
	printf("sizeof(*ptr)=%d\n", sizeof(*ptr));
	getchar();
	return 0;
}