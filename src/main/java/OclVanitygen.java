import java.lang.System;

public class OclVanitygen {
    static {
        System.loadLibrary("oclvanitygen");
    }

    public static native int oclGenerateAddress(String address, boolean ignore);

    public static native String[] oclGetPrivateKey();

    public static native double[] oclGetProgress();

    public static native String[] getDevices();

    public static native void oclQuit();

    public static boolean ISRUNNING = true;

    public static void main(String[] args) {

        new Thread(new Runnable() {
            @Override
            public void run() {
                ISRUNNING = true;
 		System.out.println("java:");
                String[] devices = getDevices();
                for (int i = 0; i < devices.length; i++) {
                    System.out.println("java-device:" + devices[i]);
                }
                System.out.println("oclGenerateAddress");
                oclGenerateAddress("1PQPP,0:0", true);
                String[] strings = oclGetPrivateKey();
                if (strings != null) {
                    for (String str : strings)
                        System.out.println("java :" + str);
                }
                ISRUNNING = false;

            }
        }
        ).start();
        new Thread(new Runnable() {
            @Override
            public void run() {
                while (ISRUNNING) {
                    double[] doubleArray = oclGetProgress();
                    if (doubleArray != null) {
                        String string = "";
                        for (int i = 0; i < doubleArray.length; i++) {
                            string = string + "," + doubleArray[i];
                            if (i == doubleArray.length - 1) {
                                System.out.println(string);
                                string = "";
                            }
                        }
                    }
                    try {
                        Thread.sleep(200);
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            }
        }).start();

    }
}
