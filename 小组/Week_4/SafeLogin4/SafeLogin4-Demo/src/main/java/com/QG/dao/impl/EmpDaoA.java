package com.QG.dao.impl;

import com.QG.dao.EmpDao;
import com.QG.utils.JDBCUtils;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;

public class EmpDaoA{
    public int findUserIdByUsernameAndPassword(String username, String pwd){
        Connection connection = null;
        Statement statement = null;
        ResultSet resultSet = null;

            try {
                // 调用 JDBCUtils 获取数据库连接,这里为什么没有调用JDBCUtils中的static方法呢？
                //静态代码块，用于在类加载时执行一次，初始化数据库连接相关配置
                connection = JDBCUtils.getConnection();

                // 创建 Statement 对象用于执行 SQL 语句
                statement = connection.createStatement();

                // 调用 JDBCUtils 依据username和pwd查询用户
                return JDBCUtils.findEmp(connection, username, pwd);
            } catch (Exception e) {
                // 处理异常
                e.printStackTrace();
            }
            finally {
                // 释放资源
                JDBCUtils.close(resultSet, statement, connection);
            }
            return 0;
    }
}
