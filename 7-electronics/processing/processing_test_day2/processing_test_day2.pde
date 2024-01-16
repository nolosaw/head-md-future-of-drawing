
// images
PImage img; // On déclare l'image de fond
PImage imgMouse; // On déclare l'image "souris"

//son
import processing.sound.*; // importation de la librairire
SoundFile sound; // on déclare la variable du son

// clic
boolean clicked = false; // variable du clic
boolean noClic = true; // est vrai si rien n'est cliqué
int xClicked, yClicked; // coordonnées du clic

void setup() {
  size(1920, 1480); // taille du sketch en fullscreen
  img = loadImage("Couleur.png"); // on charge l'image de fond
  img.resize(width, height); // recadrée à la taille du sketch
  imgMouse = loadImage("noir.png"); // la "souris" en halo

  // son
  sound = new SoundFile(this, "nature.mp3"); // on charge le son
  sound.amp(0); // le son est à zéro par défaut
  sound.loop(); // on met le son en boucle
}

void draw() {
  //images
  image(img, 0, 0); // affiche l'image dans le sketch



  // "souris"
  image(imgMouse, mouseX - imgMouse.width/2, mouseY - imgMouse.height/2); // l'image "souris" est guidée par le centre du curseur

  // quand on clique pas, pas d'image et pas de son
  if (noClic) {
    background(0); // Fond noir
    fill(0);
    noStroke();
    rect(0, 0, width, height);
  }

  // son
  // Calculer la distance entre la souris et l'endroit où se trouve le son
  float distance = dist(mouseX, mouseY, 800, 800); // ici 800, 800 est l'emplacement fictif du son

  // Si la distance est inférieure à 500 pixels et qu'on clique, on ajuste le volume en conséquence
  if (distance < 500 && noClic == false) {
    // Calculer le volume en fonction de la proximité
    float volume = map(distance, 0, 500, 1, 0);
    sound.amp(volume); // on change le volume du son en fonction de la proximité
  } else {
    sound.amp(0); // si la souris est plus loin que 500, mettre le volume à zéro
  }
  

}


// quand on clique
void mousePressed() {
  clicked = true; // on a cliqué
  noClic = false; // le rectangle noir disparaît
  xClicked = mouseX; // Enregistre la position x du clic
  yClicked = mouseY; // Enregistre la position y du clic
}


// quand on relâche le clic
void mouseReleased() {
  clicked = true; // on a cliqué
  noClic = true; // le rectangle noir disparaît
  xClicked = mouseX; // Enregistre la position x du clic
  yClicked = mouseY; // Enregistre la position y du clic
}
