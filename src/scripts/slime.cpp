#include "slime.h"
#include "godot_cpp/classes/animated_sprite2d.hpp"
#include "godot_cpp/classes/engine.hpp"
#include "godot_cpp/classes/ray_cast2d.hpp"
#include "godot_cpp/variant/vector2.hpp"


namespace godot {

	slime::slime() {

	}

	void slime::_ready() {
		if (Engine::get_singleton()->is_editor_hint()) {
			return;
		}
		left  = get_node<RayCast2D>("RayCastLeft");
		right = get_node<RayCast2D>("RayCastRight");

		sprite = get_node<AnimatedSprite2D>("AnimatedSprite2D");
	}


	void slime::_process(double delta) {

		if(Engine::get_singleton()->is_editor_hint()) {
		return;
		}

		if (right->is_colliding()) {
			direction = -1;
			sprite->set_flip_h(true);
		} else if (left->is_colliding()) {
			direction = 1;
			sprite->set_flip_h(false);
		}


		Vector2 position = get_position();
		position.x += direction * speed * delta;
		set_position(position);

	}

}
