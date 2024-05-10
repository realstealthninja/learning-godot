#include "game_manager.h"
#include "godot_cpp/classes/engine.hpp"
#include "godot_cpp/classes/label.hpp"
#include "godot_cpp/classes/node.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/variant/node_path.hpp"
#include "godot_cpp/variant/string.hpp"
#include "godot_cpp/variant/variant.hpp"

namespace godot {

    GameManager::GameManager() {

    }

    void GameManager::_ready() {
        if(Engine::get_singleton()->is_editor_hint()){
            return;
        }

        scoreLabel = get_node<Label>("ScoreLabel");
        finish_node = get_node<Node>(*finish);

    }

    void GameManager::_bind_methods() {
        ClassDB::bind_method(D_METHOD("add_points"), &GameManager::add_points);
        ClassDB::bind_method(D_METHOD("get_finish"), &GameManager::get_finish);
        ClassDB::bind_method(D_METHOD("set_finish", "finish"), &GameManager::set_finish);
        ClassDB::add_property("Finish", PropertyInfo(Variant::NODE_PATH, "finish"), "set_finish", "get_finish");
    }


    void GameManager::add_points() {
        score += 1;
        scoreLabel->set_text("You've\nCollected\n" + String::num_int64(score) + " coins!\n Congratulations!");
    }

    NodePath* GameManager::get_finish() {
        return finish;
    };

    void GameManager::set_finish(NodePath* _finish) {
        finish = _finish;
    }




}
