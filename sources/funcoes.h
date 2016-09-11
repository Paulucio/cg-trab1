#ifndef FUNCOES_H
#define FUNCOES_H

#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include "types.h"
#include "../tinyxml2/tinyxml2.h"
#include "janela.h"
#include "quadrado.h"

using namespace std;
using namespace tinyxml2;

void readXMLFile(const char*, Janela&, Quadrado&);

#endif //FUNCOES_H
