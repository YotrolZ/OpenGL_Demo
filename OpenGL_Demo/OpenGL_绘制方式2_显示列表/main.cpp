//
//  main.cpp
//  OpenGL_绘制方式2_显示列表
//
//  Created by Sunshine on 2018/3/16.
//  Copyright © 2018年 YotrolZ. All rights reserved.
//

#include <stdio.h>
#include "GLTools.h"
#include <GLUT/GLUT.h>

void draw() {
    
    glNewList(1, GL_COMPILE);
    
    glColor3f (1.0, 0.0, 0.0);
    
    glBegin (GL_TRIANGLES);
    glVertex2f(-0.5f, 0.0f);
    glVertex2f(0.5f, 0.0f);
    glVertex2f(0.0f, 0.5f);
    glEnd ();
    
    glEndList ();
    
    glCallList (1);
    
    glFlush(); // 强制刷新缓冲，保证绘图命令将被执行，而不是存储在缓冲区中等待其他的OpenGL命令。
}

int main(int argc,const char *argv[]) {
    
    //1.初始化一个GLUT库
    glutInit(&argc, (char **)argv);
    
    //2.创建一个窗口并制定窗口名
    glutCreateWindow("OpenGL绘制方式2--显示列表");
    
    //3.注册一个绘图函数，操作系统在必要时刻就会对窗体进行重绘制操作
    //它设置了一个显示回调（diplay callback），即GLUT在每次更新窗口内容的时候回自动调用该例程
    glutDisplayFunc(draw);
    
    //这是一个无限执行的循环，它会负责一直处理窗口和操作系统的用户输入等操作。（注意：不会执行在glutMainLoop()之后的所有命令。）
    glutMainLoop();
    
    return 0;
}
