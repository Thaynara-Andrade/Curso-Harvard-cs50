#include<stdio.h>
int main()
{
    int a[10],i,j,temp,n;
    printf("\n Insira o número máximo de elementos a classificar: \n");
    scanf("%d",&n);
    printf("\n Digite os Elementos : \n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    for(i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}