#include <Geode.hpp>

// i hate myself
USE_GEODE_NAMESPACE();

class $modify(MoreOptionsLayer) {
	bool init() {
		if (!MoreOptionsLayer::init()) return false;
		this->addToggle("Show only on death", "2387", "Shows the hitbox visuals only on death");
		this->addToggle("Enable hitbox trail", "2388", "Enables the hitbox trail");
		this->addToggle("Show only hitboxes", "2389", "Hides all objects themselves, leaving only the hitboxes");
		this->addToggle("No limit trail", "2390", "Shows all of the player trails in the editor. May lag, haven't tested.");
		return true;
	}
};
