#include "library.h"

#include <fcitx-utils/log.h>
#include <fcitx/addonmanager.h>
#include <fcitx/addoninstance.h>
#include <fcitx/instance.h>
#include <fcitx/addonfactory.h>

NekoInput::NekoInput() {
    FCITX_INFO() << "NekoInput loaded!";
}

std::string NekoInput::transmitString(const std::string &text) {
    std::string ret = text;
    if (text.compare("禁用喵喵喵") == 0 && this->plugin_enabled) {
        this->plugin_enabled = false;
        return "NekoInput disabled";
    }
    if (text.compare("启用喵喵喵") == 0 && !this->plugin_enabled) {
        this->plugin_enabled = true;
        return "NekoInput enabled";
    }
    if (!this->plugin_enabled) {
        return ret;
    }
    const auto suffixs = {"？", "！", "，", "。", "；", "：", "”", "）"};
    for (std::string suffix : suffixs) {
        if (ret.ends_with(suffix)) {
            ret.insert(ret.size() - suffix.size(), "喵");
            break;
        }
    }
    return ret;
}

void NekoInput::setConnection(fcitx::Connection connection) {
    this->connection_ = connection;
}

class NekoInputFactory : public fcitx::AddonFactory {
public:
    fcitx::AddonInstance *create(fcitx::AddonManager *manager) override {
        (void)manager;
        fcitx::Instance* instance = manager->instance();
        auto* addon_instance = new NekoInput();
        auto connection = instance->connect<fcitx::Instance::CommitFilter>(
        [addon_instance](fcitx::InputContext *ic, std::string &text) {
            text = addon_instance->transmitString(text);
          });
        addon_instance->setConnection(connection);
        return addon_instance;
        // return new NekoInput();
    }
};

FCITX_ADDON_FACTORY(NekoInputFactory);
