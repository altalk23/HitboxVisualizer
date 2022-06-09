// #include <Geode.hpp>
// #include <deque>

// USE_GEODE_NAMESPACE();

// class HitboxNode : public CCDrawNode {
// public:
// 	static HitboxNode* create() {
// 		auto ret = new HitboxNode;
// 		if (ret) {
// 			ret->init();
// 			return ret;
// 		}
// 		return nullptr;
// 	}
// 	void drawCircleObj(GameObject* ob, _ccColor4B col) {
// 		ob->updateOrientedBox();
// 		if (!ob->m_objectOBB2D) return;
// 		auto rad = ob->getObjectRadius();

// 		auto color1 = ccc4FFromccc4B(col);
// 		auto colorA = ccc4FFromccc4B(ccc4(0, 0, 0, 0));

// 		constexpr size_t N = 64;
// 		constexpr float PI = 3.14159265;
// 		CCPoint vert[N];
// 		for (size_t i = 0; i < N; ++i) {
// 			vert[i] = ob->m_objectOBB2D->m_center + CCPointMake(std::cos(2 * PI * i / N), std::sin(2 * PI * i / N)) * rad;
// 		}
// 		drawPolygon(vert, N, colorA, 0.5, color1);
// 	}
// 	void drawRectObj(GameObject* ob, _ccColor4B col) {
// 		ob->updateOrientedBox();
// 		if (!ob->m_objectOBB2D) return;

// 		constexpr size_t N = 4;
// 		CCPoint vert[N];
// 		vert[0] = ob->m_objectOBB2D->m_p1_1;
// 		vert[1] = ob->m_objectOBB2D->m_p1_2;
// 		vert[2] = ob->m_objectOBB2D->m_p1_3;
// 		vert[3] = ob->m_objectOBB2D->m_p1_4;
		
// 		auto color1 = ccc4FFromccc4B(col);
// 		auto colorA = ccc4FFromccc4B(ccc4(0, 0, 0, 0));

// 		drawPolygon(vert, N, colorA, 0.5, color1);		
// 	}
// 	void drawOBB2D(OBB2D* obb, _ccColor4B col) {
// 		constexpr size_t N = 4;
// 		CCPoint vert[N];
// 		vert[0] = obb->m_p1_1;
// 		vert[1] = obb->m_p1_2;
// 		vert[2] = obb->m_p1_3;
// 		vert[3] = obb->m_p1_4;
		
// 		auto color1 = ccc4FFromccc4B(col);
// 		auto colorA = ccc4FFromccc4B(ccc4(0, 0, 0, 0));

// 		drawPolygon(vert, N, colorA, 0.5, color1);
// 	}
// 	void drawRect(CCRect const& rect, _ccColor4B col) {
// 		constexpr size_t N = 4;
// 		CCPoint vert[N];

// 		vert[0] = CCPointMake(rect.getMinX(), rect.getMinY());
// 		vert[1] = CCPointMake(rect.getMinX(), rect.getMaxY());
// 		vert[2] = CCPointMake(rect.getMaxX(), rect.getMaxY());
// 		vert[3] = CCPointMake(rect.getMaxX(), rect.getMinY());

// 		auto color = ccc4FFromccc4B(col);
// 		auto colorA = ccc4FFromccc4B(ccc4(0, 0, 0, 0));

// 		drawPolygon(vert, N, colorA, 0.5, color);
// 	}
// 	void drawTriangleObj(GameObject* ob, _ccColor4B col) {
// 		ob->updateOrientedBox();
// 		if (!ob->m_objectOBB2D) return;

// 		constexpr size_t N = 3;
// 		CCPoint vert[N];
// 		int i = 0;
// 		if (ob->isFlipX() or !ob->isFlipY())
// 			vert[i++] = ob->m_objectOBB2D->m_p1_1;
// 		if (!ob->isFlipX() or !ob->isFlipY())
// 			vert[i++] = ob->m_objectOBB2D->m_p1_2;
// 		if (!ob->isFlipX() or ob->isFlipY())
// 			vert[i++] = ob->m_objectOBB2D->m_p1_3;
// 		if (ob->isFlipX() or ob->isFlipY())
// 			vert[i++] = ob->m_objectOBB2D->m_p1_4;
		
// 		auto color1 = ccc4FFromccc4B(col);
// 		auto colorA = ccc4FFromccc4B(ccc4(0, 0, 0, 0));

// 		drawPolygon(vert, N, colorA, 0.5, color1);
// 	}
// };

// // class $modify(PlayerObject) {
// // 	bool collidedWithObject(float p0, GameObject* p1, cocos2d::CCRect p2) {
// // 		auto ret = PlayerObject::collidedWithObject(p0, p1, p2);
// // 		Log::get() << "PlayerObject::collidedWithObject(): ";
// // 		Log::get() << ret << " | " << p0 << " | " << p1 << " | " << p2;
// // 		return ret;
// // 	}
// // };

// /*
// base() + 0x21D8B9
// base() + 0x7A2E4
// */

// // OBB2D* copyOBB2D(OBB2D* other) {
// // 	auto ret = OBB2D::create(CCPointMake(0, 0), 0, 0, 0);
// // 	ret->m_p1_1 = other->m_p1_1;
// // 	ret->m_p1_2 = other->m_p1_2;
// // 	ret->m_p1_3 = other->m_p1_3;
// // 	ret->m_p1_4 = other->m_p1_4;

// // 	ret->m_p2_1 = other->m_p2_1;
// // 	ret->m_p2_2 = other->m_p2_2;
// // 	ret->m_p2_3 = other->m_p2_3;
// // 	ret->m_p2_4 = other->m_p2_4;

// // 	ret->m_p3_1 = other->m_p3_1;
// // 	ret->m_p3_2 = other->m_p3_2;
// // 	ret->m_p3_3 = other->m_p3_3;
// // 	ret->m_p3_4 = other->m_p3_4;

// // 	ret->m_rot1 = other->m_rot1;
// // 	ret->m_rot2 = other->m_rot2;

// // 	ret->m_center = other->m_center;

// // 	return ret;
// // }

// std::deque<CCRect> s_player1trail;
// std::deque<CCRect> s_player2trail;

// class $modify(HitboxViewer, PlayLayer) {
// 	static inline HitboxNode* drawer;
// 	bool init(GJGameLevel* lvl) {
// 		auto ret = PlayLayer::init(lvl);
// 		drawer = HitboxNode::create();
// 		m_objectLayer->addChild(drawer, 40);
// 		return ret;
// 	}
// 	void checkCollisions(PlayerObject* player, float uhh) {
// 		PlayLayer::checkCollisions(player, uhh);
// 		if (player == m_player1) {
// 			float xp = m_player1->getPositionX();
// 			// const float xobblimit = xp - 300;
// 			// const float xobblimit2 = xp + 30;
// 			const float xobblimit = xp;
// 			const float xobblimit2 = xp;
// 			while (s_player1trail.size() > 0 && s_player1trail.front().origin.x <= xobblimit) {
// 				s_player1trail.pop_front();
// 			}
// 			while (s_player1trail.size() > 0 && s_player1trail.back().origin.x >= xobblimit2) {
// 				s_player1trail.pop_back();
// 			}
// 			s_player1trail.push_back(m_player1->getObjectRect());
			
// 			// obb->retain();
// 			// drawer->drawRectObj(m_player1, ccc4(255, 127, 255, 255));
			
// 		}
// 		if (player == m_player2) {
// 			float xp = m_player2->getPositionX();
// 			// const float xobblimit = xp - 300;
// 			// const float xobblimit2 = xp + 30;
// 			const float xobblimit = xp;
// 			const float xobblimit2 = xp;

// 			while (s_player2trail.size() > 0 && s_player2trail.front().origin.x <= xobblimit) {
// 				s_player2trail.pop_front();
// 			}
// 			while (s_player2trail.size() > 0 && s_player2trail.back().origin.x >= xobblimit2) {
// 				s_player2trail.pop_back();
// 			}
// 			s_player2trail.push_back(m_player2->getObjectRect());
// 		}

		
// 	}
// 	void resetLevel() {
//         while (s_player1trail.size() > 0) {
// 			s_player1trail.pop_front();
// 		}
// 		while (s_player2trail.size() > 0) {
// 			s_player2trail.pop_front();
// 		}
//         PlayLayer::resetLevel();
//     }

// 	void update(float dt) {
		
// 		drawer->clear();
// 		PlayLayer::update(dt);
		
// 		if (m_player1) {
// 			for (auto rect : s_player1trail) {
// 				drawer->drawRect(rect, ccc4(255, 127, 255, 255));
// 			}
// 			drawer->drawRectObj(m_player1, ccc4(63, 127, 127, 255));
// 			drawer->drawRect(m_player1->getObjectRect(0.25, 0.25), ccc4(63, 127, 127, 255));
// 		}
// 		if (m_player2) {
// 			for (auto rect : s_player2trail) {
// 				drawer->drawRect(rect, ccc4(127, 255, 255, 255));
// 			}
// 			drawer->drawRectObj(m_player2, ccc4(127, 63, 127, 255));
// 			drawer->drawRect(m_player2->getObjectRect(0.25, 0.25), ccc4(127, 63, 127, 255));
// 		}
		

// 		float xp = m_player1->getPositionX();

// 		for (int s = sectionForPos(xp) - 6; s < sectionForPos(xp) + 6; ++s) {
// 			if (s < 0) continue;
// 			if (s >= m_sectionObjects->count()) break;
// 			auto section = reinterpret_cast<CCArray*>(m_sectionObjects->objectAtIndex(s));
// 			for (auto& obj : ccArrayToVector<GameObject*>(section)) {

// 				ccColor4B color;
// 				// Log::get() << (int)obj->getType() << " " << obj->m_objectID;
// 				// checkpoint object
// 				// if (obj->m_objectID != 44) obj->setOpacity(0);
// 				if (obj->m_objectID != 749 && obj->getType() == GameObjectType::Decoration) continue;
// 				if (!obj->m_active) continue;

// 				switch (obj->getType()) {
// 					case GameObjectType::Solid:
// 						color = ccc4(63, 63, 63, 255);
// 						break;
// 					case GameObjectType::Decoration:
// 						switch (obj->m_objectID) {
// 					        case 749:
// 					        	color = ccc4(255, 127, 0, 255);
// 								break;
// 					        default:
// 					            continue;
// 						}
// 						break;
// 					case GameObjectType::TeleportPortal:
// 						// Log::get() << obj->m_objectID;
// 						// TODO: make colors seperate
// 						color = ccc4(0, 127, 255, 255);
// 						break;
// 					case GameObjectType::Modifier:
// 						switch (obj->m_objectID) {
// 							case 200:
// 					        case 201:
// 					        case 202:
// 					        case 203:
// 					        case 1334:
// 					        	color = ccc4(255, 255, 255, 255);
// 								break;
// 					        default:
// 					            continue;
// 						}
// 						break;
// 					case GameObjectType::Slope:
// 						color = ccc4(63, 63, 63, 255);
// 						drawer->drawTriangleObj(obj, color);
// 						continue;
// 					case GameObjectType::Hazard:
// 						color = ccc4(191, 191, 191, 255);
// 						break;

// 					case GameObjectType::InverseGravityPortal:
// 					case GameObjectType::YellowJumpPad:
// 					case GameObjectType::YellowJumpRing:
// 						color = ccc4(255, 255, 0, 255);
// 						break;
// 					case GameObjectType::InverseMirrorPortal:
// 					case GameObjectType::DualPortal:
// 						color = ccc4(255, 127, 0, 255);
// 						break;
// 					case GameObjectType::NormalGravityPortal:
// 					case GameObjectType::NormalMirrorPortal:
// 					case GameObjectType::SoloPortal:
// 						color = ccc4(0, 127, 255, 255);
// 						break;
// 					case GameObjectType::PinkJumpPad:
// 					case GameObjectType::PinkJumpRing:
// 						color = ccc4(255, 0, 255, 255);
// 						break;
// 					case GameObjectType::GravityPad:
// 					case GameObjectType::GravityRing:
// 						color = ccc4(0, 255, 255, 255);
// 						break;
// 					case GameObjectType::RedJumpPad:
// 					case GameObjectType::RedJumpRing:
// 						color = ccc4(255, 0, 0, 255);
// 						break;
// 					case GameObjectType::GreenRing:
// 					case GameObjectType::DashRing:
// 					case GameObjectType::RegularSizePortal:
// 						color = ccc4(0, 255, 0, 255);
// 						break;
// 					case GameObjectType::GravityDashRing:
// 					case GameObjectType::MiniSizePortal:
// 						color = ccc4(127, 0, 255, 255);
// 						break;
// 					case GameObjectType::SecretCoin:
// 					case GameObjectType::CustomRing:
// 					case GameObjectType::Collectible:
// 						color = ccc4(223, 223, 223, 255);
// 						break;
// 					case GameObjectType::DropRing:
// 						color = ccc4(31, 31, 31, 255);
// 						break;

// 					case GameObjectType::CubePortal:
// 						color = ccc4(0, 255, 0, 255);
// 						break;
// 					case GameObjectType::ShipPortal:
// 						color = ccc4(255, 127, 255, 255);
// 						break;
// 					case GameObjectType::BallPortal:
// 						color = ccc4(255, 127, 0, 255);
// 						break;
// 					case GameObjectType::UfoPortal:
// 						color = ccc4(255, 255, 0, 255);
// 						break;
// 					case GameObjectType::WavePortal:
// 						color = ccc4(0, 127, 255, 255);
// 						break;
// 					case GameObjectType::RobotPortal:
// 						color = ccc4(223, 223, 223, 255);
// 						break;
// 					case GameObjectType::SpiderPortal:
// 						color = ccc4(127, 0, 255, 255);
// 						break;

// 					default:
// 						color = ccc4(0, 0, 0, 1);
// 						break;
// 				}
// 				if (color.a != 1) {
// 					if (obj->getObjectRadius() > 0) drawer->drawCircleObj(obj, color);
// 					else {
// 						if (obj->m_objectOBB2D) drawer->drawOBB2D(obj->m_objectOBB2D, color);
// 						else drawer->drawRect(obj->getObjectRect(), color);
// 					}
// 				}
// 			}
// 		}
// 	}
// };
