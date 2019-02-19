#include "main.h"
#include "timer.h"
#include "sea.h"
#include "plane.h"
#include "enemy.h"
#include "models.h"
#include "missile1.h"
#include "missile2.h"
#include "ring.h"
#include "para.h"
#include "marker.h"
#include "enemy_missile.h"
#include "ball.h"
#include "fuel_bar.h"
#include "altimeter.h"
#include "airspeed.h"
#include "bomb.h"
#include "refuel.h"
using namespace std;

GLMatrices Matrices;
GLMatrices Matrices2;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;
int camera = 2;
long long score = 0;
float F = 100.0f;
int release_missile1 = 0;
int release_missile2 = 0;
long long last_bomb = -10;
float height = 0.0f;
float knots;
int pressed;
long long plane_health = 100;
int camera_x, camera_y, camera_z;
Timer t60(1.0 / 60);

/* Render the scene with openGL */
Sea sea;
Marker marker;
Models cube;
Plane plane;
Ball ball;
float theta = 0;
double prev_mouse;
double curr_mouse;
Airspeed airspeed;
Altimeter altimeter;
vector <Bomb> bombs;
vector <Enemy> enemies;
vector <Enemy_Missile> enemy_missiles;
vector <Missile1> missile1;
vector <Missile2> missile2;
vector <Refuel> refuel;
vector <Ring> rings;
vector <Para> parachutes;
Fuel_Bar fuel_bar;
int press_click;
int release_click;
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
    //glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
    glm::vec3 eye, target, up;
    glm::vec3 eye2 = glm::vec3(0, 10, 20);
    glm::vec3 target2 = glm::vec3(0, 10, 0);
    glm::vec3 up2 = glm::vec3(0, 1, 0);
    if(camera == 0){
        if(pressed == 1){
            camera_x = plane.position.x + (-1 * (rand() % 2)) * rand() % 4;
            camera_y = plane.position.y + 10 + (-1 * (rand() % 2)) * rand() % 4;
            camera_z = plane.position.z + 15 + (-1 * (rand() % 2)) * rand() % 4;
            pressed = 0;
        }
        glm::vec3 eye (camera_x, camera_y, camera_z);
        // Target - Where is the camera looking at.  Don't change unless you are sure!!
        glm::vec3 target (plane.position.x, plane.position.y, plane.position.z);
        // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
        glm::vec3 up (0, 1, 0);
    }
    if(camera == 1){
        glm::vec3 z = glm::vec3(-plane.zcoord[0], -plane.zcoord[1], -plane.zcoord[2]);
        glm::vec3 x = glm::vec3(plane.xcoord[0], plane.xcoord[1], plane.xcoord[2]);
        glm::vec3 y = glm::vec3(plane.ycoord[0], plane.ycoord[1], plane.ycoord[2]);
        glm::vec3 eye  = glm::vec3(plane.position.x + (3 * z[0]), plane.position.y + 3 * z[1], plane.position.z + 3 * z[2]);
        // Target - Where is the camera looking at.  Don't change unless you are sure!!
        glm::vec3 target  = glm::vec3(eye[0] + 2 * z[0], eye[1] + 2*z[1], eye[2]+2*z[2]); //(plane.position.x + 10 * plane.coords[2][0], plane.position.y + 10 * plane.coords[2][1], plane.position.z -10 * plane.coords[2][2]);
        // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
        glm::vec3 up (y[0], y[1], y[2]);
    }
    if(camera == 2){
        glm::mat4 rotate = glm::rotate((float) (plane.rot[1] * M_PI / 180.0f), glm::vec3(0, 1, 0));
        glm::vec3 eye (plane.position.x, plane.position.y + 20, plane.position.z + 5 * rotate[2][2]);
        // Target - Where is the camera looking at.  Don't change unless you are sure!!
        glm::vec3 target (plane.position.x, plane.position.y, plane.position.z);
        // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
        
        glm::vec3 up (-rotate[2][0], -rotate[2][1], -rotate[2][2]);
    }
    if(camera == 3){
        glm::mat4 rotate = glm::rotate((float) (plane.rot[1] * M_PI / 180.0f), glm::vec3(0, 1, 0));
        glm::vec3 eye (plane.position.x + 10 * rotate[2][0], plane.position.y + 15, plane.position.z + 15 * rotate[2][2]);
        //glm::vec3 eye (plane.position.x - 10 * plane.coords[2][0], plane.position.y + 15, plane.position.z + 15 );//* plane.coords[2][2]);
        // Target - Where is the camera looking at.  Don't change unless you are sure!!
        glm::vec3 target (plane.position.x, plane.position.y, plane.position.z);
        // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
        glm::vec3 up (0, 1, 0);
    }
    if(camera == 4){
        double tmp;
        glfwGetCursorPos(window, &curr_mouse, &tmp);
        if(press_click){
            prev_mouse = curr_mouse;
            press_click = 0;
        }
        if(release_click){
            release_click = 0;
            theta -= (curr_mouse - prev_mouse) / 5;
        }
        glm::vec3 eye (plane.position.x + 10 * sin(theta * M_PI / 180.0f), plane.position.y + 8, plane.position.z + 10 * cos(theta * M_PI / 180.0f));
        glm::vec3 target (plane.position.x, plane.position.y, plane.position.z);
        glm::vec3 up (0, 1, 0);
    }
    // Compute Camera matrix (view)
    Matrices2.view = glm::lookAt(eye2, target2, up2);
    glm::mat4 VP1 = Matrices2.projection * Matrices2.view;
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane
    
    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;
    
    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model
    // Scene render
    //cube.draw(VP);
    
    sea.draw(VP);
    
    for(int i = 0; i < enemies.size(); ++i)
        enemies[i].draw(VP);
    for(int i = 0; i < missile1.size(); ++i)
        missile1[i].draw(VP);
    for(int i = 0; i < missile2.size(); ++i)
        missile2[i].draw(VP);
    for(int i = 0; i < rings.size(); ++i)
        rings[i].draw(VP);
    for(int i = 0; i < parachutes.size(); ++i)
        parachutes[i].draw(VP);
    marker.draw(VP);
    for(int i = 0; i < enemy_missiles.size(); ++i)
        enemy_missiles[i].draw(VP);
    for(int i = 0; i < bombs.size(); ++i)
        bombs[i].draw(VP);
    for(int i = 0; i < refuel.size(); ++i)
        refuel[i].draw(VP);
    plane.draw(VP);
    // Dashboard
    fuel_bar.draw(VP1);
    altimeter.draw(VP1);
    airspeed.draw(VP1);
    //ball.draw(VP1);
    /////////////
}
int timer;
int last_missile1;
void tick_input(GLFWwindow *window) {
    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int up = glfwGetKey(window, GLFW_KEY_UP);
    int down = glfwGetKey(window, GLFW_KEY_DOWN);
    int lalt = glfwGetKey(window, GLFW_KEY_0);
    int w = glfwGetKey(window, GLFW_KEY_W);
    int q = glfwGetKey(window, GLFW_KEY_Q);
    int e = glfwGetKey(window, GLFW_KEY_E);
    int k = glfwGetKey(window, GLFW_KEY_K);
    int m = glfwGetKey(window, GLFW_KEY_M);
    int spc = glfwGetKey(window, GLFW_KEY_SPACE);
    int leftctrl = glfwGetKey(window, GLFW_KEY_LEFT_CONTROL);
    int b = glfwGetKey(window, GLFW_KEY_B);
    if(spc){
        if(abs(last_bomb - timer) >= 10){
            bombs.push_back(Bomb(plane.position.x, plane.position.y, plane.position.z, COLOR_BLACK, 1.0));
            last_bomb = timer;
        }
    }
    if(b){
        plane.speed = max(0.0, plane.speed - 0.005);
    }
    if(k){
        plane.axis = 0;
        plane.rot[plane.axis] += 0.5;
    }
    if(m){
        plane.axis = 0;
        plane.rot[plane.axis] -= 0.5;
    }
    if (left) {
        // Do something
    }
    if(up){
        plane.position.y += 0.1;
        //plane.rot[0] += 1;
    }
    if(down){
        plane.position.y -= 0.1;
        //plane.rot[0] -= 1;
    }
    if(w){
        plane.speed = min(0.5, plane.speed + 0.001);
        //plane.position.x += (-0.1 * plane.zcoord[0]);
        //plane.position.z += (-0.1 * plane.zcoord[2]);
        //F -= 0.05;
    }
    if(q){
        plane.axis = 1;
        plane.rot[plane.axis] += 1;
    }
    if(e){
        plane.axis = 1;
        plane.rot[plane.axis] += (-1);
    }
    if(left){
        plane.axis = 2;
        plane.rot[plane.axis] += 1;
    }
    if(right){
        plane.axis = 2;
        plane.rot[plane.axis] += (-1);
    }
    if(release_missile1 && !leftctrl){
        glm::vec3 z = glm::vec3(-plane.zcoord[0], -plane.zcoord[1], -plane.zcoord[2]);
        if(abs(last_missile1 - timer) >= 100){
            missile1.push_back(Missile1(plane.position.x, plane.position.y, plane.position.z, COLOR_YELLOW, 1, z[0], z[1], z[2], plane.rot[1], plane.rot[0]));
            last_missile1  = timer;
        }
        release_missile1 = 0;
    }
    if(release_missile1)
        release_missile1 = 0;
    if(release_missile2 && !leftctrl){
        glm::vec3 z = glm::vec3(-plane.zcoord[0], -plane.zcoord[1], -plane.zcoord[2]);
        if(abs(last_missile1 - timer) >= 100){
            missile2.push_back(Missile2(plane.position.x, plane.position.y, plane.position.z, COLOR_YELLOW, 1, z[0], z[1], z[2], plane.rot[1], plane.rot[0]));
            last_missile1  = timer;
        }
        release_missile2 = 0;
    }
    if(release_missile2)
        release_missile2 = 0;
}

void tick_elements() {
    for(int i = 0; i < refuel.size(); ++i)
    if(check_collision(plane.position.x, plane.position.y, plane.position.z, refuel[i].position.x, refuel[i].position.y, refuel[i].position.z, 2, 2, 2)
    || check_collision(plane.position.x, plane.position.y, plane.position.z - plane.length/2, refuel[i].position.x, refuel[i].position.y, refuel[i].position.z, 2, 2, 2)
    || check_collision(plane.position.x, plane.position.y, plane.position.z + plane.length/2, refuel[i].position.x, refuel[i].position.y, refuel[i].position.z, 2, 2, 2))
    {
        F = 200;
        refuel.erase(refuel.begin() + i);
        i = i - 1;
    }
    for(int i = 0; i < bombs.size(); ++i){
        bombs[i].tick();
        for(int j = 0; j < enemies.size(); ++j){
            if(check_collision(bombs[i].position.x, bombs[i].position.y, bombs[i].position.z,
            enemies[j].position.x, enemies[j].position.y, enemies[j].position.z, 4,4,6)){
                enemies[j].health -= 5;
                bombs.erase(bombs.begin() + i);
                i = i - 1;
                break;
            }
        }
    }
    for(int i = 0; i < enemies.size(); ++i){
        if(enemies[i].health <= 0){
            enemies.erase(enemies.begin() + i);
            i = i - 1;
        }
    }
    knots = plane.speed;
    height = plane.position.y;
    if(height >= 75){
        cout << "Game Over!\n You exceeded your allowed altitude!" << endl;
        quit(window);
    }
    if(height <= 0.2){
        cout << "Game Over!\n Your plane crashed on the ground!" << endl;
        quit(window);
    }
    if(plane_health <= 0)
    {
        cout << "Game Over!\n Your plane health became 0!" << endl;
        quit(window);
    }
    if(F <= 0)
    {
        cout << "Game Over!\n You ran out of fuel!" << endl;
        quit(window);
    }
    if(enemies.size() == 0)
    {
        cout << "Mission Accomplished!" << endl;
        quit(window);
    }
    //cout << "Plane Health: " << plane_health << " Active Enemy health: " << max(0.0 * 1.0, enemies[0].health) << " Score: " << score << " Height: " << height << endl;
    if(enemies[0].health <= 0)
    {
        enemies.erase(enemies.begin());
    }
    timer++;
    marker.set_position(enemies[0].position.x, marker.position.y, enemies[0].position.z);
    marker.tick();
    for(int i = 0; i < missile1.size(); ++i)
    {
        missile1[i].set_position(missile1[i].position.x + missile1[i].v.x, missile1[i].position.y + missile1[i].v.y, missile1[i].position.z + missile1[i].v.z);
        if(check_collision(missile1[i].position.x, missile1[i].position.y, missile1[i].position.z,
        enemies[0].position.x, enemies[0].position.y, enemies[0].position.z, 4, 4, 6))
        {
            enemies[0].health--;
            missile1.erase(missile1.begin() + i);
            i = i - 1;
        }
        for(int j = 0; j < parachutes.size(); ++j)
        {
            if(check_collision(missile1[i].position.x, missile1[i].position.y, missile1[i].position.z,
            parachutes[j].position.x, parachutes[j].position.y, parachutes[j].position.z, 2, 2, 2))
            {
                parachutes.erase(parachutes.begin() + j);
                score += 100;
                j = j - 1;
            }
        }
    }

    for(int i = 0; i < missile2.size(); ++i)
    {
        missile2[i].set_position(missile2[i].position.x + missile2[i].v.x, missile2[i].position.y + missile2[i].v.y, missile2[i].position.z + missile2[i].v.z);
        if(check_collision(missile2[i].position.x, missile2[i].position.y, missile2[i].position.z,
        enemies[0].position.x, enemies[0].position.y, enemies[0].position.z, 4, 4, 6))
        {
            enemies[0].health-=4;
            missile2.erase(missile2.begin() + i);
            i = i - 1;
        }
        for(int j = 0; j < parachutes.size(); ++j)
        {
            if(check_collision(missile2[i].position.x, missile2[i].position.y, missile2[i].position.z,
            parachutes[j].position.x, parachutes[j].position.y, parachutes[j].position.z, 2, 2, 2))
            {
                parachutes.erase(parachutes.begin() + j);
                score += 100;
                j = j - 1;
            }
        }
    }
    plane.tick();
    for(int i = 0; i < parachutes.size(); ++i)
        parachutes[i].tick();
    for(int i = 0; i < enemy_missiles.size(); ++i){
        enemy_missiles[i].tick();
        if(check_collision(enemy_missiles[i].position.x, enemy_missiles[i].position.y, enemy_missiles[i].position.z, 
        plane.position.x, plane.position.y, plane.position.z, plane.radius, plane.radius, plane.length)){
            plane_health--;
            enemy_missiles.erase(enemy_missiles.begin() + i);
            i = i - 1;
        }
    }
    for(int i = 0; i < rings.size(); ++i)
    {
        if(plane.position.x >= rings[i].position.x - rings[i].radius/2 && plane.position.x <= rings[i].position.x + rings[i].radius/2)
            if(plane.position.y >= rings[i].position.y - rings[i].radius/2 && plane.position.y <= rings[i].position.y + rings[i].radius/2)
                if(plane.position.z >= rings[i].position.z - rings[i].length/2 && plane.position.z <= rings[i].position.z + rings[i].length/2){
                    rings.erase(rings.begin() + i);
                    i = i - 1;
                    score += 200;
                }
    }
    if((timer % 100) == 0){
        float xxx = enemies[0].position.x - plane.position.x;
        float yyy = enemies[0].position.y - plane.position.y;
        float zzz = enemies[0].position.z - plane.position.z;
        double tmp = sqrt(xxx*xxx + yyy * yyy + zzz * zzz);
        xxx = xxx / tmp;
        yyy = yyy / tmp;
        zzz = zzz / tmp;
        enemy_missiles.push_back(Enemy_Missile(enemies[0].position.x, enemies[0].position.y, enemies[0].position.z, COLOR_BROWN, 1, xxx, yyy, zzz, 1, 1));
    }
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models
    //cube = Models(0, 0, COLOR_BLACK, 1);
    fuel_bar = Fuel_Bar(-1, 7, 0, COLOR_WHITE, 1);
    altimeter = Altimeter(-3, 7, 0, COLOR_WHITE, 1);
    airspeed = Airspeed(1, 7, 0, COLOR_WHITE, 1);
    //ball = Ball(0, -10, -3015, COLOR_BLACK, 1);
    refuel.push_back(Refuel(0, 20, -10, COLOR_GREEN, 1.0));
    sea = Sea(0, 0, COLOR_SEA_BLUE, 1);
    plane = Plane(1, 5, COLOR_RED, 1);
    enemies.push_back(Enemy(6, 0, -10, COLOR_BLACK, 0));
    enemies.push_back(Enemy(12, 0, 0, COLOR_BLACK, 0));
    enemies.push_back(Enemy(6, 0, 10, COLOR_BLACK, 0));
    enemies.push_back(Enemy(-12, 0, 0, COLOR_BLACK, 0));
    rings.push_back(Ring(0, 15, -20, COLOR_YELLOW, 1));
    parachutes.push_back(Para(0, 20, -20, COLOR_RED, 0));
    marker = Marker(0, 20, 0, COLOR_SHINY_RED, 1);
    
    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}
int window_width;
int window_height;
int main(int argc, char **argv) {
    srand(time(0));
    window_width  = 800;
    window_height = 800;

    window = initGLFW(window_width, window_height);

    initGL (window, window_width, window_height);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}

void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    GLfloat fov = M_PI / 2;
    Matrices.projection = glm::perspective(fov, (GLfloat) window_width / (GLfloat) window_height, 0.1f, 500.0f);
    Matrices2.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
}
bool check_collision(float x, float y, float z, float X, float Y, float Z, float x_sz, float y_sz, float z_sz){
    if(x >= (X - x_sz / 2) && x <= (X + x_sz / 2))
        if(y >= (Y - y_sz / 2) && y <= (Y + y_sz / 2))
            if(z >= (Z - z_sz / 2) && z <= (Z + z_sz / 2))
                return true;
    return false;
}
