#include "example.h"


namespace godot {

void example::_bind_methods() {
}


example::example() {
	time_passed = 0.0f;
}

void example::_process(double delta) {
	time_passed += delta;

	Vector2 position(10.0 + (10.0 + sin(time_passed * 2.0f)), 10.0 + (10.0f + sin(time_passed *2.0f)));

	set_position(position);
}


example::~example() = default;

} //namespace godot
