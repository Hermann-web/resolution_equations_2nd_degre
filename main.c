#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>  //la bibliothèque math.h !!!!!!!!

float discriminant( float a, float b, float c);
void lire(float *a, float *b, float *c);
float pui(float b, int n);

int main(void)
{
    float a; float b; float c; float D; int continuer;
    do
    {
        lire(&a,&b,&c);
        D=discriminant(a,b,c);
        printf("discriminant=%f \n",D);
        if(D==0 && D<0)
            printf("%f==0 et %f<0",D,D);
        if(D<0)
            printf("%f est n%cgatif",D,130);
        if (D==0)
            printf("unique solution r%celle: %f \n",130,(-b)/(2*a));
        //else if(D<0)
          //  printf("pas de solutions r%celles \n",130);
        else if(D<0)
            printf("pas de solutions r%celles \n",130);
        else
            printf("deux solutions r%celles: %f et %f \n",130,(-b-sqrt(D))/(2*a),(-b+sqrt(D))/(2*a)); //sqrt dans math.h
        printf("si vous voulez continuer, cliquez 1 sinon 0: ");
        scanf("%d",&continuer);  // le & pour le scanf !!!!
        printf("\n");
    } while(continuer==1);  //le point virgule
    return 0;
}

void lire(float *a, float *b, float *c)
{
    printf("a(x^2) + b x + c = 0 \n");
    printf("entrer a: ");
    scanf("%f",a);
    printf("entrer b: ");
    scanf("%f",b);
    printf("entrer c: ");
    scanf("%f",c);
}

float discriminant( float a, float b, float c)
{
    //return pui(b,2)- 4*(a*c);    // pui(b,2) et non b**2 //mais il y a un soucis au niveau de pui(b,2) bbref j'évite la récursivité.
    //return pow(b,2)- 4*(a*c);    //ca marche pour pow de la bibliothèque math.h
    return b*b - 4*(a*c);          //ca aussi marche                //4*a*c et non 4*(a*c) peut être que ca marche
}

float pui(float b, int n)
{
    if(n==0)
        return 1;
    return b*pui(b,n-1);
}
