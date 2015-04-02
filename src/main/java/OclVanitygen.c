#include "OclVanitygen.h"
#include "vanitygen/oclvanitygen.h"
#include "JniUtil.h"



JNIEXPORT void JNICALL Java_OclVanitygen_oclGenerateAddress
  (JNIEnv * env, jclass object, jstring string,jboolean ignore){
      char** pP = NULL;
      pP = (char**)calloc(2, sizeof(char*));
      pP[0] = "./oclvanitygen";
      pP[1] = jstringTostring(env,string);
      printf("vanjni\n%s",pP[1]);
      oclvanitygen(2,pP);
      return;

  }

JNIEXPORT jobjectArray JNICALL Java_OclVanitygen_oclGetPrivateKey
  (JNIEnv * env, jclass object){
      jstring      str;
      jobjectArray args = 0;
      char** sa = oclgetPrivatekey();
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

JNIEXPORT jdoubleArray JNICALL Java_OclVanitygen_oclGetProgress
  (JNIEnv * env, jclass object){
        jdouble   str;
        jobjectArray args = 0;
        double* sa = oclgetProgresses();
        jsize len =4;
        if(!sa){
            printf("result isnull");
            return NULL;
        }
        args = (*env)->NewDoubleArray(env,len);
        (*env)->SetDoubleArrayRegion(env,args,0,len,sa);
        return args;


  }

 JNIEXPORT jobjectArray JNICALL Java_OclVanitygen_oclGetEquipment
    (JNIEnv * env, jclass object){
        return NULL;

 }

 JNIEXPORT void JNICALL Java_OclVanitygen_oclQuit
   (JNIEnv * env, jclass object){

   }
