package com.QG.controller;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import com.QG.service.EmpService;
import com.QG.service.impl.EmpServiceA;

import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/login")
public class LoginController extends BaseServlet{
    private final EmpServiceA empService = new EmpServiceA();
    @Override
    protected void processRequest(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //获取请求参数
        String username = req.getParameter("username");
        String pwd = req.getParameter("pwd");

        //调用service层方法，获取结果
        int result = empService.findUserIdByUsernameAndPassword(username, pwd);

        //返回结果
        PrintWriter writer = resp.getWriter();
        if(result == 1){
            writer.write(String.valueOf("登录成功！"));
        }
        else{
            writer.write(String.valueOf("登录失败！"));
        }

    }

}
