#include "Includes.hpp"

class CreateFolderPopup : public geode::Popup<> {

private:

    CreateFolderDelegate* m_delegate = nullptr;

    TextInput* m_input = nullptr;

    bool setup() override;

    void onCreate(CCObject*);

public:

    static CreateFolderPopup* create(CreateFolderDelegate*);

};