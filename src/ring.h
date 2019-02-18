#include "main.h"
#define GLM_ENABLE_EXPERIMENTAL
#ifndef RING_H
#define RING_H


class Ring {
public:
    Ring() {}
    Ring(float x, float y, float z, color_t color, double SPEED);
    glm::vec3 position;
    float rotation;
    float radius;
    float length;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
    double gravity;
private:
    VAO *object;
};

#endif // BALL_H
