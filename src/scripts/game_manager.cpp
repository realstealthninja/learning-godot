#include "game_manager.h"
#include "godot_cpp/core/class_db.hpp"

namespace godot {

	GameManager::GameManager() {

	}

	void GameManager::_bind_methods() {
		ClassDB::bind_method(D_METHOD("add_points"), &GameManager::add_points);
	}


	void GameManager::add_points() {
		score += 1;
	}


}
