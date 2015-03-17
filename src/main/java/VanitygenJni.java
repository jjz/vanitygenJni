/**
 * Created by nn on 15/3/6.
 */
public class VanitygenJni {
    static {
        System.loadLibrary("vanitygen");
    }

    public static native void generateAddress(String address);

    public static native String[] getPrivaeKey();

    public static native String[] getProgress();

    public static void main(String[] args) {

        new Thread(new Runnable() {
            @Override
            public void run() {
                generateAddress("1PPP");
                String[] strings = getPrivaeKey();
                if (strings != null) {
                    for (String str : strings) {
                        System.out.println("java :" + str);
                    }
                }
            }
        }).start();

    }
}
