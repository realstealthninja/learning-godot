#ifndef LEARNING_GODOT_PLAYER_H
#define LEARNING_GODOT_PLAYER_H

#include <godot_cpp/classes/character_body2d.hpp>

namespace godot {

class player : public CharacterBody2D {
	GDCLASS(player, CharacterBody2D);

protected:
	static void _bind_methods() {};

public:
    player();
    ~player() override = default;

    void _physics_process(double delta) override;
    void _ready() override;

private:
    const float speed = 300.0f;
    const float jump_velocity = -400.0f;
    float gravity;


};

} //namespace godot

#endif //LEARNING_GODOT_PLAYER_H
