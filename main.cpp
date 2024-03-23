#include <iostream>

using namespace std;

#include <gui_glut/gui.h>

Vetor3D posEsfera = Vetor3D (2, 1, 0);
float raioEsfera  = 0.2;

Model3DS carro = Model3DS ("../3ds/cartest.3DS");

void casa ()
{
    // glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

    // frontal
    glBegin (GL_POLYGON);
    glNormal3f (0, 0, 1);
    glTexCoord2f (0, 0);
    glVertex3f (0, 0, 1);
    glTexCoord2f (0.25, 0);
    glVertex3f (1, 0, 1);
    glTexCoord2f (0.25, 1);
    glVertex3f (1, 1, 1);
    glTexCoord2f (0, 1);
    glVertex3f (0, 1, 1);
    glEnd ();
    // direita
    glBegin (GL_POLYGON);
    glNormal3f (1, 0, 0);
    glTexCoord2f (0.25, 0);
    glVertex3f (1, 0, 1);
    glTexCoord2f (0.5, 0);
    glVertex3f (1, 0, 0);
    glTexCoord2f (0.5, 1);
    glVertex3f (1, 1, 0);
    glTexCoord2f (0.25, 1);
    glVertex3f (1, 1, 1);
    glEnd ();
    // traseira
    glBegin (GL_POLYGON);
    glNormal3f (0, 0, -1);
    glTexCoord2f (0.5, 0);
    glVertex3f (1, 0, 0);
    glTexCoord2f (0.75, 0);
    glVertex3f (0, 0, 0);
    glTexCoord2f (0.75, 1);
    glVertex3f (0, 1, 0);
    glTexCoord2f (0.5, 1);
    glVertex3f (1, 1, 0);
    glEnd ();
    // esquerda
    glBegin (GL_POLYGON);
    glNormal3f (-1, 0, 0);
    glTexCoord2f (0.75, 0);
    glVertex3f (0, 0, 0);
    glTexCoord2f (1.0, 0);
    glVertex3f (0, 0, 1);
    glTexCoord2f (1.0, 1);
    glVertex3f (0, 1, 1);
    glTexCoord2f (0.75, 1);
    glVertex3f (0, 1, 0);
    glEnd ();
    // superior
    glBegin (GL_POLYGON);
    glNormal3f (0, 1, 0);
    glVertex3f (0, 1, 0);
    glVertex3f (0, 1, 1);
    glVertex3f (1, 1, 1);
    glVertex3f (1, 1, 0);
    glEnd ();
    // inferior
    glBegin (GL_POLYGON);
    glNormal3f (0, -1, 0);
    glVertex3f (0, 0, 0);
    glVertex3f (1, 0, 0);
    glVertex3f (1, 0, 1);
    glVertex3f (0, 0, 1);
    glEnd ();
    // teto esquerdo
    glBegin (GL_POLYGON);
    glNormal3f (-1, 1, 0);
    glVertex3f (0, 1, 0);
    glVertex3f (0, 1, 1);
    glVertex3f (0.5, 1.5, 1);
    glVertex3f (0.5, 1.5, 0);
    glEnd ();
}

int idTexture = 3;

void usandoTexturas ()
{
    // Usando texturas

    GUI::habilitaTextura (true, false, 0);
    GUI::selecionaTextura (idTexture);

    // objeto a ser aplicada a textura
    // GUI::drawBox(-1,-1,-1, 1,1,1);
    // GUI::drawSphere(posEsfera.x,posEsfera.y,posEsfera.z, raioEsfera);
    // GUI::drawHalfSphere(posEsfera.x,posEsfera.y,posEsfera.z, raioEsfera);

    GUI::setColor (0.7, 0.7, 0.7);
    // glBegin(GL_POLYGON);
    //     glTexCoord2f(0,0); glVertex3f(0,0,0);
    //     glTexCoord2f(0.5,0); glVertex3f(1,0,0);
    //     glTexCoord2f(0.5,1); glVertex3f(1,1,0);
    //     glTexCoord2f(0,1); glVertex3f(0,1,0);
    // glEnd();
    // glBegin(GL_POLYGON);
    //     glTexCoord2f(0,0); glVertex3f(0,0,0);
    //     glTexCoord2f(0.5,0); glVertex3f(1,0,0);
    //     glTexCoord2f(0.25,1); glVertex3f(0.5,1,0);
    // glEnd();

    // casa();

    glRotatef (-90, 1, 0, 0);
    GLUquadricObj *quad = gluNewQuadric ();
    Desenha::gluClosedCylinder (quad, 0.5, 0, 1, 30, 30);
    gluDeleteQuadric (quad);

    GUI::desabilitaTextura (true, false);
}

void desenha ()
{
    GUI::displayInit ();

    GUI::setLight (0, 0, 2, 2, true, false);

    // referencia
    GUI::drawOrigin (0.5);
    // GUI::drawOriginAL(5);
    GUI::setColor (0.8, 0.0, 0.0, 1, true);
    GUI::drawFloor (5, 5);

    GUI::setColor (0.0, 0.8, 0.0, 1, true);
    // GUI::drawSphere(posEsfera.x,posEsfera.y,posEsfera.z, raioEsfera);
    // posEsfera.x -= 0.001;
    // raioEsfera += 0.001;

    // GUI::drawBox(-1,-1,-1, 1,1,1, true);

    // GUI::setColor(0,0,0.8);
    // GUI::draw3ds(carro);

    // casa();

    usandoTexturas ();

    // GUI::drawSphere(posEsfera.x,posEsfera.y,posEsfera.z, raioEsfera);
    // GUI::drawHalfSphere(posEsfera.x,posEsfera.y,posEsfera.z, raioEsfera);
    // GUI::drawSphereInsideBox222(posEsfera.x,posEsfera.y,posEsfera.z,
    // raioEsfera); GUI::drawSphereInsideBox222(0,0,0, raioEsfera);

    // interacao com o mouse
    posEsfera.x += glutGUI::drx;
    posEsfera.y += glutGUI::dry;
    posEsfera.z += -0.1 * glutGUI::dlrx;
    raioEsfera += 0.01 * glutGUI::dlx;

    GUI::displayEnd ();
}

void teclado (unsigned char tecla, int x, int y)
{
    GUI::keyInit (tecla, x, y);

    switch (tecla)
        {
        case 'a':
            posEsfera.x -= 0.1;
            break;
        case 'd':
            posEsfera.x += 0.1;
            break;
        case 's':
            posEsfera.y -= 0.1;
            break;
        case 'w':
            posEsfera.y += 0.1;
            break;
        case 'l':
            glutGUI::trans_luz = !glutGUI::trans_luz;
            break;
        case 'p':
            glutGUI::trans_obj = !glutGUI::trans_obj;
            break;
        case 't':
            idTexture++;
            idTexture = idTexture % 7;
            break;
        default:
            break;
        }
}

int main ()
{
    cout << "Hello World!" << endl;

    GUI gui = GUI (800, 600, desenha, teclado);
}

// inicializando OpenGL
// while(true) {
//     desenha();
//     interacaoUsuario();
//     //if () {
//     //    break;
//     //}
// }

// void cortandoObjetos() {
//     //glRotatef(90,1,0,0);

//    //clipping
//    //GLdouble plane[4] = { 0.0, 1.0, 0.0, 1}; //deixa a parte acima (y) do
//    plano aparecendo (plano posicionado no y=-1, d desloca o plano no sentido
//    oposto à normal) (corta o y<-1)
//    //GLdouble plane[4] = { 0.0, -1.0, 0.0, 1}; //deixa a parte abaixo (y) do
//    plano aparecendo (plano posicionado no y=1, d desloca o plano no sentido
//    oposto à normal) (corta o y>1) GLdouble plane[4] = { -1.0, 0.0, 1.0, 0.0
//    }; //deixa a parte à frente do plano (z) do plano aparecendo (plano
//    posicionado no z=0, d desloca o plano no sentido oposto à normal) (corta
//    o z<0) glClipPlane(GL_CLIP_PLANE0, plane); glEnable(GL_CLIP_PLANE0);

//    //    ax + by + cz + d = 0
//    //            n = (a,b,c)
//    //            d = deslocamento a partir da origem

//    //glRotatef(90,1,0,0);

//    //objeto a ser cortado
//    //GUI::drawSphere(0,0,0,raioEsfera);
//    casa();

//    //clipping
//    glDisable(GL_CLIP_PLANE0);
//}
