#include "NOclVanitygen.h"
#include "vanitygen/oclvanitygen.h"
#include "vanitygen/oclengine.h"
#include "JniUtil.h"
#include "vanitygen/pattern.h"

void split(char **arr, char *str, const char *del) {
   char *s = strtok(str, del);

   while(s != NULL) {
     *arr++ = s;
     s = strtok(NULL, del);
   }
 }

JNIEXPORT jint JNICALL Java_OclVanitygen_oclGenerateAddress
  (JNIEnv * env, jclass object, jstring input , jboolean ignore){
      char** params = NULL;
      printf("ocl\n");
      int index=0;
      int count=3;

      if(ignore){
         count++;
      }
      params = (char**)calloc(count, sizeof(char*));
      params[index] = "./oclvanitygen";      
      index++;
      char s[15];
      char * str= jstringTostring(env,input);
      char ** pP= (char**)calloc(2, sizeof(char*));
      split(pP,str,",");
      sprintf(s, "-D %s",pP[1]);
      params[index]=s;
      printf("oclvanjni:%s\n",s);

      index++;
      if(ignore){
         params[index]="-i";
         index++;
      }
      params[index] = pP[0];
      printf("2:%s\n",params[index]);
      return  oclvanitygen(count,params);

  }

JNIEXPORT jobjectArray JNICALL Java_OclVanitygen_oclGetPrivateKey
  (JNIEnv * env, jclass object){
      jstring      str;
      jobjectArray args = 0;
      char** sa = get_private_key();
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
        double* sa = get_progresses();
        jsize len =4;
        if(!sa){
            printf("result isnull");
            return NULL;
        }
        args = (*env)->NewDoubleArray(env,len);
        (*env)->SetDoubleArrayRegion(env,args,0,len,sa);
        return args;


  }
//0:Appl,0:Intel(R) Core(TM) i7-2640M CPU @ 2.80GHz
 JNIEXPORT jobjectArray JNICALL Java_OclVanitygen_getDevices
    (JNIEnv * env, jclass object){
        jstring      str;
        jobjectArray args = 0;
        char** sa = vg_ocl_enumerate_devices();
        jint len =0;
        while(getlen(sa[len])>0){
            ++len;
        }
        if(!sa){
            printf("result isnull");
            return NULL;
        }
         int i=0;
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

 JNIEXPORT void JNICALL Java_OclVanitygen_oclQuit
   (JNIEnv * env, jclass object){

   }
