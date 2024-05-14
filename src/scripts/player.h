#ifndef LEARNING_GODOT_PLAYER_H
#define LEARNING_GODOT_PLAYER_H

#include "godot_cpp/classes/audio_stream_player2d.hpp"
#include "godot_cpp/classes/ray_cast2d.hpp"
#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/animated_sprite2d.hpp>

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
    const float speed = 130.0f;
    const float jump_velocity = -300.0f;
    float gravity;

		RayCast2D* cast = nullptr;

    AnimatedSprite2D* sprite = nullptr;
	  AudioStreamPlayer2D* audio = nullptr;
};

} //namespace godot

#endif //LEARNING_GODOT_PLAYER_H
