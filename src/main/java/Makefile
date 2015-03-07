#编译JNI的DLL
#参考: http://www.inonit.com/cygwin/jni/helloWorld/c.html
#JAVA_HOME=/System/Library/Frameworks/JavaVM.framework
#final:JAVAHOME clear
#	gcc -dynamiclib -o libHello.jnilib jni_helloworldImpl.cpp -framework JavaVM -I$(JAVA_HOME)/Headers
#clear:
#	rm -f *.jnilib


# Define a variable for classpath

JAVA_HOME=/System/Library/Frameworks/JavaVM.framework

CC=gcc
OBJS=main.o
#CFLAGS=-dynamiclib

all : libvanitygen.jnilib
LIBS=-framework JavaVM

CFLAGS          :=      $(CFLAGS) -I$(JAVA_HOME)/Headers
# $@ matches the target, $< matches the first dependancy
libvanitygen.jnilib : main.o
	$(CC) -shared -fpic -o $@ $<

# $@ matches the target, $< matches the first dependancy
main.o : main.c main.h
	gcc -dynamiclib -I$(JAVA_HOME)/Headers -c $< -o $@  


# $* matches the target filename without the extension
#TapeJNI.h : TapeJNI.class
#javah -classpath $(CLASS_PATH) $*

clean:
	rm -rf *.o
	rm -rf *.jnilib
	rm -rf *.so