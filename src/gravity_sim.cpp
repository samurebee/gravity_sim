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

void processInput(GLFWwindow* window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        std::cout << "Escape pressed\n";
        glfwSetWindowShouldClose(window,true);
    }
    
}

int main(){
    glfwInit();  
    init_context_hints();

    
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "Gravity_sim", NULL, NULL); //window object width,height,name

     float vertices[] = {
        -0.5f,-0.5f,0.0f,
        0.5f,-0.5f,0.0f,
        0.0f,0.5f,0.0f
        };


    //This reserves an ID number, but doesn’t create or use GPU memory yet.
    unsigned int VBO; 
    glGenBuffers(1, &VBO); //generates buffer for VBO to store vertices 

    //Now vbo is the current buffer for the GL_ARRAY_BUFFER target
    glBindBuffer(GL_ARRAY_BUFFER, VBO); 

    //This uploads vertex data into the buffer currently bound to GL_ARRAY_BUFFER.
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


    if(window == nullptr){
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

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); //tells glfw we use this func every window resize 


    while(!glfwWindowShouldClose(window)){ //render loop, so it doesnt close immediately 
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //clears buffer with this color
        glClear(GL_COLOR_BUFFER_BIT);
        processInput(window);

        //rendering commands

        glfwSwapBuffers(window); //swap color buffer(contains each pixel in GLFWS window)
        glfwPollEvents(); //checks if any events occured, keyboard input, and calls corresponding functions 
    }
    
    
    glfwTerminate(); //terminate after exit

}