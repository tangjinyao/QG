package com.QG.dao;


public interface EmpDao {
    int findUserIdByUsernameAndPassword(String username, String pwd);

    int addUserIdByUsernameAndPassword(String username, String pwd);
}
