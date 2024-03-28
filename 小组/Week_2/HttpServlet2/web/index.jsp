<%--
  Created by IntelliJ IDEA.
  User: Lenovo
  Date: 2024/3/28
  Time: 18:14
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>

    <output>输入"/login.html"进入登录界面</output><br>
    <output>输入"/demo"测试200 OK 正常访问</output><br>
    <output>输入"/301"测试301 Moved Permanently 永久性重定向</output><br>
    <output>输入"/404"测试404 Not Found </output><br>
    <output>(原本想用/*接受所有用户输入然后用servlet判断用户输入的资源路径是否存在的,
        但是那样就没法访问login.html了, 这里有待完善)</output><br>
    <output>输入"/500"测试500 Internal Server Error 服务器错误</output>

</body>
</html>
