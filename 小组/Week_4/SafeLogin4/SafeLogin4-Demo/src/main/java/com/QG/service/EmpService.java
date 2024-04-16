package com.QG.service;

public interface EmpService {
    public int findUserIdByUsernameAndPassword(String username, String pwd);

    public int addUserIdByUsernameAndPassword(String username, String pwd);
}
