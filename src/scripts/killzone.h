
#ifndef LEARNING_GODOT_KILLZONE_HPP
#define LEARNING_GODOT_KILLZONE_HPP

#include <godot_cpp/classes/area2d.hpp>
#include <godot_cpp/classes/timer.hpp>

namespace godot {

    class killzone : public Area2D {
        GDCLASS(killzone, Area2D)
    private:
        Timer* timer;
    protected:
        static void _bind_methods();
    public:
        killzone();
        ~killzone() = default;

        void _ready() override;
        void __on_body_entered(Node2D* body);
        void _on_timer_timeout();

    };

} // godot

#endif //LEARNING_GODOT_KILLZONE_HPP
