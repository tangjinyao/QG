package com.QG.controller;

// 通用的 Servlet 基类，封装了一些通用的逻辑
import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;

public abstract class BaseServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        processRequest(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        processRequest(req, resp);
    }

    // 抽象方法，子类需要实现具体的处理逻辑
    protected abstract void processRequest(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException;

    // 一个示例的通用方法，用于设置响应的内容类型为JSON
    protected void setResponseContentTypeToJson(HttpServletResponse response) {
        response.setContentType("application/json;charset=UTF-8");
    }

    // 另一个示例的通用方法，用于发送错误响应
    protected void sendErrorResponse(HttpServletResponse response, String errorMessage) throws IOException {
        response.sendError(HttpServletResponse.SC_INTERNAL_SERVER_ERROR, errorMessage);
    }

    // 还可以添加其他通用的方法或逻辑...
}
