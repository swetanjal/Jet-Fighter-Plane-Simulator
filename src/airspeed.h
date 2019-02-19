#include "main.h"
#define GLM_ENABLE_EXPERIMENTAL
#ifndef AIRSPEED_H
#define AIRSPEED_H


class Airspeed {
public:
    Airspeed() {}
    Airspeed(float x, float y, float z, color_t color, double SPEED);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
    float radius;
    double gravity;
private:
    VAO *object;
    VAO *object1;
};

#endif // BALL_H
