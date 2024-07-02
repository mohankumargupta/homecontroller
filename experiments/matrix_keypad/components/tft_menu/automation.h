#pragma once

#include "esphome/core/component.h"
#include "esphome/core/automation.h"
#include "tft_menu.h"

namespace esphome {
namespace tft_menu {

template<typename... Ts> class KeyPressAction : public Action<Ts...>, public Parented<TFTMenuComponent> {
 public:
  void play(Ts... x) override {
    ESP_LOGI("tft_menu", "this is from KeyPressAction");
  }

 protected:
  TEMPLATABLE_VALUE(uint16_t, value)
};

}  // namespace tft_menu
}  // namespace esphome