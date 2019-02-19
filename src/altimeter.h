#include "main.h"
#define GLM_ENABLE_EXPERIMENTAL
#ifndef ALTIMETER_H
#define ALTIMETER_H


class Altimeter {
public:
    Altimeter() {}
    Altimeter(float x, float y, float z, color_t color, double SPEED);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
    double gravity;
private:
    VAO *object;
    VAO *object1;
};

#endif // BALL_H
