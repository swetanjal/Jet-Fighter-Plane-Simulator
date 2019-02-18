#include "main.h"
#define GLM_ENABLE_EXPERIMENTAL
#ifndef MISSILE2_H
#define MISSILE2_H


class Missile2 {
public:
    Missile2() {}
    Missile2(float x, float y, float z, color_t color, double SPEED, float vx, float vy, float vz, double ya, double p);
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
