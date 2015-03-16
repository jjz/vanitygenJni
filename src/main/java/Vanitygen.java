/**
 * Created by nn on 15/3/6.
 */
public class Vanitygen {
    static {
        System.loadLibrary("vanitygen");
    }

    public native void generateAddress(String address);

    public native String[] getPrivaeKey();

    public native String[] getProgress();

    public static void main(String[] args) {

        new Thread(new Runnable() {
            @Override
            public void run() {
                new Vanitygen().generateAddress("1P");
            }
        }).start();

    }
}
