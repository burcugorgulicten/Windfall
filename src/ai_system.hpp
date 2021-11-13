#pragma once

#include <vector>
#include "tiny_ecs_registry.hpp"
#include "common.hpp"

class AISystem
{
public:
	AISystem();
	~AISystem();

	void step(float elapsed_ms);
	void callTree(Entity currPlayer);
};

// ---------------------------------------------------------------------------------------------------------------------------
enum class BTState {
	Running,
	Success,
	Failure
};

class BTNode {
public:
	virtual void init(Entity e);

	virtual BTState process(Entity e) = 0;
};

class BTRunCheckMage : public BTNode {
private:
	int m_index;
	BTNode* m_children[2];	// Run pair has two children, using an array

public:
	BTRunCheckMage(BTNode* c0, BTNode* c1)	// build tree bottom up, we need to know children before building this node for instance
		;

	void init(Entity e) override;

	BTState process(Entity e) override;
};

class BTRunCheckPlayerMageTaunt : public BTNode {
private:
	int m_index;
	BTNode* m_children[2];	// Run pair has two children, using an array

public:
	BTRunCheckPlayerMageTaunt(BTNode* c0, BTNode* c1)	// build tree bottom up, we need to know children before building this node for instance
	;

	void init(Entity e) override;

	BTState process(Entity e) override;
};

// A composite node that loops through all children and exits when one fails
class BTRunCheckCharacter : public BTNode {
private:
	int m_index;
	BTNode* m_children[4];	// Run pair has two children, using an array

public:
	BTRunCheckCharacter(BTNode* c0, BTNode* c1, BTNode* c2, BTNode* c3)	// build tree bottom up, we need to know children before building this node for instance
	;

	void init(Entity e) override;

	BTState process(Entity e) override;
};

// A composite node that loops through all children and exits when one fails
class BTRunCheckMageTaunt : public BTNode {
private:
	int m_index;
	BTNode* m_children[2];	// Run pair has two children, using an array

public:
	BTRunCheckMageTaunt(BTNode* c0, BTNode* c1)	// build tree bottom up, we need to know children before building this node for instance
	;

	void init(Entity e) override;

	BTState process(Entity e) override;
};

// A composite node that loops through all children and exits when one fails
class BTRunCheckEnemyHP : public BTNode {
private:
	int m_index;
	BTNode* m_children[2];	// Run pair has two children, using an array

public:
	BTRunCheckEnemyHP(BTNode* c0, BTNode* c1)	// build tree bottom up, we need to know children before building this node for instance
	;

	void init(Entity e) override;

	BTState process(Entity e) override;
};

// A composite node that loops through all children and exits when one fails
class BTRunCheckMageHP : public BTNode {
private:
	int m_index;
	BTNode* m_children[2];	// Run pair has two children, using an array

public:
	BTRunCheckMageHP(BTNode* c0, BTNode* c1)	// build tree bottom up, we need to know children before building this node for instance
	;

	void init(Entity e) override;

	BTState process(Entity e) override;
};

// A composite node that loops through all children and exits when one fails
class BTRunCheckSwordsman : public BTNode {
private:
	int m_index;
	BTNode* m_children[2];	// Run pair has two children, using an array

public:
	BTRunCheckSwordsman(BTNode* c0, BTNode* c1)	// build tree bottom up, we need to know children before building this node for instance
	;

	void init(Entity e) override;

	BTState process(Entity e) override;
};

// A composite node that loops through all children and exits when one fails
class BTRunCheckSwordsmanTaunt : public BTNode {
private:
	int m_index;
	BTNode* m_children[2];	// Run pair has two children, using an array

public:
	BTRunCheckSwordsmanTaunt(BTNode* c0, BTNode* c1)	// build tree bottom up, we need to know children before building this node for instance
	;

	void init(Entity e) override;

	BTState process(Entity e) override;
};

// A composite node that loops through all children and exits when one fails
class BTRunCheckPlayersDead : public BTNode {
private:
	int m_index;
	BTNode* m_children[2];	// Run pair has two children, using an array

public:
	BTRunCheckPlayersDead(BTNode* c0, BTNode* c1)	// build tree bottom up, we need to know children before building this node for instance
	;

	void init(Entity e) override;

	BTState process(Entity e) override;
};

// A composite node that loops through all children and exits when one fails
class BTRunCheckNecroMinion : public BTNode {
private:
	int m_index;
	BTNode* m_children[2];	// Run pair has two children, using an array

public:
	BTRunCheckNecroMinion(BTNode* c0, BTNode* c1)	// build tree bottom up, we need to know children before building this node for instance
		;

	void init(Entity e) override;

	BTState process(Entity e) override;
};

// A composite node that loops through all children and exits when one fails
class BTRunCheckPlayerMageSilenced : public BTNode {
private:
	int m_index;
	BTNode* m_children[2];	// Run pair has two children, using an array

public:
	BTRunCheckPlayerMageSilenced(BTNode* c0, BTNode* c1)	// build tree bottom up, we need to know children before building this node for instance
		;

	void init(Entity e) override;

	BTState process(Entity e) override;
};

// A general decorator with lambda condition
class BTIfPlayerSideDoNotHaveMageHardCoded : public BTNode
{
public:
	BTIfPlayerSideDoNotHaveMageHardCoded(BTNode* child)	// Has one child
		;

	virtual void init(Entity e) override;

	virtual BTState process(Entity e) override;

private:
	BTNode* m_child;	// one child stored in BTNode as a pointer
};

// A general decorator with lambda condition
class BTIfPlayerSideHasMageHardCoded : public BTNode
{
public:
	BTIfPlayerSideHasMageHardCoded(BTNode* child)	// Has one child
		;

	virtual void init(Entity e) override;

	virtual BTState process(Entity e) override;

private:
	BTNode* m_child;	// one child stored in BTNode as a pointer
};

// A general decorator with lambda condition
class BTIfPlayerMageTaunted : public BTNode
{
public:
	BTIfPlayerMageTaunted(BTNode* child)	// Has one child
		;

	virtual void init(Entity e) override;

	virtual BTState process(Entity e) override;

private:
	BTNode* m_child;	// one child stored in BTNode as a pointer
};

// A general decorator with lambda condition
class BTIfPlayerMageNotTaunted : public BTNode
{
public:
	BTIfPlayerMageNotTaunted(BTNode* child)	// Has one child
		;

	virtual void init(Entity e) override;

	virtual BTState process(Entity e) override;

private:
	BTNode* m_child;	// one child stored in BTNode as a pointer
};

// A general decorator with lambda condition
class BTIfEnemyIsSwordsman : public BTNode
{
public:
	BTIfEnemyIsSwordsman(BTNode* child)	// Has one child
		;

	virtual void init(Entity e) override;

	virtual BTState process(Entity e) override;

private:
	BTNode* m_child;	// one child stored in BTNode as a pointer
};

// A general decorator with lambda condition
class BTIfEnemyIsMagician : public BTNode
{
public:
	BTIfEnemyIsMagician(BTNode* child)	// Has one child
		;

	virtual void init(Entity e) override;

	virtual BTState process(Entity e) override;

private:
	BTNode* m_child;	// one child stored in BTNode as a pointer
};

// A general decorator with lambda condition
class BTIfEnemyMageTaunted : public BTNode
{
public:
	BTIfEnemyMageTaunted(BTNode* child)	// Has one child
		;

	virtual void init(Entity e) override;

	virtual BTState process(Entity e) override;

private:
	BTNode* m_child;	// one child stored in BTNode as a pointer
};

// A general decorator with lambda condition
class BTIfEnemyMageNotTaunted : public BTNode
{
public:
	BTIfEnemyMageNotTaunted(BTNode* child)	// Has one child
		;

	virtual void init(Entity e) override;

	virtual BTState process(Entity e) override;

private:
	BTNode* m_child;	// one child stored in BTNode as a pointer
};

// A general decorator with lambda condition
class BTIfOneLessThanHalf : public BTNode
{
public:
	BTIfOneLessThanHalf(BTNode* child)	// Has one child
		;

	virtual void init(Entity e) override;

	virtual BTState process(Entity e) override;

private:
	BTNode* m_child;	// one child stored in BTNode as a pointer
};

// A general decorator with lambda condition
class BTIfNoneLessThanHalf : public BTNode
{
public:
	BTIfNoneLessThanHalf(BTNode* child)	// Has one child
		;

	virtual void init(Entity e) override;

	virtual BTState process(Entity e) override;

private:
	BTNode* m_child;	// one child stored in BTNode as a pointer
};

// A general decorator with lambda condition
class BTIfMageHPBelowHalf : public BTNode
{
public:
	BTIfMageHPBelowHalf(BTNode* child)	// Has one child
		;

	virtual void init(Entity e) override;

	virtual BTState process(Entity e) override;

private:
	BTNode* m_child;	// one child stored in BTNode as a pointer
};

// A general decorator with lambda condition
class BTIfMageHPAboveHalf : public BTNode
{
public:
	BTIfMageHPAboveHalf(BTNode* child)	// Has one child
		;

	virtual void init(Entity e) override;

	virtual BTState process(Entity e) override;

private:
	BTNode* m_child;	// one child stored in BTNode as a pointer
};

// A general decorator with lambda condition
class BTIfPlayerSideHasSwordsman : public BTNode
{
public:
	BTIfPlayerSideHasSwordsman(BTNode* child)	// Has one child
		;

	virtual void init(Entity e) override;

	virtual BTState process(Entity e) override;

private:
	BTNode* m_child;	// one child stored in BTNode as a pointer
};

// A general decorator with lambda condition
class BTIfPlayerSideDoNotHaveSwordsman : public BTNode
{
public:
	BTIfPlayerSideDoNotHaveSwordsman(BTNode* child)	// Has one child
		;

	virtual void init(Entity e) override;

	virtual BTState process(Entity e) override;

private:
	BTNode* m_child;	// one child stored in BTNode as a pointer
};

// A general decorator with lambda condition
class BTIfEnemySwordsmanNotTaunted : public BTNode
{
public:
	BTIfEnemySwordsmanNotTaunted(BTNode* child)	// Has one child
		;

	virtual void init(Entity e) override;

	virtual BTState process(Entity e) override;

private:
	BTNode* m_child;	// one child stored in BTNode as a pointer
};

// A general decorator with lambda condition
class BTIfEnemySwordsmanTaunted : public BTNode
{
public:
	BTIfEnemySwordsmanTaunted(BTNode* child)	// Has one child
		;

	virtual void init(Entity e) override;

	virtual BTState process(Entity e) override;

private:
	BTNode* m_child;	// one child stored in BTNode as a pointer
};

// A general decorator with lambda condition
class BTIfPlayersDead : public BTNode
{
public:
	BTIfPlayersDead(BTNode* child)	// Has one child
		;

	virtual void init(Entity e) override;

	virtual BTState process(Entity e) override;

private:
	BTNode* m_child;	// one child stored in BTNode as a pointer
};

// A general decorator with lambda condition
class BTIfPlayersAlive : public BTNode
{
public:
	BTIfPlayersAlive(BTNode* child)	// Has one child
		;

	virtual void init(Entity e) override;

	virtual BTState process(Entity e) override;

private:
	BTNode* m_child;	// one child stored in BTNode as a pointer
};

// A general decorator with lambda condition
class BTIfEnemyIsNecroMinion : public BTNode
{
public:
	BTIfEnemyIsNecroMinion(BTNode* child)	// Has one child
		;

	virtual void init(Entity e) override;

	virtual BTState process(Entity e) override;

private:
	BTNode* m_child;	// one child stored in BTNode as a pointer
};

// A general decorator with lambda condition
class BTIfEnemyIsNecroPhaseOne : public BTNode
{
public:
	BTIfEnemyIsNecroPhaseOne(BTNode* child)	// Has one child
		;

	virtual void init(Entity e) override;

	virtual BTState process(Entity e) override;

private:
	BTNode* m_child;	// one child stored in BTNode as a pointer
};

// A general decorator with lambda condition
class BTIfHasNecroMinion : public BTNode
{
public:
	BTIfHasNecroMinion(BTNode* child)	// Has one child
		;

	virtual void init(Entity e) override;

	virtual BTState process(Entity e) override;

private:
	BTNode* m_child;	// one child stored in BTNode as a pointer
};

// A general decorator with lambda condition
class BTIfNoNecroMinion : public BTNode
{
public:
	BTIfNoNecroMinion(BTNode* child)	// Has one child
		;

	virtual void init(Entity e) override;

	virtual BTState process(Entity e) override;

private:
	BTNode* m_child;	// one child stored in BTNode as a pointer
};

// A general decorator with lambda condition
class BTIfPlayerMageSilenced : public BTNode
{
public:
	BTIfPlayerMageSilenced(BTNode* child)	// Has one child
		;

	virtual void init(Entity e) override;

	virtual BTState process(Entity e) override;

private:
	BTNode* m_child;	// one child stored in BTNode as a pointer
};

// A general decorator with lambda condition
class BTIfPlayerMageNotSilenced : public BTNode
{
public:
	BTIfPlayerMageNotSilenced(BTNode* child)	// Has one child
		;

	virtual void init(Entity e) override;

	virtual BTState process(Entity e) override;

private:
	BTNode* m_child;	// one child stored in BTNode as a pointer
};

class BTCastIceShard : public BTNode {
private:
	void init(Entity e) override;
	BTState process(Entity e) override;
};

class BTCastTauntOnMage : public BTNode {
private:
	void init(Entity e) override;
	BTState process(Entity e) override;
};

class BTMeleeAttack : public BTNode {
private:
	void init(Entity e) override;
	BTState process(Entity e) override;
};

class BTCastRockOnSwordsman : public BTNode {
private:
	void init(Entity e) override;
	BTState process(Entity e) override;
};

class BTCastHeal : public BTNode {
private:
	void init(Entity e) override;
	BTState process(Entity e) override;
};

class BTCastHealOnSelf : public BTNode {
private:
	void init(Entity e) override;
	BTState process(Entity e) override;
};

class BTDoNothing : public BTNode {
private:
	void init(Entity e) override;
	BTState process(Entity e) override;
};

class BTSummonNecroMinion : public BTNode {
private:
	void init(Entity e) override;
	BTState process(Entity e) override;
};

class BTCastSilence : public BTNode {
private:
	void init(Entity e) override;
	BTState process(Entity e) override;
};

class BTRandomTargetLightningAttack : public BTNode {
private:
	void init(Entity e) override;
	BTState process(Entity e) override;
};

// ---------------------------------------------------------------------------------------------------------------------------
