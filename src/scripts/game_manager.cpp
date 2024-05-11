#include "game_manager.h"
#include "godot_cpp/classes/area2d.hpp"
#include "godot_cpp/classes/engine.hpp"
#include "godot_cpp/classes/label.hpp"
#include "godot_cpp/classes/node.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/core/object.hpp"
#include "godot_cpp/variant/callable.hpp"
#include "godot_cpp/variant/node_path.hpp"
#include "godot_cpp/variant/string.hpp"

namespace godot {


    GameManager::GameManager() {

    }

    void GameManager::_ready() {
        if(Engine::get_singleton()->is_editor_hint()){
            return;
        }

        scoreLabel = get_node<Label>("ScoreLabel");
        finish_node = get_node<Area2D>("%Finish");
        finish_node->connect("body_entered", Callable(this, "on_finish"));

    }

    void GameManager::_bind_methods() {
        ClassDB::bind_method(D_METHOD("add_points"), &GameManager::add_points);
        ClassDB::bind_method(D_METHOD("on_finish", "body"), &GameManager::on_finish);
        ClassDB::bind_method(D_METHOD("set_next_scene", "scene"), &GameManager::set_next_scene);
        ClassDB::bind_method(D_METHOD("get_next_scene"), &GameManager::get_next_scene);
        ADD_PROPERTY(PropertyInfo(Variant::STRING, "scene"), "set_next_scene", "get_next_scene");
    }


    void GameManager::add_points() {
        score += 1;
        scoreLabel->set_text("You've\nCollected\n" + String::num_int64(score) + " coins!\n Congratulations!");
    }

    void GameManager::on_finish(Node* body) {
        get_tree()->change_scene_to_file(next_scene);
    }

    void GameManager::set_next_scene(String scene) {
        next_scene = scene;
    };

    String GameManager::get_next_scene() {
        return next_scene;
    }

}
