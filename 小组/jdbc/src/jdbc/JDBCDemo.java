package src.jdbc;

import java.sql.Connection;
import java.sql.Statement;
import java.sql.ResultSet;

public class JDBCDemo {

    public static void main(String[] args) throws Exception {
        Connection connection = null;
        Statement statement = null;
        ResultSet resultSet = null;

        try {
            // 调用 JDBCUtils 获取数据库连接
            connection = JDBCUtils.getConnection();

            // 创建 Statement 对象用于执行 SQL 语句
            statement = connection.createStatement();

            // 调用 JDBCUtils 往数据库插入数据
            //JDBCUtils.insertStudent(connection, "abc", 80);
            //JDBCUtils.insertStudent(connection, "fde", 28);

            // 调用 JDBCUtils 遍历整个数据库
            JDBCUtils.traverse(statement);

            // 调用 JDBCUtils 修改学生姓名
            JDBCUtils.updateStudent(connection, 1, "tjy");

            // 调用 JDBCUtils 修改学生年龄
            JDBCUtils.updateStudent(connection, 1, 18);

            // 调用 JDBCUtils 依据姓名删除学生
            JDBCUtils.deleteStudent(connection, "abc");

            // 调用 JDBCUtils 依据年龄删除学生
            JDBCUtils.deleteStudent(connection, 28);

            // 调用 JDBCUtils 遍历整个数据库
            JDBCUtils.traverse(statement);

            // 调用 JDBCUtils 依据姓名查询学生
            JDBCUtils.findStudent(connection, "tjy");

            // 调用 JDBCUtils 依据年龄查询学生
            JDBCUtils.findStudent(connection, 18);

        } catch (Exception e) {
            // 处理异常
            e.printStackTrace();
        } finally {
            // 释放资源
            JDBCUtils.close(resultSet, statement, connection);
        }

    }
}
