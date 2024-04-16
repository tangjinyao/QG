package com.QG.utils;

import java.io.InputStream;
import java.sql.*;
import java.util.Properties;

public class JDBCUtils {

    // 定义数据库连接需要的URL、用户名和密码的静态变量
    private static String url;
    private static String user;
    private static String password;

    // 静态代码块，用于在类加载时执行一次，初始化数据库连接相关配置
    static {
        try {
            // 获取类加载器中的database.properties配置文件的输入流
            // "database.properties"文件应该位于类路径（classpath）下
            InputStream inputStream = JDBCUtils.class.getClassLoader().getResourceAsStream("database.properties");

            // 创建一个Properties对象，用于加载属性文件
            Properties prop = new Properties();

            // 从输入流中加载属性到Properties对象中
            prop.load(inputStream);

            // 从Properties对象中获取数据库连接URL，并赋值给静态变量url
            url = prop.getProperty("db.url");

            // 从Properties对象中获取数据库用户名，并赋值给静态变量user
            user = prop.getProperty("db.user");

            // 从Properties对象中获取数据库密码，并赋值给静态变量password
            password = prop.getProperty("db.password");

            // 从Properties对象中获取数据库驱动类名
            String driver = prop.getProperty("db.driver");

            // 加载并注册数据库驱动，使得JDBC可以通过驱动管理器连接到数据库
            Class.forName(driver);

        } catch (Exception e) {
            // 如果在加载属性文件、获取属性或注册驱动时发生异常，则打印异常堆栈信息
            e.printStackTrace();
        }
    }


    /**
     * 获取可用的链接对象
     *
     * @return connection 返回数据库连接对象
     */
    public static Connection getConnection() {
        // 初始化Connection对象为null，后续将通过数据库驱动管理器获取实际连接
        Connection connection = null;

        try {
            // 输出信息到控制台，表示正在尝试连接数据库
            System.out.println("Connecting to database...");

            // 使用JDBC的DriverManager来获取数据库连接对象
            connection = DriverManager.getConnection(url, user, password);

            // 连接成功后输出信息到控制台
            System.out.println("Connected database successfully...");

        } catch (SQLException se) {
            // 如果在获取连接过程中发生了SQLException异常
            // 则打印异常的堆栈跟踪信息，这有助于诊断连接失败的原因
            se.printStackTrace();
        }

        // 方法结束，返回获取到的数据库连接对象（可能是null，如果连接失败）
        return connection;
    }

    /**
     * 释放资源
     *
     * @param resultSet 结果集对象，可能为空（如果查询未执行或失败）
     * @param statement 命令对象，用于执行SQL语句，可能为空（如果未创建或已关闭）
     * @param connection 链接对象，代表与数据库的连接，可能为空（如果连接未建立或已关闭）
     */
    public static void close(ResultSet resultSet, Statement statement, Connection connection) {
        // 使用try块来封装可能抛出SQLException的代码
        try {
            // 检查resultSet是否不为null，如果不为null则关闭它
            // 关闭ResultSet可以释放与其相关的数据库资源
            if (resultSet != null) {
                resultSet.close();
            }

            // 检查statement是否不为null，如果不为null则关闭它
            // 关闭Statement可以释放与其相关的数据库资源，包括它创建的ResultSet对象
            if (statement != null) {
                statement.close();
            }

            // 检查connection是否不为null，如果不为null则关闭它
            // 关闭Connection可以释放与数据库的物理连接，这是非常重要的资源
            if (connection != null) {
                connection.close();
            }
        } catch (SQLException se) {
            // 如果在关闭资源时发生SQLException异常，则打印异常的堆栈跟踪信息
            // 这有助于诊断关闭资源时可能遇到的问题
            se.printStackTrace();
        }
    }

    /**
     * 查询数据并打印结果。
     *
     * @param statement 数据库连接对象
     * @throws Exception 如果发生数据库访问错误
     */
    public static void traverse(Statement statement) throws Exception {
        // 执行查询语句并获取结果集
        String sql = "SELECT * FROM student"; // 定义SQL查询语句，从student表中选择所有列。
        ResultSet resultSet = statement.executeQuery(sql); // 使用Statement对象执行SQL查询，并将结果集赋值给resultSet变量。

        // 处理查询结果
        System.out.println("id" + '\t' + "name" + '\t' + "age");//打印表头，使用制表符('\t')分隔列名。

        // 遍历结果集
        while (resultSet.next()) { // 使用resultSet的next()方法遍历每一行数据。
            // 对于每一行数据，使用getString方法获取指定列的值，并打印到控制台。
            System.out.print(resultSet.getString("id") + '\t'); // 打印id列的值，后跟制表符。
            System.out.print(resultSet.getString("name") + "\t\t"); // 打印name列的值，后跟两个制表符
            System.out.println(resultSet.getString("age")); // 打印age列的值，并换行。
        }

        //close(resultSet, statement, null);
    }

    /**
     * 插入数据
     *
     * @param connection 链接对象       // 传入一个数据库连接对象
     * @param name 学生姓名           // 传入要插入的学生的姓名
     * @param age 学生年龄           // 传入要插入的学生的年龄
     */
// 定义一个公开的静态方法，用于插入学生数据到数据库
    public static void insertStudent(Connection connection, String name, int age) {
        PreparedStatement preparedStatement = null;  // 定义一个PreparedStatement对象，并初始化为null

        try {
            // 定义SQL插入语句，其中使用占位符'?'代替实际的值
            String sql = "INSERT INTO student (name, age) VALUES (?, ?)";

            // 使用connection对象准备SQL语句，返回一个PreparedStatement对象
            preparedStatement = connection.prepareStatement(sql);

            // 使用PreparedStatement的setString方法设置第一个占位符的值为传入的name
            preparedStatement.setString(1, name);

            // 使用PreparedStatement的setInt方法设置第二个占位符的值为传入的age
            preparedStatement.setInt(2, age);

            // 执行更新操作，返回被影响的行数
            int rowsInserted = preparedStatement.executeUpdate();

            // 如果被影响的行数大于0，说明插入操作成功
            if (rowsInserted > 0) {
                System.out.println("A new student was inserted successfully!");
            }

        } catch (SQLException se) {
            // 如果在执行SQL操作时发生异常，则捕获该异常并打印堆栈信息
            se.printStackTrace();
        } finally {
            // 无论是否发生异常，都执行finally块中的代码
            close(null, preparedStatement, null);
        }
    }

    /**
     * 删除数据(依据姓名删除)
     *
     * @param connection 链接对象
     * @param name 想删除的姓名
     */
    public static void deleteStudent(Connection connection, String name) {
        PreparedStatement preparedStatement = null; // 用于执行SQL删除语句的PreparedStatement对象

        try {
            // 定义SQL删除语句，使用占位符'?'代替要删除的姓名，以防止SQL注入攻击。
            String sql = "DELETE FROM student WHERE name = ?";

            // 使用Connection对象创建PreparedStatement对象，并传入SQL删除语句。
            preparedStatement = connection.prepareStatement(sql);

            // 设置PreparedStatement对象的参数，将占位符'?'替换为实际的姓名值。
            preparedStatement.setString(1, name);

            // 执行删除操作，返回影响的行数。
            int affectedRows = preparedStatement.executeUpdate();

            // 如果影响的行数大于0，说明删除操作成功。
            if (affectedRows > 0) {
                System.out.println("Student with name '" + name + "' was deleted successfully.");
            } else {
                System.out.println("No student found with the name '" + name + "' to delete.");
            }

        } catch (SQLException e) {
            // 处理数据库访问错误，打印错误堆栈跟踪信息。
            e.printStackTrace();
        } finally {
            // 关闭PreparedStatement对象，释放资源。
            try {
                if (preparedStatement != null) {
                    preparedStatement.close();
                }
            } catch (SQLException ex) {
                // 处理关闭PreparedStatement对象时可能发生的错误。
                ex.printStackTrace();
            }
        }
    }

    /**
     * 删除数据(依据年龄删除)
     *
     * @param connection 链接对象
     * @param age 想删除的年龄
     */
    public static void deleteStudent(Connection connection, int age) {
        PreparedStatement preparedStatement = null; // 用于执行SQL删除语句的PreparedStatement对象

        try {
            // 定义SQL删除语句，使用占位符'?'代替要删除的姓名，以防止SQL注入攻击。
            String sql = "DELETE FROM student WHERE age = ?";

            // 使用Connection对象创建PreparedStatement对象，并传入SQL删除语句。
            preparedStatement = connection.prepareStatement(sql);

            // 设置PreparedStatement对象的参数，将占位符'?'替换为实际的姓名值。
            preparedStatement.setInt(1, age);

            // 执行删除操作，返回影响的行数。
            int affectedRows = preparedStatement.executeUpdate();

            // 如果影响的行数大于0，说明删除操作成功。
            if (affectedRows > 0) {
                System.out.println("Student with age '" + age + "' was deleted successfully.");
            } else {
                System.out.println("No student found with the age '" + age + "' to delete.");
            }

        } catch (SQLException e) {
            // 处理数据库访问错误，打印错误堆栈跟踪信息。
            e.printStackTrace();
        } finally {
            // 关闭PreparedStatement对象，释放资源。
            try {
                if (preparedStatement != null) {
                    preparedStatement.close();
                }
            } catch (SQLException ex) {
                // 处理关闭PreparedStatement对象时可能发生的错误。
                ex.printStackTrace();
            }
        }
    }

    /**
     * 依据姓名查找学生的所有信息
     *
     * @param connection 链接对象
     * @param name 想查找的姓名
     */
    public static void findStudent(Connection connection, String name) {
        PreparedStatement preparedStatement = null;
        ResultSet resultSet = null;

        try {
            // 定义SQL查询语句，使用占位符'?'代替要查询的姓名，以防止SQL注入攻击。
            String sql = "SELECT * FROM student WHERE name = ?";

            // 使用Connection对象创建PreparedStatement对象，并传入SQL查询语句。
            preparedStatement = connection.prepareStatement(sql);

            // 设置PreparedStatement对象的参数，将占位符'?'替换为实际的姓名值。
            preparedStatement.setString(1, name);

            // 执行查询操作，获取结果集。
            resultSet = preparedStatement.executeQuery();

            // 如果结果集不为空，则遍历结果集并打印学生的信息。
            if (resultSet.next()) {
                System.out.println("找到学生信息：");
                System.out.println("id: " + resultSet.getString("id"));
                System.out.println("name: " + resultSet.getString("name"));
                System.out.println("age: " + resultSet.getString("age"));
                // 如果有更多列，可以继续打印

                // 处理可能存在的其他结果行（虽然根据姓名查找通常应该只有一个结果）
                while (resultSet.next()) {
                    System.out.println("注意：找到多个同名学生！");
                    System.out.println("id: " + resultSet.getString("id"));
                    System.out.println("name: " + resultSet.getString("name"));
                    System.out.println("age: " + resultSet.getString("age"));
                    // 如果有更多列，可以继续打印
                }
            } else {
                System.out.println("没有找到姓名为 '" + name + "' 的学生信息。");
            }

        } catch (SQLException e) {
            // 处理数据库访问错误
            e.printStackTrace();
        }
    }

    /**
     * 依据年龄查找学生信息
     *
     * @param connection
     * @param age
     */
    public static void findStudent(Connection connection, int age){
        PreparedStatement preparedStatement = null;
        ResultSet resultSet = null;

        try{
            String sql = "SELECT * FROM student WHERE age = ?";

            preparedStatement = connection.prepareStatement(sql);

            preparedStatement.setInt(1, age);

            resultSet = preparedStatement.executeQuery();

            if(resultSet.next()){
                System.out.println("找到学生信息:");
                System.out.println("id:" + resultSet.getString("id"));
                System.out.println("name:" + resultSet.getString("name"));
                System.out.println("age:" + resultSet.getInt("age"));
                while(resultSet.next()){
                    System.out.println("注意：找到多个同年龄学生！");
                    System.out.println("id:" + resultSet.getString("id"));
                    System.out.println("name:" + resultSet.getString("name"));
                    System.out.println("age:" + resultSet.getInt("age"));
                }
            }
            else{
                System.out.println("没有找到年龄为" + age + "的学生信息");
            }
        }

        catch (SQLException e) {
            e.printStackTrace();
        }

    }

    public static int findEmp(Connection connection, String username, String pwd){
        PreparedStatement preparedStatement = null;
        ResultSet resultSet = null;

        try{
            String sql = "SELECT * FROM user WHERE username = ? and pwd = ?";

            preparedStatement = connection.prepareStatement(sql);

            preparedStatement.setString(1, username);
            preparedStatement.setString(2, pwd);

            resultSet = preparedStatement.executeQuery();

            if(resultSet.next()){
                System.out.println("找到Emp信息:");
                System.out.println("id:" + resultSet.getString("uid"));
                System.out.println("name:" + resultSet.getString("username"));
                System.out.println("age:" + resultSet.getString("pwd"));
                while(resultSet.next()){
                    System.out.println("注意：找到多个Emp！");
                    System.out.println("id:" + resultSet.getString("uid"));
                    System.out.println("name:" + resultSet.getString("username"));
                    System.out.println("age:" + resultSet.getString("pwd"));
                }
                return 1;//找到了
            }
            else{
                System.out.println("没有找到username为" + username + ",pwd为" + pwd + "的Emp.");
            }
        }

        catch (SQLException e) {
            e.printStackTrace();
        }

        return 0;//没有找到
    }

    public static int addEmp(Connection connection, String username, String pwd){
        PreparedStatement preparedStatement = null;

        try{
            String sqlSelect = "SELECT COUNT(*) FROM user WHERE username = ?";
            PreparedStatement selectStmt = connection.prepareStatement(sqlSelect);
            selectStmt.setString(1, username);
            ResultSet resultSet = selectStmt.executeQuery();

            if (resultSet.next()) {
                int count = resultSet.getInt(1);
                if (count > 0) {
                    // 已存在相同名字的用户
                    return 0; // 返回0表示用户名已存在，不添加重复名字
                }
            }

            // 用户名不存在，执行插入操作
            String sqlInsert = "INSERT INTO user(username, pwd) VALUES (?, ?)";
            PreparedStatement insertStmt = connection.prepareStatement(sqlInsert);
            insertStmt.setString(1, username);
            insertStmt.setString(2, pwd);

            // 执行插入操作，由于已经检查过用户名不存在，因此可以直接插入
            int affectedRows = insertStmt.executeUpdate();

            // 插入成功，返回受影响的行数
            //return affectedRows;

            return 1;
        }

        catch (SQLException e) {
            e.printStackTrace();
        }

        return 1;//注册成功
    }

    /**
     * 修改学生姓名
     *
     * @param connection 数据库连接对象
     * @param studentId    要修改姓名的学生的ID
     * @param newName      学生的新姓名
     */
    public static void updateStudent(Connection connection, int studentId, String newName) {
        PreparedStatement preparedStatement = null;

        try {
            // 准备SQL更新语句
            String sql = "UPDATE student SET name = ? WHERE id = ?";

            // 创建PreparedStatement对象
            preparedStatement = connection.prepareStatement(sql);

            // 设置参数
            preparedStatement.setString(1, newName);
            preparedStatement.setInt(2, studentId);

            // 执行更新
            int affectedRows = preparedStatement.executeUpdate();

            // 检查是否成功更新了记录
            if (affectedRows > 0) {
                System.out.println("成功更新学生姓名。");
            } else {
                System.out.println("没有找到ID为 " + studentId + " 的学生记录，无法更新姓名。");
            }

        } catch (SQLException e) {
            // 处理数据库访问错误
            System.err.println("更新学生姓名时发生错误：");
            e.printStackTrace();
        }
    }

    /**
     * 修改学生姓名
     *
     * @param connection 数据库连接对象
     * @param studentId    要修改姓名的学生的ID
     * @param newAge      学生的新年龄
     */
    public static void updateStudent(Connection connection, int studentId, int newAge) {
        PreparedStatement preparedStatement = null;

        try {
            // 准备SQL更新语句
            String sql = "UPDATE student SET age = ? WHERE id = ?";

            // 创建PreparedStatement对象
            preparedStatement = connection.prepareStatement(sql);

            // 设置参数
            preparedStatement.setInt(1, newAge);
            preparedStatement.setInt(2, studentId);

            // 执行更新
            int affectedRows = preparedStatement.executeUpdate();

            // 检查是否成功更新了记录
            if (affectedRows > 0) {
                System.out.println("成功更新学生年龄。");
            } else {
                System.out.println("没有找到ID为 " + studentId + " 的学生记录，无法更新年龄。");
            }

        } catch (SQLException e) {
            // 处理数据库访问错误
            System.err.println("更新学生年龄时发生错误：");
            e.printStackTrace();
        }
    }
}