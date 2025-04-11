#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;


float ground = 400;

float x_position = 0, y_position = 0;
float v0 = 20.0f;
float ACELERACAO_GRAVIDADE = -9.8;
float tempo = 0.0f;
bool estaPulando = false;
float x_direcao = 1;
float y_direcao = 1;
float theta = 0.0;
float PI = 3.14159265;

float CORES_EX_6[12][3] = {
    {0.25, 0.35, 0.25},
    {0.19, 0.31, 0.69},
    {0.33, 0.25, 0.35},
    {0.44, 0.25, 0.27},
    {0.60, 0.23, 0.20},
    {0.90, 0.17, 0.18},
    {0.89, 0.25, 0.15},
    {0.89, 0.47, 0.10},
    {0.85, 0.48, 0.05},
    {0.84, 0.65, 0.00},
    {0.73, 0.62, 0.00},
    {0.43, 0.46, 0.09}
};


void animar(int timer) {
    glutPostRedisplay();

    glutTimerFunc(timer, animar, 0);

}


void teclado3(unsigned char key, int x, int y) {
    if (key == 'd') {
        x_position += 5.0f;
    }
    else if (key == 'a') {
        x_position -= 5.0f;
    }
    else if (key == 32 && !estaPulando) {
        estaPulando = true;
        tempo = 0.0f;
    }

    glutPostRedisplay();
}

void updateJump(float deltaT) {
    if (estaPulando) {
        // Atualizar o tempo de simulação
        tempo += deltaT;


        // Equação de movimento para a posição vertical
        y_position = 5 * (v0 * tempo + 0.5f * ACELERACAO_GRAVIDADE * tempo * tempo);

        // Se o personagem atingir o chão, ele para de pular
        float zero = 0.0f;
        if (x_position + 400 > 458 && x_position + 400 < 602) {
            zero = -9600;
        }
        if (y_position <= zero) {
            y_position = zero; // O personagem retorna ao chão
            estaPulando = false; // Fim do pulo
            tempo = 0.0f; // Reseta o tempo para o próximo pulo
        }
    }
}

void update3(int value) {
    float deltaTime = 0.036f; // Supondo 60 FPS (1/60 segundos por frame)

    // Atualizar a posição do pulo
    updateJump(deltaTime);

    glutPostRedisplay(); // Redesenha a cena
    glutTimerFunc(16, update3, 0); // Chama a função de update novamente após 16ms


}

void animar4(int timer) {
    x_position += 2 * x_direcao;
    y_position += 2 * y_direcao;

    glutPostRedisplay();

    if (x_position + 50 >= 600 && x_direcao > 0) {
        x_direcao = -1;
    }
    if (x_position <= 0 && x_direcao < 0) {
        x_direcao = 1;
    }
    if (y_position + 50 >= 600 && y_direcao > 0) {
        y_direcao = -1;
    }
    if (y_position <= 0 && y_direcao < 0) {
        y_direcao = 1;
    }

    glutTimerFunc(16, animar4, 0);
}

void animar5(int timer) {
    theta += 0.02;

    glutTimerFunc(0, animar5, 0);
}

void display1() {

    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5.0f);

    // vela cinza

    glColor3f(0.76f, 0.76f, 0.76f);
    glBegin(GL_TRIANGLES);

    glVertex2f(180, -90);
    glVertex2f(-180, 360); //Vértice compartilhado com o mastro e a bandeira
    glVertex2f(-300, -90);

    glEnd();
    glFlush();

    // mastro marrom

    glColor3f(0.50f, 0.25f, 0.00f);
    glBegin(GL_QUADS);

    glVertex2f(-190, 360);
    glVertex2f(-160, 360);
    glVertex2f(-160, -180);
    glVertex2f(-190, -180);

    glEnd();
    glFlush();

    // bandeira azul

    glColor3f(0.25f, 0.28f, 0.80f);
    glBegin(GL_QUADS);

    glVertex2f(-190, 360);
    glVertex2f(-20, 360);
    glVertex2f(-20, 300);
    glVertex2f(-190, 300);

    glEnd();
    glFlush();


    //barco vermelho

    glColor3f(0.93f, 0.11f, 0.14f);
    glBegin(GL_QUADS);

    glVertex2f(-450, -180);
    glVertex2f(330, -180);
    glVertex2f(160, -320);
    glVertex2f(-180, -320);

    glEnd();
    glFlush();


    //ponto vermelho origem

    /*
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POINTS);
    glVertex2f(0, 0);

    glEnd();
    glFlush(); */


}


void display2() {
    glClear(GL_COLOR_BUFFER_BIT);

    // circulo 1

    glColor3f(0.00f, 0.00f, 0.20f);
    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(0, 0);
    for (int i = 0; i < 360; i++) {
        glVertex2f(sin(i) * 225, cos(i) * 225);
    }

    glEnd();
    glFlush();

    // circulo 2

    glColor3f(0.00f, 0.00f, 0.60f);
    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(0, 0);
    for (int i = 0; i < 360; i++) {
        glVertex2f(sin(i) * 165, cos(i) * 165);
    }

    glEnd();
    glFlush();

    // circulo 3

    glColor3f(0.00f, 0.00f, 0.20f);
    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(0, 0);
    for (int i = 0; i < 360; i++) {
        glVertex2f(sin(i) * 105, cos(i) * 105);
    }


    glEnd();
    glFlush();

    // circulo 4

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(0, 0);
    for (int i = 0; i < 360; i++) {
        glVertex2f(sin(i) * 45, cos(i) * 45);
    }


    glEnd();
    glFlush();

}


void display3() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.60f, 0.38f, 0.11f);
    glBegin(GL_QUADS);
    glVertex2f(0, 399);
    glVertex2f(900, 399);
    glVertex2f(900, 0);
    glVertex2f(0, 0);

    glEnd();
    glFlush();


    glColor3f(0.15f, 0.58f, 0.05f);
    glBegin(GL_QUADS);
    glVertex2f(0, 399);
    glVertex2f(900, 399);
    glVertex2f(900, 379);
    glVertex2f(0, 379);

    glEnd();
    glFlush();


    glColor3f(0.58f, 0.05f, 0.05f);
    glBegin(GL_QUADS);
    glVertex2f(450, 399); 
    glVertex2f(650, 399);
    glVertex2f(650, 0);
    glVertex2f(450, 0);

    glEnd();
    glFlush();


    glColor3f(1.0f, 0.0f, 0.0f);



    glBegin(GL_QUADS);
    glVertex2f(400 + x_position, ground + y_position);
    glVertex2f(400 + x_position, ground + 50 + y_position);
    glVertex2f(450 + x_position, ground + 50 + y_position);
    glVertex2f(450 + x_position, ground + y_position);

    glEnd();
    glFlush();


}


void display4() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 1.0f);
    
    glBegin(GL_QUADS);
        glVertex2f(x_position, y_position);
        glVertex2f(50+x_position, y_position);
        glVertex2f(50+x_position, 50+y_position);
        glVertex2f(x_position, 50+y_position);
    glEnd();
    glFlush();
}


void display5() {

    int i_cor = 0;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLE_FAN);
    glRotatef(theta, 0, 0, 1);

    glColor3f(CORES_EX_6[i_cor][0], CORES_EX_6[i_cor][1], CORES_EX_6[i_cor][2]);
    glVertex2f(0, 0);

    for (int i = 0; i < 360; i++) {
        float ang = 2 * PI * i / 360;
        glVertex2f(cos(ang) * 210, sin(ang) * 210);
        if (i % 30 == 0) {
            i_cor += 1;
            glEnd();
            glFlush();
            glColor3f(CORES_EX_6[i_cor][0], CORES_EX_6[i_cor][1], CORES_EX_6[i_cor][2]);
            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(0, 0);
        }
    }


    glEnd();
    glFlush();
    
}
void display6() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.85f, 0.82f, 0.18f);
    glPointSize(10.0f);
    glBegin(GL_QUADS);
    glVertex2f(0, -369);
    glVertex2f(549, 0);
    glVertex2f(0, 369);
    glVertex2f(-549, 0);
    glEnd();
    glFlush();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.08f, 0.24f, 0.8f);
    glVertex2f(0, 0);
    for (int i = 0; i < 360; i++) {
        glVertex2f(sin(i) * 210, cos(i) * 210);
    }


    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    int resp;
    cout << "Digite o numero correspondente ao exercicio que quer exibir (1 a 5, e 6 exibe a bandeira do brasil): \n";
    cin >> resp;
    switch (resp) {
    case 1:
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
        glutInitWindowSize(1200, 840);
        glutCreateWindow("Exercício 01");
        glutDisplayFunc(display1);
        gluOrtho2D(-600, 600, -420, 420);
        glClearColor(1.00f, 0.96f, 0.82f, 0);
        glutMainLoop();
        break;
    case 2:
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
        glutInitWindowSize(900, 900);
        glutCreateWindow("Exercício 02");
        glutDisplayFunc(display2);
        gluOrtho2D(-450, 450, -450, 450);
        glClearColor(1.00f, 1.00f, 1.00f, 0);
        glutMainLoop();
        break;
    case 3:
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
        glutInitWindowSize(900, 900);
        glutCreateWindow("Exercício 03");
        glutDisplayFunc(display3);
        glutTimerFunc(25, update3, 0);
        glutKeyboardFunc(teclado3);

        gluOrtho2D(0, 900, 0, 900);
        glClearColor(0.27f, 0.93f, 0.93f, 0);
        glutMainLoop();
        break;
    case 4:
        y_position = 1;
        x_position = 200;

        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
        glutInitWindowSize(600, 600);
        glutCreateWindow("Exercício 04");
        glutDisplayFunc(display4);
        glutTimerFunc(0, animar4, 0);
        gluOrtho2D(0, 600, 0, 600);
        glClearColor(1.0f, 1.0f, 1.0f, 0);
        glutMainLoop();
    case 5:
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
        glutInitWindowSize(600, 600);
        glutCreateWindow("Exercício 05");
        glutDisplayFunc(display5);
        glutTimerFunc(0, animar5, 0);
        gluOrtho2D(-600, 600, -420, 420);
        glClearColor(1.0f, 1.0f, 1.0f, 0);
        glutMainLoop();
    case 6:
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
        glutInitWindowSize(1200, 840);
        glutCreateWindow("Aula_02_bandeira_do_brasil");
        glutDisplayFunc(display6);
        gluOrtho2D(-600, 600, -420, 420);
        glClearColor(0.09, 0.56, 0.13, 0);
        glutMainLoop();
        break;
    }

    return 0;
}