#include "player.h"
#include "godot_cpp/classes/animated_sprite2d.hpp"
#include "godot_cpp/classes/engine.hpp"


#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/project_settings.hpp>

namespace godot {
    player::player() {
        gravity = ProjectSettings::get_singleton()->get_setting("physics/2d/default_gravity");

    }

    void player::_physics_process(double delta) {
        if (Engine::get_singleton()->is_editor_hint()) {
            return;
        }

        auto velocity = get_velocity();
        auto input = Input::get_singleton();

        auto direction = input->get_axis("ui_left", "ui_right");

        velocity.y += gravity * (float)delta;


        if (input->is_action_just_pressed("ui_accept") && is_on_floor()) {
            velocity.y = jump_velocity;
        	// add animation
        }


        if (direction > 0) {
	  sprite->play("run");

	  // set flip to false if player is going right
	  sprite->set_flip_h(false);
        } else if (direction < 0) {
	  sprite->play("run");
          // set flip to true if player is going left
	  sprite->set_flip_h(true);
        } else {
	  // not any direction must be standing still
	  sprite->play("idle");
	}

        velocity.x = (float) direction *  speed;

        set_velocity(velocity);
        move_and_slide();
    }

    void player::_ready() {
        // run
	if (Engine::get_singleton()->is_editor_hint()) {
	    return;
	}

	sprite = get_node<AnimatedSprite2D>("AnimatedSprite2D");



    }
} //namespace godot
