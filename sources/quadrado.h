#ifndef QUADRADO_H
#define QUADRADO_H

#include "types.h"

class Quadrado
{
    private:
        float length;
        float RGBColors[3];
        float vertices[4][3];
        float xc, yc;

    public:

        Quadrado();

        float getLength() const;

        void setLength(float length);

        const float* getRGBColors() const;

        const float getRGBColors(COLOR_ID) const;

        void setRGBColors(const float[3]);

        float getXc() const;

        void setXc(float xc);

        float getYc() const;

        void setYc(float yc);

        const float* getVertices(int n) const;

        const float getVertices(int, AXES) const;

        void translate(float, float);

        void updateVertices();

        bool insideSquare(float, float) const;

        ~Quadrado();

};


#endif //QUADRADO_H
