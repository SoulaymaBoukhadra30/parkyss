#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agents.h"
#include <gtk/gtk.h>
int ajouterAgent(char *filename, Agent ag) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) return -1; // Erreur lors de l'ouverture

    if (fprintf(file, "%s %s %s %d/%d/%d %s %s %s %s %s %s %s %s\n",
                ag.nom, ag.pren, ag.cin,
                ag.dn.jour, ag.dn.mois, ag.dn.annee,
                ag.sexe, ag.etatCiv, ag.etatSan,
                ag.tel, ag.email, ag.poste,
                ag.nomAdmin, ag.mdp) < 0) {
        fclose(file);
        return 0; // Échec lors de l'écriture
    }

    fclose(file);
    return 1; // Succès
}



int supprimerAgent(char*filename,const char* cin) {
    FILE *fichier = fopen("agents.txt", "r");
    FILE *temporaire = fopen("temp.txt", "w");
    Agent ag;
    int found = 0;

    if (fichier == NULL || temporaire == NULL) {
        perror("Erreur lors de l'ouverture des fichiers");
        return;
    }

    while (fscanf(fichier, "%s %s %s %d/%d/%d %s %s %s %s %s %s %s %s\n",
                  ag.nom, ag.pren, ag.cin,
                  &ag.dn.jour, &ag.dn.mois, &ag.dn.annee,
                  ag.sexe, ag.etatCiv, ag.etatSan,
                  ag.tel, ag.email, ag.poste,
                  ag.nomAdmin, ag.mdp) != EOF) {
        if (strcmp(ag.cin, cin) != 0) {
            fprintf(temporaire, "%s %s %s %d/%d/%d %s %s %s %s %s %s %s %s\n",
                    ag.nom, ag.pren, ag.cin,
                    ag.dn.jour, ag.dn.mois, ag.dn.annee,
                    ag.sexe, ag.etatCiv, ag.etatSan,
                    ag.tel, ag.email, ag.poste,
                    ag.nomAdmin, ag.mdp);
        } else {
            found = 1;
        }
    }

    fclose(fichier);
    fclose(temporaire);

    remove("agents.txt");
    rename("temp.txt", "agents.txt");

    if (found) {
        printf("Agent supprimé avec succès.\n");
    } else {
        printf("Agent avec CIN '%s' non trouvé.\n", cin);
    }
}

int modifierAgent(char*filename, char *cin1,Agent nv) {
    FILE *fichier = fopen(filename, "r");
    FILE *temporaire = fopen("temp.txt", "w");
    Agent ag;
    int found = 0;

    if (fichier == NULL && temporaire == NULL) {
        perror("Erreur lors de l'ouverture des fichiers");
        return;
    }

    while (fscanf(fichier, "%s %s %s %d/%d/%d %s %s %s %s %s %s %s %s\n",
                  ag.nom, ag.pren, ag.cin,
                  &ag.dn.jour, &ag.dn.mois, &ag.dn.annee,
                  ag.sexe, ag.etatCiv, ag.etatSan,
                  ag.tel, ag.email, ag.poste,
                  ag.nomAdmin, ag.mdp) != EOF) {
        if (strcmp(ag.cin, cin1) == 0) {
            
           fprintf(temporaire, "%s %s %s %d/%d/%d %s %s %s %s %s %s %s %s\n",
                nv.nom, nv.pren, nv.cin,
                nv.dn.jour, nv.dn.mois, nv.dn.annee,
                nv.sexe, nv.etatCiv, nv.etatSan,
               nv.tel, nv.email, nv.poste,
               nv.nomAdmin, nv.mdp);
found = 1;
        }
else{

        fprintf(temporaire, "%s %s %s %d/%d/%d %s %s %s %s %s %s %s %s\n",
                ag.nom, ag.pren, ag.cin,
                ag.dn.jour, ag.dn.mois, ag.dn.annee,
                ag.sexe, ag.etatCiv, ag.etatSan,
                ag.tel, ag.email, ag.poste,
                ag.nomAdmin, ag.mdp);
}
    }

    fclose(fichier);
    fclose(temporaire);

    remove(filename);
    rename("temp.txt", filename);
return found;

    
}


void afficherAgents(char*filename,GtkWidget*treeview) {
GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;

    char datenaissance[15];
    Agent ag;           // Modèle de données

    store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(treeview)));
    if (store == NULL) {
        // Création des colonnes si elles n'existent pas encore
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", 0, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Prénom", renderer, "text", 1, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Numéro CIN", renderer, "text", 2, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Sexe", renderer, "text", 3, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Date de naissance", renderer, "text", 4, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Numéro du téléphone", renderer, "text", 5, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Adresse Mail", renderer, "text", 6, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Etat sanitaire", renderer, "text", 7, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Etat civil", renderer, "text", 8, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Poste", renderer, "text",9,  NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
    


   }

    // Création du modèle de données
    store = gtk_list_store_new(10, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,
 G_TYPE_STRING,G_TYPE_STRING);

   
   FILE *fichier = fopen("agents.txt", "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier agents.txt");
        return;
    }
 
    printf("Liste des agents:\n");
    printf("-----------------------------------------\n");
    while (fscanf(fichier, "%s %s %s %d/%d/%d %s %s %s %s %s %s %s %s\n",
                  ag.nom, ag.pren, ag.cin,
                  &ag.dn.jour, &ag.dn.mois, &ag.dn.annee,
                  ag.sexe, ag.etatCiv, ag.etatSan,
                  ag.tel, ag.email, ag.poste,
                  ag.nomAdmin, ag.mdp) != EOF) {

    // Ajouter les données au modèle
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter,
                           0, ag.nom,
                           1, ag.pren,
                           2,ag.cin,
                           3, ag.sexe,
                           4, datenaissance,
                           5, ag.tel,
                           6, ag.email,
                           7, ag.etatSan,
                           8, ag.etatCiv,
                           9, ag.poste,
                           -1);








}

    fclose(fichier);
  // Associer le modèle de données au TreeView
    gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), GTK_TREE_MODEL(store));

    // Ne pas libérer store ici (ownership transféré à treeview)

}






int chercherAgent(char*filename,const char* cin) {
    FILE *fichier = fopen("agents.txt", "r");
    Agent ag;
    int found = 0;

    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier.\n");
        return 0;
    }

    while (fscanf(fichier, "%s %s %s %d/%d/%d %s %s %s %s %s %s %s %s\n",
                  ag.nom, ag.pren, ag.cin, &ag.dn.jour, &ag.dn.mois, &ag.dn.annee,
                  ag.sexe, ag.etatCiv, ag.etatSan, ag.tel, ag.email, ag.poste,
                  ag.nomAdmin, ag.mdp) != EOF) {
        if (strcmp(ag.cin, cin) == 0) {
            found = 1;
            printf("Agent trouvé : %s %s, CIN: %s, Naissance: %02d/%02d/%04d, Sexe: %s, État civil: %s, "
                   "État santé: %s, Téléphone: %s, Email: %s, Poste: %s, Admin: %s, MDP: %s\n",
                   ag.nom, ag.pren, ag.cin, ag.dn.jour, ag.dn.mois, ag.dn.annee,
                   ag.sexe, ag.etatCiv, ag.etatSan, ag.tel, ag.email, ag.poste, ag.nomAdmin, ag.mdp);
            break;
        }
    }

    fclose(fichier);

    if (!found) {
        printf("Aucun agent trouvé avec le CIN %s.\n", cin);
    }
    return found;
}

void afficherlistereserv(const char* filenameR,GtkWidget*treeview,const char *date_recherche){ 
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    FILE *file;
    char date_naissance[15];
    char temps_res1[10];
    char temps_res2[10];
    Reservation res; 
    citoyen cit ;
    // Check if a model already exists for the tree view
    store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(treeview)));
    if (store == NULL) {
        // If the store doesn't exist, create columns for the tree view
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID Résérvation", renderer, "text", 0, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID Citoyen", renderer, "text", 1, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes(" Date Résérvation", renderer, "text", 2, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Date Début", renderer, "text", 3, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Date Fin", renderer, "text", 4, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Type Vehicle ", renderer, "text", 5, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Addresse Parking ", renderer, "text", 6, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
    }

    // Create a new data model with 7 columns
    store = gtk_list_store_new(7, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

    // Open the file and read the reservation data
    file = fopen(filenameR, "r");
    if (file == NULL) {
        g_print("Error: Could not open file %s\n", filenameR);
        return;
    }

    // Reading the file and populating the treeview
    while (fscanf(file, "%d %d %d %2d/%2d/%4d %2d:%2d %2d:%2d %49s %99[^\n]",
                  &res.id_reservation, &cit.id_citoyen, &res.parking.id_parking,
                 &res.date_reservation.jour, &res.date_reservation.mois, &res.date_reservation.annee,
                  &res.heure_debut.heure, &res.heure_debut.minute,
                  &res.heure_fin.heure, &res.heure_fin.minute,
                  res.vehicule.type, res.parking.adresse) != EOF) {
        // Format date and times
        sprintf(date_naissance, "%02d/%02d/%04d", res.date_reservation.jour, res.date_reservation.mois, res.date_reservation.annee);

        // Check if the reservation date matches the search date
        char date_formatee[15];
        sprintf(date_formatee, "%02d/%02d/%04d", res.date_reservation.jour, res.date_reservation.mois, res.date_reservation.annee);

        if (strcmp(date_formatee, date_recherche) == 0) { // Dates match
            sprintf(temps_res1, "%02d:%02d", res.heure_debut.heure, res.heure_debut.minute);
            sprintf(temps_res2, "%02d:%02d", res.heure_fin.heure, res.heure_fin.minute);

            // Add data to list store
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter,
                               0, res.id_reservation,
                               1, cit.id_citoyen,
                               2, date_naissance,
                               3, temps_res1,
                               4, temps_res2,
                               5, res.vehicule.type,
                               6, res.parking.adresse,
                               -1); // Make sure to end with -1
        }
    }

    fclose(file);

    // Set the model for the tree view
    gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), GTK_TREE_MODEL(store));

    // Unreference the store to free memory
    g_object_unref(store);
}
#include <stdio.h>

void creerFichierreservations() {
    FILE *fichier = fopen("reservations.txt", "w");
    if (fichier == NULL) {
        perror("Erreur lors de la création du fichier reservations.txt");
        return;
    }

    // Écriture des en-têtes des colonnes
    fprintf(fichier, "ID_Reservation ID_Citoyen ID_Parking Date_Reservation Heure_Debut Heure_Fin Type_Vehicle Adresse_Parking\n");

    // Ajout de données exemple
    fprintf(fichier, " 1001 101 20/12/2024 08:30 12:30 Voiture \"123 Rue A\"\n");
    fprintf(fichier, " 1002 102 21/12/2024 10:00 14:00 Moto \"456 Avenue B\"\n");
    fprintf(fichier, " 1003 103 22/12/2024 09:00 13:30 Camion \"789 Boulevard C\"\n");

    fclose(fichier);
    printf("Fichier reservations.txt créé avec succès.\n");
}
