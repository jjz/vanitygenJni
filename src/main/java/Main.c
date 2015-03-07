#include <jni.h>
#include "main.h"
#include <stdio.h>
JNIEXPORT void JNICALL Java_Main_DisplayHello
(JNIEnv *env, jobject obj)
{
    printf("From jni_helloworldImpl.cpp :");
    printf("Hello world ! \n");
    return;
}