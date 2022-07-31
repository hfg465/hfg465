#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<time.h>
#include<assert.h>
#include<stdarg.h>                                      //可变参头文件，包含 va_list,va_start(),va_arg(),va_end()

#define BOOKNAME 40                                     //书名最大长度
#define FIRST 0                                         //FIRST为1，按名排序，否则按姓排序
//#define ORDER_BY_AGE 0                                //ORDER_BY_AGE为1按年龄从大到小排序，否则从小到大排序
#define PER_NAME 4                                      //结构体数组的元素个数
#define SMALL_TO_BIG 1                                  //排序顺序选择，1-从小到大，0-从大到小
#define NUMB 30                                         //快速排序算法的元素个数
#define SPACE0 "                  "                     //宏定义空格
#define SPACE "                                       "
//#define MY_GENERIC(X) _generic(X,char:"char",int:"int",float:"float",default:"other")           //宏定义泛型选择表达式

char *s_fgets(char *str, int n);                             //fgets()函数补充处理'\n'转换为'\0'
void book_system(void);                                      //用链表(linked list)创建图书管理系统
void embellish(void);                                        /*****转义序列与修饰符*****/
void predef_macro(void);                                     /********预定义宏的应用********/
void save2file(void);                                        //保存到文件
void my_generic(void);                                       //泛型选择表达式
void angle(void);                                            //角度计算
void qsort_name_struct(void);                                //结构体数据使用qsort()函数
void quick_sort(void);                                       //快速排序算法的应用
int mycompar(const void *mp1, const void *mp2);              //quick_sort()函数使用的比较函数
int compare_name(const void *cn1, const void *cn2);          //按姓名排序
void(*fp)(void);                                             //定义一个函数指针
void mystrcpy(const char *src);                              //实现库函数strcpy()的功能
void UseTime(time_t t0,clock_t clk);                         // Use some function in time.h headfile

/*使用qsort()函数排序结构数据*/
struct names {
	char first[10];
	char last[10];
	int age;
};

/*使用链表创建一个图书管理库*/
struct books {
	char bookname[BOOKNAME];
	char author_fname[10];                        //作者名默认长度为10字节
	char author_lname[10];
	float price;
	struct books *books_next;                      //结构包含同一类型结构的指针
};

int main()
{
	int times = 5;                             // 使用quick_sort()的次数
	clock_t SubClock;                          //用于 UseTime()函数计算从程序开始执行到调用该函数所用的时间
	time_t Time0;                              //用于 UseTime()函数计算时间差
	Time0 = time(NULL);                        //time()返回当前日历时间，以s为单位，从1970/1/1开始计数
	SubClock = clock();                        // unit is 'ms'
//	srand((unsigned int)time(NULL));           //根据系统时间为srand()提供随机种子，提供rand()随机数
	fp = save2file;                            //函数指针赋值
	srand((unsigned int)time(0));
	embellish();                               //转义序列与修饰符输出示例
	predef_macro();                            //预定义宏的应用
	angle();                                   //数学库函数的应用
	save2file();                               //保存数据到文件
	fp();                                      //使用函数指针替换函数
	qsort_name_struct();                       //结构体数据使用qsort()函数的输出
	mystrcpy("an example");                    //实现strcpy()函数的功能
	book_system();                             //使用链表创建的图书管理系统
	for (int x = 0; x < times; x++)            //循环输出quich_sort()
	{
		printf_s("The %d(th) circle:\n", x+1);
		quick_sort();
	}
	UseTime(Time0, SubClock);                  //
//	my_generic();
	getchar();
	return 0;
}

/*****图书管理系统*****/
void book_system()
{
	struct books *prev, *current, *head = NULL;                 //前两个没初始化的指针，*prev由current赋值，current由malloc()分配
	char input[BOOKNAME];
	/*输入部分*/
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
			prev->books_next = current;                                  // 这条语句第二次循环开始生效
		current->books_next = NULL;
		strcpy_s(current->bookname,BOOKNAME*sizeof(char), input);          //不能写为 current->bookname = input;
		puts("Now input the author's first name:");
		scanf_s(" %s", current->author_fname,sizeof(current->author_fname));        // " %s" %s前有空格，用于忽略输入字符前的空白 %与s不能有空格
		puts("Now input the auther's last name:");
		scanf_s("%s", current->author_lname,10,sizeof(current->author_lname));
		puts("Now input the book's price:");
		scanf_s(" %f", &current->price,sizeof(float));
		while (getchar() != '\n')                                     //为下次fgets()的读取消去'\n'，否则scanf()遗留的'\n'将被fgets()读取到
			continue;
		prev = current;                                             //为前面的if-else条件中prev->books_next=current作铺垫
		puts("Input the next book's title(ENTER to quit):");
	}
	/*输出部分*/
	if (head == NULL)
		puts("NO BOOK IS ENTERED!");
	else
		puts("The list of the books:");
	current = head;
	while (current != NULL)
	{
		int i = 0;
		while (current->bookname[i] != '\0')                          //将书名全部换成大写字母
		{
			current->bookname[i] = toupper(current->bookname[i]);
			i++;
		}
		printf_s("Books:%s by %s %s,$%.2f.\n", current->bookname,current->author_fname,current->author_lname,current->price);
		current = current->books_next;
	}
	/*完成任务，释放已分配的内存*/
	current = head;
	while (current != NULL)
	{
		head = current->books_next;
		free(current);
		current = head;
	}
	puts("That all!\n");
}

/*****转义序列与修饰符*****/
void embellish()
{
	putchar('\a');
	printf_s("Output two different demical numbers:\n%-+10d %-+10d\n", -125,125);
	printf_s("Output a float number:\n%6.8e %.2f%%\n",314.15926,23.0);                   // 23.0不能写成23
	printf_s("Output a number with space if it is bigger than 0:\n% -10d % -10d\n", 100, -100);
	printf_s("Output two number by actal and hexademical format:\n%#-10o %#-10x\n", 315, 315);
}

/********预定义宏的应用********/
void predef_macro()
{
	printf_s("The file name is:\n%s\n", __FILE__);
	printf_s("The line is:\n%s%d\n", SPACE0,__LINE__);
//	printf_s("The environment is:\n%d\n",__STDC_HOSTED__);
	printf_s("The date of today and the time now is:\n%s%s %s\n", SPACE,__DATE__,__TIME__);
	printf_s("The version is:\n%s%lu\n", SPACE0,__STDC_SECURE_LIB__);
	printf_s("The function is:\n%s%s\n", SPACE0,__FUNCTION__);                    // __func__ 预定义标识符被 __FUNCTION__替换
	printf_s("The last time to change the file:\n%s%s\n", SPACE,__TIMESTAMP__);
}

/******将数据保存到文件********/
void save2file()
{
	FILE *fp;
	char word[] = "Hello world!！";
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

/******角度计算********/
void angle()
{
	printf_s("The angle is:%.10f\n\n", 180.0*asin(1.0 / 2) / 3.1415926535);
}

/*****结构体数据使用qsort()函数*****/
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

/*******快速排序算法的应用********/
void quick_sort()
{
	/*double 型数据排序*/
	puts("The random array vary from 0 to 30 with no sequence list:");
	double arr[NUMB];
	for (int i = 0; i < NUMB; i++)
	{
		arr[i] = (double)((rand() % 31)/(rand()%30+1.0));                // 注意后边的 1.0
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

/*****quick_sort()函数使用的比较函数******/
int mycompar(const void *mp1, const void *mp2)
{
	/****指明具体指向的数据类型****/
	const double *p1 = (const double *)mp1;               // ( )为强制类型转换
	const double *p2 = (const double *)mp2;
#if SMALL_TO_BIG==1
	/*****按从小到大的顺序排序*****/
	if (*p1 > *p2)
		return 1;
	else if (*p1 == *p2)
		return 0;
	else
		return -1;
#else
	/*****按从大到小的顺序排序*****/
	if (*p1 > *p2)
		return -1;
	else if (*p1 == *p2)
		return 0;
	else
		return 1;
#endif
}

/*****结构体数组使用qsort()的比较函数*****/
int compare_name(const void *cn1, const void *cn2)
{
	const struct names *ca1 = (const struct names *)cn1;
	const struct names *ca2 = (const struct names *)cn2;
	int ret;
	/*优先以年龄从大到小排序*/
#if (!defined FIRST) && ORDER_BY_AGE==1
	if(ca1->age>ca2->age)
		return -1;
	else if(ca1->age==ca2->age)
		return 0;
	else
		return 1;
	/*优先以年龄从小到大排序*/
#elif (!defined FIRST) && ORDER_BY_AGE==0
	if(ca1->age>ca2->age)
		return 1;
	else if(ca1->age==ca2->age)
		return 0;
	else
		return -1;
	/*优先以first name排序*/
#elif (!defined ORDER_BY_AGE) && FIRST==1
	ret = strcmp(ca1->first, ca2->first);
	if (ret != 0)
		return ret;
	else
		return strcmp(ca1->last,ca2->last);
	/*优先以last name排序*/
#else
	ret=strcmp(ca1->last,ca2->last);
	if (ret!=0)
		return ret;
	else
		return strcmp(ca1->first,ca2->first);
#endif
}

/******对fgets()的输入做处理，将'\n'转换为'\0'******/
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

/******实现库函数strcpy()的功能******/
void mystrcpy(const char *src)
{
//	assert(src != NULL);
	const char *cpsrc = src;
	char *des;
	char *cpdes;                                            //保存 des 的首地址
	int i = 0;
	while (*cpsrc++ != '\0')
	{
		i++;
	}
	des = (char *)malloc(i + 1);                           //为 des 分配与 src 同样大小的空间
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
	atime=time(NULL);                                                                 //获取当前日历时间
	diff = difftime(atime, t0);                                                       //计算时间差，从程序执行开始到现在所用的时间
	printf_s("difftime():The subtract of the two time is:%lfs.\n", diff);
	SubClock1 = clock()-clk;                                                         //clock():程序运行到这所用的时间，SubClock1:两个时间差
	printf_s("clock():The program has running %ldms (%gs).\n", SubClock1,
		((double)SubClock1)/CLOCKS_PER_SEC);                                         //计算从程序开始到调用该函数所用的时间
	
	/*sactime()/asctime_s():输出时间的一种方式*/
	/* asctime()=ctime(localtime(time(NULL))) */
	gmtime_s(NowTime,&atime);                                                        // 获得当前协调世界时(UTC)的分解时间，返回值为0，操作成功
	asctime_s(AsctimeBuf, 30, NowTime);
	printf_s("asctime():The time now is(UTC):%s\n", AsctimeBuf);                     //将 UTC 时间转换为字符串的格式
	
	/*ctime()/ctime_s():输出时间的另一种方式*/
	ctime_s(CtimeBuf, 30, &atime);
	printf_s("ctime():The time now is(local time):%s\n",CtimeBuf);
	
	/*mktime():一般用于已经给struct tm 结构中成员赋值了的情况*/
	MkTime = mktime(NowTime);                                                        //将 struct tm 的分解时间转换为日历时间
	printf_s("atime:%lld,mktime():%lld\n", atime, MkTime);
	localtime_s(NowTime, &MkTime);                                                   //把日历时间转换成本地时间表示的分解时间，原本NowTime表示UTC时间
	asctime_s(AsctimeBuf, 30, NowTime);                                              //localtime()/localtime_s() just changes the time format,the time won't vary with time area
	printf_s("asctime_s():The time now is(UTC):%s\n", AsctimeBuf);

	/* strftime():输出时间的又一种方法*/
	atime = time(NULL);
	localtime_s(NowTime, &atime);                                                    //NowTime 存储本地时间的分解时间
	RetStr=strftime(StrTime, 80, "The time is --%a %H:%M:%S %Y/%m/%d,the %U(th) week of the year--", NowTime);
	printf_s("strftime():THe value returned is:%d\n", RetStr);                       //返回 0 ，说明实际字符串长度超出数组空间,or return its length
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