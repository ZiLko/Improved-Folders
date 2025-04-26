#include "ItemCell.hpp"
#include "ItemNode.hpp"

ItemCell* ItemCell::create() {
    ItemCell* ret = new ItemCell();

    if (ret->init()) {
        ret->autorelease();
        return ret;
    }

    delete ret;
    return nullptr;
}

ItemCell* ItemCell::create(const std::vector<Item>& items, ItemCellDelegate* delegate) {
    ItemCell* ret = new ItemCell();

    if (ret->init(items, delegate)) {
        ret->autorelease();
        return ret;
    }

    delete ret;
    return nullptr;
}

ItemCell* ItemCell::create(const Item& item, ItemCellDelegate* delegate) {
    ItemCell* ret = new ItemCell();

    if (ret->init(item, delegate)) {
        ret->autorelease();
        return ret;
    }

    delete ret;
    return nullptr;
}

bool ItemCell::init() {
    return true;
}

bool ItemCell::init(const Item& item, ItemCellDelegate* delegate) {

    addChild(ItemNode::create(item, delegate, false));

    return true;
}

bool ItemCell::init(const std::vector<Item>& items, ItemCellDelegate* delegate) {

    for (int i = 0; i < items.size(); i++) {
        ItemNode* node = ItemNode::create(items[i], delegate, true);
        node->setPositionX(94.6666666f * i);

        addChild(node);
    }
    
    return true;
}