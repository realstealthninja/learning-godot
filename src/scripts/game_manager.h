#ifndef LEARN_GODOT_GAME_MANAGER_H
#define LEARN_GODOT_GAME_MANAGER_H


#include "godot_cpp/classes/label.hpp"
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/node_path.hpp>


namespace godot {


class GameManager : public Node {
	GDCLASS(GameManager, Node);

	protected:
	static void _bind_methods();

	public:
	GameManager();

	void add_points();
	void _ready() override;

	NodePath* get_finish();
	void set_finish(NodePath* finish);


	private:
	int score{0};
	Label* scoreLabel = nullptr;
	NodePath* finish = nullptr;
	Node* finish_node = nullptr;

};

}

#endif // LEARN_GODOT_GAME_MANAGER_H
