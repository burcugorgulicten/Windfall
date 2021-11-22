#pragma once

#include "common.hpp"
#include "tiny_ecs.hpp"
#include "render_system.hpp"

// These are ahrd coded to the dimensions of the entity texture
const float MAGE_WIDTH = 250.f;
const float MAGE_HEIGHT = 200.f;
const float SWORDSMAN_WIDTH = 310.f;
const float SWORDSMAN_HEIGHT = 350.f;
const float NECRO_ONE_WIDTH = 220.f;
const float NECRO_ONE_HEIGHT = 250.f;
const float NECRO_TWO_WIDTH = 300.f;
const float NECRO_TWO_HEIGHT = 400.f;
const float NECRO_MINION_WIDTH = 90.f;
const float NECRO_MINION_HEIGHT = 110.f;

const float HEALTHBAR_WIDTH = 130.f;
const float HEALTHBAR_HEIGHT = 15.f;
const float SILENCEBUBBLE_WIDTH = 60.f;
const float SILENCEBUBBLE_HEIGHT = 40.f;
const float PARTICLEBEAMCHARGE_WIDTH = 750.f;
const float PARTICLEBEAMCHARGE_HEIGHT = 750.f;
const float FIREBALL_WIDTH = 80.f;
const float FIREBALL_HEIGHT = 30.f;
const float ARROW_WIDTH = 80.f;
const float ARROW_HEIGHT = 10.f;
const float FIREBALL_ICON_WIDTH = 80.f;
const float FIREBALL_ICON_HEIGHT = 80.f;
const float SILENCE_ICON_WIDTH = 80.f;
const float SILENCE_ICON_HEIGHT = 80.f;
const float ICON_WIDTH = 80.f;
const float ICON_HEIGHT = 80.f;
const float BARRIER_WIDTH = 50.f;
const float BARRIER_HEIGHT = 500.f;

const float PLAYERTURN_WIDTH = 300.f;
const float PLAYERTURN_HEIGHT = 100.f;
const float ENEMYTURN_WIDTH = 300.f;
const float ENEMYTURN_HEIGHT = 100.f;

const float BACKGROUND_WIDTH = 1800.f;
const float BACKGROUND_HEIGHT = 1080.f;

const float DIALOGUE_WIDTH = 1200.f;
const float DIALOGUE_HEIGHT = 200.f;


const float ROCK_WIDTH = 75.f;
const float ROCK_HEIGHT = 75.f;
const float ICESHARD_WIDTH = 80.f;
const float ICESHARD_HEIGHT = 20.f;
const float GREENCROSS_WIDTH = 30.f;
const float GREENCROSS_HEIGHT = 30.f;
const float METEOR_WIDTH = 500.f;
const float METEOR_HEIGHT = 500.f;

const float BACKGROUND_OBJ_WIDTH = 60;
const float BACKGROUND_OBJ_HEIGHT = 60.f;

const float LIGHTNING_WIDTH = 300.f;
const float LIGHTNING_HEIGHT = 450.f;
const float CHARARROW_WIDTH = 60.f;
const float CHARARROW_HEIGHT = 40.f;
const float DOT_WIDTH = 30.f;
const float DOT_HEIGHT = 30.f;

const float TUTORIAL_BOX_WIDTH = 400.f;
const float TUTORIAL_BOX_HEIGHT = 200.f;
const float UI_BUTTON_WIDTH = 300.f;
const float UI_BUTTON_HEIGHT = 75.f;
const float MENU_PANEL_WIDTH = 600.f;
const float MENU_PANEL_HEIGHT = 400.f;
const float TITLE_WIDTH = 300.f;
const float TITLE_HEIGHT = 100.f;
const float SPIKE_WIDTH = 40.f;
const float SPIKE_HEIGHT = 100.f;

// the player mage
Entity createPlayerMage(RenderSystem* renderer, vec2 pos);
// the enemy mage
Entity createEnemyMage(RenderSystem* renderer, vec2 position);
// the player swordsman
Entity createPlayerSwordsman(RenderSystem* renderer, vec2 pos);
// the enemy swordsman
Entity createEnemySwordsman(RenderSystem* renderer, vec2 pos);
// the necromancer's phase one
Entity createNecromancerPhaseOne(RenderSystem* renderer, vec2 pos);
// the necromancer's phase two
Entity createNecromancerPhaseTwo(RenderSystem* renderer, vec2 pos);
// the necromancer's minion
Entity createNecromancerMinion(RenderSystem* renderer, vec2 pos);

// Create background layers
Entity createBackgroundLayerOne(RenderSystem* renderer, vec2 pos);
Entity createBackgroundLayerTwo(RenderSystem* renderer, vec2 pos);
Entity createBackgroundLayerThree(RenderSystem* renderer, vec2 pos);
Entity createBackgroundLayerFour(RenderSystem* renderer, vec2 pos);

//healthbar
Entity createHealthBar(RenderSystem* renderer, vec2 position);
// create the silence bubble
Entity createSilenceBubble(RenderSystem* renderer, vec2 position);
// create the particle beam charge
Entity createParticleBeamCharge(RenderSystem* renderer, vec2 position);
// the fireball
Entity createIceShard(RenderSystem* renderer, vec2 position, float angle, vec2 velocity, int isFriendly);

Entity createFireBall(RenderSystem* renderer, vec2 position, float angle, vec2 velocity, int isFriendly);
// the icons
Entity createMeleeIcon(RenderSystem* renderer, vec2 position);
Entity createIceShardIcon(RenderSystem* renderer, vec2 position);
Entity createFireballIcon(RenderSystem* renderer, vec2 position);
Entity createFireballIconSelected(RenderSystem* renderer, vec2 position);

// the silence icon
Entity createSilenceIcon(RenderSystem* renderer, vec2 position);
Entity createSilenceIconSelected(RenderSystem* renderer, vec2 position);

Entity createTauntIcon(RenderSystem* renderer, vec2 position);
Entity createHealIcon(RenderSystem* renderer, vec2 position);
Entity createRockIcon(RenderSystem* renderer, vec2 position);
// Turn indicators
Entity createPlayerTurn(RenderSystem* renderer, vec2 position);
Entity createEnemyTurn(RenderSystem* renderer, vec2 position);
// barrier
Entity createBarrier(RenderSystem* renderer, vec2 position);

Entity createGreenCross(RenderSystem* renderer, vec2 position);
Entity createMeteorShower(RenderSystem* renderer, vec2 position, int isFriendly);

Entity createDot(RenderSystem* renderer, vec2 position);

Entity createRock(RenderSystem* renderer, vec2 position, int isFriendly);
Entity createSpike(RenderSystem* renderer, vec2 position, int isFriendly);
Entity createLightning(RenderSystem* renderer, vec2 position, int isFriendly);

Entity createMelee(RenderSystem* renderer, vec2 position, int isFriendly);
// a basic, textured enemy
Entity createEnemyMage(RenderSystem* renderer, vec2 position);
// a red line for debugging purposes
Entity createLine(vec2 position, vec2 size);

Entity createTauntIndicator(RenderSystem* renderer, Entity owner);

Entity createTutorialBox(RenderSystem* renderer, vec2 position);
Entity createBleedIndicator(RenderSystem* renderer, Entity owner);
Entity createBleedDMG(RenderSystem* renderer, vec2 position, int isFriendly);
Entity createTooltip(RenderSystem* renderer, vec2 position, std::string type);

Entity createBackgroundObject(RenderSystem* renderer, vec2 position);

Entity createCharIndicator(RenderSystem* renderer, vec2 position, Entity owner);

Entity createUIButton(RenderSystem* renderer, vec2 position, int buttonType);

// create story background image
Entity createStoryBackground(RenderSystem* renderer, vec2 pos, int number);
// create dialogue image
Entity createDiaogue(RenderSystem* renderer, vec2 pos, int number);

//Game Stats

const int enemy_mage_hp = 90;
const int enemy_swordsman_hp = 130;

const int player_mage_hp = 90;
const int player_swordsman_hp = 130;

//skill dmg
const int rock_dmg = 2000;
const int fireball_dmg = 30;
const int iceshard_dmg = 20;
const int melee_dmg = 15;
const int bleed_dmg = 5;
const int spike_dmg = 10;
const int lightning_dmg = 15;


