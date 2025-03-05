<?php
/*
 * @Author: dav1d wei.liu@zendure.com
 * @Date: 2025-03-05 14:23:04
 * @LastEditors: dav1d wei.liu@zendure.com
 * @LastEditTime: 2025-03-05 14:23:10
 * @FilePath: /zenSDK/examples/PHP/demo.php
 * @Description: 
 * 
 * Copyright (c) 2025 by Zendure, All Rights Reserved. 
 */
// GET 请求
$get_url = "http://<server-ip>/properties/report";
echo file_get_contents($get_url);

// POST 请求
$post_url = "http://<server-ip>/properties/write";
$data = json_encode(["sn" => "your_device_sn", "properties" => ["acMode" => 2]]);
$options = [
    "http" => [
        "header"  => "Content-Type: application/json",
        "method"  => "POST",
        "content" => $data
    ]
];
echo file_get_contents($post_url, false, stream_context_create($options));
?>