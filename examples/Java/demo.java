/*
 * @Author: dav1d wei.liu@zendure.com
 * @Date: 2025-03-05 14:22:12
 * @LastEditors: dav1d wei.liu@zendure.com
 * @LastEditTime: 2025-03-05 14:22:17
 * @FilePath: /zenSDK/examples/Java/demo.java
 * @Description: 
 * 
 * Copyright (c) 2025 by Zendure, All Rights Reserved. 
 */
import java.io.*;
import java.net.*;

public class SimpleHttp {
    public static void main(String[] args) throws Exception {
        // GET 请求
        URL getUrl = new URL("http://<server-ip>/properties/report");
        HttpURLConnection getConn = (HttpURLConnection) getUrl.openConnection();
        getConn.setRequestMethod("GET");
        System.out.println("GET Response Code: " + getConn.getResponseCode());

        // POST 请求
        URL postUrl = new URL("http://<server-ip>/properties/write");
        HttpURLConnection postConn = (HttpURLConnection) postUrl.openConnection();
        postConn.setRequestMethod("POST");
        postConn.setRequestProperty("Content-Type", "application/json");
        postConn.setDoOutput(true);

        String json = "{\"sn\": \"your_device_sn\", \"properties\": {\"acMode\": 2}}";
        try (OutputStream os = postConn.getOutputStream()) {
            os.write(json.getBytes());
        }
        System.out.println("POST Response Code: " + postConn.getResponseCode());
    }
}