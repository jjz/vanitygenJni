/**
 * Created by nn on 15/3/6.
 */
public class Main {
    static {
        System.loadLibrary("vanitygen");
    }

    public native void DisplayHello();

    public static void main(String[] args) {
        new Main().DisplayHello();
    }
}
