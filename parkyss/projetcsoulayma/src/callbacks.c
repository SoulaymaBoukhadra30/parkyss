#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "agents.h"
int homme = 0;
int femme = 0;
Agent nv;
void
on_buttonajouter_clicked               (GtkButton       *buttonajouter,
                                        gpointer         user_data)
{
    Agent ag;
    GtkWidget *entryNom, *entryPrenom,*entrycin ,*entryEtatcivil, *entryEtatsanitaire, *entryNumerodetelephone, *entryAdressemail, *entryLogin, *entryMotdepasse;
    GtkWidget *etatpcomboboxentry1;
    GtkWidget *spin1, *spin2, *spin3;
    GtkWidget *radiobutton1, *radiobutton2;

    // Correction des noms des widgets (enlever les ; après les noms)
    entryNom = lookup_widget(GTK_WIDGET(buttonajouter), "entryNom");
    entryPrenom = lookup_widget(GTK_WIDGET(buttonajouter), "entryPrenom");
    entryEtatcivil = lookup_widget(GTK_WIDGET(buttonajouter), "entryEtatcivil");
    entryEtatsanitaire = lookup_widget(GTK_WIDGET(buttonajouter), "entryEtatsanitaire");
    entryNumerodetelephone = lookup_widget(GTK_WIDGET(buttonajouter), "entryNumerodetelephone");
    entryAdressemail = lookup_widget(GTK_WIDGET(buttonajouter), "entryAdressemail");
    entryLogin = lookup_widget(GTK_WIDGET(buttonajouter), "entryLogin");
    entryMotdepasse = lookup_widget(GTK_WIDGET(buttonajouter), "entryMotdepasse");
    entrycin = lookup_widget(GTK_WIDGET(buttonajouter), "entrycin");
    etatpcomboboxentry1 = lookup_widget(GTK_WIDGET(buttonajouter), "etatpcomboboxentry1");

    spin1 = lookup_widget(GTK_WIDGET(buttonajouter), "spin1");
    spin2 = lookup_widget(GTK_WIDGET(buttonajouter), "spin2");
    spin3 = lookup_widget(GTK_WIDGET(buttonajouter), "spin3");

    radiobutton1 = lookup_widget(GTK_WIDGET(buttonajouter), "radiobutton1");
    radiobutton2 = lookup_widget(GTK_WIDGET(buttonajouter), "radiobutton2");

    strcpy(ag.nom, gtk_entry_get_text(GTK_ENTRY(entryNom)));
    strcpy(ag.pren, gtk_entry_get_text(GTK_ENTRY(entryPrenom)));
    strcpy(ag.etatCiv, gtk_entry_get_text(GTK_ENTRY(entryEtatcivil)));
    strcpy(ag.etatSan, gtk_entry_get_text(GTK_ENTRY(entryEtatsanitaire)));
    strcpy(ag.tel, gtk_entry_get_text(GTK_ENTRY(entryNumerodetelephone)));
    strcpy(ag.email, gtk_entry_get_text(GTK_ENTRY(entryAdressemail)));
    strcpy(ag.nomAdmin, gtk_entry_get_text(GTK_ENTRY(entryLogin)));
    strcpy(ag.mdp, gtk_entry_get_text(GTK_ENTRY(entryMotdepasse)));
    strcpy(ag.poste, gtk_combo_box_get_active_text(GTK_COMBO_BOX(etatpcomboboxentry1)));
    strcpy(ag.cin, gtk_entry_get_text(GTK_ENTRY(entrycin)));
    ag.dn.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin1));
    ag.dn.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin2));
    ag.dn.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin3));

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton1))) {
        strcpy(ag.sexe, "homme");
    } else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton2))) {
        strcpy(ag.sexe, "femme");
    }

    if (ajouterAgent("agents.txt", ag)) {
        g_print("Agent ajouté avec succès.\n");
  } else {
        g_print("Erreur lors de l'ajout de l'agent.\n");
    }
}



void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) {
        homme= 1;
}
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if (gtk_toggle_button_get_active(togglebutton)) {
        femme = 2;
}
}


void
on_buttannuler_clicked                 (GtkButton       *buttannuler,
                                        gpointer         user_data)
{
    Agent ag;
    GtkWidget *entryNom, *entryPrenom,*entrycin, *entryEtatcivil, *entryEtatsanitaire, *entryNumerodetelephone, *entryAdressemail, *entryLogin, *entryMotdepasse;
    GtkWidget *etatpcomboboxentry1;
    GtkWidget *spin1, *spin2, *spin3;
    GtkWidget *radiobutton1, *radiobutton2;

    entryNom = lookup_widget(GTK_WIDGET(buttannuler), "entryNom");
    entryPrenom = lookup_widget(GTK_WIDGET(buttannuler), "entryPrenom");
    entryEtatcivil = lookup_widget(GTK_WIDGET(buttannuler), "entryEtatcivil");
    entryEtatsanitaire = lookup_widget(GTK_WIDGET(buttannuler), "entryEtatsanitaire");
    entryNumerodetelephone = lookup_widget(GTK_WIDGET(buttannuler), "entryNumerodetelephone");
    entryAdressemail = lookup_widget(GTK_WIDGET(buttannuler), "entryAdressemail");
    entryLogin = lookup_widget(GTK_WIDGET(buttannuler), "entryLogin");
    entryMotdepasse = lookup_widget(GTK_WIDGET(buttannuler), "entryMotdepasse");
    entrycin = lookup_widget(GTK_WIDGET(buttannuler), "entrycin");
    etatpcomboboxentry1 = lookup_widget(GTK_WIDGET(buttannuler), "etatpcomboboxentry1");

    spin1 = lookup_widget(GTK_WIDGET(buttannuler), "spin1");
    spin2 = lookup_widget(GTK_WIDGET(buttannuler), "spin2");
    spin3 = lookup_widget(GTK_WIDGET(buttannuler), "spin3");

   
    gtk_entry_set_text(GTK_ENTRY(entryNom), "");
    gtk_entry_set_text(GTK_ENTRY(entryPrenom), "");
    gtk_entry_set_text(GTK_ENTRY(entryEtatcivil), "");
    gtk_entry_set_text(GTK_ENTRY(entryEtatsanitaire), "");
    gtk_entry_set_text(GTK_ENTRY(entryNumerodetelephone), "");
    gtk_entry_set_text(GTK_ENTRY(entryAdressemail), "");
    gtk_entry_set_text(GTK_ENTRY(entryLogin), "");
    gtk_entry_set_text(GTK_ENTRY(entrycin), "");
    gtk_entry_set_text(GTK_ENTRY(entryMotdepasse), "");
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin1), 1);  // Premier jour du mois
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin2), 1);  // Premier mois (janvier)
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin3), 2024); // Année actuelle
    g_print("Ajout de l'agent annulé. \n");
}

void
on_buttonmodifier_clicked              (GtkButton       *buttonmodifier,
                                        gpointer         user_data)
{
 Agent ag;
    GtkWidget *entryn, *entryp,*entrycin1 , *entryes, *entrynt, *entryadresse, *entrylog, *entrymdp;
    GtkWidget *combo3,*combo4;
    GtkWidget *spinbutton4, *spinbutton5, *spinbutton6;
    GtkWidget *radiobutton3, *radiobutton4;
char cin1[50];
    // Correction des noms des widgets (enlever les ; après les noms)
    entryn = lookup_widget(GTK_WIDGET(buttonmodifier), "entryn");
    entryp = lookup_widget(GTK_WIDGET(buttonmodifier), "entryp");
    entryes = lookup_widget(GTK_WIDGET(buttonmodifier), "entryes");
    entrynt = lookup_widget(GTK_WIDGET(buttonmodifier), "entrynt");
    entryadresse = lookup_widget(GTK_WIDGET(buttonmodifier), "entryadresse");
    entrylog = lookup_widget(GTK_WIDGET(buttonmodifier), "entrylog");
    entrymdp = lookup_widget(GTK_WIDGET(buttonmodifier), "entrymdp");
    entrycin1 = lookup_widget(GTK_WIDGET(buttonmodifier), "entrycin1");
    
    spinbutton4 = lookup_widget(GTK_WIDGET(buttonmodifier), "spinbutton4");
    spinbutton5 = lookup_widget(GTK_WIDGET(buttonmodifier), "spinbutton5");
    spinbutton6 = lookup_widget(GTK_WIDGET(buttonmodifier), "spinbutton6");

    radiobutton3 = lookup_widget(GTK_WIDGET(buttonmodifier), "radiobutton3");
    radiobutton4 = lookup_widget(GTK_WIDGET(buttonmodifier), "radiobutton4");
    
    combo3 = lookup_widget(GTK_WIDGET(buttonmodifier), "combo3");
    combo4 = lookup_widget(GTK_WIDGET(buttonmodifier), "combo4");
    
    strcpy(nv.nom, gtk_entry_get_text(GTK_ENTRY(entryn)));
    strcpy(nv.pren, gtk_entry_get_text(GTK_ENTRY(entryp)));
    strcpy(nv.etatSan, gtk_entry_get_text(GTK_ENTRY(entryes)));
    strcpy(nv.tel, gtk_entry_get_text(GTK_ENTRY(entrynt)));
    strcpy(nv.email, gtk_entry_get_text(GTK_ENTRY(entryadresse)));
    strcpy(nv.nomAdmin, gtk_entry_get_text(GTK_ENTRY(entrylog)));
    strcpy(nv.mdp, gtk_entry_get_text(GTK_ENTRY(entrymdp)));
    strcpy(nv.etatCiv, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo3)));
    strcpy(nv.poste, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo4)));
    
    nv.dn.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton4));
    nv.dn.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton5));
    nv.dn.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton6));
strcpy(cin1,gtk_entry_get_text(GTK_ENTRY(entrycin1)));
sprintf(nv.cin, cin1);

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton3))) {
        strcpy(nv.sexe, "homme");
    } else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton4))) {
        strcpy(nv.sexe, "femme");
    }

    if (modifierAgent("agents.txt", cin1, nv)) {
        g_print("Les informations de l'agent sont modifiées avec succés.\n");
  } else {
        g_print("Erreur lors de la modification de l'agent !\n");
    }
}



void
on_buttonannulermodif_clicked          (GtkButton       *buttonannulermodif,
                                        gpointer         user_data)
{
Agent ag;
    GtkWidget *entryn, *entryp,*entrycin1 , *entryes, *entrynt, *entryadresse, *entrylog, *entrymdp;
    GtkWidget *combo3,*combo4;
    GtkWidget *spinbutton4, *spinbutton5, *spinbutton6;
    GtkWidget *radiobutton3, *radiobutton4;
char cin1[50];
    // Correction des noms des widgets (enlever les ; après les noms)
    entryn = lookup_widget(GTK_WIDGET(buttonannulermodif), "entryn");
    entryp = lookup_widget(GTK_WIDGET(buttonannulermodif), "entryp");
    entryes = lookup_widget(GTK_WIDGET(buttonannulermodif), "entryes");
    entrynt = lookup_widget(GTK_WIDGET(buttonannulermodif), "entrynt");
    entryadresse = lookup_widget(GTK_WIDGET(buttonannulermodif), "entryadresse");
    entrylog = lookup_widget(GTK_WIDGET(buttonannulermodif), "entrylog");
    entrymdp = lookup_widget(GTK_WIDGET(buttonannulermodif), "entrymdp");
    entrycin1 = lookup_widget(GTK_WIDGET(buttonannulermodif), "entrycin1");
    
    spinbutton4 = lookup_widget(GTK_WIDGET(buttonannulermodif), "spinbutton4");
    spinbutton5 = lookup_widget(GTK_WIDGET(buttonannulermodif), "spinbutton5");
    spinbutton6 = lookup_widget(GTK_WIDGET(buttonannulermodif), "spinbutton6");

    radiobutton3 = lookup_widget(GTK_WIDGET(buttonannulermodif), "radiobutton3");
    radiobutton4 = lookup_widget(GTK_WIDGET(buttonannulermodif), "radiobutton4");
    
    combo3 = lookup_widget(GTK_WIDGET(buttonannulermodif), "combo3");
    combo4 = lookup_widget(GTK_WIDGET(buttonannulermodif), "combo4");
    gtk_entry_set_text(GTK_ENTRY(entryn), "");
    gtk_entry_set_text(GTK_ENTRY(entryp), "");
    gtk_entry_set_text(GTK_ENTRY(entryes), "");
    gtk_entry_set_text(GTK_ENTRY(entrynt), "");
    gtk_entry_set_text(GTK_ENTRY(entryadresse), "");
    gtk_entry_set_text(GTK_ENTRY(entrylog), "");
    gtk_entry_set_text(GTK_ENTRY(entrymdp), "");
    gtk_entry_set_text(GTK_ENTRY(entrycin1), "");
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(ag.dn.jour), 1);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(ag.dn.mois), 1);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(ag.dn.annee),1);
    gtk_combo_box_set_active(GTK_COMBO_BOX(ag.etatCiv),-1);
    gtk_combo_box_set_active(GTK_COMBO_BOX(ag.poste),-1);
    g_print("modification annulée et formulaire réinitialisé.\n");
}

void
on_radiobutton3_toggled                (GtkToggleButton *radiobutton3,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(radiobutton3)) 
        homme= 1;
}


void
on_radiobutton4_toggled                (GtkToggleButton *radiobutton4,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(radiobutton4)) 
        femme= 2;
}
void
on_buttsupprimer_clicked               (GtkButton       *buttsupprimer,
                                        gpointer         user_data)
{
GtkWidget *supprimer;
GtkWidget *dialog2;
GtkWidget *cinsupp;
   
  char cin[20];

    cinsupp = lookup_widget(GTK_WIDGET(buttsupprimer), "cinsupp");
    strcpy(cin, gtk_entry_get_text(GTK_ENTRY(cinsupp)));
    if (chercherAgent("agents.txt",cin)){
        g_print("agent avec numéro CIN %s trouvé",cin);
        supprimer = lookup_widget(GTK_WIDGET(buttsupprimer), "supprimer");
        gtk_widget_hide(supprimer);


        dialog2 = create_dialog2();
        g_object_set_data_full(G_OBJECT(dialog2),"cin",g_strdup(cin),g_free);
       


        gtk_widget_show(dialog2);
    }

    else{
        g_print("Erreur : agent avec numéro CIN %s introuvable.\n", cin);
    }
}


void
on_buttonannuler_clicked               (GtkButton       *buttonannuler,
                                        gpointer         user_data)
{
GtkWidget *cinsupp;
    char cin[20];

    cinsupp = lookup_widget(GTK_WIDGET(buttonannuler), "cinsupp");
    gtk_entry_set_text(GTK_ENTRY(cinsupp), "");
    g_print("suppression annulée.\n");
}   


void
on_buttonafficher_clicked              (GtkButton       *buttonafficher,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *afficher;
// Récupérer la fenêtre principale "gestionagentsparkings" depuis Glade
    afficher = lookup_widget(buttonafficher, "afficher");

    if (afficher == NULL) {
        g_print("Erreur : Fenêtre gestionagentsparkings non trouvée dans Glade.\n");
        return;
    }

    // Afficher la fenêtre principale
    gtk_widget_show_all(afficher);

    // Récupérer le TreeView "treeview4" depuis la fenêtre
    treeview1 = lookup_widget(afficher, "treeview1");
    if (treeview1 == NULL) {
        g_print("Erreur : TreeView treeview4 non trouvé dans Glade.\n");
        return;
    }

    // Appeler la fonction afficher pour remplir le TreeView
    afficherAgents("agents.txt", treeview1);
}   















void
on_buttonafficherres_clicked           (GtkButton       *buttonafficherres,
                                        gpointer         user_data)
{
  GtkWidget *tachesupplementaire;  
    GtkWidget *treeview2;  
    GtkWidget *spin_button_jour, *spin_button_mois, *spin_button_annee;
    gint jour, mois, annee;
    char date_recherche[15];

    // Récupérer la fenêtre principale "gestionagentsparkings" depuis Glade
    tachesupplementaire = lookup_widget(GTK_WIDGET(buttonafficherres), "tachesupplementaire");

    if (tachesupplementaire == NULL) {
        g_print("Erreur : Fenêtre non trouvée dans Glade.\n");
        return;
    }    
    gtk_widget_show_all(tachesupplementaire);

    treeview2 = lookup_widget(tachesupplementaire, "treeview2");
    if (treeview2 == NULL) {
        g_print("Erreur : TreeView2 non trouvé dans Glade.\n");
        return;
    }

    // Récupérer les valeurs des SpinButtons
    spin_button_jour = lookup_widget(tachesupplementaire, "spinbutton1");
    spin_button_mois = lookup_widget(tachesupplementaire, "spinbutton2");
    spin_button_annee = lookup_widget(tachesupplementaire,"spinbutton3");

    if (spin_button_jour == NULL || spin_button_mois == NULL || spin_button_annee == NULL) {
        g_print("Erreur : SpinButton non trouvé dans Glade.\n");
        return;
    }

    // Récupérer les valeurs sélectionnées dans les SpinButtons
    jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_button_jour));
    mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_button_mois));
    annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_button_annee));

    // Assembler la date dans une chaîne de caractères au format "dd/mm/yyyy"
    sprintf(date_recherche, "%02d/%02d/%04d", jour, mois, annee);

    // Appeler la fonction afficher pour remplir le TreeView avec les réservations correspondant à la date
    afficherlistereserv("reservations.txt", treeview2,date_recherche);
}














void
on_butajout_clicked                    (GtkButton       *butajout,
                                        gpointer         user_data)
{

    GtkWidget *menu_window;
    GtkWidget *ajouter_window;

    // Fermer la fenêtre actuelle (Display)
    menu_window = lookup_widget(GTK_WIDGET(butajout), "menu");
    gtk_widget_destroy(menu_window);

    // Ouvrir la nouvelle fenêtre (Add)
    ajouter_window = create_ajouter();
    gtk_widget_show(ajouter_window);

}


void
on_butmodif_clicked                    (GtkButton       *butmodif,
                                        gpointer         user_data)
{
    GtkWidget *menu_window;
    GtkWidget *modifier_window;

    // Fermer la fenêtre actuelle (Display)
    menu_window = lookup_widget(GTK_WIDGET(butmodif), "menu");
    gtk_widget_destroy(menu_window);

    // Ouvrir la nouvelle fenêtre (Add)
    modifier_window = create_modifier();
    gtk_widget_show(modifier_window);
}


void
on_butsupprim_clicked                  (GtkButton       *butsupprim,
                                        gpointer         user_data)
{
    GtkWidget *menu_window;
    GtkWidget *supprimer_window;

    // Fermer la fenêtre actuelle (Display)
    menu_window = lookup_widget(GTK_WIDGET(butsupprim), "menu");
    gtk_widget_destroy(menu_window);

    // Ouvrir la nouvelle fenêtre (Add)
    supprimer_window = create_supprimer();
    gtk_widget_show(supprimer_window);
}


void
on_butaffichres_clicked                (GtkButton       *butaffichres,
                                        gpointer         user_data)
{
    GtkWidget *menu_window;
    GtkWidget *tachesupplementaire_window;

    // Fermer la fenêtre actuelle (Display)
    menu_window = lookup_widget(GTK_WIDGET(butaffichres), "menu");
    gtk_widget_destroy(menu_window);

    // Ouvrir la nouvelle fenêtre (Add)
    tachesupplementaire_window = create_tachesupplementaire();
    gtk_widget_show(tachesupplementaire_window);
}


void
on_butaffich_clicked                   (GtkButton       *butaffich,
                                        gpointer         user_data)
{
    GtkWidget *menu_window;
    GtkWidget *afficher_window;

    // Fermer la fenêtre actuelle (Display)
    menu_window = lookup_widget(GTK_WIDGET(butaffich), "menu");
    gtk_widget_destroy(menu_window);

    // Ouvrir la nouvelle fenêtre (Add)
    afficher_window = create_afficher();
    gtk_widget_show(afficher_window);
}

void
on_butrech_clicked                     (GtkButton       *butrech,
                                        gpointer         user_data)
{
GtkWidget *menu_window;
    GtkWidget *chercher_window;

    // Fermer la fenêtre actuelle (Display)
    menu_window = lookup_widget(GTK_WIDGET(butrech), "menu");
    gtk_widget_destroy(menu_window);

    // Ouvrir la nouvelle fenêtre (Add)
    chercher_window = create_chercher();
    gtk_widget_show(chercher_window);

}









void
on_buttonchercher_clicked              (GtkButton       *buttonchercher,
                                        gpointer         user_data)
{
GtkWidget *resultat;
GtkWidget *entryrecherchercin;
 entryrecherchercin = lookup_widget(GTK_WIDGET(buttonchercher), "entryrecherchercin");
resultat = lookup_widget(GTK_WIDGET(buttonchercher), "resultat");
char cinrech[20];

 strcpy(cinrech, gtk_entry_get_text(GTK_ENTRY(entryrecherchercin)));
if (chercherAgent("agents.txt",cinrech))
{
 //cher1(id, msg,ag);
  gtk_label_set_text(GTK_LABEL(resultat),"existe");
}
else
  gtk_label_set_text(GTK_LABEL(resultat),"introuvable");
}



void
on_suivantajouter_clicked              (GtkButton       *buttonsuivant,
                                        gpointer         user_data)
{

    GtkWidget *modifier_window;
    GtkWidget *ajouter_window;

    // Fermer la fenêtre actuelle (ajouter)
    ajouter_window = lookup_widget(GTK_WIDGET(buttonsuivant), "ajouter");
    gtk_widget_destroy(ajouter_window);

    // Ouvrir la nouvelle fenêtre (modifier)
    modifier_window = create_modifier();
    gtk_widget_show(modifier_window);
}



 /*GtkWidget *menu_window;
    GtkWidget *ajouter_window;

    // Fermer la fenêtre actuelle (Display)
    ajouter_window = lookup_widget(GTK_WIDGET(buttonprécédent), "ajouter");
    gtk_widget_destroy(ajouter_window);

    // Ouvrir la nouvelle fenêtre (Add)
    menu_window = create_menu();
    gtk_widget_show(menu_window);*/


void
on_precedentajouter_clicked            (GtkButton       *buttonprecedentajouter,
                                        gpointer         user_data)
{

 GtkWidget *menu_window;
    GtkWidget *ajouter_window;

    // Fermer la fenêtre actuelle (Display)
    ajouter_window = lookup_widget(GTK_WIDGET(buttonprecedentajouter), "ajouter");
    gtk_widget_destroy(ajouter_window);

    // Ouvrir la nouvelle fenêtre (Add)
    menu_window = create_menu();
    gtk_widget_show(menu_window);

}




void
on_buttonprecedentmodifier_clicked     (GtkButton       *buttonprecedentmodifier,
                                        gpointer         user_data)
{
GtkWidget *modifier_window;
    GtkWidget *ajouter_window;

    // Fermer la fenêtre actuelle (Display)
    modifier_window = lookup_widget(GTK_WIDGET(buttonprecedentmodifier), "modifier");
    gtk_widget_destroy(modifier_window);

    // Ouvrir la nouvelle fenêtre (Add)
    ajouter_window = create_ajouter();
    gtk_widget_show(ajouter_window);
}


void
on_buttonsuivantmodifier_clicked       (GtkButton       *buttonsuivantmodifier,
                                        gpointer         user_data)
{
GtkWidget *modifier_window;
    GtkWidget *supprimer_window;

    // Fermer la fenêtre actuelle (Display)
    modifier_window = lookup_widget(GTK_WIDGET(buttonsuivantmodifier), "modifier");
    gtk_widget_destroy(modifier_window);

    // Ouvrir la nouvelle fenêtre (Add)
    supprimer_window = create_supprimer();
    gtk_widget_show(supprimer_window);
}


void
on_buttonprecedentsupprimer_clicked    (GtkButton       *buttonprecedentsupprimer,
                                        gpointer         user_data)
{
GtkWidget *modifier_window;
    GtkWidget *supprimer_window;

    // Fermer la fenêtre actuelle (Display)
    supprimer_window = lookup_widget(GTK_WIDGET(buttonprecedentsupprimer), "supprimer");
    gtk_widget_destroy(supprimer_window);

    // Ouvrir la nouvelle fenêtre (Add)
    modifier_window = create_modifier();
    gtk_widget_show(modifier_window);
}


void
on_suivantsupprimer_clicked      (GtkButton       *suivantsupprimer,
                                        gpointer         user_data)
{
GtkWidget *afficher_window;
    GtkWidget *supprimer_window;

    // Fermer la fenêtre actuelle (Display)
    supprimer_window = lookup_widget(GTK_WIDGET(suivantsupprimer), "supprimer");
    gtk_widget_destroy(supprimer_window);

    // Ouvrir la nouvelle fenêtre (Add)
    afficher_window = create_afficher();
    gtk_widget_show(afficher_window);

}



void
on_annulerdialog2_clicked              (GtkButton       *buttonannulerdialog2,
                                        gpointer       user_data)
{
GtkWidget *dialog2_window;
    GtkWidget *supprimer_window;

    // Fermer la fenêtre actuelle (Display)
    dialog2_window = lookup_widget(GTK_WIDGET(buttonannulerdialog2), "dialog2");
    gtk_widget_destroy(dialog2_window);

    // Ouvrir la nouvelle fenêtre (Add)
    supprimer_window = create_supprimer();
    gtk_widget_show(supprimer_window);
}


void
on_validerdialog2_clicked              (GtkButton       *buttonvaliderdialog2,
                                        gpointer         user_data)
{
GtkWidget *supprimer= gtk_widget_get_toplevel(GTK_WIDGET(buttonvaliderdialog2));
char *cin=(char*)g_object_get_data(G_OBJECT(supprimer),"cin");
if(cin){
if(supprimerAgent("agents.txt",cin)){
GtkWidget *dialog2=create_dialog2();
gtk_widget_show(dialog2);
}
else{
g_warning("agent introuvable");
}
}else{
g_critical("aucun id associe a la boite de dialogue");
}
gtk_widget_hide(supprimer);
}

/*GtkWidget *dialog2_window;
GtkWidget *cinsupp;
   
  char cin[20];


    cinsupp = lookup_widget(GTK_WIDGET(buttonvaliderdialog2), "cinsupp");
    strcpy(cin, gtk_entry_get_text(GTK_ENTRY(cinsupp)));
   if (supprimerAgent("agents.txt",cin)){
        g_print("agent avec numéro CIN %s supprimé",cin);
    // Ouvrir la nouvelle fenêtre (Add)
     dialog2_window = lookup_widget(GTK_WIDGET(buttonvaliderdialog2), "dialog2");
     gtk_widget_destroy(dialog2_window);
     supprimer_window = create_supprimer();
     gtk_widget_show(supprimer_window);

}
}
*/


void
on_suivantafficher_clicked             (GtkButton       *suivantafficher,
                                        gpointer         user_data)
{
GtkWidget *tachesupplementaire_window;
    GtkWidget *goodbye_window;

    // Fermer la fenêtre actuelle (Display)
    tachesupplementaire_window = lookup_widget(GTK_WIDGET(suivantafficher), "tachesupplementaire");
    gtk_widget_destroy(tachesupplementaire_window);

    // Ouvrir la nouvelle fenêtre (Add)
    goodbye_window = create_goodbye();
    gtk_widget_show(goodbye_window);
}

void
on_precedentafficher_clicked           (GtkButton       *precedentafficher,
                                        gpointer         user_data)
{
GtkWidget *tachesupplementaire_window;
    GtkWidget *chercher_window;

    // Fermer la fenêtre actuelle (Display)
    tachesupplementaire_window = lookup_widget(GTK_WIDGET(precedentafficher), "tachesupplementaire");
    gtk_widget_destroy(tachesupplementaire_window);

    // Ouvrir la nouvelle fenêtre (Add)
    chercher_window = create_chercher();
    gtk_widget_show(chercher_window);

}


void
on_buttonquitter_clicked               (GtkButton       *buttonquitter,
                                        gpointer         user_data)
{

    GtkWidget *goodbye_window;

    // Fermer la fenêtre actuelle (Display)
    goodbye_window = lookup_widget(GTK_WIDGET(buttonquitter), "goodbye");
    gtk_widget_destroy(goodbye_window);
}
   
 


void
on_buttonprecedentafficher_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonsuivantafficheragent_clicked  (GtkButton       *buttonsuivantafficheragent,
                                        gpointer         user_data)
{
GtkWidget *afficher_window;
    GtkWidget *chercher_window;

    // Fermer la fenêtre actuelle (Display)
    afficher_window = lookup_widget(GTK_WIDGET(buttonsuivantafficheragent), "afficher");
    gtk_widget_destroy(afficher_window);

    // Ouvrir la nouvelle fenêtre (Add)
    chercher_window = create_chercher();
    gtk_widget_show(chercher_window);

}


void
on_buttonprecedentafficheragent_clicked
                                        (GtkButton       *buttonprecedentafficheragent,
                                        gpointer         user_data)
{
GtkWidget *afficher_window;
    GtkWidget *supprimer_window;

    // Fermer la fenêtre actuelle (Display)
    afficher_window = lookup_widget(GTK_WIDGET(buttonprecedentafficheragent), "afficher");
    gtk_widget_destroy(afficher_window);

    // Ouvrir la nouvelle fenêtre (Add)
    supprimer_window = create_supprimer();
    gtk_widget_show(supprimer_window);

}


void
on_buttonprecedentchercher_clicked     (GtkButton       *buttonprecedentchercher,
                                        gpointer         user_data)
{
GtkWidget *afficher_window;
    GtkWidget *chercher_window;

    // Fermer la fenêtre actuelle (Display)
    chercher_window = lookup_widget(GTK_WIDGET(buttonprecedentchercher), "chercher");
    gtk_widget_destroy(chercher_window);

    // Ouvrir la nouvelle fenêtre (Add)
    afficher_window = create_afficher();
    gtk_widget_show(afficher_window);

}



void
on_bouttonsuivantchercher_clicked      (GtkButton       *buttonsuivantchercher,
                                        gpointer         user_data)
{
GtkWidget *tachesupplementaire_window;
    GtkWidget *chercher_window;

    // Fermer la fenêtre actuelle (Display)
    chercher_window = lookup_widget(GTK_WIDGET(buttonsuivantchercher), "chercher");
    gtk_widget_destroy(chercher_window);

    // Ouvrir la nouvelle fenêtre (Add)
    tachesupplementaire_window = create_tachesupplementaire();
    gtk_widget_show(tachesupplementaire_window);
}






void
on_buttonverifier_clicked(GtkButton *buttonverifier, gpointer user_data)
{
    Agent ag;
    GtkWidget *entryn, *entryp, *entrycin1, *entryes, *entrynt, *entryadresse, *entrylog;
    GtkWidget *combo3, *combo4;
    GtkWidget *spinbutton4, *spinbutton5, *spinbutton6;
    GtkWidget *radiobutton3, *radiobutton4;
    char cin1[50];

    // Retrieve widgets
    entryn = lookup_widget(GTK_WIDGET(buttonverifier), "entryn");
    entryp = lookup_widget(GTK_WIDGET(buttonverifier), "entryp");
    entryes = lookup_widget(GTK_WIDGET(buttonverifier), "entryes");
    entrynt = lookup_widget(GTK_WIDGET(buttonverifier), "entrynt");
    entryadresse = lookup_widget(GTK_WIDGET(buttonverifier), "entryadresse");
    entrylog = lookup_widget(GTK_WIDGET(buttonverifier), "entrylog");
    
    entrycin1 = lookup_widget(GTK_WIDGET(buttonverifier), "entrycin1");

    spinbutton4 = lookup_widget(GTK_WIDGET(buttonverifier), "spinbutton4");
    spinbutton5 = lookup_widget(GTK_WIDGET(buttonverifier), "spinbutton5");
    spinbutton6 = lookup_widget(GTK_WIDGET(buttonverifier), "spinbutton6");

    radiobutton3 = lookup_widget(GTK_WIDGET(buttonverifier), "radiobutton3");
    radiobutton4 = lookup_widget(GTK_WIDGET(buttonverifier), "radiobutton4");

    combo3 = lookup_widget(GTK_WIDGET(buttonverifier), "combo3");
    combo4 = lookup_widget(GTK_WIDGET(buttonverifier), "combo4");

    // Get ID entered by the user
    strcpy(cin1, gtk_entry_get_text(GTK_ENTRY(entrycin1)));
    g_strstrip(cin1);

    g_print("Searching numéro CIN: %s\n", cin1);

    // Call the chercher function
    if (chercherAgent("agents.txt", cin1)) {  // Assuming chercherAgent correctly updates 'ag'
        // Populate widgets with data
        gtk_entry_set_text(GTK_ENTRY(entryn), ag.nom);
        gtk_entry_set_text(GTK_ENTRY(entryp), ag.pren);
        gtk_entry_set_text(GTK_ENTRY(entryes), ag.etatSan);
        gtk_entry_set_text(GTK_ENTRY(entrynt), ag.tel);
        gtk_entry_set_text(GTK_ENTRY(entryadresse), ag.email);
        gtk_entry_set_text(GTK_ENTRY(entrylog), ag.nomAdmin);
        
        // Set spin buttons for date (jour, mois, annee)
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton4), ag.dn.jour);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton5), ag.dn.mois);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton6), ag.dn.annee);

        /*// Set combo boxes for etatCiv and poste
        gtk_combo_box_set_active(GTK_COMBO_BOX(combo3), get_combo_index(combo3, ag.etatCiv));
        gtk_combo_box_set_active(GTK_COMBO_BOX(combo4), get_combo_index(combo4, ag.poste));
*/
        // Set radio buttons based on some condition
        if (strcmp(ag.sexe, "Option1") == 0) {  // Replace with actual field name
            gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton3), TRUE);
        } else {
            gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton4), TRUE);
        }
    } else {
        g_print("Agent non trouvé pour le numéro CIN: %s\n", cin1);
    }
}

