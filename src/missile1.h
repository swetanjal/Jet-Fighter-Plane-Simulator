#include "main.h"
#define GLM_ENABLE_EXPERIMENTAL
#ifndef MISSILE1_H
#define MISSILE1_H


class Missile1 {
public:
    Missile1() {}
    Missile1(float x, float y, float z, color_t color, double SPEED, float vx, float vy, float vz, double ya, double p);
    glm::vec3 position;
    float rotation;
    float length;
    float radius;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
    double speed;
    double gravity;
    double yaw;
    double pitch;
    glm::vec3 v;
private:
    VAO *object;
    VAO *object2;
    VAO *object3;
};

#endif // BALL_H
