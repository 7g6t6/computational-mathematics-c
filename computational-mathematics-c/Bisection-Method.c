#include<stdio.h>
#include<math.h>
#include<time.h>

double f(double x); //Funkciya
int res(int i, double a, double b, double z, double e1, double e2); //Pechat resultata
double Bisection(double a, double b, double e1, double e2); //Metod dihotomii

int main()
{
    double a, b, z, h=0.5, k, x1, x2, e1, e2;
    int i=0;

    printf(" __________________________________________________________  \n");
    printf("|                                                          | \n");
    printf("| Reshenie uravneniya s odnoi peremennoi metodom dihotomii | \n");
    printf("|__________________________________________________________| \n\n");
    printf("\nISHODNYE DANNYE:\n");
    printf("\nFunkciya: f(x) = 2^x - 2 * cos(x)");
    printf("\nVvedite nachalo intervala a = ");
	scanf("%lf", &a);
    printf("Vvedite konec intervala b = ");
	scanf("%lf", &b);
    printf("Vvedite tochnost vychisleniya po argumentu e1 = ");
	scanf("%lf", &e1);
    printf("Vvedite tochnost vychisleniya po funkcii e2 = ");
	scanf("%lf", &e2);
    printf("\n\nRESHENIE:");

    clock_t t; //Vremya vypolneniya programmy
    t=clock(); //Vremya vypolneniya programmy

    //Otdelenie kornei
    x1=a;
    x2=x1+h;
    while (x2<=b)
    {
        if ((f(x1)*f(x2))<0) 
        {
            i++;
            printf("\n\n%d) %di koren uravneniya soderzhitsya na otrezke [%.1f, %.1f]\n",i, i, x1, x2);
            printf("\nn\t     a\t\t   b\t\t x\t     f(x)\t     e1\t\t    e2\n");
            Bisection(x1,x2,e1,e2); //Utochnenie kornei metodom dihotomii
        }
        x1=x2;
        x2=x1+h;
    }

    t = clock()-t; //Vremya vypolneniya programmy
    float time_taken=((float)t)/CLOCKS_PER_SEC; //Vremya vypolneniya programmy
    printf("Vremya vypolneniya programmy: %f sec \n\n", time_taken);
    return 0;
}

//Zadannaya funkciya
double f(double x) 
{
   double y;
   y=pow(2,x)-2*cos(x);
   return y;
}

//Pechat resultata
int res(int i, double a, double b, double z, double e1, double e2) 
{
   printf("%d\t%10.7f    %10.7f    %10.7f    %10.7f    %e    %e\n", i, a, b, z, f(z), e1, e2);
   return 0;
}

//Metod dihotomii
double Bisection(double a, double b, double e1, double e2)
{
    double z=(a+b)/2; //Seredina otrezka
    double val = f(z);
    double k;
    int i=0;
    if (val==0) 
    {
        printf("Koren uravneniya: %f \n\n", z);
    }
    else 
    {
        while ((fabs(val)>e2) && (fabs(b-a)>e1)) //Tochnost opredeleniya kornya
        {
            if ((f(a)*val)<0) 
            {
                b=z;
            }
            else 
            {
                a=z;
            }
            z=(a+b)/2;
            val = f(z);
            res(i+1, a, b, z, e1, e2); //Pechat resultata
            i++;
        }
        k = fabs(z-a)/fabs(b-a);
        printf("\nParametr skhodimosti: k=%.1f\n", k);
        printf("Koren uravneniya z=%.7f najden posle %d iteracij\n", z, i);
        printf("Znachenie funkcii f(z)=%.10f najdeno posle %d vychislenij\n", f(z), i);
    }
    return 0;
}