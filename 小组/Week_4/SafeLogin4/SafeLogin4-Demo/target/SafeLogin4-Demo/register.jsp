<%--
  Created by IntelliJ IDEA.
  User: Lenovo
  Date: 2024/4/16
  Time: 14:17
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>login</title>
    <script src="js/jquery-3.7.1.js" type="text/javascript" charset="utf-8"></script>
    <script>
        // 定义方法
        function fun() {
            $.ajax({
                url: "register", // 请求地址，这里可以是Servlet的URL-pattern或者一个处理登录请求的Controller的URL
                type: "post", // 请求方式
                data: {
                    "username": $("#name").val(),
                    "pwd": $("#password").val(),
                }, // 请求数据
                success: function (data) { // 请求成功时调用此函数
                    alert(data);
                },
                error: function (jqXHR, textStatus, errorThrown) {
                    alert("发生错误");
                    console.log("HTTP Status: " + jqXHR.status); // 输出HTTP状态码
                    console.log("Ajax Error: " + textStatus); // 输出Ajax错误信息
                    console.log("Exception: " + errorThrown); // 输出异常信息（如果有）
                }
            });
        }
    </script>
</head>
<body>
<label for="name">用户名:</label>
<input type="text" id="name" name="name" required><br>

<label for="password">密码:</label>
<input type="password" id="password" name="password" required><br>

<input type="button" value="发送异步请求" onclick="fun();">
</body>
</html>
