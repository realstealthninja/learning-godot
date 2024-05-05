#include "killzone.h"
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/collision_shape2d.hpp>

namespace godot {
    void killzone::_bind_methods() {
        ClassDB::bind_method(D_METHOD("__on_body_entered", "body"), &killzone::__on_body_entered);
        ClassDB::bind_method(D_METHOD("_on_timer_timeout"), &killzone::_on_timer_timeout);
    }

    killzone::killzone() {
        connect("body_entered", Callable(this, "__on_body_entered"));
        timer = nullptr;
    }

    void killzone::_ready() {
        if (Engine::get_singleton()->is_editor_hint()) {
            return;
        }
        timer = get_node<Timer>(NodePath("Timer"));
        timer->connect("timeout", Callable(this, "_on_timer_timeout"));
    }

    void killzone::__on_body_entered(godot::Node2D *body) {
        UtilityFunctions::print("you died");
        body->get_node<CollisionShape2D>("CollisionShape2D")->queue_free();
        Engine::get_singleton()->set_time_scale(0.5);
        timer->start();
    }

    void killzone::_on_timer_timeout() {
        get_tree()->reload_current_scene();
    }
} // godot
