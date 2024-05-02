

#ifndef LEARNING_GODOT_COIN_H
#define LEARNING_GODOT_COIN_H

#include <godot_cpp/classes/area2d.hpp>

namespace godot {

    class coin : public Area2D {
        GDCLASS(coin, Area2D);

    protected:
        static void _bind_methods() {};

    public:
        coin();
        ~coin() = default;

        void area_entered();
    };

} // godot

#endif //LEARNING_GODOT_COIN_H
