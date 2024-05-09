#ifndef LEARN_GODOT_GAME_MANAGER_H
#define LEARN_GODOT_GAME_MANAGER_H


#include "godot_cpp/classes/label.hpp"
#include <godot_cpp/classes/node.hpp>

namespace godot {


class GameManager : public Node {
	GDCLASS(GameManager, Node);

	protected:
	static void _bind_methods();

	public:
	GameManager();

	void add_points();
	void _ready() override;

	private:
	int score{0};
	Label* scoreLabel = nullptr;
};

}

#endif // LEARN_GODOT_GAME_MANAGER_H
