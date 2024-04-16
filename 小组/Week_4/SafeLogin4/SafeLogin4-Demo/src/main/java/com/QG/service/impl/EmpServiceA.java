package com.QG.service.impl;

import com.QG.dao.EmpDao;
import com.QG.dao.impl.EmpDaoA;
import com.QG.service.EmpService;

public class EmpServiceA{
    private EmpDaoA empDao = new EmpDaoA();
    public int findUserIdByUsernameAndPassword(String username, String pwd) {
        return empDao.findUserIdByUsernameAndPassword(username, pwd);
    }

}
