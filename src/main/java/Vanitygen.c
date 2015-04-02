#include "Vanitygen.h"
#include "vanitygen/vanitygen.h"
#include "JniUtil.h"


JNIEXPORT void JNICALL Java_Vanitygen_generateAddress
  (JNIEnv * env, jobject object, jstring string,jboolean ignore){
      char** pP = NULL;
      pP = (char**)calloc(2, sizeof(char*));
      pP[0] = "./vanitygen";
      pP[1] = jstringTostring(env,string);
      printf("vanjni\n%s",pP[1]);
      vanitygen(2,pP);
      return;

  }

JNIEXPORT jobjectArray JNICALL Java_Vanitygen_getPrivateKey
  (JNIEnv * env, jobject object){
      jstring      str;
      jobjectArray args = 0;
      char** sa = getPrivatekey();
      jsize len =2;
      if(!sa){
          printf("result isnull");
          return NULL;
      }
      int          i=0;
      args = (*env)->NewObjectArray(env,len,(*env)->FindClass(env,"java/lang/String"),0);
      for( i=0; i < len; i++ )
      {
          str = stoJstring(env,sa[i]);
          (*env)->SetObjectArrayElement(env,args, i, str);
          free(sa[i]);
          sa[i]=NULL;
          str=NULL;
      }
      return args;


  }

JNIEXPORT jdoubleArray JNICALL Java_Vanitygen_getProgress
  (JNIEnv * env, jobject object){
        jdouble   str;
        jobjectArray args = 0;
        double* sa = getProgresses();
        jsize len =4;
        if(!sa){
            printf("result isnull");
            return NULL;
        }
        args = (*env)->NewDoubleArray(env,len);
        (*env)->SetDoubleArrayRegion(env,args,0,len,sa);
        return args;


  }


