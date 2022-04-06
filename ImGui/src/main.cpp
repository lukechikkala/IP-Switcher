// Author: Luke Chikkala

#include "libs/imgui.h"
#include "libs/imgui_impl_glfw.h"
#include "libs/imgui_impl_opengl3.h"

#include <iostream>
#include <cmath>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void processInput(GLFWwindow *window);

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	int window_width 	= 400; 	int window_height	= 200;
	GLFWwindow* window = glfwCreateWindow(window_width, window_height, "IP Info", NULL, NULL); // Replace first NULL with 'glfwGetPrimaryMonitor()' to run Full Screen on First Monitor.
	if (window == NULL)
	{
		std::cout << "Failed" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	gladLoadGL();
	glViewport(0, 0, 800, 800);

	// ImGUI Stuff
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		// --> Background Color
		float Red, Green, Blue;
		Red		= 0.000f;
		Green	= 0.065f;
		Blue	= 0.118f;
		glClearColor(Red, Green, Blue, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// --> DOCKING
		const ImGuiViewport* viewport = ImGui::GetMainViewport();
		ImGui::SetNextWindowPos(viewport->WorkPos);
		ImGui::SetNextWindowSize(viewport->WorkSize);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
		ImGui::PopStyleVar(2);

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		// Window Flags
		ImGuiWindowFlags	window_flags = 0;
							window_flags |= ImGuiWindowFlags_NoTitleBar;
//							window_flags |= ImGuiWindowFlags_NoScrollbar;
							window_flags |= ImGuiWindowFlags_MenuBar;
//							window_flags |= ImGuiWindowFlags_NoMove;
//							window_flags |= ImGuiWindowFlags_NoResize;
//							window_flags |= ImGuiWindowFlags_NoCollapse;
//							window_flags |= ImGuiWindowFlags_NoNav;
							window_flags |= ImGuiWindowFlags_NoBackground;
//							window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus;
//							window_flags |= ImGuiWindowFlags_UnsavedDocument;
							bool*  p_open = NULL; // Don't pass our bool* to Begin

		// --> Program Begin
		ImGui::Begin("IP Switcher by Luke Chikkala", p_open, window_flags); // 		ImGui::Begin("Hello", nullptr, ImGuiWindowFlags_NoCollapse); will remove the collapse button.

		// --> Menu Bar
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("Menu"))
			{
				if (ImGui::MenuItem("Clear Screen"))
					system("clear");
				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}
		if (ImGui::Button("Print IP Address"))
			system("ifconfig en0 | grep mas | sed -E 's/.*inet //' | sed -E 's/ netmask.*//'");
		if (ImGui::Button("Print Subnet Mask"))
			system("ipconfig getoption en0 subnet_mask");
		if (ImGui::Button("Network Interface List"))
			system("networksetup -listallnetworkservices");
		ImGui::End();
		// --> Program End

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window);
	glfwTerminate();
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}