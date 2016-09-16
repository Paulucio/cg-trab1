#include "quadrado.h"

Quadrado::Quadrado()
{
    length = 0;
    xc = yc = 0;
    for(int i = 0; i < 3; i++)
        vertices[i][Z_AXIS] = 0;
}

float Quadrado::getLength() const
{
    return length;
}

void Quadrado::setLength(float length)
{
    this->length = length;
}

const float* Quadrado::getRGBColors() const
{
    return RGBColors;
}

const float Quadrado::getRGBColors(COLOR_ID id) const
{
    return RGBColors[id];
}

void Quadrado::setRGBColors(const float colors[3])
{
    for(int i = 0; i < 3; i++)
        RGBColors[i] = colors[i];
}

float Quadrado::getXc() const
{
    return xc;
}

void Quadrado::setXc(float xc)
{
    this->xc = xc;
}

float Quadrado::getYc() const
{
    return yc;
}

void Quadrado::setYc(float yc)
{
    this->yc = yc;
}

const float* Quadrado::getVertices(int n) const
{
    return vertices[n];
}

const float Quadrado::getVertices(int n, AXES a) const
{
    return vertices[n][a];
}

void Quadrado::translate(float dx, float dy)
{
    this->xc += dx;
    this->yc += dy;
    updateVertices();
}

void Quadrado::updateVertices()
{
    float delta = this->length/2.0;
    //counter clock-wise
    //Vertice one
    vertices[0][X_AXIS] = this->xc - delta;
    vertices[0][Y_AXIS] = this->yc + delta;
    //Vertice two
    vertices[1][X_AXIS] = this->xc - delta;
    vertices[1][Y_AXIS] = this->yc - delta;
    //Vertice three
    vertices[2][X_AXIS] = this->xc + delta;
    vertices[2][Y_AXIS] = this->yc - delta;
    //Vertice four
    vertices[3][X_AXIS] = this->xc + delta;
    vertices[3][Y_AXIS] = this->yc + delta;
}

bool Quadrado::insideSquare(float x, float y) const
{
    if(x >= vertices[0][X_AXIS] && x <= vertices[3][X_AXIS] && y <= vertices[0][Y_AXIS] && y >= vertices[1][Y_AXIS])
        return true;
    else
        return false;
}


Quadrado::~Quadrado(){};