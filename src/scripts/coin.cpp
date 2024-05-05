#include "coin.h"

#include "godot_cpp/classes/engine.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

namespace godot {
    void coin::_bind_methods() {
        ClassDB::bind_method(D_METHOD("on_coin_collect", "p_body"), &coin::on_coin_collect);

    }

    coin::coin() {
        Error err = connect("body_entered", Callable(this, "on_coin_collect"));
        UtilityFunctions::print(err);
    }

    void coin::on_coin_collect(Node2D* p_body) {
        UtilityFunctions::print("+1 coin");
        queue_free();
    }

} // godot
