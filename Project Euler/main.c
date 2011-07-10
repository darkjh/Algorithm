#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int p_1(int n)
{
    int i;
    int sum=0;
    for(i=1;i<n;i++)
    {
        if(i%3==0 || i%5==0)
            sum+=i;
    }
    return sum;
}

int p_2(int limit)
{
    int a=0,b=1,c=0;
    long sum=0;
    while(b<=limit)
    {
        if(b%2==0)
        {
            sum+=b;
            if(b>limit)
            {
                sum=sum-b;
                break;
            }
        }
        c=b;
        b=a+b;
        a=c;
    }
    return sum;
}
int prime(long long int n)
{
    long long int i;
    if(n%2==1){
    for(i=2;i<=sqrt(n);i++)
       {
       if(n%i==0)
            {
                return 0;
            }
       }
    return 1;
    }
    else
        return 1;
}

int prime();

long long p_3(long long int n)
{
    long long int i;
    long long int result;
    for(i=2;i<=sqrt(n);i++)
        {
            if(n%i==0 && prime(i)==1)
            result=i;
        }
    return result;
}

int char_to_int(char a[])
{
    int n=strlen(a);
    int i=0,sum=0;
    for(i=0;i<n;i++)
        sum+=pow(10,n-i-1)*(a[i]-'0');
    return sum;
}

int palindrome(char a[],int l)
{
    int i;
    int test=1;
    if(l%2==1)
    {
        for(i=0;i<(l/2-1);i++)
            if(a[i]!=a[l-1-i])
                test=0;
    }
    if(l%2==0)
    {
        for(i=0;i<(l/2);i++)
            if(a[i]!=a[l-1-i])
                test=0;
    }
    return test;
}

int p_4()
{
    int i=0,j=0;
    int inter,l;
    int result=0;
    char c[10];
    for(i=100;i<1000;i++)
        for(j=100;j<1000;j++)
        {
            inter=i*j;
            sprintf(c,"%d",inter);
            l=strlen(c);
            if(palindrome(c,l)==1 && inter>result)
                result=inter;
        }
    return result;

}

int p_5()
{
    int i=20,flag=0,j;
        for(i=20;;i=i+2)
            {flag=0;
            for(j=1;j<20;j++)
                {if(i%j!=0)
                 flag=1;}
             if(flag==0)
                break;
            }
    return i;
}

int p_6()
{
    int i=0;
    long sum1=0,sum2=0,sum;
    for(i=1;i<101;i++)
    {
        sum1+=i*i;
        sum2+=i;
    }
    sum=sum2*sum2-sum1;
    printf("%d",sum);
}

void p_7()                      //所有质数满足的条件为他们都能表示成 6n +/- 1
{
    int count=2;
    int i=1;
    long result;
    while(count<=10001)
    {
        if(prime(6*i-1))
        {
            count++;
            result=6*i-1;
            if(count==10001)
                break;
        }

        if(prime(6*i+1))
        {
            count++;
            result=6*i+1;
            if(count==10001)
                break;
        }
        i++;
    }
    printf("%d",result);
}

void p_8()
{
    char temp[1000];
    int a[1000];
    int i=0,j,flag=0;
    int product=1;
    int max;
    FILE *pfile;
    //lire les chiffres a partie du fichier comme des caractere
    if((pfile=fopen("data_p_8.txt","r"))!=NULL)
    {
        for(i=0;i<1000;i++)
        {
            fscanf(pfile,"%c",&temp[i]);
            //printf("%c",temp[i]);
        }
        fclose(pfile);
    }

    //convertir les caractere aux chiffres
    for(i=0;i<1000;i++)
    {
        a[i]=temp[i]-'0';
        //printf("%d",a[i]);
    }
    //printf("%d",a[3]);

    //la commence de l'algo
    max=a[0]*a[1]*a[2]*a[3]*a[4];
    for(i=5;i<1000;i++)
    {
        product=1;
        flag=0;
        for(j=i;j<i+5;j++)
            if(a[j]==0)
                flag=1;
        if(flag==0)
        {
       for(j=i;j<i+5;j++)
       {
            product*=a[j];
       }
       if(product>max)
            max=product;
        }
        else
            i=i+5;

    }
    printf("%d",max);
}

void InsertionSort(int a[], int n)
{
    int i,j;
    int key;
    for(i=1;i<n;i++)
    {
        key=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>key)
                a[j+1]=a[j];
            else
                break;
        }
        a[j+1]=key;
    }
}
int SC( int n )
{
    if ( n==1 )
        return( 1 );
    else
        return( n*n+SC(n-1) );
}

int* jiecheng(int n)
{
    int a[5]={-1};

    return a;
}

int main()
{
//    int b=3;
//    int a=SC(3);
//    printf("%d",a);
    printf("%d",jiecheng(2)[3]);



















//    long a=p_2(4000000);
//    long long int a=p_3(600851475143);
//
//    int a=palindrome(c,strlen(c));
//    int a=prime(13);
//    printf("%d",a);
//    p_8();


}


