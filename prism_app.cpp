#include <iostream>
#include <GLFW/glfw3.h>
int main() {
    int sides;
    std::cout << "Enter the number of sides: ";
    std::cin >> sides;
    if (sides < 3) {
        std::cout << "A shape must have at least 3 sides!" << std::endl;
        return 1;
    }
    GLFWwindow* window;
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }
    window = glfwCreateWindow(640, 480, "Polygon", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    return 0;

}