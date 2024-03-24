#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>




///********************************************************************************************************************///
   void s_sleep(int seconds) {
    /* Init. */
    time_t start_time = 0;
    time_t current_time = 0;

    /* Operate. */
    start_time = time(NULL);
    while(current_time-start_time+1 <= seconds) {
        current_time = time(NULL);
    }
}
///************************************************************************************************************************///
  typedef struct cartebancaire{

  char numcarte[20];
  char code[5];
  int moisdexpiration;
  int anneedexpiration;

  }crt;
///*********************************************************************************************************************///
void TAKEPASSEWORD(char pwd[50]){

  int i=0;
  char ch;
  while(1){
    ch=getch();
    if(ch==13){
        pwd[i]='\0';
        break;

    }
    pwd[i++]=ch;
    printf("*");
      }


  }
///********************************************************************************************************************///
int generateNumber(int max){
    srand(time(NULL));
    return rand() % max;
}
///********************************************************************************************************************///
      typedef struct clientlogin
       {
        char USERID[50];
        char MOTDEPASSE[10];
       }log;


///**********************************************************************************************************************///
      typedef struct clientinscrire
      {
        char userid[20];
        char motdepasse[50];
      }esp;
      ////********************************************************************************************************************///
      typedef struct ecriredansfichier{

          char login[30];
         char passseword[30];
      }ecriredsfichier;
       ///***********************************************************************************************************************///
         typedef struct espacedeadmin{

          char login1[30];
         char passseword1[30];
      }espa;
      ///*************************************************************************************************************************///
      typedef struct voyage {
          char ville_depart[50];
          char ville_arrivee[50];
          char heure_depart[30];
          char heure_arrivee[30];
          int prix;
          int nb_places;
      }vg;
      ///**********************************///
      typedef struct DATEVOYAGE {
      int jour;
      int mois;
      int annee;

      }date;
      ///*************************************************************************************************************************///
      typedef struct cherchervoyage{
      char ville_depart1[50];
      char ville_arrivee[50];
      date DV;

      }chvg;
      ///*******************************///


///***************************************************************************************************************************///

   typedef struct {
     char nom[20];
     char prenom[30];
     char email[50];
      int telephone;
      char CIN[50];
}info;
///******************************************************************************************************************************///
    void Color(int t,int f)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}
///**************************************************************************************************************************///


void INTERFACESITE()
   {
       int choix;
       Color(13,0);
       printf("\n");
       printf ("\t\t\t\t\t\t\t\t\t* * * * * * * * * * * * * * * *\n");
        printf ("\t\t\t\t\t\t\t\t\t*                             * \n");
       printf ("\t\t\t\t\t\t\t\t\t*  WELCOME TO TRAVEL AGENCY    * \n");
        printf ("\t\t\t\t\t\t\t\t\t*                             * \n");
      printf ("\t\t\t\t\t\t\t\t\t* * * * * * * * * * * * * * * *\n");
       Color (15,0);
       printf ("\n");
       printf ("\n");
       printf ("\t\t\t\t\t\t\t\t\t   * * * * * * * * * * * * *\n");
       printf ("\n\t\t\t\t\t\t\t\t\t      1-ESPACE ADMIN \n");
       printf ("\n\t\t\t\t\t\t\t\t\t      2-ESPACE CLIENT \n");
       printf ("\n\t\t\t\t\t\t\t\t\t      3-QUITTER \n");
      printf ("\n\t\t\t\t\t\t\t\t\t   * * * * * * * * * * * * *\n");
      debut:
       printf("\n\t\t\t\t\t===> ");
       scanf ("%d",&choix);
          switch (choix)
          {
               case 1 :
                     system("cls");
                     printf ("\n");
                     printf ("\n");
                      Color(13,0);
                     printf("\t\t\t\t\t\t\t\t\t- - - - - - - LOG IN ADMIN - - - - - - -\n");
                      Color(15,0);
                       printf ("\n");
                     espaceadmin();
                     break;

                case 2:
                    system("cls");
                    LOGINCLIENT();
                    break;

                case 3:
                    system("cls");
                    QUITTER();
                    break;

                default :
                    Beep(500,700);
                    printf("\t\t\t\t\t\t CHOIX INVALIDE");
                    goto debut;
                    break;

         }
   }
   ///*****************************************************************************************************************///
   void espaceadmin()
   {
           ecriredsfichier *e = (ecriredsfichier *)malloc(sizeof(ecriredsfichier));
           espa *a=(espa *)malloc(sizeof(espa));
           FILE *fichier =fopen("admin100","rb");

               printf("\n\t\t\t\t\t\t\t\t\t  LOGIN ===>   ");
               fflush(stdin);
               gets(a->login1);
               printf("\n\t\t\t\t\t\t\t\t\t  PASSEWORD  ===>   ");
              TAKEPASSEWORD(a->passseword1);
               int i=0;
               while(!feof(fichier))
                  {
                 fread( e,sizeof(ecriredsfichier),1,fichier);

                  if(strcmp(e->login,a->login1)==0 && strcmp(e->passseword,a->passseword1)==0)
                         {
                              i++;
                              break;
                         }

                  }

                if(i!=0)
        {
                        printf("\n");
                        printf("\n");
                           Color(13,0);
                        printf("\n\t\t\t\t\t\t\t\t\t\t** SUCCESFUL LOGIN  ** \n");
                        printf("\n\t\t\t\t\t\t\t\t\t\t\t...");
                           s_sleep(4);
                           system("cls");
                           printf("\n");
                           printf("\n");
                        printf("\t\t\t\t\t\t\t\t\t\t   * * WELCOME ADMIN %s * * \n",a->login1);
                           Color(15,0);
                        printf("\n");
                        printf("\n");
                        admin2();
        }
             else
                {
                    printf("\n");
                    printf("\n");
                 printf("\n\t\t\t\t\t\t\t\t\t      LOGIN OR PASSEWORD INCORRECTE.\n");
                   printf("\n");
                 espaceadmin();
                }


            fclose(fichier);
   }

  ///**************************************************************************************************************///
    void admin2()
    {

      int reponse;
      printf("\n");
      printf("\n");
      printf("\t\t\t\t\t\t\t\t\t\t- - - - - - - - - - - - - - - - - - - -\n");
      printf("\n\t\t\t\t\t\t\t\t\t\t   1-ACCESCOMMENTAIRE           \n");
      printf("\n\t\t\t\t\t\t\t\t\t\t   2-AJOUTERADMIN               \n");
      printf("\n\t\t\t\t\t\t\t\t\t\t   3-MODIFIERVOYAGE             \n");
      printf("\n\t\t\t\t\t\t\t\t\t\t   4-RETOUR AU MENU PRECEDENT   \n");
      printf("\n\t\t\t\t\t\t\t\t\t\t   5-QUITTER                    \n");
      printf("\n\t\t\t\t\t\t\t\t\t\t- - - - - - - - - - - - - - - - - - - -\n");
        debut :
          printf("\n\t\t\t\t\t ===> ");
          scanf("%d",&reponse);
            switch(reponse)
            {

               case 1:
               system("cls");
               ACCESCOMMENTAIREETRATING();
               break;

               case 2:
               system("cls");
               AJOUTERADMIN();
               break;

               case 3:
              system("cls");
              MODIFIERVOYAGE();
               break;

               case 4:
                system("cls");
               INTERFACESITE();
               break;

               case 5:
                system("cls");
               QUITTER();
               break;

               default:
                Beep(500,700);
               printf(" CHOIX INVALIDE ");
               goto debut;
               break;

              }
  }

  ///*****************************************************************************************************************///

   void ACCESCOMMENTAIREETRATING()
   {
       int reponse;
       printf("\n");
       printf("\n");
       printf("\t\t\t\t\t\t\t\t\t\t- - - - - - - - - - - - - -\n");
       printf("\n\t\t\t\t\t\t\t\t\t\t    1-COMMENTAIRE\n");
       printf("\n\t\t\t\t\t\t\t\t\t\t    2-EVALUATION  \n");
       printf("\n\t\t\t\t\t\t\t\t\t\t    3-MENU\n");
       printf("\n\t\t\t\t\t\t\t\t\t\t    4-QUITTER\n");
      printf("\n\t\t\t\t\t\t\t\t\t\t- - - - - - - - - - - - - -\n");
        debut:
        printf("\n\t\t\t\t==> ");
       scanf("%d",&reponse);
       switch(reponse){
      case 1:
        system("cls");
        COMMENTAIRE();
        break;
      case 2:
        system("cls");
        EVALUATION();
        break;
      case 3:
        system("cls");
        admin2();
        break;
      case 4:
        system("cls");
        QUITTER();
        break;

        default:
         Beep(500,700);
         printf(" CHOIX INVALIDE ");
         goto debut;
         break;

       }

    }

  ///*****************************************************************************************************************///
  void  COMMENTAIRE(){
      int REPONSE;
      printf("\n");
      printf("\n");
      printf("\t\t\t\t\t\t\t\t\t\t- - - - - - - - - - - - - - -\n");
      printf("\n\t\t\t\t\t\t\t\t\t\t  1-AFFICHER COMMENTAIRE\n");
      printf("\n\t\t\t\t\t\t\t\t\t\t  2-SUPPRIMER COMMENTAIRE\n");
      printf("\n\t\t\t\t\t\t\t\t\t\t  3-MENU\n");
      printf("\n\t\t\t\t\t\t\t\t\t\t  4-QUITTER\n");
     printf("\n\t\t\t\t\t\t\t\t\t\t- - - - - - - - - - - - - - -\n");
      debut:
          printf("\t\t\t\t==> ");
          scanf("%d",&REPONSE);
      switch(REPONSE)
      {


         case 1:
               system("cls");
               AFFICHERCOMMENTAIRE();
               break;

        case 2:
              system("cls");
              SUPRIMMERCOMMENTAIRE();
              break;
        case 3:
              system("cls");
              ACCESCOMMENTAIREETRATING();
              break;

        case 4:
             system("cls");
             QUITTER();
             break;

        default:
              Beep(500,700);
              printf("CHOIX INVALIDE");
              goto debut;
              break;


       }

  }
 ///*****************************************************************************************************************///

     void EVALUATION(){
         FILE *fichier=fopen("evaluation.txt","rt");
         int i=0,j=0,k=0,l=0,m=0;
         char reponse[15];
         fflush(stdin);
              while(!feof(fichier))
               {
                fscanf(fichier,"%s\n",reponse);
                if( strcmp(reponse,"*")== 0 )
                    {
                    i++;
                    }
                else if(strcmp(reponse,"**")==0 )
                    {
                    j++;
                    }
                else if(strcmp(reponse,"***")==0)
                    {
                     k++;
                    }
                else if(strcmp(reponse,"****")==0)
                    {
                     l++;
                    }
                else if(strcmp(reponse,"*****")==0)
                    {
                     m++;
                    }

                  }
     fclose(fichier);

            printf("\n");
            printf("\n");
            if(i!=0 || j!=0 || k!=0 || l!=0 || m!=0 ){
           printf("\n\t\t\t\t\t\t\t\t ( %d ) PERSONNE ONT VOTE (*) .\n",i);
           printf("\n\t\t\t\t\t\t\t\t ( %d ) PERSONNE ONT VOTE (**) .\n",j);
           printf("\n\t\t\t\t\t\t\t\t ( %d ) PERSONNE ONT VOTE (***) .\n",k);
           printf("\n\t\t\t\t\t\t\t\t ( %d ) PERSONNE ONT VOTE (****) .\n",l);
           printf("\n\t\t\t\t\t\t\t\t ( %d ) PERSONNE ONT VOTE (*****) .\n",m);}

           else if(i==0 || j==0 || k==0 || l==0 || m==0 ){
           printf("AUCUN RATING POUR LE MOMENT"); }

           Color(13,0);
           printf("\n");
           printf("\t\t\t\t\t\t\t\t FIN TRAITEMENT.\n");
           Color(15,0);
           printf("\n\t\t\t\t\t\t\t\t===> TAPEZ ENTRER POUR REVENIR AU MENU .");
           getche();
           system("cls");
           ACCESCOMMENTAIREETRATING();

  }
  ///*****************************************************************************************************************///
void EVALUATION3(){
    FILE *fichier=fopen("evaluation.txt","rt");
         int i=0,j=0,k=0,l=0,m=0;
         char reponse[15];
         fflush(stdin);
              while(!feof(fichier))
               {
                fscanf(fichier,"%s\n",reponse);
                if( strcmp(reponse,"*")== 0 )
                    {
                    i++;
                    }
                else if(strcmp(reponse,"**")==0 )
                    {
                    j++;
                    }
                else if(strcmp(reponse,"***")==0)
                    {
                     k++;
                    }
                else if(strcmp(reponse,"****")==0)
                    {
                     l++;
                    }
                else if(strcmp(reponse,"*****")==0)
                    {
                     m++;
                    }

                  }
     fclose(fichier);

            printf("\n");
            printf("\n");
            if(i!=0 || j!=0 || k!=0 || l!=0 || m!=0 ){
           printf("\n\t\t\t\t\t\t\t\t ( %d ) PERSONNE ONT VOTE (*) .\n",i);
           printf("\n\t\t\t\t\t\t\t\t ( %d ) PERSONNE ONT VOTE (**) .\n",j);
           printf("\n\t\t\t\t\t\t\t\t ( %d ) PERSONNE ONT VOTE (***) .\n",k);
           printf("\n\t\t\t\t\t\t\t\t ( %d ) PERSONNE ONT VOTE (****) .\n",l);
           printf("\n\t\t\t\t\t\t\t\t ( %d ) PERSONNE ONT VOTE (*****) .\n",m);}

           else if(i==0 || j==0 || k==0 || l==0 || m==0 ){
           printf("AUCUN RATING POUR LE MOMENT"); }




}
///******************************************************************************************************************///
  void AFFICHERCOMMENTAIRE2(){

       FILE *FICHIER =fopen("commen.txt","r");
       char commentaire[10000];
       printf("\n");
       printf("\n\t\t\t\t\t\t\t\t* * * * * LES COMMENTAIRES DES CLIENTS SONT : * * * * \n");
        printf("\ \n");
        printf("\n\t\t\t\t\t\t    N COMMENTAIRE                       COMMENTAIRE \n");
          while(fgets(commentaire,1000,FICHIER)!=NULL)
            {

               Color(13,0);
               printf("\t\t\t\t\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
               Color(15,0);
               printf("\t\t\t\t\t\t");
               fflush(stdin);
               puts(commentaire);

          }
             fclose(FICHIER);
    }
  ///*****************************************************************************************************************///

    void AFFICHERCOMMENTAIRE(){

       FILE *FICHIER =fopen("commen.txt","r");
       char commentaire[10000];
       printf("\n");
       printf("\n\t\t\t\t\t\t\t\t* * * * * LES COMMENTAIRES DES CLIENTS SONT : * * * * \n");
        printf("\ \n");
        printf("\n\t\t\t\t\t\t    N COMMENTAIRE                       COMMENTAIRE \n");
          while(fgets(commentaire,1000,FICHIER)!=NULL)
            {

               Color(13,0);
               printf("\t\t\t\t\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
               Color(15,0);
               printf("\t\t\t\t\t\t");
               fflush(stdin);
               puts(commentaire);

          }
             fclose(FICHIER);
             Color(13,0);
             printf("\n\t\t\t\t\t\t\t  FIN TRAITEMENT.\n");
             Color(15,0);
             printf("\n\t\t\t\t\t\t===> TAPEZ POUR REVENIR AU MENU ");
             getche();
             system("cls");
             COMMENTAIRE();

    }


  ///********************************************************************************************************************///

         void SUPRIMMERCOMMENTAIRE(){
              FILE *FICHIER =fopen("commen.txt","r");
              FILE *FICHIER2 =fopen("commen44.txt","w");
              char reponse [10000];
              char reponse3 [30];
              char reponse4 [30];
              int i=0;
              AFFICHERCOMMENTAIRE2();
                printf("\n");
                printf("\n");
                debut:
                 printf("\t\t\t\t\t\t===> ENTRER LE CODE DE QUATRE CHIFFRE DU COMMENTAIRE DONT VOULEZ VOUS SUPPRIMER :");
                   fflush (stdin);
                   gets(reponse);

                     while (fgets(reponse4,1000,FICHIER)!=NULL)
                       {
                           fflush (stdin);

                             char *C= strstr(reponse4,reponse);
                             if (C==NULL)
                               {
                                fputs(reponse4,FICHIER2);

                               }
                               else{
                               i++;}
                       }


                       fclose(FICHIER);
                       fclose(FICHIER2);
                       remove("commen.txt");
                       rename("commen44.txt","commen.txt");


                       if(i!=0){
                            Color(13,0);
                        printf("\n\t\t\t\t\t\t SUCCESFFUL OPERATION\n");
                             Color(15,0);
                        printf("\n\t\t\t\t\t\t ==> TAPEZ POUR REVENIR AU MENU \n");
                        getche();
                        system("cls");
                        COMMENTAIRE();

                       }
                       else {
                        printf("\n\t\t\t\t\t\t FAILED OPERATION OR CODE WRONG\n");
                        printf("\n\t\t\t\t\t\t TRY AGAIN\n");
                        s_sleep(4);
                        system("cls");
                        COMMENTAIRE();
                       }








    }

  ///********************************************************************************************************************///

    void AJOUTERUNADMIN()
    {
         ecriredsfichier *e =(ecriredsfichier *)malloc(sizeof(ecriredsfichier));;
         FILE *fichier=fopen("admin100","ab");
         printf("\n");
         printf("\n");
         printf("\n\t\t\t\t\t\t\t LOGIN ==> ");
         fflush(stdin);
         gets(e->login);
         printf("\n\t\t\t\t\t\t\t PASSEWORD ==> ");
         TAKEPASSEWORD(e->passseword);


         fwrite(e,sizeof(ecriredsfichier),1,fichier);
         fwrite("\n",sizeof(ecriredsfichier),1,fichier);
         fclose(fichier);
         Color(13,0);
         printf("\n");
         printf("\n");

         printf("\n\t\t\t\t\t\t\t SUCCESFUL OPERATION");
          Color(15,0);

   }
  ///*******************************************************************************************************************///


        void AJOUTERADMIN()
        {

            AJOUTERUNADMIN();
             printf("\n");
            printf("\n\t\t\t\t\t\t\t TAPEZ POUR REVENIR AU MENU :");
            getche();
            system("cls");
            admin2();
        }



///******************************************************************************************************************///
  void MODIFIERVOYAGE(){
     int (reponse);
     printf("\n");
     printf("\n");
     printf("\t\t\t\t\t\t\t\t\t - - - - - - - - - - - - - - - - - \n");

      printf("\n\t\t\t\t\t\t\t\t\t      1-AJOUTER VOYAGE\n");
      printf("\n\t\t\t\t\t\t\t\t\t      2-SUPRRIMMER VOYAGE\n");
      printf("\n\t\t\t\t\t\t\t\t\t      3-MENU \n");
     printf("\n\t\t\t\t\t\t\t\t\t - - - - - - - - - - - - - - - - \n");
      debut:
          printf("\n");
      printf("\n\t\t\t\t\t\t\t\t ==>  ");

        scanf("%d",&reponse);
        switch(reponse){
        case 1 :

            AJOUTERVOYAGE();
            break;
        case 2 :

           SUPPRIMERVOYAGE();
          break;

        case 3:
            system("cls");
            admin2();
            break;

        default :
             Beep(500,700);
            printf("CHOIX INVALIDE ");
            goto debut;
            break;

        }

        }
///*****************************************************************************************************************///
  void AJOUTERVOYAGE()
  {
     system("cls");
     SAISIEVOYAGE();
     printf("\n\t\t\t\t\t\t\t\t\t TAPEZ POUR REVENIR AU MENU :");
     getche();
     system("cls");
     MODIFIERVOYAGE();

     }
///******************************************************************************************************************///

      void SUPPRIMERVOYAGE(){
          FILE *fichier = fopen("voyage.txt","rt");
          vg *v1=(vg *)malloc(sizeof(vg));
          int d;
          int reponse;
          int r;

          printf("\n\t\t\t LES VOYAGES DISPONIBLES SONT :\n");
             Color(13,0);
               printf("\n\t\t\t\t   N VOYAGE    VILLE DEPART   VILLE ARRIVEE   H_DEPART   H_ARRIVEE   PLACES_DISPO    PRIX\n");
               Color(15,0);
               printf("\t\t\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
          while(!feof(fichier)){
                fscanf(fichier,"%d\t%s\t%s\t%s\t%s\t%d\t%d\n",&d,v1->ville_depart,v1->ville_arrivee,v1->heure_depart,v1->heure_arrivee,&v1->nb_places,&v1->prix);
             printf("\t\t\t\t%10d%13s%13s%13s%13s%13d%14d\n",d,v1->ville_depart,v1->ville_arrivee,v1->heure_depart,v1->heure_arrivee,v1->nb_places,v1->prix);
              printf("\t\t\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
          }
          fclose(fichier);


          printf("\n\t\t\t\t ENTERE LE NUMERO DE VOYAGE A SUPPRIMER.\n");
          printf("\n\t\t\t\t ==>");
          scanf("%d",&reponse);
           fopen("voyage.txt","rt");
           FILE *fichier2 =fopen("voyage1300.txt","wt");
           while( !feof(fichier)){
               fscanf(fichier,"%d\t%s\t%s\t%s\t%s\t%d\t%d\n",&d,v1->ville_depart,v1->ville_arrivee,v1->heure_depart,v1->heure_arrivee,&v1->nb_places,&v1->prix);
             if(d!=reponse){
                fprintf(fichier2,"%d\t%s\t%s\t%s\t%s\t%d\t%d\n",d,v1->ville_depart,v1->ville_arrivee,v1->heure_depart,v1->heure_arrivee,v1->nb_places,v1->prix);
             }
             else{
                r++;
             }
             }
             fclose(fichier);
             fclose(fichier2);
             remove("voyage.txt");
             rename("voyage1300.txt","voyage.txt");


             if(r!=0){
                      Color(13,0);
                        printf("\n\t\t\t\t\t\t SUCCESFFUL OPERATION\n");
                             Color(15,0);
                        printf("\n\t\t\t\t\t\t ==> TAPEZ POUR REVENIR AU MENU \n");
                        getche();
                        system("cls");
                        MODIFIERVOYAGE();
             }

             else{

                printf("\n\t\t\t\t\t\t FAILED OPERATION OR CODE WRONG\n");
                        printf("\n\t\t\t\t\t\t TRY AGAIN\n");
                        s_sleep(4);
                        system("cls");
                        MODIFIERVOYAGE();

             }
             }


///****************************************************************************************************************///


///*************************************************************************************************************///


    void LOGINCLIENT ()
       {
         int reponse;
         printf("\n");
         printf("\n");
         printf("\t\t\t\t\t\t\t\t\t\t- - - - - - - - - - \n");
         printf ("\n\t\t\t\t\t\t\t\t\t\t  1-LOGIN \n");
         printf ("\n\t\t\t\t\t\t\t\t\t\t  2-S'INSCRIRE \n");
         printf("\n\t\t\t\t\t\t\t\t\t\t- - - - - - - - - -\n");
         debut:
         printf("\n\t\t\t\t\t\t ===> ");

         scanf("%d",&reponse);
             switch(reponse)
     {
                 case 1:
                      system("cls");
                       printf ("\n");
                       printf ("\n");
                      Color(13,0);
                     printf("\t\t\t\t\t\t\t\t\t- - - - - - - LOG IN CLIENT - - - - - - -\n");
                      Color(15,0);
                       printf ("\n");
                       login();
                       break;

                case 2:
                      system("cls");
                      inscrire();
                      break;

                default :
                     Beep(500,700);
                     printf("\t\t\t\t\tCHOIX INVALIDE");
                     goto debut;
                     break;
    }

  }


///***********************************************************************************************************************///

    void login()
  {

          log *l=(log *)malloc(sizeof(log));;
          esp *g=(esp *)malloc(sizeof(esp));
          FILE *file=fopen("login22.txt","r");
          int i=0;
          int j=0;

             printf("\n\t\t\t\t\t\t\t\t\t\t USERID ===> ");
            fflush(stdin);
            gets(l->USERID);
             printf("\n\t\t\t\t\t\t\t\t\t\t MOTDEPASSE ===>  ");
             TAKEPASSEWORD(l->MOTDEPASSE);

        while ( !feof(file))

            {
                fscanf(file,"%s\t%s\n",g->userid,g->motdepasse);


              if (strcmp(g->userid,l->USERID)==0 && strcmp(g->motdepasse,l->MOTDEPASSE)==0)
               {
                  j++;
                  break;


              }

              }




           if(j!=0){
                s_sleep(1);
                   printf("\n");
                   printf("\n");

                   Color(13,0);
                  printf("\n\t\t\t\t\t\t\t\t\t\t    ** SUCCESFUL LOGIN **");
                  s_sleep(10);
                  system("cls");
                  printf("\n");
                   printf("\n");
                  printf("\t\t\t\t\t\t\t\t\t\t     WELCOME  %s \n",l->USERID);
                  Color(15,0);
                  printf("\n");
                  printf("\n");
                  ///AFFICHER LE MENU POUR N CLIENT :
                  VOYAGE();

        }
        else {
                   printf("\n");
                  printf("\n");
                  printf("\n\t\t\t\t\t\t\t\t\t    MOT DE PASSE OU USERID INCORECTE.\n");
                   login();}



         fclose(file);


 }

///********************************************************************************************************************///
///********************************************************************************************************************///
   void inscrire()
   {
        esp *e=malloc(sizeof(esp));
        FILE *file=fopen("login22.txt","a");
        printf("\n");
        Color(13,0);
        printf ("\n\t\t\t\t\t\t\t\t\t WELCOME TO OUR AGENCY\n");
        Color(15,0);
        printf("\n");
        printf ("\n\t\t\t\t\t\t\t PLEASE ENTER YOUR FULLNAME(METTEZ _ AU LIEU D'ESPACE) \n ");
        printf("\n\t\t\t\t\t\t\t ===> ");
        fflush(stdin);
        gets(e->userid);
        Color(13,0);
        printf ("\n\t\t\t\t\t\t\t    ===> YOUR USER ID EST: %s\n ",e->userid);
        Color(15,0);
        printf ("\n\t\t\t\t\t\t\t PLEASE ENTER YOUR PASSEWORD (MAX 8 CARACTER ) \n  ");
        again:
            printf("\n\t\t\t\t\t\t\t  ===>  ");
            fflush(stdin);
        gets(e->motdepasse);

          if (strlen(e->motdepasse)>=8)
            {
                s_sleep(1);
                Color(13,0);
                printf("\n");
            printf("\n\t\t\t\t\t\t\t       SUCCESFUL INSCRIPTION \n");
            Color(15,0);
            }
        else
            {
            printf("\n");
            printf("\n\t\t\t\t\t\t\t==> mot de passe invalide essayer avec un mot de passe de 8 caractere au maximum. \n");
            goto again;
            }
            fprintf(file,"%s\t%s\n",e->userid,e->motdepasse);
            fclose(file);

            printf("\n\t\t\t\t\t\t\t ==> TAPEZ ENTRER POUR FAIRE  LOGIN");

            getche();
            s_sleep(2);
            system("cls");
            printf ("\n");
                       printf ("\n");
                      Color(13,0);
                     printf("\t\t\t\t\t\t\t\t\t- - - - - - - - - - LOG IN CLIENT - - - - - - - - - -\n");
                      Color(15,0);
                       printf ("\n");
            login();
  }
  ///*********************************************************************************************************///


  void VOYAGE(){
      int reponse;
      printf("\n");
      printf("\n");

      printf("\t\t\t\t\t\t\t\t\t- - - - - - - - - - - - - - - - - - - - - - - - - \n");
      printf("\n\t\t\t\t\t\t\t\t\t         1-A PROPOS\n");
      printf("\n\t\t\t\t\t\t\t\t\t         2-CHERCHER VOYAGE ET RESERVATION \n");
      printf("\n\t\t\t\t\t\t\t\t\t         3-ANNULER RESERVATION\n");
      printf("\n\t\t\t\t\t\t\t\t\t         4-COMMENTAIRE ET EVALUATION\n");
       printf("\n\t\t\t\t\t\t\t\t\t         5-MENU\n");
      printf("\n\t\t\t\t\t\t\t\t\t         6-QUITTER\n");
      printf("\n\t\t\t\t\t\t\t\t\t- - - - - - - - - - - - - - - - - - - - - - - - - \n");
      debut:

        printf("\n");
        printf("\t\t\t\t\t ===> ");

      scanf("%d",&reponse);
      switch(reponse){

       case 1:
           system("cls");
          APROPOS();
          break;

       case 2 :

        system("cls");
        printf("\n");
        printf("\n\t\t\t\t\t\t\t\t CHERCHER VOYAGE\n");
        printf("\n");
        DATEe();
         break;

         case 3:
         system("cls");
         ANNULERRESERVATION();
          break;

      case 6:
        system("cls");
         QUITTER();
         break;

      case 4:
           system("cls");
        COMMENTAIREETRATING();
        break;

      case 5:
          system("cls");
          INTERFACESITE();
          break;


      default:
          Beep(500,700);
        printf("CHOIX INVALIDE .");
        goto debut;
        break;
      }

  }
  ///******************************************************************************************************************///
    void  ANNULERRESERVATION(){
        int cr,cr1;  ///code reservation///
        int d,i;
        info *f =(info *)malloc(sizeof(info));
      printf("\n\t\t\t\t\t\t\t\t ENTRER VOTRE CODE DE RESERVATION ==> ");
      scanf("%d",&cr);
      FILE *fp =fopen("RESERVATION.txt","r");
      FILE *fp1 =fopen("COPIE_RESERVATION.txt","w");
      while(!feof(fp)){
        fscanf(fp,"%d\t%d\t%s\t%s\t%s\t%d\t%s\n",&cr1,&d,f->nom,f->prenom,f->CIN,&f->telephone,f->email);
        if(cr!=cr1){
                fprintf(fp1,"%d\t%d\t%s\t%s\t%s\t%d\t%s\n",cr1,d,f->nom,f->prenom,f->CIN,f->telephone,f->email);}
            else{
                i++;
            }


      }

      fclose(fp);
      fclose(fp1);
      remove("RESERVATION.txt");
      rename("COPIE_RESERVATION.txt","RESERVATION.txt");
           if(i!=0){
                Color(13,0);
                        printf("\n\t\t\t\t\t\t\t\t SUCCESFFUL OPERATION \n");
                             Color(15,0);
                        printf("\n\t\t\t\t\t\t\t ==> TAPEZ POUR REVENIR AU MENU \n");
                        getche();
                        system("cls");
                       VOYAGE();

                       }
                       else {
                        printf("\n\t\t\t\t\t\t\t\t FAILED OPERATION OR CODE WRONG\n");
                        printf("\n\t\t\t\t\t\t\t\t TRY AGAIN\n");
                        s_sleep(4);
                        system("cls");
                       VOYAGE();
                       }




    }




  ///******************************************************************************************************************///
  void APROPOS(){
      printf("\n");
   printf("\t\t\t\t\t TRAVEL AGENCY est une agence de voyage nationnal specialisee dans les reservattions des tickets en ligne .\n");
   printf("\t\t\t\t\t Contactez-nous :\n");
   printf("\t\t\t\t\ttele:0609152430\n");
   printf("\t\t\t\t\tfix:0509152430\n");
   printf("\t\t\t\t\temail:dihajouassima1@gmail.com\t elalamisafa@gmail.com\n");
   printf("\t\t\t\t\trejoignez-nous\n");
   printf("\t\t\t\t\tfacebook:TRAVEL AGENCY\n");
   printf("\t\t\t\t\tInstagram:travel_agency\n");
   printf ("\n\t\t\t\t\t TAPEZ ENTRER POUR REVENIR AU MENU \n");
   getche();
   system("cls");
   VOYAGE();
  }
  ///********************************************************************************************************************///
  void SAISIEVOYAGE(){
     FILE *fichier= fopen("voyage.txt","at");
     vg *v=(vg *)malloc(sizeof(vg));
     int d;
     d=generateNumber(100);
     printf("\n\t\t\t\t\t\t\t\t\t VILLE DE DEPART :  ");
     fflush(stdin);
     gets(v->ville_depart);

      printf("\n\t\t\t\t\t\t\t\t\t VILLE D'ARRIVEE : ");
     fflush(stdin);
     gets(v->ville_arrivee);

      printf("\n\t\t\t\t\t\t\t\t\t HEURE DE DEPART : ");
     fflush(stdin);
     gets(v->heure_depart);

      printf("\n\t\t\t\t\t\t\t\t\t HEURE D'ARRIVEE : ");
      fflush(stdin);
      gets(v->heure_arrivee);

      printf("\n\t\t\t\t\t\t\t\t\t NOMBRE DE PLACE : ");
     fflush(stdin);
     scanf("%d",&v->nb_places);

      printf("\n\t\t\t\t\t\t\t\t\t PRIX : ");
     fflush(stdin);
     scanf("%d",&v->prix);

     fprintf(fichier,"%d\t%s\t%s\t%s\t%s\t%d\t%d\n",d,v->ville_depart,v->ville_arrivee,v->heure_depart,v->heure_arrivee,v->nb_places,v->prix);
     fclose(fichier);

     Color(13,0);
     printf("\n\t\t\t\t\t\t\t\t\t SUCCESFUL OPERATION \n");
     Color(15,0);

  }
  ///********************************************************************************************************************///
  void DATEe(){
      chvg *ch1=(chvg *)(malloc(sizeof(chvg)));

     DEBUT:
    printf("\n\t\t\t\t\t\t\t\t JOUR DE VOYAGE :   ");
    scanf("%d",&ch1->DV.jour);

    printf("\n\t\t\t\t\t\t\t\t  MOIS DE VOYAGE : ");
    scanf("%d",&ch1->DV.mois);

    printf("\n\t\t\t\t\t\t\t\t ANNEE DE VOYAGE : ");

    scanf("%d",&ch1->DV.annee);

    if(ch1->DV.jour<1||ch1->DV.jour>31){
          printf("\n\t\t\t\t\t\t\t\t JOUR NON VALIDE\n");
          s_sleep(3);
          system("cls");
          DATEe();}


    if(ch1->DV.annee<2022){
        printf("\n\t\t\t\t\t\t\t\t ANNE NON VALIDE\n");
        s_sleep(3);
        system("cls");
        DATEe();}


     if(ch1->DV.mois>12||ch1->DV.mois<1){
        printf("\n\t\t\t\t\t\t\t\t MOIS INVALIDE\n");
        s_sleep(3);
        system("cls");
        DATEe();}


     if((ch1->DV.jour<29 || ch1->DV.mois<12)  && ch1->DV.annee==2022){
        printf("\n\t\t\t\t\t\t\t\t DATE NON VALIDE\n");
        s_sleep(3);
        system("cls");
        DATEe();}



    else {
            printf("\n\t\t\t\t\t\t\t\t DATE DE VOYAGE : %d-%d-%d \n",ch1->DV.jour,ch1->DV.mois,ch1->DV.annee);
            CHERCHERVOYAGE();}

        }

  ///*********************************************************************************************************************///
    void CHERCHERVOYAGE(){

  FILE *fichier=fopen("voyage.txt","rt");
   chvg *ch1=(chvg *)(malloc(sizeof(chvg)));

   vg *v1=(vg *)malloc(sizeof(vg));
   vg *v2=(vg *)malloc(sizeof(vg));
   vg *v3=(vg *)malloc(sizeof(vg));
   int place;
   int c;
   int g;
   int  i;
   int reponse2;
   char reponse;
   char reponse3;

   printf("\n\t\t\t\t\t\t\t\t\t VILLE DE DEPART : ");
   fflush(stdin);
   gets(ch1->ville_depart1);

   printf("\n\t\t\t\t\t\t\t\t\t VILLE D'ARRIVEE : ");
   fflush(stdin);
   gets(ch1->ville_arrivee);





   printf("\n\t\t\t\t\t\t\t\t\t LES VOYAGES DISPONIBLES SONT :\n");
   Color(13,0);
   printf("\n\t\t\t\t   N VOYAGE    VILLE DEPART   VILLE ARRIVEE   H_DEPART   H_ARRIVEE   PLACES_DISPO    PRIX\n");
   Color(15,0);
   printf("\n\t\t\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
     while(!feof(fichier)){
        fscanf(fichier,"%d\t%s\t%s\t%s\t%s\t%d\t%d\n",&c,v1->ville_depart,v1->ville_arrivee,v1->heure_depart,v1->heure_arrivee,&v1->nb_places,&v1->prix);
        if(strcmp(v1->ville_depart,ch1->ville_depart1)==0 && strcmp(v1->ville_arrivee,ch1->ville_arrivee)==0){

    printf("%40d%14s%14s%14s%14s%14d%14d\n",c,v1->ville_depart,v1->ville_arrivee,v1->heure_depart,v1->heure_arrivee,v1->nb_places,v1->prix);
    printf("\n\t\t\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
                    }
                    }




        fclose(fichier);


    fopen("voyage.txt","rt");

    printf("\n\t\t\t\t ETES VOUS INTERESSEZ PAR UN VOYAGE PARMI LA LISTE : O/N\n");
    printf("\n\t\t\t\t ==> ");
    scanf("%c",&reponse);
    if (reponse=='o'|| reponse=='O'){
            printf("\n\t\t\t\t ENTRER LE NUMERO DE VOYAGE INTERESSE :\n");
            printf("\n\t\t\t\t ==> ");
            scanf("%d",&reponse2);

    while (fscanf(fichier,"%d\t%s\t%s\t%s\t%s\t%d\t%d\n",&g,v2->ville_depart,v2->ville_arrivee,v2->heure_depart,v2->heure_arrivee,&v2->nb_places,&v2->prix)!=NULL){
                if(g==reponse2){
                    printf("\n\t\t\t\t LE VOYAGE CHOISI EST LE SUIVANT \n");
                     Color(13,0);
                     printf("\n");
                    printf("%40d%14s%14s%14s%14s%14d%14d\n",g,v2->ville_depart,v2->ville_arrivee,v2->heure_depart,v2->heure_arrivee,v2->nb_places,v2->prix);
                         Color(15,0);
                    printf("\n\t\t\t\t TAPEZ 'O' OU 'o' POUR CONTINUER LA PROCEDURE DE RESERVATION.\n");
                    printf("\n\t\t\t\t ==> ");
                     fflush(stdin);
                     scanf("%c",&reponse3);

                     printf("\n\t\t\t\t COMBIEN DE PLACE VOULEZ VOUS RESERVER :\n");
                     printf("\n\t\t\t\t ==> ");
                     scanf("%d",&place);
                     break;
                    }
                     }
                    }
                    else if(reponse=='n'|| reponse=='N')
                        {

                        printf("\n\t\t\t\t TAPEZ ENTRER POUR REVENIR AU MENU \n");
                        getche();
                        system("cls");
                        VOYAGE();

                        }
                            fclose(fichier);



                            /*if(reponse3=='n'|| reponse3=='N'){
                                printf("\n\t\t\t\t TAPEZ POUR REVENIR AU MENU ");
                                    system("cls");
                                    VOYAGE();}*/


                        if(reponse3=='o'|| reponse3=='O'){
                            s_sleep(2);
                            system("cls");
                             Color(13,0);
                             printf ("\n\t\t\t\t\t\t\t\t CHERCHER VOYAGE ==> ");
                              printf (" RESERVATION ");
                              Color(15,0);
                              printf("==> INFORMATION PERSONELLE\n");
                               printf("\n");}
                              for (int j=0;j<place  ;j++){


                                    FILE *fichier=fopen("voyage.txt","rt");
                                    FILE *fichier3 =fopen("copie66.txt","wt");



    while (!feof(fichier)){
    fscanf(fichier,"%d\t%s\t%s\t%s\t%s\t%d\t%d\n",&g,v3->ville_depart,v3->ville_arrivee,v3->heure_depart,v3->heure_arrivee,&v3->nb_places,&v3->prix);
            if(g!=reponse2){
                fprintf(fichier3,"%d\t%s\t%s\t%s\t%s\t%d\t%d\n",g,v3->ville_depart,v3->ville_arrivee,v3->heure_depart,v3->heure_arrivee,v3->nb_places,v3->prix);
                }
                else{

                            if(place<=v3->nb_places){

                     v3->nb_places=v3->nb_places - 1;

                    fprintf(fichier3,"%d\t%s\t%s\t%s\t%s\t%d\t%d\n",g,v3->ville_depart,v3->ville_arrivee,v3->heure_depart,v3->heure_arrivee,v3->nb_places,v3->prix);
                    }
                             else if (place>v3->nb_places){

                        printf("\n\t\t\t\t ==>NOMBRE DE PLACE INDISPONIBLE OU VOYAGE COMPLET \n");
                        fprintf(fichier3,"%d\t%s\t%s\t%s\t%s\t%d\t%d\n",g,v3->ville_depart,v3->ville_arrivee,v3->heure_depart,v3->heure_arrivee,v3->nb_places,v3->prix);
                         printf(" \n\t\t\t\t ESSAYER AVEC UN AUTRE VOYAGE\n");
                          Beep(500,700);
                         s_sleep(3);
                         system("cls");
                         VOYAGE();
                         break;
                        }
                      }


                    }

                    fclose(fichier);
                    fclose(fichier3);
                    remove("voyage.txt");
                    rename("copie66.txt","voyage.txt");



              INFORMATIONPERSONELLE(reponse2);








    }}



  ///********************************************************************************************************************///
  void INFORMATIONPERSONELLE(int d){

      int c;
    FILE *fichier=fopen("RESERVATION.txt","at");
    info *f=(info *)malloc(sizeof(info));
    vg *v1=(vg *)malloc(sizeof(vg));
    printf("\n\t\t\t\t\t\t\t    ==> MERCI DE NE PAS UTILISER ESPACE ENTRE LESS MOTS VOUS POUVEZ UTILISER ( _ )\n");
    printf("\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t NOM: ");
    fflush(stdin);
    gets(f->nom);
    printf("\n\t\t\t\t\t\t\t\t\t\t PRENOM :");
    fflush(stdin);
    gets(f->prenom);
    printf("\n\t\t\t\t\t\t\t\t\t\t CIN :");
     fflush(stdin);
    gets(f->CIN);
    printf("\n\t\t\t\t\t\t\t\t\t\t TELEPHONE : +212");
    scanf("%d",&f->telephone);
    printf("\n\t\t\t\t\t\t\t\t\t\t EMAIL :");
    fflush(stdin);
    gets(f->email);
    int CR =generateNumber(1000000);
    printf("%d",CR);
    fprintf(fichier,"%d\t%d\t%s\t%s\t%s\t%d\t%s\n",CR,d,f->nom,f->prenom,f->CIN,f->telephone,f->email);
   fclose(fichier);
    FILE *fichier2=fopen("voyage.txt","rt");
     while(!feof(fichier2)){
        fscanf(fichier2,"%d\t%s\t%s\t%s\t%s\t%d\t%d\n",&c,v1->ville_depart,v1->ville_arrivee,v1->heure_depart,v1->heure_arrivee,&v1->nb_places,&v1->prix);
        if(c==d){

        break;}
     }
     fclose(fichier2);
                             //system("cls");
                              Color(13,0);
                              printf("\n");
                              printf ("\n\t\t\t\t\t\t CHERCHER VOYAGE ");
                              printf ("==> RESERVATION ");
                              printf("==> INFORMATION PERSONELLE ");
                              Color(15,0);
                              printf("==> PAIEMENT\n");
                              printf("\n");
                              printf("\n");


     PAIEMENT(CR,v1->ville_depart,v1->ville_arrivee,v1->heure_depart,v1->heure_arrivee,v1->nb_places,v1->prix);

  }
  ///********************************************************************************************************************///
  void PAIEMENT(int CR,char ville_depart[30],char ville_arrivee[40],char heure_depart[30],char heure_arrivee[30],int nb_place,int X){

      int CR2 = CR;
      int reponse;

      printf("\t\t\t\t\t\t\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
      printf("\n\t\t\t\t\t\t\t                 DE: %s \t\t\t A: %s            \n",ville_depart,ville_arrivee);
      printf("\n\t\t\t\t\t\t\t                  CONFORT : \t\t\t %s--->%s                       \n",heure_depart,heure_arrivee);
      printf("\n\t\t\t\t\t\t\t                  N* SIEGE : \t\t\t %d                                \n",50-nb_place);
       printf("\n\t\t\t\t\t\t\t                  PRIX : \t\t\t %d DH                              \n",X);
         printf("\n\t\t\t\t\t\t\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
        printf("\n");
       printf("\n\t\t\t\t\t\t\t\t\t 1-PAIEMNET PAR CARTE\n");
       printf("\n\t\t\t\t\t\t\t\t\t 2-PAIEMENT PAR ESPECE\n");
       debut :
       printf("\n");
       printf("\t\t\t\t\t\t\t\t ==> ");
       scanf("%d",&reponse);
       switch(reponse){
     case 1 :
        PAIEMENTENLIGNE();
        break;
     case 2:
       PAIEMENTESPECE();
        break;

      defaut :
          printf("CHOIX INVALIDE ");
          goto debut;
          break;

       }


                              system("cls");
                              Color(13,0);
                              printf("\n");
                              printf ("\n\t\t\t\t\t\t CHERCHER VOYAGE ");
                              printf ("==> RESERVATION ");
                              printf("==> INFORMATION PERSONELLE ");
                              printf("==> PAIEMENT ");

                              Color(15,0);
                              printf("==> E-TICKET\n");
                              printf("\n");
                              printf("\n");
                TICKET(CR2,50-nb_place,ville_depart,ville_arrivee,heure_depart,heure_arrivee);
  }
  ///**************************************************************************************************************************///
  PAIEMENTENLIGNE(){
      crt *c =(crt *)malloc(sizeof(crt));
     // crt *c1= crt *)malloc(sizeof(crt));
      printf("\n\t\t\t\t\t\t\t\t\t\t NUMERO DE CARTE : ");
      fflush(stdin);
      gets(c->numcarte);

      printf("\n\t\t\t\t\t\t\t\t\t\t CODE : ");
      fflush(stdin);
      gets(c->code);
      printf("\n\t\t\t\t\t\t\t\t\t\t MOIS D'EXPIRATION : ");
      scanf("%d",&c->moisdexpiration);
      printf("\n\t\t\t\t\t\t\t\t\t\t ANNEE D'EXPIRATION : ");
      scanf("%d",&c->anneedexpiration);

      if (strlen(c->numcarte)!= 24){
        printf("\n\t\t\t\t\t\t\t\t\t\t NUMERO DE CARTE OU CODE INVALIDE ");
        //system("cls");
        PAIEMENTENLIGNE();
      }
      else if(c->moisdexpiration>12 || c->moisdexpiration<1){
        printf("\n\t\t\t\t\t\t\t\t\t\t MOIS INVALIDE");
        //system("cls");
        PAIEMENTENLIGNE();
      }
      else if(c->anneedexpiration<2022){
        printf("\n\t\t\t\t\t\t\t\t\t\t ANNEE INVALIDE");
        //system("cls");
        PAIEMENTENLIGNE();
      }

              s_sleep(4);

  }
  ///************************************************************************************************************************///
  PAIEMENTESPECE(){
   FILE *fichier = fopen("codedepaiement.txt","rt");
      int code;
      int codedepaiement;
     printf("\n\t\t\t\t\t\t\t\t VEUILLEZ PAYER CHEZ WAFACASH OU CHSHPLUS ET ENTRER LE CODE OBTENU APRES PAYMENT  \n");
     printf("\n\t\t\t\t\t\t\t\t EXPIRE DANS 10 MIN");
    printf("\n");
     printf("\n\t\t\t\t\t\t\t\t\t ENTRER LE CODE ==> ");

     scanf("%d",&code);
     while(!feof(fichier)){
        fscanf(fichier,"%d\n",&codedepaiement);
        if(code==codedepaiement){
                Color(13,0);
            printf("\n\t\t\t\t\t\t\t\t\t\t SUCCESFUL PAIEMENT");
        Color(15,0);
            break;
        }
        else{
           printf("\n\t\t\t\t\t\t\t\t\t\t CODE INVALIDE");
           s_sleep(4);
          system("cls");
           PAIEMENTESPECE();}

     }
     s_sleep(4);
  }
  ///************************************************************************************************************************///
  void codepaiement(){
      int code;
      int codedepaiement;
     FILE *fichier = fopen("codedepaiement.txt","wt");
     printf("CODE DE PAIEMENT VALIDE :");
     scanf("%d",&codedepaiement);
     fprintf(fichier,"%d\n",codedepaiement);
     fclose(fichier);

  }

///************************************************************************************************************************///
 void TICKET(int CR2,int C,char ville_depart[30],char ville_arrivee[40],char heure_depart[30],char heure_arrivee[30]){
     int CR3 = CR2;

   printf("\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n ");
   Color(13,0);
   printf("\n\t\t\t\t\t*\t\t\t\t\t VOYAGE SAFIR                                             * \n");
   Color(15,0);
   printf("\n\t\t\t\t\t*\t\t\t DE : %s \t\t\t\t A : %s                         *\n",ville_depart,ville_arrivee);
   printf("\n\t\t\t\t\t*\t\t\t DE : %s \t\t\t\t A : %s                        *\n",heure_depart,heure_arrivee);
   printf("\n\t\t\t\t\t*\t\t\t N* SIEGE : \t\t\t\t  %d                              *\n",C);

   Color(13,0);
   printf("\n\t\t\t\t\t*\t\t\t\t\tVOTRE CONFORT NOTRE PRIORITE                              *\n");

      Color(15,0);


   printf("\n\t\t\t\t\t*\t\t      ==> AUCUN EXUSE N'EST ACCEPTEE SI NE VOUS PAS PRESENTER EN TEMPS            *\n");

  printf("\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n ");
 printf("\n");
 printf("\n");
 printf("\n\t\t\t\t\t\t\t\t\t ==> VOICI VOTRE CODE DE SUIVI DE CETTE RESERVATION  : * %d * ",CR2);
   s_sleep(5);
   system("cls");


 }
///************************************************************************************************************************///
   void COMMENTAIREETRATING(){
       int reponse;
       printf("\n");
       printf("\n");
       printf("\t\t\t\t\t\t\t\t\t- - - - - - - - - - - - - - - - - - - -  \n");
       printf("\n\t\t\t\t\t\t\t\t\t 1-AJOUTER COMMENTAIRE \n");
       printf("\n\t\t\t\t\t\t\t\t\t 2-EVALUER NOTRE SERVICE \n");
       printf("\n\t\t\t\t\t\t\t\t\t 3-AFFICHER COMMENTAIRE \n");
        printf("\n\t\t\t\t\t\t\t\t\t 4-AFFICHER EVALUATION \n");

       printf("\n\t\t\t\t\t\t\t\t\t 5-MENU \n");
       printf("\n\t\t\t\t\t\t\t\t\t 6-QUITTER \n");
       printf("\n\t\t\t\t\t\t\t\t\t- - - - - - - - - - - - - - - - - - -  \n");
       debut:
           printf("\n");
       printf("\t\t\t\t ===> ");
       scanf("%d",&reponse);
       switch(reponse){
    case 1 :
        system("cls");
        AJOUTERCOMMENTAIRE();

        break;

    case 2:
        system("cls");
       EVALUATION2();
       printf("\n\t\t\t\t\t\t\t TAPEZ ENTRER POUR REVENIR AU MENU :");

       getche();
       system("cls");
       COMMENTAIREETRATING();

        break;

    case 5:
        system("cls");
        VOYAGE();
        break;

    case 6:
        QUITTER();
        break;

    case 3 :
        system("cls");
        AFFICHERCOMMENTAIRE2();
        printf("\n");
         printf("\n\t\t\t\t\t\t\t\t TAPEZ ENTRER POUR REVENIR AU MENU ");
        getche();
        system("cls");
        COMMENTAIREETRATING();
        break;

    case 4:
        system("cls");
        EVALUATION3();
        printf("\n");
         printf("\n\t\t\t\t\t\t\t\t TAPEZ ENTRER POUR REVENIR AU MENU ");
        getche();
        system("cls");
        COMMENTAIREETRATING();
        break;



    default:

        printf("CHOIX INVALIDE ");
        goto debut;
        break;

       }}


   ///******************************************************************************************************************///
       void AJOUTERCOMMENTAIRE(){
       int c = generateNumber(10000);
       int number;
          FILE *fichier = fopen("commen.txt","a");
             char reponse;
             printf("\n");
             printf("\n");
                 printf("\t\t\t\t\t\t\t VOULEZ VOUS LAISSER UN COMMENTAIRE SUR NOTRE SERVICE : O/N ");
                 printf("\n");
                 printf("\n");
                 printf("\t\t\t\t\t\t ==> ");
                 fflush(stdin);
                 scanf("%c",&reponse);
                 if(reponse=='O' || reponse=='o')
                    {
                        while(!feof(fichier)){
                        fscanf(fichier,"%d",number);
                        if (number!=c){
                      fprintf(fichier,"\t%d\t\t\t\t",c);
                      break;}
                      else {
                        AJOUTERCOMMENTAIRE();

                      }}


                       char commentaire[40000];
                       printf("\n\t\t\t\t\t\t\t VOTRE COMMENTAIRE : :");
                       fflush(stdin);
                       gets(commentaire);
                       fputs(commentaire,fichier);
                       fputs("\n",fichier);
                       fclose(fichier);
                       Color(13,0);
                       printf ("\n\t\t\t\t\t\t\t ==> MERCI VOTRE CONFORT EST NOTRE PRIORITE \n");
                       Color(15,0);
                       printf("\n\t\t\t\t\t\t\t TAPEZ ENTRER POUR REVENIR AU MENU :");
                      getche();
                      system("cls");
                       COMMENTAIREETRATING();


                    }

                else if (reponse=='N' || reponse=='n')
                    {
                       system("cls");
                       COMMENTAIREETRATING();

                    }




     }





///******************************************************************************************************************///

   void EVALUATION2(){
     FILE *fichier=fopen ("evaluation.txt","a");
   char reponse[50];
 printf("\n\t\t\t\t\t\t\t SUR COMBIEN D'ETOILE POUVEZ VOUS RATEZ NOTRE SERVICE :(* * * * *)\n");
 printf("\n\t\t\t\t\t\t ===> ");
 fflush(stdin);
 gets(reponse);
    if (strcmp(reponse,"*")==0){
            Color(13,0);
    printf("\n\t\t\t\t\t\t\t MERCI NOUS ESSAYERONS D'AMELIORER NOTRE SERVICE\n");
             Color(15,0);
    }
     else if (strcmp(reponse,"**")==0){
            Color(13,0);
    printf("\n\t\t\t\t\t\t\t MERCI NOUS ESSAYERONS D'AMELIORER NOTRE SERVICE\n");
    Color(15,0);}
     else if (strcmp(reponse,"***")==0){
            Color(13,0);
    printf("\n\t\t\t\t\t\t\t MERCI NOUS ESSAYERONS D'AMELIORER NOTRE SERVICE\n");
            Color(15,0);}
     else if (strcmp(reponse,"****")==0){
           Color(13,0);
    printf("\n\t\t\t\t\t\t\t MERCI DE VOTRE CONFIANCE\n");
          Color(15,0);}
     else if (strcmp(reponse,"*****")==0){
            Color(13,0);
    printf("\n\t\t\t\t\t\t\t MERCI DE VOTRE CONFIANCE\n");
           Color(15,0);}
    else{
            Color(13,0);
        printf("\n\t\t\t\t\t\t\t VOUS AVEZ DEPASSER 5 ETOILES OU VOUS N'AVEZ FAIT AUCUN ETOILE\n");
                 Color(15,0);}

    fputs(reponse,fichier);
    fputs("\n",fichier);
    fclose(fichier);
}




///******************************************************************************************************************///
     void QUITTER()
     {

                       exit(0);


     }
     ///******************************************************************************************************************///
int main()
{

       INTERFACESITE();



 return 0;
}

