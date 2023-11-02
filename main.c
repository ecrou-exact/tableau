#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


#define  NBMAX = 100 ;

typedef struct
{
    int n;
    int tab[100];
}Ttab;

Ttab trie_de_tableau (Ttab t)
{
    for (int i=0; i < t.n-1; i++)
      {
        int index = i;

        for (int j=i + 1; j < t.n; j++)
        {
          if (t.tab[index] > t.tab[j])
            index = j;
        }
        if (index != i)
        {
          int tmp = t.tab[i];
          t.tab[i] = t.tab[index];
          t.tab[index] = tmp;
        }
      }
    return t;
}






Ttab remplir_tableau ()
{
    Ttab t;
    do
    {
        printf("combien voulez vous de valeurs dans votre tableau ? ");
        scanf("%d", &t.n);
    } while (t.n == 0 || t.n < 0);
    for (int i = 0 ; i<= t.n-1;i++)
    {
        do
        {
            printf("veuiller rentrer la valeur %d du tableau : ",i+1);
            scanf("%d", &t.tab[i]);
        } while (t.tab[i] < 0);
    }
    return t;
}

void afficher_tableau(Ttab t)
{
    for(int i = 0; i <= t.n-1; i++)
    {
        printf ("valeur %d : %d",i+1,t.tab[i]);
        printf("\n");
    }
}


int main()
{

    int reponse;
    Ttab t;
    do
    {
        printf(" vouler vous remplir un tableau ? 0/1 ");
        scanf("%d", &reponse);
        if (reponse == 1)
        {
            t = remplir_tableau();
            //on va tester le trie
            //int tab[] = {2,4,1,10,3,8};
            //int n = 6;
            t = trie_de_tableau (t);
            afficher_tableau(t);
        }else
        {
            printf("fin du programme");
        }
    } while (reponse < 0 || reponse > 1);


    return 0;
}
