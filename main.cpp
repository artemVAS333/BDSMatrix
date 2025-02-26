#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;
using namespace std;
class HelloTriangleApplication {
public:
    void run() {
        std::cout << "Hello World!\n";
        initWindow();
        cout << "window init" << endl;
        initVulkan();
        cout << "vulkan init" << endl;
        mainLoop();
        cout << "main loop" << endl;

        cleanup();
        cout << "cleanup" << endl;
    }

private:
    GLFWwindow* window;
    void initWindow() {
        glfwInit();
        cout << "window init" << endl;
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
        std::cout << "window created" << std::endl;
    }
    void initVulkan() {

    }

    void mainLoop() {
        while (!glfwWindowShouldClose(window))
        {
            glfwPollEvents();
        }
        

    }

    void cleanup() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
};

int main() {
    HelloTriangleApplication app;

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}