#pragma once

#include <fcitx-utils/handlertable_details.h>
#include <fcitx/addoninstance.h>
#include <fcitx/event.h>
#include <fcitx/instance.h>

class NekoInput : public fcitx::AddonInstance {
public:
    NekoInput();
    std::string transmitString(const std::string &text);
    void setConnection(fcitx::Connection connection);

private:
    fcitx::Connection connection_;
    bool plugin_enabled = true;
};
