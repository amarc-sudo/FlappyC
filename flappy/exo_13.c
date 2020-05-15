#include "../lib/libgraphique.h"
#include<stdio.h>

#define FALSE 0
#define TRUE 1

int main(int argc, char *argv[]){



    // début de la session graphique
    ouvrir_fenetre(800,600);
	
	Point pipe1 = {800,0};
	Point pipe2 = {800,0};
	Point souris;
	Point sourisDep;
	Point coin = {0,0};
	Point pipe3 = {-150,-150};
	Point pipe4 = {-150,-150};
	int i = 1, crdn,crdn1, v = 2, score = 0;
	
	
	sourisDep = attendre_clic();
	dessiner_rectangle(sourisDep, 50, 50, rouge);
	attendre_clic();
	pipe1.x = 800;
	pipe2.x = 800;
	pipe2.y = 0;
	
	pipe1.y = entier_aleatoire(300)+150;
	crdn = pipe1.y - 100;
	pipe2.y -= (793-crdn);
	
	do
	{
	dessiner_rectangle(coin,800,600, noir);
	
	if(pipe1.x < 0-138 && pipe2.x < 0-138)
	{
		pipe1.x = 800;
		pipe2.x = 800;
		pipe2.y = 0;
		
		pipe1.y = entier_aleatoire(300)+150;
		crdn = pipe1.y - 100;
		pipe2.y -= (793-crdn);
		if(v < 15)
			v++;
	}
	
	dessiner_rectangle(pipe1, 138, pipe1.y, noir);
	dessiner_rectangle(pipe2, 138, crdn, noir);
	
	pipe1.x-= v;
	pipe2.x-= v;
	afficher_image("pipe.bmp", pipe1);
	afficher_image("pipe1.bmp", pipe2);
	
	
	if(pipe1.x < 400 && pipe3.x <= 0)
	{
		pipe3.x = 800;
		pipe4.x = 800;
		pipe4.y = 0;
		pipe3.y = entier_aleatoire(300)+150;
		crdn1 = pipe3.y - 100;
		pipe4.y -= (793-crdn1);
		printf("%d - %d", pipe3.y, pipe4.y);
		if(v < 15)
			v++;
	}
	if(pipe3.x <= 800 && pipe3.x >0-138)
	{
		dessiner_rectangle(pipe3, 138, pipe3.y, noir);
		dessiner_rectangle(pipe4, 138, crdn1, noir);
	
		pipe3.x-= v;
		pipe4.x-= v;
		afficher_image("pipe.bmp", pipe3);
		afficher_image("pipe1.bmp", pipe4);

	}
	
	reinitialiser_evenements();
	traiter_evenements();
	souris = deplacement_souris_a_eu_lieu();
	if(souris.x > 0)
	{
		dessiner_rectangle(sourisDep, 50, 50, noir);
		sourisDep.x = souris.x-25;
		sourisDep.y = souris.y-25;
		afficher_image("flappy.bmp", sourisDep);
	}
	
	
	if(((sourisDep.y +50 > pipe1.y || sourisDep.y < pipe2.y+793)&&((sourisDep.x > pipe1.x-50)&&sourisDep.x < pipe1.x+138))||((sourisDep.y +50 > pipe3.y || sourisDep.y < pipe4.y+793)&&((sourisDep.x > pipe3.x-50)&&sourisDep.x < pipe3.x+138)))
	i=FALSE;
	
	if(((sourisDep.y +50 < pipe1.y || sourisDep.y > pipe2.y+793)&&((sourisDep.x < pipe1.x-50)&&sourisDep.x > pipe1.x+138))||((sourisDep.y +50 < pipe3.y || sourisDep.y > pipe4.y+793)&&((sourisDep.x < pipe3.x-50)&&sourisDep.x > pipe3.x+138)))
	{
		score++;
		printf("%d", score);
	}
	actualiser();
	attente(10);
	}while(i);


    // fin de la session graphique
    attendre_clic();
    fermer_fenetre();
    return 0;
}
