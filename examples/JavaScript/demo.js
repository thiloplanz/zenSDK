/*
 * @Author: dav1d wei.liu@zendure.com
 * @Date: 2025-03-05 14:22:34
 * @LastEditors: dav1d wei.liu@zendure.com
 * @LastEditTime: 2025-03-05 14:22:36
 * @FilePath: /zenSDK/examples/JavaScript/demo.js
 * @Description: 
 * 
 * Copyright (c) 2025 by Zendure, All Rights Reserved. 
 */
const axios = require('axios');

// GET 请求
axios.get('http://<server-ip>/properties/report')
     .then(res => console.log("GET:", res.data));

// POST 请求
axios.post('http://<server-ip>/properties/write', { sn: "your_device_sn", properties: { acMode: 2 } })
     .then(res => console.log("POST:", res.data));