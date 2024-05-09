#ifndef LEARN_GODOT_SLIME_H
#define LEARN_GODOT_SLIME_H



#include "godot_cpp/classes/animated_sprite2d.hpp"
#include "godot_cpp/classes/animation_player.hpp"
#include "godot_cpp/classes/node2d.hpp"
#include "godot_cpp/classes/area2d.hpp"
#include "godot_cpp/classes/ray_cast2d.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "killzone.h"


namespace godot {

class slime : public Node2D {
	GDCLASS(slime, Node2D);

	protected:
	static void _bind_methods();

	public:
	slime();

	void _process(double delta) override;

	void _ready() override;

	void on_stomp(Node2D* body);


	private:
	const int speed{60};
	short direction{1};

	RayCast2D* left = nullptr;
	RayCast2D* right = nullptr;

	AnimatedSprite2D* sprite = nullptr;
	Area2D* stompzone = nullptr;
	AnimationPlayer* player = nullptr;
	killzone* zone = nullptr;
};

}

#endif // !LEARN_GODOT_SLIME_H
