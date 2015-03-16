#include <jni.h>
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include <math.h>
#include <stdint.h>
#include "Vanitygen.h"
#include <stdio.h>
#include "vanitygen/vanitygen.h"



char* jstringTostring(JNIEnv* env, jstring jstr)
{
       char* rtn = NULL;
       jclass clsstring = (*env)->FindClass(env,"java/lang/String");
       jstring strencode = (*env)->NewStringUTF(env,"utf-8");
       jmethodID mid = (*env)->GetMethodID(env,clsstring, "getBytes", "(Ljava/lang/String;)[B");
       jbyteArray barr= (jbyteArray)(*env)->CallObjectMethod(env,jstr, mid, strencode);
       jsize alen = (*env)->GetArrayLength(env,barr);
       jbyte* ba = (*env)->GetByteArrayElements(env,barr, JNI_FALSE);
       if (alen > 0)
       {
                 rtn = (char*)malloc(alen + 1);
                 memcpy(rtn, ba, alen);
                 rtn[alen] = 0;
       }
       (*env)->ReleaseByteArrayElements(env,barr, ba, 0);
       return rtn;
}

//char* to jstring
jstring stoJstring(JNIEnv* env, const char* pat)
{
       jclass strClass = (*env)->FindClass(env,"Ljava/lang/String;");
       jmethodID ctorID = (*env)->GetMethodID(env,strClass, "<init>", "([BLjava/lang/String;)V");
       jbyteArray bytes = (*env)->NewByteArray(env,strlen(pat));
       (*env)->SetByteArrayRegion(env,bytes, 0, strlen(pat), (jbyte*)pat);
       jstring encoding = (*env)->NewStringUTF(env,"utf-8");
       return (jstring)(*env)->NewObject(env,strClass, ctorID, bytes, encoding);
}


JNIEXPORT void JNICALL Java_Vanitygen_generateAddress
  (JNIEnv * env, jobject object, jstring string){

        printf("From jni :\n");
      char** pP = NULL;
      pP = (char**)calloc(2, sizeof(char*));
      pP[0] = "./vanitygen";
      printf("From jni : %s\n", jstringTostring(env,string));
      pP[1] = jstringTostring(env,string);
      printf("vanitygen :\n");
      vanitygen(2,pP);
      return;

  }

JNIEXPORT jobjectArray JNICALL Java_Vanitygen_getPrivaeKey
  (JNIEnv * env, jobject object){

  }

JNIEXPORT jobjectArray JNICALL Java_Vanitygen_getProgress
  (JNIEnv * env, jobject object){

  }


