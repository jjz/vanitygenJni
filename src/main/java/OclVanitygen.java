
public class OclVanitygen {
    static {
        System.loadLibrary("oclvanitygen");
    }

    public static native void oclGenerateAddress(String address, boolean ignore);

    public static native String[] oclGetPrivateKey();

    public static native double[] oclGetProgress();

    public static native String[] oclGetEquipment();
}
