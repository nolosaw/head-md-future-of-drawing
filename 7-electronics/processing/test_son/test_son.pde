import processing.sound.*;

SoundFile sound; // Déclaration de la variable du son

void setup() {
  size(600, 400);
  // Charger le son à partir d'un fichier audio
  sound = new SoundFile(this, "nature.wav");
  
  // Définir la position initiale du son
  sound.amp(0); // Définir le volume initial à zéro
  sound.loop(); // Mettre le son en boucle
}

void draw() {
  background(255);
  
  // Calculer la distance entre la souris et l'endroit où se trouve le son
  float distance = dist(mouseX, mouseY, 200, 200);
  
  // Si la distance est inférieure à 500 pixels, ajuster le volume en conséquence
  if (distance < 500) {
    // Calculer le volume en fonction de la proximité
    float volume = map(distance, 0, 500, 1, 0);
    sound.amp(volume); // Changer le volume du son en fonction de la proximité
  } else {
    sound.amp(0); // Si la souris est trop éloignée, mettre le volume à zéro
  }
  
  // Dessiner le cercle représentant l'emplacement du son
  fill(255, 0, 0);
  ellipse(200, 200, 20, 20);
}
