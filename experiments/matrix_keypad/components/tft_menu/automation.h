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
    ESP_LOGI("tft_menu", "key pressed: %d", this->key);
  }
  void set_key(int key) {this->key = key;}

 protected:
  int key;
};

}  // namespace scd30
}  // namespace esphome

/*
@automation.register_action(
    "output.rp2040_pwm.set_frequency",
    SetFrequencyAction,
    cv.Schema(
        {
            cv.Required(CONF_ID): cv.use_id(RP2040PWM),
            cv.Required(CONF_FREQUENCY): cv.templatable(validate_frequency),
        }
    ),
)
async def rp2040_set_frequency_to_code(config, action_id, template_arg, args):
    paren = await cg.get_variable(config[CONF_ID])
    var = cg.new_Pvariable(action_id, template_arg, paren)
    template_ = await cg.templatable(config[CONF_FREQUENCY], args, float)
    cg.add(var.set_frequency(template_))
    return var

*/