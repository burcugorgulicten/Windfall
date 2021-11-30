#pragma once

// internal
#include "common.hpp"

// stlib
#include <vector>
#include <random>

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_mixer.h>

#include "ai_system.hpp"
#include "render_system.hpp"
#include "skill_system.hpp"

// Container for all our entities and game logic. Individual rendering / update is
// deferred to the relative update() methods
class WorldSystem
{
public:
	WorldSystem();

	// Creates a window
	GLFWwindow* create_window(int width, int height);

	// starts the game
	void init(RenderSystem* renderer, AISystem* ai_arg, SkillSystem* skill_arg);

	// Displays the start screen and buttons
	void render_startscreen();

	// display player turn
	void displayPlayerTurn();

	// display enemy turn
	void displayEnemyTurn();

	// create attacks
	void iceShardAttack(Entity currPlayer);

	//Prep skill Function
	//void startTauntAttack(Entity origin, Entity target);
	//void startIceShardAttack(Entity origin, Entity target);
	//void startFireballAttack(Entity origin);
	//void startRockAttack(Entity origin, Entity target);
	//void startHealAttack(Entity origin, Entity target);
	//void startMeleeAttack(Entity origin, Entity target);

	// creates a round
	void createRound();

	// check a round
	void checkRound();

	// Releases all associated resources
	~WorldSystem();

	// Steps the game ahead by ms milliseconds
	bool step(float elapsed_ms);

	// Check for collisions
	void handle_collisions();

	void handle_boundary_collision();

	// Should the game be over ?
	bool is_over()const;


	int player_turn;

	// IMPORTANT: Determines if systems can call step()
	int canStep = 0;
	int closeWindow = 0;

private:
	// Input callback functions
	void on_key(int key, int, int action, int mod);
	void on_mouse_move(vec2 pos);
	// handle mouse click
	void on_mouse_button( int button,int action, int mods);

	// check if mouse in button
	bool inButton(vec2 buttonPos, float buttonX, float buttonY);

	// check if mouse in entity
	bool inEntity(const Entity entity);

	// check if mouse is on an area
	bool mouseInArea(vec2 buttonPos, float buttonX, float buttonY);

	// make tooltip smartly place
	vec2 placeDirection(vec2 mouse_position, vec2 icon_position, float width, float height);

	// deselect current button (after using ability)
	void deselectButton();

	// reset all selected buttons if there are any (when a button is clicked)
	void deselectButtons();

	// Helper function for updating health in collision
	void update_health(Entity entity, Entity other_entity);

	// Updates all healthbars
	void update_healthBars();

	// restart level
	void restart_game(bool force_restart = false);

	// OpenGL window handle
	GLFWwindow* window;

	// Number of fish eaten by the salmon, displayed in the window title
	unsigned int points;

	// Death particle activation
	void activate_deathParticles(Entity entity);

	//Skills Function
	void removeTaunt(Entity target);
	void removeSilence(Entity target);
	bool canUseSkill(Entity user, int skill);
	void showCorrectSkills();

	void displayTurnIndicator(int isPlayerTurn);
	void advanceTutorial(Entity currTutorial, vec2 pos);

	// Story telling
	void backgroundTelling();

	// Game state
	RenderSystem* renderer;
	AISystem* ai;
	SkillSystem* sk;

	float current_speed;
	Entity player_mage;
	Entity enemy_mage;
	Entity player_swordsman;
	Entity enemy_swordsman;
	Entity player_archer;
	Entity arrow_mesh;

	Entity fireball;
	Entity silence_icon;
	Entity iceShard;
	Entity tooltip;


	Entity turn_indicator;
	Entity curr_tutorial_box;
	int curr_tutorial_box_num = 0;
	int tutorial_icon_selected = 1;
	int tutorial_ability_fired = 1;
	int tutorial_enabled = 0;

	// UI buttons
	Entity new_game_button;
	Entity load_game_button;
	Entity save_game_button;
	Entity exit_game_button;
	Entity open_menu_button;
	int pauseMenuOpened = 0;

	// story telling system
	Entity backgroundImage;
	Entity dialogue;

	// C++ random number generator
	std::default_random_engine rng;
	std::uniform_real_distribution<float> uniform_dist; // number between 0..1

	// Camera Control constants
	float CAM_OFFSET_XMAX = 0.4;
	float CAM_OFFSET_YMAX = 0.2;

	//skill constants
	float FIREBALLSPEED = 900.f;
	float ARROWSPEED = 700.f;
	float ICESHARDSPEED = 100.f;

	const int16 MAX_GAME_LEVELS = 3;

	std::vector<std::vector<bool>> skill_character_aviability = {
		// ice  fire  rock  heal  taunt  melee
//mage
		{ true, true, true, true, false, false},
//swordsman
		{ false, false, false, false, true, true}
	};
};
// Can't use diretly somehow so just for reference
enum class SKILL_ID {
	SK_ICESHARD = 0,
	SK_FIREBALL = SK_ICESHARD + 1, //1
	SK_ROCK = SK_FIREBALL + 1, //2
	SK_HEAL = SK_ROCK + 1, //3
	SK_TAUNT = SK_HEAL+1,//4
	SK_MELEE = SK_TAUNT +1,//5
	SKILL_COUNT = SK_MELEE + 1,
};
