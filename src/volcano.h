#include "main.h"
#define GLM_ENABLE_EXPERIMENTAL
#ifndef VOLCANO_H
#define VOLCANO_H


class Volcano {
public:
    Volcano() {}
    Volcano(float x, float y, float z, color_t color, double SPEED);
    glm::vec3 position;
    float rotation;
    float length;
    float height;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
    double gravity;
private:
    VAO *object;
};

#endif // BALL_H
