#include "coin.h"

#include "game_manager.h"
#include "godot_cpp/classes/animation_player.hpp"
#include "godot_cpp/classes/engine.hpp"

namespace godot {
    void coin::_bind_methods() {
        ClassDB::bind_method(D_METHOD("on_coin_collect", "p_body"), &coin::on_coin_collect);

    }

    coin::coin() {
        connect("body_entered", Callable(this, "on_coin_collect"));
    }

    void coin::on_coin_collect(Node2D* p_body) {
		manager->add_points();
		player->play("Pickup");
    }

	void coin::_ready() {
		if(Engine::get_singleton()->is_editor_hint()) {
			return;
		}

		manager = get_node<GameManager>("%GameManager");
		player = get_node<AnimationPlayer>("AnimationPlayer");

	}

} // godot
