#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void process_input(GLFWwindow* window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
	glfwInit(); //This is to initiate the glfw lib
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //hints are basically Configuration settings and here we are setting major
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //and minor version of OpenGL
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //this is to set our profile to core so that we can get more flexibility 

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "triangle window", NULL, NULL); //here we allocate space and create window object
	
	if (window == NULL) {
		cout << "Failed To Create Window" << endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window); //here we make that window object run on the current thread 

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  // here we bind the callback fucntion we created

	if ((!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))) //here we are checking if glad can load all opengl function pointers or not
	{
		cout << "Failed to load the GLAD" << endl;
		return -1;
	}

	while (!glfwWindowShouldClose(window)) //to keep the window open we are running a while loop 
	{
		process_input(window);
		glClearColor(0.3f, 0.4f, 0.5f, 1.0f); // this is the color that will be brought up once you clear the screen
		glClear(GL_COLOR_BUFFER_BIT); 
		glfwSwapBuffers(window); // this function helps with buffer swaps
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}

void process_input(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) //this manages the closing input from the window
	{
		glfwSetWindowShouldClose(window, true);
	}
		
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) // this to handle the window resizing
{
	glViewport(0, 0, width, height);
}