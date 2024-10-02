/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>

/**
 * Brings cocos2d and all Geode namespaces to the current scope.
 */
using namespace geode::prelude;

/**
 * `$modify` lets you extend and modify GD's classes.
 * To hook a function in Geode, simply $modify the class
 * and write a new function definition with the signature of
 * the function you want to hook.
 *
 * Here we use the overloaded `$modify` macro to set our own class name,
 * so that we can use it for button callbacks.
 *
 * Notice the header being included, you *must* include the header for
 * the class you are modifying, or you will get a compile error.
 *
 * Another way you could do this is like this:
 *
 * struct MyMenuLayer : Modify<MyMenuLayer, MenuLayer> {};
 */

#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>

/*
cocos2d::CCNode* findTransformLayer(cocos2d::CCNode* layer) {
	auto children = layer->getChildren();

	CCObject* child;
	CCARRAY_FOREACH(children, child) {
		auto node = static_cast<cocos2d::CCNode*>(child);
		node->getChild
		if (node->getName() == layerName) {
			return node;
		}
	}

	return nullptr;
}
*/

class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init())
			return false;

		auto winSize = CCDirector::get()->getWinSize();

		auto label = cocos2d::CCLabelBMFont::create("Hello world", "bigFont.fnt");
		label->setPosition(winSize / 2);
		this->addChild(label);

		log::debug("hi");

		return true;
	}


};

class $modify(TheEditor, LevelEditorLayer) {
	bool init(GJGameLevel * p0, bool p1) {
		if (!LevelEditorLayer::init(p0, p1)) {
			return false;
		}

		log::debug("step 1!");

		auto mainNode = this->getChildByID("main-node");
		auto batchLayer = mainNode->getChildByID("batch-layer");
		auto GjTransformControl = batchLayer->getChildByID("GjTransformControl");

		/*
		auto label = cocos2d::CCLabelBMFont::create("Hi world", "bigFont.fnt");
			label->setPosition(300, 300);


		GjTransformControl->addChild(label);
		*/
	}
};