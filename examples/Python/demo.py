'''
Author: dav1d wei.liu@zendure.com
Date: 2025-03-05 14:23:28
LastEditors: dav1d wei.liu@zendure.com
LastEditTime: 2025-03-05 14:23:33
FilePath: /zenSDK/examples/Python/demo.py
Description: 

Copyright (c) 2025 by Zendure, All Rights Reserved. 
'''
import requests

# GET 请求
get_response = requests.get("http://<server-ip>/properties/report")
print("GET:", get_response.text)

# POST 请求
post_response = requests.post("http://<server-ip>/properties/write", json={"sn": "your_device_sn", "properties": {"acMode": 2}})
print("POST:", post_response.text)