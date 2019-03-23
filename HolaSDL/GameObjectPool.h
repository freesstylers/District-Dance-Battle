#pragma once

#include "GameObject.h"
#include <array>

/*
 *
 */
template<typename T, int SIZE>
class GameObjectPool: public GameObject {
public:
	GameObjectPool(SDLGame* game);
	virtual ~GameObjectPool();
	virtual bool handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time, bool beatSync);

	T* getUnusedObject();
	const vector<T*>& getAllObjects();
	void deactiveAllObjects();

private:
	array<T, SIZE> objs_;
	vector<T*> objsPointers_;
};

template<typename T, int SIZE>
inline GameObjectPool<T, SIZE>::GameObjectPool(SDLGame* game) :
	GameObject(game), objs_() {

	for (auto &o : objs_) {
		o.setActive(false);
		o.setGame(game);
		o.init();
		objsPointers_.push_back(&o);
	}
}

template<typename T, int SIZE>
inline GameObjectPool<T, SIZE>::~GameObjectPool() {
}

template<typename T, int SIZE>
inline bool GameObjectPool<T, SIZE>::handleInput(Uint32 time,
		const SDL_Event& event) {
	if (!isActive())
		return false;
	for (auto &o : objs_) {
		if (o.isActive()) {
			o.handleInput(time, event);
		}
	}
	return true;
}

template<typename T, int SIZE>
inline void GameObjectPool<T, SIZE>::update(Uint32 time) {
	if (!isActive())
		return;
	for (auto &o : objs_) {
		if (o.isActive()) {
			o.update(time);
		}
	}
}

template<typename T, int SIZE>
inline void GameObjectPool<T, SIZE>::render(Uint32 time, bool beatSync){
	if (!isActive())
		return;
	for (auto &o : objs_) {
		if (o.isActive()) {
			o.render(time);
		}
	}
}

template<typename T, int SIZE>
inline T* GameObjectPool<T, SIZE>::getUnusedObject() {
	for (auto &o : objs_) {
		if (!o.isActive()) {
			return &o;
		}
	}

	return nullptr;
}

template<typename T, int SIZE>
inline const vector<T*>& GameObjectPool<T,SIZE>::getAllObjects() {
	return objsPointers_;
}

template<typename T, int SIZE>
inline void GameObjectPool<T,SIZE>::deactiveAllObjects() {
	for (auto &o : objs_) {
		o.setActive(false);
	}
}
