#include "freertos/FreeRTOS.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "nvs_flash.h"
#include "driver/gpio.h"

esp_err_t event_handler(void *ctx, system_event_t *event)
{
    return ESP_OK;
}

#define LED_PIN GPIO_NUM_14

void app_main(void)
{
    nvs_flash_init();

    gpio_pad_select_gpio(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    int level = 0;
    while (true) {
        gpio_set_level(LED_PIN, level);
        level = !level;
        vTaskDelay(300 / portTICK_PERIOD_MS);
    }
}

