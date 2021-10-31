
#define GL3W_IMPLEMENTATION
#include <gl3w.h>

// stlib
#include <chrono>
#include <iostream>


// internal
#include "ai_system.hpp"
#include "physics_system.hpp"
#include "render_system.hpp"
#include "world_system.hpp"
#include "json_loader.hpp"

using Clock = std::chrono::high_resolution_clock;
using namespace std;

const int window_width_px = 1200;
const int window_height_px = 800;

// Entry point
int main()
{
	// Global systems
	WorldSystem world;
	RenderSystem renderer;
	PhysicsSystem physics;
	AISystem ai;

	// Initializing window
	GLFWwindow* window = world.create_window(window_width_px, window_height_px);
	if (!window) {
		// Time to read the error message
		printf("Press any key to exit");
		getchar();
		return EXIT_FAILURE;
	}

	// initialize the main systems
	renderer.init(window_width_px, window_height_px, window);
	world.init(&renderer);
	world.createRound();
	world.checkRound();

	std::ifstream jsonFile("../src/small_example.json");
    if (jsonFile.is_open()){
        //std::cout << jsonFile.rdbuf();
	}
	else {printf("not open?\n");}
    nlohmann::json j = nlohmann::json::parse(jsonFile);
    std::cout << j << std::endl;

	// variable timestep loop
	auto t = Clock::now();
	while (!world.is_over()) {
		// Processes system messages, if this wasn't present the window would become
		// unresponsive
		glfwPollEvents();

		// Calculating elapsed times in milliseconds from the previous iteration
		auto now = Clock::now();
		float elapsed_ms =
			(float)(std::chrono::duration_cast<std::chrono::microseconds>(now - t)).count() / 1000;
		t = now;
		world.step(elapsed_ms);
		ai.step(elapsed_ms);
		physics.step(elapsed_ms, window_width_px, window_height_px);
		world.handle_collisions();
		world.handle_boundary_collision();

		renderer.draw(elapsed_ms);
	}

	return EXIT_SUCCESS;
}
