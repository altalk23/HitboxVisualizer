#include "HitboxNode.hpp"

USE_GEODE_NAMESPACE();
using namespace tulip;

static inline bool s_onlyHitboxes = false;
static inline bool s_showOnDeath = false;
static inline bool s_drawOnDeath = false;
static inline bool s_noLimitTrail = false;
static inline HitboxNode* s_drawer = nullptr;

class $modify(PlayerObject) {
	void playerDestroyed(bool idk) {
		PlayerObject::playerDestroyed(idk);
		s_drawOnDeath = true;
	}
};



class $modify(PlayLayer) {
	static inline HitboxNode* drawer;

	bool init(GJGameLevel* lvl) {
		drawer = HitboxNode::create();
		auto ret = PlayLayer::init(lvl);
		m_objectLayer->addChild(drawer, 32);

		s_drawer = drawer;

		s_showOnDeath = GameManager::sharedState()->getGameVariable("2387");
		drawer->m_drawTrail = GameManager::sharedState()->getGameVariable("2388");
		s_onlyHitboxes = GameManager::sharedState()->getGameVariable("2389");
		if (s_showOnDeath) s_drawOnDeath = false;

		return ret;
	}
	void checkCollisions(PlayerObject* player, float uhh) {
		PlayLayer::checkCollisions(player, uhh);
		if (player == m_player1) {
			drawer->addToPlayer1Queue(m_player1->getObjectRect());
		}
		if (player == m_player2) {
			drawer->addToPlayer2Queue(m_player2->getObjectRect());
		}
	}
	void resetLevel() {
		if (s_showOnDeath) s_drawOnDeath = false;
        drawer->clearQueue();
        PlayLayer::resetLevel();
    }

	void update(float dt) {
		drawer->clear();
		PlayLayer::update(dt);
		if (s_showOnDeath) {
			if (!s_drawOnDeath) return;
			drawer->setVisible(true);
		}		

		if (m_player1) {
			drawer->drawForPlayer1(m_player1);
		}
		if (m_player2) {
			drawer->drawForPlayer2(m_player2);
		}

		float xp = m_player1->getPositionX();

		for (int s = sectionForPos(xp) - 5; s < sectionForPos(xp) + 6; ++s) {
			if (s < 0) continue;
			if (s >= m_sectionObjects->count()) break;
			auto section = static_cast<CCArray*>(m_sectionObjects->objectAtIndex(s));
			for (size_t i = 0; i < section->count(); ++i) {
				auto obj = static_cast<GameObject*>(section->objectAtIndex(i));

				if (s_onlyHitboxes) obj->setOpacity(0);

				if (obj->m_objectID != 749 && obj->getType() == GameObjectType::Decoration) continue;
				if (!obj->m_active) continue;

				drawer->drawForObject(obj);
			}
		}
	}
};

class $modify(HitboxLevelEditorLayer, LevelEditorLayer) {
	static inline HitboxNode* drawer;
	static inline bool paused = false;

	bool init(GJGameLevel* lvl) {
		drawer = HitboxNode::create();
		auto ret = LevelEditorLayer::init(lvl);
		drawer->setVisible(false);
		m_objectLayer->addChild(drawer, 32);

		s_drawer = drawer;

		// i hate bad practices
		drawer->m_drawTrail = GameManager::sharedState()->getGameVariable("2388");
		s_noLimitTrail = GameManager::sharedState()->getGameVariable("2390");
		return ret;
	}
	bool checkCollisions(PlayerObject* player, float uhh) {
		auto ret = LevelEditorLayer::checkCollisions(player, uhh);
		if (player == m_player1) {
			drawer->addToPlayer1Queue(m_player1->getObjectRect());
		}
		if (player == m_player2) {
			drawer->addToPlayer2Queue(m_player2->getObjectRect());
		}
		return ret;
	}
	void onPlaytest() {
		LevelEditorLayer::onPlaytest();
		drawer->setVisible(true);
	}
	void onPausePlaytest() {
		LevelEditorLayer::onPausePlaytest();
		paused = true;
		this->updateHitboxEditor();
	}
	void updateHitboxEditor() {
		if (!paused) return;
		if (s_noLimitTrail) drawer->m_noLimitTrail = true;

		if (m_player1) {
			drawer->drawForPlayer1(m_player1);
		}
		if (m_player2) {
			drawer->drawForPlayer2(m_player2);
		}

		if (m_player1) {
			float xp = m_player1->getPositionX();

			for (int s = sectionForPos(xp) - 10; s < sectionForPos(xp) + 10; ++s) {
				if (s < 0) continue;
				if (s >= m_sectionObjects->count()) break;
				auto section = static_cast<CCArray*>(m_sectionObjects->objectAtIndex(s));
				for (size_t i = 0; i < this->getAllObjects()->count(); ++i) {
					auto obj = static_cast<GameObject*>(this->getAllObjects()->objectAtIndex(i));

					if (s_onlyHitboxes) obj->setOpacity(0);

					if (obj->m_objectID != 749 && obj->getType() == GameObjectType::Decoration) continue;
					if (!obj->m_active) continue;

					drawer->drawForObject(obj);
				}
			}
		}
	}
	void onResumePlaytest() {
		if (s_noLimitTrail) drawer->m_noLimitTrail = false;
		paused = false;
		LevelEditorLayer::onResumePlaytest();
	}
	void onStopPlaytest() {
		if (s_noLimitTrail) drawer->m_noLimitTrail = false;
		paused = false;
        drawer->clearQueue();
        drawer->setVisible(false);
        LevelEditorLayer::onStopPlaytest();
    }

	void update(float dt) {
		drawer->clear();
		LevelEditorLayer::update(dt);

		if (m_player1) {
			drawer->drawForPlayer1(m_player1);
		}
		if (m_player2) {
			drawer->drawForPlayer2(m_player2);
		}

		float xp = m_player1->getPositionX();

		for (int s = sectionForPos(xp) - 5; s < sectionForPos(xp) + 6; ++s) {
			if (s < 0) continue;
			if (s >= m_sectionObjects->count()) break;
			auto section = static_cast<CCArray*>(m_sectionObjects->objectAtIndex(s));
			for (size_t i = 0; i < section->count(); ++i) {
				auto obj = static_cast<GameObject*>(section->objectAtIndex(i));

				if (s_onlyHitboxes) obj->setOpacity(0);

				if (obj->m_objectID != 749 && obj->getType() == GameObjectType::Decoration) continue;
				if (!obj->m_active) continue;

				drawer->drawForObject(obj);
			}
		}
	}
};

class $modify(EditorUI) {
	void keyDown(enumKeyCodes code) {
		EditorUI::keyDown(code);
		if (s_drawer) {
			s_drawer->clear();
			static_cast<HitboxLevelEditorLayer*>(LevelEditorLayer::get())->updateHitboxEditor();
		} 
	}
};
