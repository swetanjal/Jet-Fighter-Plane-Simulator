#include "main.h"
#define GLM_ENABLE_EXPERIMENTAL
#ifndef COMPASS_H
#define COMPASS_H


class Compass {
public:
    Compass() {}
    Compass(float x, float y, float z, color_t color, double SPEED);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
    double gravity;
private:
    VAO *object;
};

#endif // BALL_H
