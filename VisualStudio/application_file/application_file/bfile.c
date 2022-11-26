#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FILE_NAME_LEN 20
#define WORD_LEN 256

/******以命令行输入文件名与待查找字符******/
int main(int argc,char *argv[])
{
	FILE *wfp,*rfp;
//	char bwfile[FILE_NAME_LEN], brfile[FILE_NAME_LEN];           //argv[0]=bwfile[],argv[1]=brfile[]
	char word[WORD_LEN],*find_ch;
	int i = 0, j=0, l_count = 0, c_count = 0, ct[256] = { 0 };                     // line count,column count，计数查找的字符在文件中的位置
	if (argc < 4)                            //若参数过少，退出程序
	{
		puts("The number of argument is to low.");
		getchar();
		exit(EXIT_FAILURE);
	}
	puts("Input a file name which is wrote data into and read now:");
//	scanf_s("%s", bwfile,FILE_NAME_LEN);                     //输入文件名
	if (fopen_s(&wfp, argv[1], "ab+")!= 0)                    //可读写，在末尾添加内容
	{
		fprintf_s(stderr,"Error to open/create the file \'%s\'.\n", argv[1]);
		getchar();
		exit(EXIT_FAILURE);
	}
	fprintf_s(stdout, "Has opened/created the file \'%s\'.\n", argv[1]);
	fprintf_s(wfp,"$>Has opened/created the file \'%s\'.\n", argv[1]);                    // to bwfile
	fprintf_s(wfp, "$>%s\n", argv[1]);                                                // to bwfile
	fprintf_s(stdout, "Now input something into the file \'%s\'(input '#' to quit).\n", argv[1]);
	fprintf_s(wfp, "$>Now input something into the file \'%s\'(input '#' to quit).\n\n", argv[1]);         // to bwfile
	fprintf_s(wfp, "The character you gonna find is \'%c\'.\n\n", *argv[3]);
	fprintf_s(wfp, "Here's what you typed:\n", argv[1]);                              // to bwfile
	while ((fgets(word,WORD_LEN,stdin)!=NULL)&&word[0]!='#')              //将字符输入文件 argv[0]/bwfile[]
	{
		fputs(word,wfp);
	}
	if (fopen_s(&rfp, argv[2], "ab"))              //更新模式打开 brfile[]/argv[1]
	{
		fprintf_s(stderr,"Can't open/create the file \'%s\'.\n", argv[2]);
		puts("Bye!");
		getchar();
		exit(EXIT_FAILURE);
	}
	rewind(wfp);                                //将文件指针设置到文件开始处，或 fseek(wfp,0L,SEKK_SET);
	while ( fgets(word, WORD_LEN, wfp) != NULL)
	{
		for (i = 0; i < strlen(word); i++)
		{
			c_count++;
			if (word[i] == *argv[3])
			{
				ct[j] = c_count;
				j++;
			}
			if (i==255||word[i] == '\n')               //关系运算符>||/&&>赋值运算符
			{
				l_count++;
				c_count = 0;
				j = 0;
			}
		}
		find_ch = strchr(word, *argv[3]);
		if (find_ch == NULL)
			continue;
		else
		{
			fputs(word, rfp);
			fprintf_s(rfp, "(Its location is %d line ", l_count);
			for (i = 0; i <j-1; i++)
				fprintf_s(rfp, "%d,", ct[i]);
			fprintf_s(rfp,"%d column.)\n\n",ct[j-1]);
		}
	}
	if (fclose(wfp)||fclose(rfp))                    //关闭文件 argv[0]/bwfile[]
	{
		puts("Error to close the flie you just opened.");
	}
	puts("Has normally closed the file you just opened.");
	getchar();
	return 0;
}