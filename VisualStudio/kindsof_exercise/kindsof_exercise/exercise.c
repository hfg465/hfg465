#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<time.h>
#include<assert.h>
#include<stdarg.h>                                      //�ɱ��ͷ�ļ������� va_list,va_start(),va_arg(),va_end()

#define BOOKNAME 40                                     //������󳤶�
#define FIRST 0                                         //FIRSTΪ1���������򣬷���������
//#define ORDER_BY_AGE 0                                //ORDER_BY_AGEΪ1������Ӵ�С���򣬷����С��������
#define PER_NAME 4                                      //�ṹ�������Ԫ�ظ���
#define SMALL_TO_BIG 1                                  //����˳��ѡ��1-��С����0-�Ӵ�С
#define NUMB 30                                         //���������㷨��Ԫ�ظ���
#define SPACE0 "                  "                     //�궨��ո�
#define SPACE "                                       "
//#define MY_GENERIC(X) _generic(X,char:"char",int:"int",float:"float",default:"other")           //�궨�巺��ѡ����ʽ

char *s_fgets(char *str, int n);                             //fgets()�������䴦��'\n'ת��Ϊ'\0'
void book_system(void);                                      //������(linked list)����ͼ�����ϵͳ
void embellish(void);                                        /*****ת�����������η�*****/
void predef_macro(void);                                     /********Ԥ������Ӧ��********/
void save2file(void);                                        //���浽�ļ�
void my_generic(void);                                       //����ѡ����ʽ
void angle(void);                                            //�Ƕȼ���
void qsort_name_struct(void);                                //�ṹ������ʹ��qsort()����
void quick_sort(void);                                       //���������㷨��Ӧ��
int mycompar(const void *mp1, const void *mp2);              //quick_sort()����ʹ�õıȽϺ���
int compare_name(const void *cn1, const void *cn2);          //����������
void(*fp)(void);                                             //����һ������ָ��
void mystrcpy(const char *src);                              //ʵ�ֿ⺯��strcpy()�Ĺ���
void UseTime(time_t t0,clock_t clk);                         // Use some function in time.h headfile

/*ʹ��qsort()��������ṹ����*/
struct names {
	char first[10];
	char last[10];
	int age;
};

/*ʹ��������һ��ͼ������*/
struct books {
	char bookname[BOOKNAME];
	char author_fname[10];                        //������Ĭ�ϳ���Ϊ10�ֽ�
	char author_lname[10];
	float price;
	struct books *books_next;                      //�ṹ����ͬһ���ͽṹ��ָ��
};

int main()
{
	int times = 5;                             // ʹ��quick_sort()�Ĵ���
	clock_t SubClock;                          //���� UseTime()��������ӳ���ʼִ�е����øú������õ�ʱ��
	time_t Time0;                              //���� UseTime()��������ʱ���
	Time0 = time(NULL);                        //time()���ص�ǰ����ʱ�䣬��sΪ��λ����1970/1/1��ʼ����
	SubClock = clock();                        // unit is 'ms'
//	srand((unsigned int)time(NULL));           //����ϵͳʱ��Ϊsrand()�ṩ������ӣ��ṩrand()�����
	fp = save2file;                            //����ָ�븳ֵ
	srand((unsigned int)time(0));
	embellish();                               //ת�����������η����ʾ��
	predef_macro();                            //Ԥ������Ӧ��
	angle();                                   //��ѧ�⺯����Ӧ��
	save2file();                               //�������ݵ��ļ�
	fp();                                      //ʹ�ú���ָ���滻����
	qsort_name_struct();                       //�ṹ������ʹ��qsort()���������
	mystrcpy("an example");                    //ʵ��strcpy()�����Ĺ���
	book_system();                             //ʹ����������ͼ�����ϵͳ
	for (int x = 0; x < times; x++)            //ѭ�����quich_sort()
	{
		printf_s("The %d(th) circle:\n", x+1);
		quick_sort();
	}
	UseTime(Time0, SubClock);                  //
//	my_generic();
	getchar();
	return 0;
}

/*****ͼ�����ϵͳ*****/
void book_system()
{
	struct books *prev, *current, *head = NULL;                 //ǰ����û��ʼ����ָ�룬*prev��current��ֵ��current��malloc()����
	char input[BOOKNAME];
	/*���벿��*/
	puts("Input the book's title(ENTER without input to quit):");
	while (s_fgets(input, BOOKNAME) != NULL&&input[0] != '\0')
	{
		current = (struct books *)malloc(sizeof(struct books));
		if (current == NULL)
		{
			puts("Fail to call malloc() function.");
			continue;
		}
		if (head == NULL)
			head = current;
		else
			prev->books_next = current;                                  // �������ڶ���ѭ����ʼ��Ч
		current->books_next = NULL;
		strcpy_s(current->bookname,BOOKNAME*sizeof(char), input);          //����дΪ current->bookname = input;
		puts("Now input the author's first name:");
		scanf_s(" %s", current->author_fname,sizeof(current->author_fname));        // " %s" %sǰ�пո����ں��������ַ�ǰ�Ŀհ� %��s�����пո�
		puts("Now input the auther's last name:");
		scanf_s("%s", current->author_lname,10,sizeof(current->author_lname));
		puts("Now input the book's price:");
		scanf_s(" %f", &current->price,sizeof(float));
		while (getchar() != '\n')                                     //Ϊ�´�fgets()�Ķ�ȡ��ȥ'\n'������scanf()������'\n'����fgets()��ȡ��
			continue;
		prev = current;                                             //Ϊǰ���if-else������prev->books_next=current���̵�
		puts("Input the next book's title(ENTER to quit):");
	}
	/*�������*/
	if (head == NULL)
		puts("NO BOOK IS ENTERED!");
	else
		puts("The list of the books:");
	current = head;
	while (current != NULL)
	{
		int i = 0;
		while (current->bookname[i] != '\0')                          //������ȫ�����ɴ�д��ĸ
		{
			current->bookname[i] = toupper(current->bookname[i]);
			i++;
		}
		printf_s("Books:%s by %s %s,$%.2f.\n", current->bookname,current->author_fname,current->author_lname,current->price);
		current = current->books_next;
	}
	/*��������ͷ��ѷ�����ڴ�*/
	current = head;
	while (current != NULL)
	{
		head = current->books_next;
		free(current);
		current = head;
	}
	puts("That all!\n");
}

/*****ת�����������η�*****/
void embellish()
{
	putchar('\a');
	printf_s("Output two different demical numbers:\n%-+10d %-+10d\n", -125,125);
	printf_s("Output a float number:\n%6.8e %.2f%%\n",314.15926,23.0);                   // 23.0����д��23
	printf_s("Output a number with space if it is bigger than 0:\n% -10d % -10d\n", 100, -100);
	printf_s("Output two number by actal and hexademical format:\n%#-10o %#-10x\n", 315, 315);
}

/********Ԥ������Ӧ��********/
void predef_macro()
{
	printf_s("The file name is:\n%s\n", __FILE__);
	printf_s("The line is:\n%s%d\n", SPACE0,__LINE__);
//	printf_s("The environment is:\n%d\n",__STDC_HOSTED__);
	printf_s("The date of today and the time now is:\n%s%s %s\n", SPACE,__DATE__,__TIME__);
	printf_s("The version is:\n%s%lu\n", SPACE0,__STDC_SECURE_LIB__);
	printf_s("The function is:\n%s%s\n", SPACE0,__FUNCTION__);                    // __func__ Ԥ�����ʶ���� __FUNCTION__�滻
	printf_s("The last time to change the file:\n%s%s\n", SPACE,__TIMESTAMP__);
}

/******�����ݱ��浽�ļ�********/
void save2file()
{
	FILE *fp;
	char word[] = "Hello world!��";
	if (fopen_s(&fp, "save2file.txt", "a+b"))
		puts("Can't create/open the file!\n");
	else
		puts("Has create/open the file!!");
	fwrite(word, sizeof(word), 1, fp);
	fwrite("\n", 2,1,fp);
	if (fclose(fp))
		puts("Can't normally close the file.\n");
	else
		puts("Has closed the file!\n");
}

/******�Ƕȼ���********/
void angle()
{
	printf_s("The angle is:%.10f\n\n", 180.0*asin(1.0 / 2) / 3.1415926535);
}

/*****�ṹ������ʹ��qsort()����*****/
void qsort_name_struct(void)
{
	struct names name_st[PER_NAME] = {
			{ "san", "Zhang", 19 },
			{ "si", "Li", 45 },
			{ "wu", "Wang", 21 },
			{ "liu", "Zhao", 32 }
	};
	puts("persion information in original sequence:");
	puts("first name:       last name:       age:  ");
	for (int i = 0; i < PER_NAME; i++)
	{
		printf_s("%-20s%-20s%-d\n", name_st[i].first, name_st[i].last, name_st[i].age);
	}
	qsort(name_st, 4, sizeof(struct names), compare_name);
#if defined ORDER_BY_AGE
	puts("persion information in age order:");
#elif FIRST==1
	puts("persion information in first name order:");
#else
	puts("persion information in last name order:");
#endif
	puts("first name:       last name:       age:  ");
	for (int i = 0; i < PER_NAME; i++)
		printf_s("%-20s%-20s%d\n", name_st[i].first, name_st[i].last, name_st[i].age);
	puts("");
}

/*******���������㷨��Ӧ��********/
void quick_sort()
{
	/*double ����������*/
	puts("The random array vary from 0 to 30 with no sequence list:");
	double arr[NUMB];
	for (int i = 0; i < NUMB; i++)
	{
		arr[i] = (double)((rand() % 31)/(rand()%30+1.0));                // ע���ߵ� 1.0
		printf_s("%10.4f", arr[i]);
		if (i % 5 == 4)
			puts("");
	}
	if ((NUMB-1) % 5 != 4)
		puts("");
	qsort(arr, NUMB, sizeof(double), mycompar);
	puts("The sorted array list:");
	for (int i = 0; i < NUMB; i++)
	{
		printf_s("%10.4f", arr[i]);
		if (i % 5 == 4)
			puts("");
	}
	//if ((NUMB-1) % 5 != 4)
		puts("");
}

/*****quick_sort()����ʹ�õıȽϺ���******/
int mycompar(const void *mp1, const void *mp2)
{
	/****ָ������ָ�����������****/
	const double *p1 = (const double *)mp1;               // ( )Ϊǿ������ת��
	const double *p2 = (const double *)mp2;
#if SMALL_TO_BIG==1
	/*****����С�����˳������*****/
	if (*p1 > *p2)
		return 1;
	else if (*p1 == *p2)
		return 0;
	else
		return -1;
#else
	/*****���Ӵ�С��˳������*****/
	if (*p1 > *p2)
		return -1;
	else if (*p1 == *p2)
		return 0;
	else
		return 1;
#endif
}

/*****�ṹ������ʹ��qsort()�ıȽϺ���*****/
int compare_name(const void *cn1, const void *cn2)
{
	const struct names *ca1 = (const struct names *)cn1;
	const struct names *ca2 = (const struct names *)cn2;
	int ret;
	/*����������Ӵ�С����*/
#if (!defined FIRST) && ORDER_BY_AGE==1
	if(ca1->age>ca2->age)
		return -1;
	else if(ca1->age==ca2->age)
		return 0;
	else
		return 1;
	/*�����������С��������*/
#elif (!defined FIRST) && ORDER_BY_AGE==0
	if(ca1->age>ca2->age)
		return 1;
	else if(ca1->age==ca2->age)
		return 0;
	else
		return -1;
	/*������first name����*/
#elif (!defined ORDER_BY_AGE) && FIRST==1
	ret = strcmp(ca1->first, ca2->first);
	if (ret != 0)
		return ret;
	else
		return strcmp(ca1->last,ca2->last);
	/*������last name����*/
#else
	ret=strcmp(ca1->last,ca2->last);
	if (ret!=0)
		return ret;
	else
		return strcmp(ca1->first,ca2->first);
#endif
}

/******��fgets()��������������'\n'ת��Ϊ'\0'******/
char *s_fgets(char *str, int n)
{
	char *ret_val, *find;
	ret_val = fgets(str, n, stdin);
	if (ret_val)
	{
		find = strchr(str, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

/******ʵ�ֿ⺯��strcpy()�Ĺ���******/
void mystrcpy(const char *src)
{
//	assert(src != NULL);
	const char *cpsrc = src;
	char *des;
	char *cpdes;                                            //���� des ���׵�ַ
	int i = 0;
	while (*cpsrc++ != '\0')
	{
		i++;
	}
	des = (char *)malloc(i + 1);                           //Ϊ des ������ src ͬ����С�Ŀռ�
	cpdes = des;
	printf_s("the original string of \'src\' is:%s\n",src);
	while (*des++=*src++)
	{
		;
	}
	printf_s("The copied string is:%s\n\n",cpdes);
	free(cpdes);
}

/*the use of some function in time.h headfile*/
void UseTime(time_t t0,clock_t clk)
{
	struct tm *NowTime = (struct tm*)malloc(sizeof(struct tm));
	double diff;
	clock_t SubClock1;
	time_t atime,MkTime;
	char AsctimeBuf[30], CtimeBuf[30],StrTime[80];
	size_t RetStr;
	atime=time(NULL);                                                                 //��ȡ��ǰ����ʱ��
	diff = difftime(atime, t0);                                                       //����ʱ���ӳ���ִ�п�ʼ���������õ�ʱ��
	printf_s("difftime():The subtract of the two time is:%lfs.\n", diff);
	SubClock1 = clock()-clk;                                                         //clock():�������е������õ�ʱ�䣬SubClock1:����ʱ���
	printf_s("clock():The program has running %ldms (%gs).\n", SubClock1,
		((double)SubClock1)/CLOCKS_PER_SEC);                                         //����ӳ���ʼ�����øú������õ�ʱ��
	
	/*sactime()/asctime_s():���ʱ���һ�ַ�ʽ*/
	/* asctime()=ctime(localtime(time(NULL))) */
	gmtime_s(NowTime,&atime);                                                        // ��õ�ǰЭ������ʱ(UTC)�ķֽ�ʱ�䣬����ֵΪ0�������ɹ�
	asctime_s(AsctimeBuf, 30, NowTime);
	printf_s("asctime():The time now is(UTC):%s\n", AsctimeBuf);                     //�� UTC ʱ��ת��Ϊ�ַ����ĸ�ʽ
	
	/*ctime()/ctime_s():���ʱ�����һ�ַ�ʽ*/
	ctime_s(CtimeBuf, 30, &atime);
	printf_s("ctime():The time now is(local time):%s\n",CtimeBuf);
	
	/*mktime():һ�������Ѿ���struct tm �ṹ�г�Ա��ֵ�˵����*/
	MkTime = mktime(NowTime);                                                        //�� struct tm �ķֽ�ʱ��ת��Ϊ����ʱ��
	printf_s("atime:%lld,mktime():%lld\n", atime, MkTime);
	localtime_s(NowTime, &MkTime);                                                   //������ʱ��ת���ɱ���ʱ���ʾ�ķֽ�ʱ�䣬ԭ��NowTime��ʾUTCʱ��
	asctime_s(AsctimeBuf, 30, NowTime);                                              //localtime()/localtime_s() just changes the time format,the time won't vary with time area
	printf_s("asctime_s():The time now is(UTC):%s\n", AsctimeBuf);

	/* strftime():���ʱ�����һ�ַ���*/
	atime = time(NULL);
	localtime_s(NowTime, &atime);                                                    //NowTime �洢����ʱ��ķֽ�ʱ��
	RetStr=strftime(StrTime, 80, "The time is --%a %H:%M:%S %Y/%m/%d,the %U(th) week of the year--", NowTime);
	printf_s("strftime():THe value returned is:%d\n", RetStr);                       //���� 0 ��˵��ʵ���ַ������ȳ�������ռ�,or return its length
	puts(StrTime);
}

/*
void my_generic()
{
	char a_c = 'a';
	int a_t = 1024;
	float a_f = 2.0 / 3;
	printf_s("the type of a_c(%c) is:%s\n", a_c, MY_GENERIC(a_c));
	printf_s("the type of a_t(%d) is:%s\n", a_t, MY_GENERIC(a_t));
	printf("the type of a_f(%f) is:%s\n", a_f, MY_GENERIC(a_f));
	printf_s("the type of &a_t(%p) is:%s\n", &a_t, MY_GENERIC(&a_t));
}
*/