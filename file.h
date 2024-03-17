#ifndef _FILE_H
#define _FILE_H

#include "common.h"
#include "stu.h"


extern void readTimuFile(timuNode* headNode, char* fileURL);
extern void readStuFile(stuNode* headNode, char* fileURL);
extern void readPwdFile(char* pwd, char* fileURL);
extern void saveTimuFile(timuNode* headNode, char* fileURL);
extern void saveStuFile(stuNode* headNode, char* fileURL);
extern void savePwdFile(char* pwd, const char* fileURL);

#endif