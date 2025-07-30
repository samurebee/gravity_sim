#include "../dependencies/include/glad/glad.h"
#include "../dependencies/include/GLFW/glfw3.h"
#include <iostream>


void framebuffer_size_callback(GLFWwindow* window, int width, int height){ //adjusts viewport when the user resizes the window 
    glViewport(0, 0, width, height); 
}

void init_context_hints(){ //more at glfw documentation on windows
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); 
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //need for mac
}

int main(){
    glfwInit();  
    init_context_hints();
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "Gravity_sim", NULL, NULL); //window object width,height,name

    if(window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl; 
        glfwTerminate(); 
        return-1;
    }

    glfwMakeContextCurrent(window); //attach context to curr window 

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){ //glad manages functions pointers, we intialize it here
        std::cout << "Failed to initialize GLAD" << std::endl; 
        return-1; 
    }

    glViewport(0, 0, 800, 600);//size of rendering window 

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); //tells glfw we usse this func every window resize 

    while(!glfwWindowShouldClose(window)){ //render loop, so it doesnt close immediately 
        glfwSwapBuffers(window); //swap color buffer(contains each pixel in GLFWS window)
        glfwPollEvents(); //checks if any events occured, keyboard input, and calls corresponding functions 
    }
    
    
    glfwTerminate(); //terminate after exit

}