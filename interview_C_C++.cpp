#include <iostream>
#include <stdlib>
#include <string>

using namespace std;
//将数字转换为字符串输出
void itochar(int num)
{
    int i = 0;
    int j ;
    char stra[10];
    char strb[10];
    while ( num )
    {
        stra[i++]=num%10+48;
        num=num/10;
    }
    stra[i] = '\0';
    for( j=0; j < i; j++)
    {
        strb[j] = stra[i-j-1];
    }
    strb[j] = '\0';
    cout<<strb<<endl;
}

//编写用C语言实现的求n阶阶乘问题的递归算法
long int fact_of_n(int n)
{
	if(n==0||n==1)
	   return 1;
	else
	 return n*fact(n-1);
}

int BSearch(int a[],int x,int low,int high)
/*在下界为low，上界为high的数组a中折半查找数据元素x*/
{
	int mid;
	if(low>high) return -1;
	mid=(low+high)/2;
	if(x==a[mid]) return mid;
	if(x<a[mid]) return(BSearch(a,x,low,mid-1));
	else return(BSearch(a,x,mid+1,high));
}

//编写一个函数，作用是把一个char组成的字符串循环右移n个。比如原来是“abcdefghi”如果n=2，移位后应该是“hiabcdefgh”
#define MAX_LEN 64
void LoopMove ( char *pStr, int steps )
{
	int n = strlen( pStr ) - steps;
	char tmp[MAX_LEN]; 
	strcpy ( tmp, pStr + n ); 
	strcpy ( tmp + steps, pStr); 
	//*(tmp + strlen(pStr))='';
	strncpy( pStr, tmp ,strlen(pStr));
}
//用指针的方法,将字符串“ABCD1234efgh”前后对调显示
int reverse_print()
{

    char str[] = "ABCD1234efgh";
    int length = strlen(str);
    char * p1 = str;
    char * p2 = str + length - 1;
    while(p1 < p2)
    {
        char c = *p1;
        *p1 = *p2;
        *p2 = c;
        ++p1;
        --p2;
    }
    printf("str now is %s\n",str);
    return 0;
}
//判断一个字符串是不是回文
int IsReverseStr(char *aStr)
{
int i,j;
int found=1;
if(aStr==NULL)
	return -1;
j=strlen(aStr);
for(i=0;i<j/2;i++)
	if(*(aStr+i)!=*(aStr+j-i-1))
	{
		found=0;
		break;
	}
return found;
}

//字符串转换为数字
static int myAtoi(char* str) {  
	if(strlen(str)==0)  
	    return 0;  
	long result = 0;  // 要返回的结果result  
	int count = 0;  // 记录‘+’或者‘-’出现的次数  
	int num = 0;   // 判断空格出现的位置  
	int flag = 1; // 正数还是负数  
	for (int i = 0; i < strlen(str); i++) {  
	    char c = str[i];  
	    if(c>='0'&&c<='9'){  
	        result = result*10+c-'0';  
	        // 判断是否溢出  
	        num++;  
	    }else if(c==' '&&num==0&&count==0)  
	        continue;  
	    else if(c=='+'&&count==0){  
	        count = 1;  
	    }  
	    else if(c=='-'&&count==0){  
	        flag = -1;  
	        count = 1;  
	    }  
	    else{  
	        return (int) (flag*result);  

	    }  
	}  
	return (int) (flag*result);  
} 

int a1=3;   ///non-const data
int aa = 22;
const int a2=a1;    ///const data
const int * a4 = &a1;   ///const data,non-const pointer
printf("const int  a4==%d\n",*a4);
a4 = &aa;
//*a4 = a1;    //err read-only variable is not assignable
printf("const int  a4==%d\n",*a4);

char * strcpy( char *strDest, const char *strSrc ) 
{
	assert( (strDest != NULL) && (strSrc != NULL) );
	char *address = strDest; 
	while( (*strDest++ = * strSrc++) != '' ); 
		return address;
}

#define MIN(A,B) ((A) <= (B) ? (A) : (B))

//若处理器是Big_endian的，则返回0；若是Little_endian的，则返回1
int checkCPU()
{
　{
　　union w
　　{ 
　　　int a;
　　　char b;
　　} c;
　　c.a = 1;
　　return (c.b == 1);
　}
}

//逆序排序
char * ReverseChar(const char str)
{
	int len = strlen(str);
	char temp;
	for(int i=0; i<len/2; i++)
	{
		temp=str[i];
		str[i]=str[len-i-1];
		str[len-i-1]=temp;
	}
}

//找出两个字符串中最大公共子字符串,如"abccade","dgcadde"的最大子串为"cad"
char *commanstring(char shortstring[], char longstring[])
{
	if(strlen(shortstring)< 1 || strlen(longstring) < 1)
		return NULL;
	int i, j;
	char substring[256] = {0};
	if(strstr(longstring, shortstring)!=NULL)              //如果……，那么返回shortstring
		return shortstring; 
	for(i=strlen(shortstring)-1;i>0; i--)                 //否则，开始循环计算
	{
		for(j=0; j<=strlen(shortstring)-i; j++){
			memcpy(substring, &shortstring[j], i);
			substring[i]='\0';
			if(strstr(longstring, substring)!=NULL)
				return substring;
		}
	}
	return NULL;
}
/*
公司考试这种题目主要考你编写的代码是否考虑到各种情况，是否安全（不会溢出）
各种情况包括：
１、参数是指针，检查指针是否有效
２、检查复制的源目标和目的地是否为同一个，若为同一个，则直接跳出
３、读写权限检查
４、安全检查，是否会溢出
memcpy拷贝一块内存，内存的大小你告诉它
strcpy是字符串拷贝，遇到'\0'结束

*/
	
class String
{ 
public: 
	String(const char *str = NULL); // 普通构造函数 
	String(const String &other); // 拷贝构造函数 
	~ String(void); // 析构函数 
	String & operate =(const String &other); // 赋值函数 
private: 
	char *m_data; // 用于保存字符串 
};
//普通构造函数
String::String(const char *str) 
{
　if(str==NULL) 
　{
　　m_data = new char[1]; // 得分点：对空字符串自动申请存放结束标志''的空
　　//加分点：对m_data加NULL 判断
　　*m_data = '\0'; 
　}
　else
　{
　　int length = strlen(str); 
　　m_data = new char[length+1]; // 若能加 NULL 判断则更好 
　　strcpy(m_data, str); 
　}
}
// String的析构函数

String::~String(void) 
{
　delete [] m_data; // 或delete m_data;
}
//拷贝构造函数

String::String(const String &other) 　　　// 得分点：输入参数为const型
{ 
　int length = strlen(other.m_data); 
　m_data = new char[length+1]; 　　　　//加分点：对m_data加NULL 判断
　strcpy(m_data, other.m_data); 
}
//赋值函数
String & String::operate =(const String &other) // 得分点：输入参数为const型
{ 
　if(this == &other) 　　//得分点：检查自赋值
　　return *this; 
　delete [] m_data; 　　　　//得分点：释放原有的内存资源
　int length = strlen( other.m_data ); 
　m_data = new char[length+1]; 　//加分点：对m_data加NULL 判断
　strcpy( m_data, other.m_data ); 
　return *this; 　　　　　　　　//得分点：返回本对象的引用
}



