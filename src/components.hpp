#pragma once
#include "common.hpp"
#include <vector>
#include <unordered_map>
#include "../ext/stb_image/stb_image.h"


enum CharacterType {
	MAGE = 1,
	SWORDSMAN = 2,
	ARCHER = 3,
	HEALER = 4,
	NECROMANCER_ONE = 5,
	NECROMANCER_TWO = 6,
	NECROMANCER_MINION = 7
};


enum AnimType {
	IDLE = 1,
	ATTACKING = 2,
	DEAD = 3,
	WALKING = 4,
	APPEARING = 5,
	JUMPING = 6
};

enum AttackType {
	// Categories
	MELEE 		= 1,
	TAUNT 		= 2,
	FIREBALL 	= 3,
	ROCK 		= 4,
	HEAL		= 5,
	ICESHARD    = 6,
	SUMMONING   = 7,
	SILENCE		= 8,
	LIGHTNING	= 9,
	SUMMON		= 10,
	ULTI	= 11,
	CHARGING	= 12,
	AOEMELEE = 13,
	BLEEDMELEE = 14,
	SHIELD = 15,
};

enum ButtonType {
	NEW_GAME = 1,
	LOAD_GAME = 2,
	SAVE_GAME = 3,
	EXIT_GAME = 4,
	GAME_TITLE = 5,
	OPEN_MENU = 6,
	CLOSE_MENU = 7,
};

struct UIButton {
	int button_type = 0;
	int isDialogue = 0;
};

struct BackgroundObj
{
	bool shouldDeform;
	bool deformType2;
};


struct storyTellingBackground {

};
// Health bar entity
struct HealthBar
{

};

struct Dot
{

};

struct CharIndicator
{
	Entity owner;
};

struct BleedIndicator
{
	Entity owner;
};
// Currently attacking
struct Attack
{
	int attack_type = 0;
	Entity target;
	vec2 old_pos;
	float counter_ms = 250;
};

struct RunTowards
{
	float counter_ms = 1000;
	Entity target;
	vec2 target_position;
	vec2 old_pos;
	int bleedOrAOE = -1;
};

struct Companion
{
	Entity healthbar;
	// Initialize companionType in world_init create method
	int companionType = 0;
	int curr_frame = 0;
	int curr_anim_type = IDLE;
	float frame_counter_ms = 100;
};

struct Enemy
{
	Entity healthbar;
	// Initialize enemyType in world_init create method
	int enemyType = 0;
	int curr_frame = 0;
	int curr_anim_type = IDLE;
	float frame_counter_ms = 100;
};

struct BackgroundLayer
{
	float scrollX = 0.f;
	int isAutoScroll = 0;
	int isCameraScrollOne = 0;
	int isCameraScrollTwo = 0;
};

// this object is effected by gravity
struct Gravity
{
	float gravity = 98;
};

// Projectiles: Fireball
struct Projectile
{
	float flyingTimer = 0.f;
	int enableCameraTracking = 1;
};

//Special effect : Taunt
struct Taunt
{
	int duration = 3;
};
struct Bleed
{
	int duration = 3;
};


struct Ultimate
{
	int ultiDuration = 4;	// 4 to account for -1 after enemy turn
};

struct Shield
{
	int shieldDuration = 3;	// 3 to account for -1 after enemy turn
};


struct ShieldIcon
{
	int shieldDuration = 2;	// 3 to account for -1 after enemy turn
};

// reflects projectile
struct Reflect
{

};

// Damage component for attacks
// Also has the isFriendly variable
// to determine where the damage
// is coming from
struct Damage
{
	int range = 3;
	int minDamage = 10;
	int isFriendly = 1;
};

// HP for enemy and companion
// entities starts from 100%
struct Statistics 
{
	int max_health = 100;
	int health = 100;
	int speed = 0;	// new speed stat
	int classID = -1; // 0= mage, 1= swordsman for now
};

// Silence component: state of a silenced entity
struct Silenced
{
	// silenced for number of turns
	int turns = 1;	
	// the rendered speech bubble entity
	Entity silenced_effect;
};

// The power to be able to silence
// TODO: check if needed
struct Silence
{

};

struct StatIndicator
{
	Entity owner;
};

// All data relevant to the shape and motion of entities
struct Motion {
	vec2 position = { 0, 0 };
	float angle = 0;
	vec2 velocity = { 0, 0 };
	vec2 scale = { 10, 10 };
	vec2 acceleration = { 0, 0 };
};

// Stucture to store collision information
struct Collision
{
	// Note, the first object is stored in the ECS container.entities
	Entity other; // the second object involved in the collision
	Collision(Entity& other) { this->other = other; };
};

// Data structure for toggling debug mode
struct Debug {
	bool in_debug_mode = 0;
	bool in_freeze_mode = 0;
};
extern Debug debugging;

// Sets the brightness of the screen
struct ScreenState
{
	float darken_screen_factor = -1;
};

// A struct to refer to debugging graphics in the ECS
struct DebugComponent
{
	// Note, an empty struct has size 1
};

// A timer that will be associated to dying companions/enemies
struct DeathTimer
{
	float counter_ms = 2000;
};


// ButtonItem indicator
struct ButtonItem
{
};


// Single Vertex Buffer element for non-textured meshes (coloured.vs.glsl & salmon.vs.glsl)
struct ColoredVertex
{
	vec3 position;
	vec3 color;
};

// Single Vertex Buffer element for textured sprites (textured.vs.glsl)
struct TexturedVertex
{
	vec3 position;
	vec2 texcoord;
};

// Mesh datastructure for storing vertex and index buffers
struct Mesh
{
	static bool loadFromOBJFile(std::string obj_path, std::vector<ColoredVertex>& out_vertices, std::vector<uint16_t>& out_vertex_indices, vec2& out_size);
	vec2 original_size = {1,1};
	std::vector<ColoredVertex> vertices;
	std::vector<uint16_t> vertex_indices;
};

struct HitTimer
{
	float counter_ms = 250;
};

struct TurnIndicator
{
	
};

// Particles emitted
struct Particle
{
	Motion motion;
	glm::vec4 Color;
	float     Life;
	// std::vector<Particle> deathParticles;
	// int fadedParticles = 0;
	// float positions[2000 * 3];
	// float* positions = new float[4000 * 3];
	bool faded;
	// float angle;
	// particles can death particles or aoe particles
	// bool areTypeDeath;

	Particle()
		: Color(1.0f), Life(1500.f), faded(false) {
		motion.velocity.x = (float)((rand() % 50 - 10) * 5);
		motion.velocity.y = (float)((rand() % 50 - 10) * 5);
	}
};

struct ParticlePool
{
	int size;
	std::vector<Particle> particles;
	int fadedParticles = 0;
	float* positions;;
	GLuint particles_position_buffer;
	float poolLife;
	bool areTypeDeath = true;
	Motion motion;
	bool faded = false;
	float angle = 0;

	ParticlePool(int s) {
		size = s;
		float* pos = new float[size * 3];
		positions = pos;
	}
};

// A timer that will be associated to dying companions/enemies
struct CheckRoundTimer
{
	float counter_ms = 3000;
};

// Tooltip

struct toolTip
{

};

// Light
struct Light
{
	
};

/**
 * The following enumerators represent global identifiers refering to graphic
 * assets. For example TEXTURE_ASSET_ID are the identifiers of each texture
 * currently supported by the system.
 *
 * So, instead of referring to a game asset directly, the game logic just
 * uses these enumerators and the RenderRequest struct to inform the renderer
 * how to structure the next draw command.
 *
 * There are 2 reasons for this:
 *
 * First, game assets such as textures and meshes are large and should not be
 * copied around as this wastes memory and runtime. Thus separating the data
 * from its representation makes the system faster.
 *
 * Second, it is good practice to decouple the game logic from the render logic.
 * Imagine, for example, changing from OpenGL to Vulkan, if the game logic
 * depends on OpenGL semantics it will be much harder to do the switch than if
 * the renderer encapsulates all asset data and the game logic is agnostic to it.
 *
 * The final value in each enumeration is both a way to keep track of how many
 * enums there are, and as a default value to represent uninitialized fields.
 */

enum class TEXTURE_ASSET_ID {
	BARRIER = 0,
	FIREBALL = BARRIER + 1,
	FIREBALLICON = FIREBALL + 1,
	FIREBALLICONSELECTED = FIREBALLICON + 1,
	SILENCEICON = FIREBALLICONSELECTED + 1,
	SILENCEICONSELECTED = SILENCEICON + 1,
	SILENCEBUBBLE = SILENCEICONSELECTED + 1,
	FIREBALLICONDISABLED = SILENCEBUBBLE + 1,
	HEALTHBAR = FIREBALLICONDISABLED + 1,
	DEATH_PARTICLE = HEALTHBAR + 1,
	PLAYER_TURN = DEATH_PARTICLE + 1,
	ENEMY_TURN = PLAYER_TURN + 1,
	ARROW = ENEMY_TURN + 1,
	ROCK = ARROW + 1,
	LIGHTNING = ROCK + 1,
	GREENCROSS = LIGHTNING + 1,
	METEOR = GREENCROSS + 1,
	CHARARROW = METEOR + 1,
	DOT = CHARARROW +1,
	PARTICLEBEAMCHARGE = DOT + 1,
	BLEED = PARTICLEBEAMCHARGE +1 ,
	SPIKE = BLEED +1,

	ICESHARD = SPIKE + 1,
	ICESHARDICON = ICESHARD +1,
	ICESHARDICONSELECTED = ICESHARDICON+1,
	ICESHARDICONDISABLED = ICESHARDICONSELECTED + 1,

	ROCKICON = ICESHARDICONDISABLED +1,
	ROCKICONSELECTED = ROCKICON +1,
	ROCKICONDISABLED = ROCKICONSELECTED +1,

	HEALICON = ROCKICONDISABLED +1,
	HEALICONSELECTED = HEALICON +1,
	HEALICONDISABLED = HEALICONSELECTED +1,

	MELEEICON = HEALICONDISABLED + 1,
	MELEEICONSELECTED = MELEEICON + 1,
	MELEEICONDISABLED = MELEEICONSELECTED +1,

	TAUNT = MELEEICONDISABLED +1,
	TAUNTICON = TAUNT + 1,
	TAUNTICONSELECTED = TAUNTICON + 1,
	TAUNTICONDISABLED = TAUNTICONSELECTED+1,

	// ------- Animations -------
	MAGE_ANIM = TAUNTICONDISABLED + 1,
	SWORDSMAN_IDLE = MAGE_ANIM + 1,
	SWORDSMAN_WALK = SWORDSMAN_IDLE + 1,
	SWORDSMAN_MELEE = SWORDSMAN_WALK + 1,
	SWORDSMAN_TAUNT = SWORDSMAN_MELEE + 1,
	SWORDSMAN_DEATH = SWORDSMAN_TAUNT + 1,
	NECRO_ONE_IDLE = SWORDSMAN_DEATH + 1,
	NECRO_ONE_CASTING = NECRO_ONE_IDLE + 1,
	NECRO_ONE_SUMMONING = NECRO_ONE_CASTING + 1,
	NECRO_ONE_DEATH_ONE = NECRO_ONE_SUMMONING + 1,
	NECRO_ONE_DEATH_TWO = NECRO_ONE_DEATH_ONE + 1,
	NECRO_TWO_APPEAR = NECRO_ONE_DEATH_TWO + 1,
	NECRO_TWO_IDLE = NECRO_TWO_APPEAR + 1,
	NECRO_TWO_MELEE = NECRO_TWO_IDLE + 1,
	NECRO_TWO_CASTING = NECRO_TWO_MELEE + 1,
	NECRO_TWO_DEATH = NECRO_TWO_CASTING + 1,
	NECRO_MINION_APPEAR = NECRO_TWO_DEATH + 1,
	NECRO_MINION_IDLE = NECRO_MINION_APPEAR + 1,
	NECRO_MINION_WALK = NECRO_MINION_IDLE + 1,
	NECRO_MINION_MELEE = NECRO_MINION_WALK + 1,
	NECRO_MINION_DEATH = NECRO_MINION_MELEE + 1,
	ARCHER_ANIMS = NECRO_MINION_DEATH + 1,
	ARCHER_ARROW_TEXTURE = ARCHER_ANIMS + 1,
	// ------- Background layers ------
	BACKGROUNDLAYERONE = ARCHER_ARROW_TEXTURE + 1,
	BACKGROUNDLAYERTWO = BACKGROUNDLAYERONE + 1,
	BACKGROUNDLAYERTHREE = BACKGROUNDLAYERTWO + 1,
	BACKGROUNDLAYERFOUR = BACKGROUNDLAYERTHREE + 1,

	// ------ Tutorial text boxes ------
	TUTORIAL_ONE = BACKGROUNDLAYERFOUR + 1,
	TUTORIAL_TWO = TUTORIAL_ONE + 1,
	TUTORIAL_THREE = TUTORIAL_TWO + 1,
	TUTORIAL_FOUR = TUTORIAL_THREE + 1,
	TUTORIAL_FIVE = TUTORIAL_FOUR + 1,
	TUTORIAL_SIX = TUTORIAL_FIVE + 1,
	TUTORIAL_SEVEN = TUTORIAL_SIX + 1,
	TUTORIAL_EIGHT = TUTORIAL_SEVEN + 1,

	// ------ Start screen & Pause menu buttons ------
	NEW_GAME = TUTORIAL_EIGHT + 1,
	NEW_GAME_HOVER = NEW_GAME + 1,
	LOAD_GAME = NEW_GAME_HOVER + 1,
	LOAD_GAME_HOVER = LOAD_GAME + 1,
	SAVE_GAME = LOAD_GAME_HOVER + 1,
	EXIT_GAME = SAVE_GAME + 1,
	EXIT_HOVER = EXIT_GAME + 1,
	GAME_TITLE = EXIT_HOVER + 1,
	OPEN_MENU = GAME_TITLE + 1,
	CLOSE_MENU = OPEN_MENU + 1,
	EMPTY_IMAGE = CLOSE_MENU + 1,

	//------- iconToolTips -------------
	FIREBALLTOOLTIP = EMPTY_IMAGE + 1,
	ICESHARDTOOLTIP = FIREBALLTOOLTIP + 1,
	ROCKTOOLTIP = ICESHARDTOOLTIP + 1,
	MELEETOOLTIP = ROCKTOOLTIP + 1,
	TAUNTTOOLTIP = MELEETOOLTIP + 1,
	HEALTOOLTIP = TAUNTTOOLTIP + 1,

	// ----------- Story scene---------------
	BATTLE = HEALTOOLTIP + 1,
	BATTLESUB = BATTLE + 1,
	ROOM = BATTLESUB + 1,
	WHISPER = ROOM + 1,
	STORYBEGIN = WHISPER + 1,
	STARTSCREEN = STORYBEGIN + 1,
	
	// ---------- background dialogue --------------

	BACKGROUNDONE = STARTSCREEN + 1,
	BACKGROUNDTWO = BACKGROUNDONE + 1,
	BACKGROUNDTHREE = BACKGROUNDTWO + 1,
	BACKGROUNDFOUR = BACKGROUNDTHREE + 1,
	BACKGROUNDFIVE = BACKGROUNDFOUR + 1,

	// ---------- Level One dialogue --------------
	LEVELONEDIALOGUEONE = BACKGROUNDFIVE + 1,
	LEVELONEDIALOGUETWO = LEVELONEDIALOGUEONE + 1,
	LEVELONEDIALOGUETHREE = LEVELONEDIALOGUETWO + 1,
	LEVELONEDIALOGUEFOUR = LEVELONEDIALOGUETHREE + 1,
	LEVELONEDIALOGUEFIVE = LEVELONEDIALOGUEFOUR + 1,
	LEVELONEDIALOGUESIX = LEVELONEDIALOGUEFIVE + 1,

	// ---------- Level Two dialogue --------------
	LEVELTWODIALOGUEONE = LEVELONEDIALOGUESIX + 1,
	LEVELTWODIALOGUETWO = LEVELTWODIALOGUEONE + 1,
	LEVELTWODIALOGUETHREE = LEVELTWODIALOGUETWO + 1,
	LEVELTWODIALOGUEFOUR = LEVELTWODIALOGUETHREE + 1,

	//---------- Level Three dialogue --------------

	LEVELTHREEDIALOGUEONE = LEVELTWODIALOGUEFOUR + 1,
	LEVELTHREEDIALOGUETWO = LEVELTHREEDIALOGUEONE + 1,
	LEVELTHREEDIALOGUETHREE = LEVELTHREEDIALOGUETWO + 1,
	LEVELTHREEDIALOGUEFOUR = LEVELTHREEDIALOGUETHREE + 1,
	LEVELTHREEDIALOGUEFIVE = LEVELTHREEDIALOGUEFOUR + 1,
	LEVELTHREEDIALOGUESIX = LEVELTHREEDIALOGUEFIVE + 1,
	LEVELTHREEDIALOGUESEVEN = LEVELTHREEDIALOGUESIX + 1,
	LEVELTHREEDIALOGUEEIGHT = LEVELTHREEDIALOGUESEVEN + 1,

	//---------- Level Four dialogue --------------
	LEVELFOURDIALOGUEONE = LEVELTHREEDIALOGUEEIGHT + 1,
	LEVELFOURDIALOGUETWO = LEVELFOURDIALOGUEONE + 1,
	LEVELFOURDIALOGUETHREE = LEVELFOURDIALOGUETWO + 1,


	RED_PARTICLE = LEVELFOURDIALOGUETHREE + 1,
	FIREFLY_PNG = RED_PARTICLE + 1,
	TEXTURE_COUNT = FIREFLY_PNG + 1
	//-----------------------------
	
};
const int texture_count = (int)TEXTURE_ASSET_ID::TEXTURE_COUNT;

enum class EFFECT_ASSET_ID {
	COLOURED = 0,
	PEBBLE = COLOURED + 1,
	TEXTURED = PEBBLE + 1,
	WATER = TEXTURED + 1,
	PARTICLE = WATER + 1,
	BACKGROUND_OBJ = PARTICLE + 1,
	LIGHT = BACKGROUND_OBJ + 1,	// NEW
	EFFECT_COUNT = LIGHT + 1
};
const int effect_count = (int)EFFECT_ASSET_ID::EFFECT_COUNT;

enum class GEOMETRY_BUFFER_ID {
	SPRITE = 0,
	PEBBLE = SPRITE + 1,
	DEBUG_LINE = PEBBLE + 1,
	SCREEN_TRIANGLE = DEBUG_LINE + 1,

	// ------- Animations -------
	MAGE_IDLE = SCREEN_TRIANGLE + 1,
	MAGE_CASTING = MAGE_IDLE + 1,
	MAGE_DEATH = MAGE_CASTING + 1,
	SWORDSMAN_IDLE = MAGE_DEATH + 1,
	SWORDSMAN_WALK = SWORDSMAN_IDLE + 1,
	SWORDSMAN_MELEE = SWORDSMAN_WALK + 1,
	SWORDSMAN_TAUNT = SWORDSMAN_MELEE + 1,
	SWORDSMAN_DEATH = SWORDSMAN_TAUNT + 1,
	NECRO_ONE_IDLE = SWORDSMAN_DEATH + 1,
	NECRO_ONE_CASTING = NECRO_ONE_IDLE + 1,
	NECRO_ONE_SUMMONING = NECRO_ONE_CASTING + 1,
	NECRO_ONE_DEATH_ONE = NECRO_ONE_SUMMONING + 1,
	NECRO_ONE_DEATH_TWO = NECRO_ONE_DEATH_ONE + 1,
	NECRO_TWO_APPEAR = NECRO_ONE_DEATH_TWO + 1,
	NECRO_TWO_IDLE = NECRO_TWO_APPEAR + 1,
	NECRO_TWO_MELEE = NECRO_TWO_IDLE + 1,
	NECRO_TWO_CASTING = NECRO_TWO_MELEE + 1,
	NECRO_TWO_DEATH = NECRO_TWO_CASTING + 1,
	NECRO_MINION_APPEAR = NECRO_TWO_DEATH + 1,
	NECRO_MINION_IDLE = NECRO_MINION_APPEAR + 1,
	NECRO_MINION_WALK = NECRO_MINION_IDLE + 1,
	NECRO_MINION_MELEE = NECRO_MINION_WALK + 1,
	NECRO_MINION_DEATH = NECRO_MINION_MELEE + 1,
	ARCHER_IDLE = NECRO_MINION_DEATH + 1,
	ARCHER_WALKING = ARCHER_IDLE + 1,
	ARCHER_JUMPING = ARCHER_WALKING + 1,
	ARCHER_ATTACKING = ARCHER_JUMPING + 1,
	// --------------------------
	BACKGROUND = ARCHER_ATTACKING + 1,

	BACKGROUND_OBJ = BACKGROUND + 1,
	SHIELD_MESH = BACKGROUND_OBJ + 1,
	FIREFLY_MESH = SHIELD_MESH + 1,
	PLATFORM_MESH = FIREFLY_MESH + 1,
	ROCK_MESH = PLATFORM_MESH + 1,
	ARROW_MESH = ROCK_MESH + 1,
	TREASURE_CHEST_MESH = ARROW_MESH + 1,

	GEOMETRY_COUNT = TREASURE_CHEST_MESH + 1
};
const int geometry_count = (int)GEOMETRY_BUFFER_ID::GEOMETRY_COUNT;

struct RenderRequest {
	TEXTURE_ASSET_ID used_texture = TEXTURE_ASSET_ID::TEXTURE_COUNT;
	EFFECT_ASSET_ID used_effect = EFFECT_ASSET_ID::EFFECT_COUNT;
	GEOMETRY_BUFFER_ID used_geometry = GEOMETRY_BUFFER_ID::GEOMETRY_COUNT;
};

