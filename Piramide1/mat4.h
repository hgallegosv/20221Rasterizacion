//
// Created by hgallegos on 2/05/2022.
//

#ifndef PIRAMIDE1_MAT4_H
#define PIRAMIDE1_MAT4_H


class mat4 {
public:
    float m[16];

    mat4();

    void identidad();
    void escala(float sx, float sy, float sz);
    void traslacion(float tx, float ty, float tz);

    mat4 multiplicar(mat4 matriz);
};
mat4::mat4() {
    identidad();
}

void mat4::identidad() {
    for(int i=0; i < 16; i++) {
        m[i] = 0;
    }
    m[0] = m[5] = m[10] = m[15] = 1;
}
void mat4::escala(float sx, float sy, float sz) {
    identidad();
    m[0] = sx;
    m[5] = sy;
    m[10] = sz;
}
void mat4::traslacion(float tx, float ty, float tz) {
    identidad();
    m[3] = tx;
    m[7] = ty;
    m[11] = tz;
}

mat4 mat4::multiplicar(mat4 matriz) {

}



#endif //PIRAMIDE1_MAT4_H
