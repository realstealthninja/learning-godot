

#ifndef LEARNING_GODOT_COIN_H
#define LEARNING_GODOT_COIN_H

#include <godot_cpp/classes/area2d.hpp>

namespace godot {

    class coin : public Area2D {
        GDCLASS(coin, Area2D);

    protected:
        static void _bind_methods();

    public:
        coin();

        void on_coin_collect(Node2D* p_body);
    };

} // godot

#endif //LEARNING_GODOT_COIN_H
