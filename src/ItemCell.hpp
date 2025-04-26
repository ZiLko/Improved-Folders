#include "Includes.hpp"

class ItemCell : public cocos2d::CCNode {

private:

    bool init();

    bool init(const Item&, ItemCellDelegate*);

    bool init(const std::vector<Item>&, ItemCellDelegate*);

public:

    static ItemCell* create();

    static ItemCell* create(const Item&, ItemCellDelegate*);

    static ItemCell* create(const std::vector<Item>&, ItemCellDelegate*);

};