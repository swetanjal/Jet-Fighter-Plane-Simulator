#include "main.h"
#define GLM_ENABLE_EXPERIMENTAL
#ifndef PLANE_H
#define PLANE_H


class Plane {
public:
    Plane() {}
    Plane(float r, float l, color_t color, double SPEED);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
    float length;
    float radius;
    double gravity;
private:
    VAO *object;
    VAO *object2;
    VAO *object3; 
    VAO *object4;
    VAO *object5;
};

#endif // BALL_H
