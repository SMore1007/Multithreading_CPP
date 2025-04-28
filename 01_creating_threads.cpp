// #include<iostream> // for input and output
// #include<thread>   // for threading
// #include<chrono>   // for time functions

// using namespace std;  // for standad names

// void _thread1()
// {
//     for (int i = 0; i < 10; i++)
//     {
//         cout << "*";
//         this_thread::sleep_for(chrono::milliseconds(100));
//     }
    
// }

// void _thread2()
// {
//     for (int i = 0; i < 10; i++)
//     {
//         cout << "o";
//         this_thread::sleep_for(chrono::milliseconds(100));
//     }
    
// }


// int main()
// {
//     thread worker1(_thread1);
//     thread worker2(_thread2);

//     worker1.join();  // Wait for the thread to finish
//     worker2.join();
//     cout<< "\n";
// }



#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include "nvs_flash.h"

static const char *TAG = "wifi_scan";

#define DEFAULT_SCAN_LIST_SIZE 10
void app_main()
{
    // Initialize NVS (required for WiFi)
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    // Initialize TCP/IP stack
    tcpip_adapter_init();

    // Initialize WiFi with default config
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    // Set WiFi mode to STA (station)
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_start());

    // Start scanning
    wifi_scan_config_t scan_config = {
        .ssid = 0,
        .bssid = 0,
        .channel = 0,
        .show_hidden = true
    };
    ESP_ERROR_CHECK(esp_wifi_scan_start(&scan_config, true)); // true = blocking

    // Get scan results
    uint16_t number = DEFAULT_SCAN_LIST_SIZE;
    wifi_ap_record_t ap_info[DEFAULT_SCAN_LIST_SIZE];
    uint16_t ap_count = 0;
    memset(ap_info, 0, sizeof(ap_info));

    ESP_ERROR_CHECK(esp_wifi_scan_get_ap_records(&number, ap_info));
    ESP_ERROR_CHECK(esp_wifi_scan_get_ap_num(&ap_count));
    ESP_LOGI(TAG, "Total APs found: %d", ap_count);

    for (int i = 0; i < ap_count; i++) {
        ESP_LOGI(TAG, "SSID \t\t%s", ap_info[i].ssid);
        ESP_LOGI(TAG, "RSSI \t\t%d", ap_info[i].rssi);
        ESP_LOGI(TAG, "Channel \t\t%d\n", ap_info[i].primary);
    }
}
