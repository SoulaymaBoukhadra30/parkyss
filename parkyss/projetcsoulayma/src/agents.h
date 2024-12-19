#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED
#include <stdio.h>
#include <gtk/gtk.h>
typedef struct {
	int jour;
	int mois;
	int annee;
}date;
typedef struct {
     char type[10];
    char matricule[10];
 }Vehicule;
typedef struct {
    char type[20];
    char  bloc[5];
    int places_disponibles;
}Place;
typedef struct {
    char nom[50];          
    char pren[50];         
    char cin[20];          
    date dn;
    char sexe[10];         
    char etatCiv[20];      
    char etatSan[20];    
    char tel[20];          
    char email[50];       
    char poste[50];        
    char nomAdmin[50];     
    char mdp[50];         
} Agent;
typedef struct {
    int heure;
    int minute;
} Heure;


typedef struct{
      char nom[50];
      char id_parking[10];
      char adresse[100];
       Place place ;
       float tarif;

      }Parking;
 typedef struct{
    char paiement[50];
    char demande_service[50];
 } Service;

typedef struct{
    char id_reservation[10];
     Parking parking;
    Place place;
    date date_reservation;
    Heure heure_debut;
    Heure heure_fin;
    Vehicule vehicule;
    Service service;
    char type_abnmt[20];

} Reservation;

   typedef struct{
     char nom[50];
     char prenom[50];
char mdp[20];
 }Login;


  typedef struct{
   char id_citoyen[50];
 }citoyen;








 


 













int ajouterAgent(char *filename, Agent ag);
int supprimerAgent(char*filename,const char* cin);
void afficherAgents(char*filename,GtkWidget*treeview);
int chercherAgent(char*filename,const char* cin);
int modifierAgent(char *fichier, char* cin,Agent nv);
void afficherlistereserv(const char* filenameR,GtkWidget*treeview,const char *date_recherche);
void creerFichierreservations();
#endif
