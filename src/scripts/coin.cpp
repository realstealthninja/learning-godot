#include "coin.h"

#include "godot_cpp/classes/engine.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

namespace godot {
    coin::coin() {
        this->connect("area_entered", Callable(this, "area_entered"));
    }


    void coin::area_entered() {
        UtilityFunctions::print("+1 coin");
        queue_free();
    }
} // godot
