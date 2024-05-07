#ifndef LEARN_GODOT_GAME_MANAGER_H
#define LEARN_GODOT_GAME_MANAGER_H


#include <godot_cpp/classes/node.hpp>

namespace godot {


class GameManager : public Node {
	GDCLASS(GameManager, Node);

	protected:
	static void _bind_methods();

	public:
	GameManager();

	void add_points();

	private:
	int score{0};
};

}

#endif // LEARN_GODOT_GAME_MANAGER_H
