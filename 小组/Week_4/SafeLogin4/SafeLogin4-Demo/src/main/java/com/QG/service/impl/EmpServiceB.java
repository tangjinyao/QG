package com.QG.service.impl;

import com.QG.dao.EmpDao;
import com.QG.dao.impl.EmpDaoB;
import com.QG.service.EmpService;

public class EmpServiceB{
    private EmpDaoB empDao = new EmpDaoB();
    public int addUserIdByUsernameAndPassword(String username, String pwd) {
        return empDao.addUserIdByUsernameAndPassword(username, pwd);
    }

}
