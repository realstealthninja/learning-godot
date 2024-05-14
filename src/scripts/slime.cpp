#include "slime.h"
#include "godot_cpp/classes/animated_sprite2d.hpp"
#include "godot_cpp/classes/animation_player.hpp"
#include "godot_cpp/classes/area2d.hpp"
#include "godot_cpp/classes/engine.hpp"
#include "godot_cpp/classes/ray_cast2d.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/variant/callable.hpp"
#include "godot_cpp/variant/vector2.hpp"
#include "killzone.h"


namespace godot {

	slime::slime() {

	}

	void slime::_bind_methods() {
		ClassDB::bind_method(D_METHOD("on_stomp", "body"), &slime::on_stomp);

	}

	void slime::_ready() {
		if (Engine::get_singleton()->is_editor_hint()) {
			return;
		}
		left  = get_node<RayCast2D>("RayCastLeft");
		right = get_node<RayCast2D>("RayCastRight");

		sprite = get_node<AnimatedSprite2D>("AnimatedSprite2D");
		player = get_node<AnimationPlayer>("AnimationPlayer");
		zone = get_node<killzone>("killzone");

	}


	void slime::_physics_process(double delta) {

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
