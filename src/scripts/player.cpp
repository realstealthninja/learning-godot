#include "player.h"
#include "godot_cpp/classes/engine.hpp"


#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/core/math.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

namespace godot {
    player::player() {
        gravity = 9.8f;
    }

    void player::_physics_process(double delta) {
        if (Engine::get_singleton()->is_editor_hint()) {
            //UtilityFunctions::print("in editor rn");
            return;
        }
        //UtilityFunctions::print("not in editor rn");

        auto velocity = this->get_velocity();
        if (!is_on_floor()) {
            velocity.y += gravity * delta;
            UtilityFunctions::print("falling rn");
            this->set_velocity(velocity);
            UtilityFunctions::print(velocity.x);
        };
        auto input = Input::get_singleton();

        if (input->is_action_just_pressed("ui_accept") && is_on_floor()) {
            velocity.y = jump_velocity;
            this->set_velocity(velocity);
        }

        auto direction = input->get_axis("ui_left", "ui_right");

        if (direction != 0) {
            velocity.x = direction * speed;
        } else {
            velocity.x = Math::move_toward(velocity.x, 0, speed);
        }
        this->set_velocity(velocity);

        move_and_slide();
    }

    void player::_ready() {
        // run
    }
} //namespace godot
