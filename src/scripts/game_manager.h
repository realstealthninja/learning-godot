#ifndef LEARN_GODOT_GAME_MANAGER_H
#define LEARN_GODOT_GAME_MANAGER_H


#include "godot_cpp/classes/area2d.hpp"
#include "godot_cpp/classes/label.hpp"
#include "godot_cpp/classes/scene_tree.hpp"
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

	void set_next_scene(String file);
	String get_next_scene();

	void on_finish(Node* body);

	private:
	int score{0};
	String next_scene = "";
	Label* scoreLabel = nullptr;
	Area2D* finish_node = nullptr;
};

}

#endif // LEARN_GODOT_GAME_MANAGER_H
