/**
 * Created by nn on 15/3/6.
 */
public class VanitygenJni {
    static {
        System.loadLibrary("vanitygen");
    }

    public static native void generateAddress(String address);

    public static native String[] getPrivaeKey();

    public static native double[] getProgress();

    public static boolean ISRUNNING = true;

    public static void main(String[] args) {

        new Thread(new Runnable() {
            @Override
            public void run() {
                ISRUNNING = true;
                generateAddress("1PPPQ");
                String[] strings = getPrivaeKey();
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
                    double[] doubleArray = getProgress();
                    if (doubleArray != null) {
                        for (double dou : doubleArray) {
                            System.out.println("dou:" + dou);
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
