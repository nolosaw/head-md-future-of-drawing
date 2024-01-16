// Effet lampe de poche
PImage img;
PImage imgMouse;

boolean clicked = false; // Variable pour indiquer si un clic a été effectué
boolean rectangleVisible = true; // Variable pour indiquer si le rectangle est visible
int xClicked, yClicked; // Coordonnées du clic

void setup() {
  size(2732/2, 2048/2);
  img = loadImage("Couleur.png");
  img.resize(width, height);
  imgMouse = loadImage("noir.png");
}

void draw() {
  background(255); // Fond blanc
  image(img, 0, 0); // Affiche l'image dans la fenêtre
 image(imgMouse, mouseX - imgMouse.width/2, mouseY - imgMouse.height/2);

  if (rectangleVisible) {
    // mets un rectangle noir tant qu'on a pas cliqué
    background(0); // Fond noir
    fill(0);
    noStroke();
    rect(0, 0, width, height);
  }
}

void mouseClicked() {
  clicked = true; // on a cliqué
  rectangleVisible = !rectangleVisible; // le rectangle noir disparaît
  xClicked = mouseX; // Enregistre la position x du clic
  yClicked = mouseY; // Enregistre la position y du clic
}
