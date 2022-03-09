#include <stdio.h>
#include <math.h>
#include <omp.h>

void affTab(int *tab, int size);

int main() {
    double start;
    double end;
    int j;
    int n =300000;
    int p;
    int a[n];
    for(int i =0;i<n;i++)
        a[i]=i;
    start = omp_get_wtime();
    for(int i=2;i<sqrt(n);i++){
        if(a[i]>0){
            for(j=pow(i,2);j<n;j+=i)
                a[j]=0;
        }
    }
    p=0;
    for(j=0;j<n;j++){
        if(a[j]>0){
            a[p]=a[j];
            p++;
        }
    }
    end = omp_get_wtime();
    printf("Work took %f seconds for sequential\n", end - start);
    for(int i =0;i<n;i++)
        a[i]=i;
    start = omp_get_wtime();
    /*Paralel est plus long car le crible supprime les multiples des nombres ,
     * or si on découpe le for il y aura des recouvrements dans la supression de certaines valeurs*/
    int max =sqrt(n);
    #pragma omp parallel for private(j)
    for(int i=2;i<max;i++){
        if(a[i]>0){
            for(j=pow(i,2);j<n;j+=i)
                a[j]=0;
        }
    }
    p=0;
    for(j=0;j<n;j++){
        if(a[j]>0){
            a[p]=a[j];
            p++;
        }
    }
    end = omp_get_wtime();
    printf("Work took %f seconds for parallel\n", end - start);
    affTab(a,n);
    return 0;
}

void affTab(int *tab, int size){
    int lastvalue=0;
    for(int i=0;i<size;i++){
        if(tab[i]>lastvalue){
            printf("%d : ",tab[i]);
            lastvalue=tab[i];
            if(i%30==0)
                printf("\n");
        }
    }
}
