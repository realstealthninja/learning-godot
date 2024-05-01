#ifndef LEARNING_GODOT_EXAMPLE_H
#define LEARNING_GODOT_EXAMPLE_H

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {

class example : public Sprite2D {
	GDCLASS(example, Sprite2D)

private:
	double time_passed;

protected:
	static void _bind_methods();

public:
    example();
	~example();

	void _process(double delta) override;

};

} //namespace godot

#endif //LEARNING_GODOT_EXAMPLE_H
