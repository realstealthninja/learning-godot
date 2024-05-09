#include "game_manager.h"
#include "godot_cpp/classes/label.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/variant/string.hpp"

namespace godot {

	GameManager::GameManager() {

	}

	void GameManager::_ready() {
		scoreLabel = get_node<Label>("ScoreLabel");
	}

	void GameManager::_bind_methods() {
		ClassDB::bind_method(D_METHOD("add_points"), &GameManager::add_points);
	}


	void GameManager::add_points() {
		score += 1;
		scoreLabel->set_text("You've\nCollected\n" + String::num_int64(score) + " coins!\n Congratulations!");
	}


}
