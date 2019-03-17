
#include "input.h"

using std::map;

void keycallback(GLFWwindow *w, int key, int scancode, int action, int mods) {
    static_cast<InputHandler*>(glfwGetWindowUserPointer(w))->key_callback(w, key, scancode, action, mods);
}

InputHandler::InputHandler(GLFWwindow *window) {
    // so we can call the object-specific implementation of
    // key_callback later on
    glfwSetWindowUserPointer(window, this);
    glfwSetKeyCallback(window, &keycallback);
}

InputHandler::~InputHandler() {

}

void InputHandler::add(GLint key, std::function<void(float)> action) {
    keymap[key] = {0, action};
}

void InputHandler::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (action == GLFW_REPEAT)
        return;
    auto it = keymap.find(key);
    if (it != keymap.end())
        it->second.first = (action == GLFW_PRESS);
}

void InputHandler::run(float dt) {
    for (auto it = keymap.begin(); it != keymap.end(); it++)
        if (it->second.first)
            it->second.second(dt);
}


