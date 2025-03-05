/*
 * @Author: dav1d wei.liu@zendure.com
 * @Date: 2025-03-05 14:21:42
 * @LastEditors: dav1d wei.liu@zendure.com
 * @LastEditTime: 2025-03-05 14:21:47
 * @FilePath: /zenSDK/examples/C/demo.c
 * @Description: 
 * 
 * Copyright (c) 2025 by Zendure, All Rights Reserved. 
 */
#include <stdio.h>
#include <curl/curl.h>

void send_get_request() {
    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://<server-ip>/properties/report");
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
}

void send_post_request() {
    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://<server-ip>/properties/write");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "{\"sn\": \"your_device_sn\", \"properties\": {\"acMode\": 2}}");

        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
}

int main() {
    send_get_request();
    send_post_request();
    return 0;
}