#include "Includes.hpp"

class ButtonMenu : public CCMenu {

private:

    bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override;

    ItemCellDelegate* m_delegate = nullptr;

public:

    static ButtonMenu* create(ItemCellDelegate*);

};

class ItemNode : public cocos2d::CCNode, public RenameFolderDelegate {

private:

    ItemCellDelegate* m_delegate = nullptr;

    CCMenuItemSpriteExtra* m_moveButton = nullptr;

    CCSprite* m_moveSprite1 = nullptr;
    CCSprite* m_moveSprite2 = nullptr;

    bool m_isGrid = false;
    bool m_isLevel = false;

    bool init() override;

    void onSee(CCObject*);
    void onOpen(CCObject*);
    void onView(CCObject*);
    void onDelete(CCObject*);
    void onMove(CCObject*);
    void onRename(CCObject*);

public: 

    Item m_item;

    static ItemNode* create(Item, ItemCellDelegate*, bool);

    void enableMoveButton(bool);

    void onFolderRename(std::string) override;

};
