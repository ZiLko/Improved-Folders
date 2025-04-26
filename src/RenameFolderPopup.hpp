#include "Includes.hpp"

class RenameFolderPopup : public geode::Popup<std::string, RenameFolderDelegate*> {

private:

    RenameFolderDelegate* m_delegate = nullptr;

    TextInput* m_input = nullptr;

    bool setup(std::string, RenameFolderDelegate*) override;

    void onCreate(CCObject*);

public:

    static RenameFolderPopup* create(std::string, RenameFolderDelegate*);

};